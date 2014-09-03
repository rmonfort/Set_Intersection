#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::vector;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;

	// Loop through input file
	while (getline(ifs, line))
	{
		istringstream list(line);
		string temp;
		vector<int> v1, v2;

		// Get a line seperated by a semi-colon
		getline(list, temp, ';');
		istringstream values(temp);

		// Load each list of numbers into a vector
		while (getline(values, temp, ','))
		{
			int num = std::stoi(temp);
			v1.push_back(num);
		}
		getline(list, temp, ';');
		values.clear();
		values.str(temp);
		while (getline(values, temp, ','))
		{
			int num = std::stoi(temp);
			v2.push_back(num);
		}

		// Find the intersection of the vectors
		vector<int> v3(20);
		auto it = std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		v3.resize(it - v3.begin()); 

		// Build results string
		string results;
		for (auto &n : v3)
		{
			string s = std::to_string(n);
			results += (s + ",");
		}
		
		// Print new line if no results found, otherwise print results
		if (results.empty())
		{
			cout << endl;
		}
		else
		{
			results.pop_back();
			cout << results << endl;
		}
	}

	return 0;
}
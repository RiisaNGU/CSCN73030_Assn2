// Lisa Nguyen
// CSCN73030 - Assignment 2
// 09/23/22
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct STUDENT_DATA
{
	string FirstName;
	string LastName;
};

int main()
{
	string StudentDataFile = "StudentData.txt";
	string str;
	STUDENT_DATA student;
	vector <STUDENT_DATA> DataVector;
	ifstream file;
	file.open(StudentDataFile);

	if (file)
	{
		while (getline(file, str))
		{
			int comma = str.find(",");

			student.LastName = str.substr(0, comma);
			student.FirstName = str.substr(comma + 1, str.length());

			DataVector.push_back(student);
		}
	}
	else
		cout << "Error opening file" << endl;

#ifndef NDEBUG
	// printing from vector to console
	for (STUDENT_DATA i : DataVector)
		cout << i.FirstName << " " << i.LastName << endl;
#endif // NDEBUG


	return 1;
}
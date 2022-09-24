// Lisa Nguyen
// CSCN73030 - Assignment 2
// 09/23/22
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define PRE_RELEASE

struct STUDENT_DATA
{
	string FirstName;
	string LastName;
	string Email;
};

int main()
{
#ifdef PRE_RELEASE
	cout << "Running Pre-Release code" << endl;
	string StudentDataFile = "StudentData_Emails.txt";
#else
	cout << "Running standard code" << endl;
	string StudentDataFile = "StudentData.txt";
#endif // PRE_RELEASE

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
			int emailComma = str.find_last_of(",");

			student.LastName = str.substr(0, comma);

#ifdef PRE_RELEASE
			student.FirstName = str.substr(comma + 1, emailComma - comma - 1);
			student.Email = str.substr(emailComma + 1, str.length());
#else
			student.FirstName = str.substr(comma + 1, str.length());
#endif // PRE_RELEASE

			DataVector.push_back(student);
		}
	}
	else
		cout << "Error opening file" << endl;

#ifdef _DEBUG
#ifdef PRE_RELEASE
	for (STUDENT_DATA i : DataVector)
		cout << i.FirstName << " " << i.LastName << " " << i.Email << endl;
#else
	// printing from vector to console
	for (STUDENT_DATA i : DataVector)
		cout << i.FirstName << " " << i.LastName << endl;
#endif // PRE_RELEASE
#endif // _DEBUG

	return 1;
}
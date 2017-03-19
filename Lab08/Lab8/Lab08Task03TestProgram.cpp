#include<iostream>
#include<string>
#include"LinkedList.h"
using namespace std;

int main() {
	int choice = 0;
	LinkedList<Student> StudentDirectory(nullptr);
	string firstName = "", lastName = "";
	int bmonth = 0, bday = 0, byear = 0, mNumber;
	float gpa = 0.0;
	Student* tempStudent;
	Student* removedStudent;
	do {
		cout << "Please select the the action you would like to complete" << endl;
		cout << "1. Add student to directory" << endl;
		cout << "2. Get a student from the directory" << endl;
		cout << "3. Check if a student is in the directory" << endl;
		cout << "4. Check if directory is empty" << endl;
		cout << "5. Get the number of students in the directory." << endl;
		cout << "6. See the next student in the directory" << endl;
		cout << "7. See a student at a location in the directory" << endl;
		cout << "8. Reset the location. " << endl;
		cout << "0. Exit" << endl;
		cout << "Enter the number of the choice you wish to select." << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the first name of the student." << endl;
			cin >> firstName;
			cout << "Enter the last name of the student." << endl;
			cin >> lastName;
			cout << "Enter the M Number of the student" << endl;
			cin >> mNumber;
			cout << "Enter the birthday month." << endl;
			cin >> bmonth;
			cout << "Enter the birthday day." << endl;
			cin >> bday;
			cout << "Enter the birthday year." << endl;
			cin >> byear;
			cout << "Enter the student's GPA." << endl;
			cin >> gpa;
			tempStudent = new Student(firstName, lastName, mNumber, bmonth, bday, byear, gpa);
			StudentDirectory.AddItem(tempStudent);
			tempStudent = nullptr;
			firstName = "";
			lastName = "";
			mNumber = 0;
			bmonth = 0;
			bday = 0;
			byear = 0;
			gpa = 0.0;
			// delete tempStudent;
			break;
		case 2: cout << "Enter the M Number of the Student you would like to find" << endl;
			cin >> mNumber;
			cout << "Size: " << StudentDirectory.Size() << endl;
		    tempStudent = new Student(firstName, lastName, mNumber, bmonth, bday, byear, gpa);
			removedStudent = StudentDirectory.RemoveItem(tempStudent);
			cout << "Here are details of the removed student: " << endl;
			cout << "Student Name: " << removedStudent->getName() << endl;
			cout << "Student M Number: " << removedStudent->getMNumber() << endl;
			cout << "Student Birthday: " << removedStudent->getBirthday() << endl;
			cout << "Student Age: " << removedStudent->getAge() << endl;
			// delete tempStudent;
			break;
		case 3: cout << "Enter the M Number of the student to check if they are in the directory." << endl;
			cin >> mNumber;
			tempStudent = new Student(firstName, lastName, mNumber, bmonth, bday, byear, gpa);
			cout << "The student is in the list?: " << StudentDirectory.IsInList(tempStudent) << endl;
			// delete tempStudent;
			break;
		case 4: cout << "Is the directory empty?: " << StudentDirectory.IsEmpty() << endl;
			break;
		case 5: cout << "The number of students in the directory: " << StudentDirectory.Size() << endl;
			break;
		case 6: tempStudent = StudentDirectory.SeeNext();
			cout << "Here are details of the next student: " << endl;
			cout << "Student Name: " << tempStudent->getName() << endl;
			cout << "Student M Number: " << tempStudent->getMNumber() << endl;
			cout << "Student Birthday: " << tempStudent->getBirthday() << endl;
			cout << "Student Age: " << tempStudent->getAge() << endl;
			// delete tempStudent;
			break;
		case 7: int index;
			cout << "Enter the index of the student you would like to view (a number between 0 and " << StudentDirectory.Size() << ")" << endl;
			cin >> index;
			try {
				tempStudent = StudentDirectory.SeeAt(index);
				cout << "Here are details of the next student: " << endl;
				cout << "Student Name: " << tempStudent->getName() << endl;
				cout << "Student M Number: " << tempStudent->getMNumber() << endl;
				cout << "Student Birthday: " << tempStudent->getBirthday() << endl;
				cout << "Student Age: " << tempStudent->getAge() << endl;
				// delete tempStudent;
			}
			catch (exception ItemNotFound) {
				cout << "That index is not in the directory." << endl;
			}
			break;
		case 8: cout << "The positions in the list have been reset." << endl;
			StudentDirectory.Reset();
			break;
		case 0: cout << "You have chosen to exit." << endl;
			break;
		default: cout << "You have entered an invalid choice." << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}
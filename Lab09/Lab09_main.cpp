#include<iostream>
#include<string>
#include"HashTable.h"
using namespace std;

int main() {
	int choice = 0;
	HashTable<Student> StudentDirectory(3);
	string firstName = "", lastName = "";
	int bmonth = 0, bday = 0, byear = 0, mNumber;
	float gpa = 0.0;
	bool flag = false;
	Student* tempStudent;
	Student* removedStudent;
	do {
		cout << "***************************************" << endl;
		cout << "Please select the the action you would like to complete" << endl;
		cout << "1. Add student to directory" << endl;
		cout << "2. Get a student from the directory" << endl;
		cout << "3. Check if a student is in the directory" << endl;
		cout << "4. Check if directory is empty" << endl;
		cout << "5. Get the number of students in the directory." << endl;
		cout << "6. See the next student in the directory" << endl;
		cout << "7. See a student at a location in the directory" << endl;
		cout << "8. Reset the location. " << endl;
		cout << "9. Print ASCII art of all students. " << endl;
		cout << "0. Exit" << endl;
		cout << "Enter the number of the choice you wish to select: ";
		cin >> choice;
		if (cin.fail()) {
			choice = 10;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (choice) {
		case 1: cout << "You have chosen to add a student. " << endl;
			cout << "Enter the first name of the student: ";
			cin >> firstName;
			cout << "Enter the last name of the student: ";
			cin >> lastName;
			cout << "Enter the M Number of the student: ";
			cin >> mNumber;
			cout << "Enter the birthday month: ";
			cin >> bmonth;
			cout << "Enter the birthday day: ";
			cin >> bday;
			cout << "Enter the birthday year: ";
			cin >> byear;
			cout << "Enter the student's GPA: ";
			cin >> gpa;
			// cout << endl;
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
		case 2: cout << "Enter the M Number of the Student you would like to remove: ";
			cin >> mNumber;
			cout << "Size: " << StudentDirectory.GetLength() << endl;
		    tempStudent = new Student(firstName, lastName, mNumber, bmonth, bday, byear, gpa);
			removedStudent = StudentDirectory.RemoveItem(tempStudent);
			if (removedStudent == nullptr) {
				cout << "There is no student in the directory with that M Number." << endl;
			}
			else {
				cout << "Here are details of the removed student: " << endl;
				cout << "Student Name: " << removedStudent->getName() << endl;
				cout << "Student M Number: " << removedStudent->getMNumber() << endl;
				cout << "Student Birthday: " << removedStudent->getBirthday() << endl;
				cout << "Student Age: " << removedStudent->getAge() << endl;
				delete removedStudent;
				removedStudent = nullptr;
			}
			// delete tempStudent;
			break;
		case 3: cout << "Enter the M Number of the student to check if they are in the directory: ";
			cin >> mNumber;
			tempStudent = new Student(firstName, lastName, mNumber, bmonth, bday, byear, gpa);
			cout << "The student is in the list?: ";
			flag = StudentDirectory.GetItem(tempStudent);
			if (flag) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
			
			// delete tempStudent;
			break;
		case 4: cout << "Is the directory empty?: ";
			if (StudentDirectory.GetLength() == 0) {
				cout << "Yes" << endl;
			}
			else { 
				cout << "No" << endl; 
			}
			break;
		case 5: cout << "The number of students in the directory: " << StudentDirectory.GetLength() << endl;
			break;
		case 6: 
			try{
				//tempStudent = StudentDirectory.SeeNext();
			}
			catch(exception EmptyList){
				cout << "You cannot see the next item in an empty list." << endl;
			}
			if (tempStudent == nullptr) {
				cout << "There is no next student. You either have an empty directory or have reached the end of the directory. Please check whether the directory is empty and/or reset the starting location. " << endl;
			}
			else {
				cout << "Here are details of the next student: " << endl;
				cout << "Student Name: " << tempStudent->getName() << endl;
				cout << "Student M Number: " << tempStudent->getMNumber() << endl;
				cout << "Student Birthday: " << tempStudent->getBirthday() << endl;
				cout << "Student Age: " << tempStudent->getAge() << endl;
			}
			// delete tempStudent;
			break;
		case 7: int index;
			cout << "Enter the index of the student you would like to view (a number between 0 and " << StudentDirectory.GetLength() - 1 << "): ";
			cin >> index;
			/*try {
				tempStudent = StudentDirectory.GetItem(index);
				if (tempStudent != nullptr) {
					cout << "Here are details of the student at that location: " << endl;
					cout << "Student Name: " << tempStudent->getName() << endl;
					cout << "Student M Number: " << tempStudent->getMNumber() << endl;
					cout << "Student Birthday: " << tempStudent->getBirthday() << endl;
					cout << "Student Age: " << tempStudent->getAge() << endl;
					// delete tempStudent;
				}
				else {
					cout << "That index is not in the directory." << endl;
				}
			}
			catch (exception ItemNotFound) {
				cout << "That index is not in the directory." << endl;
			}*/
			break;
		case 8: cout << "The positions in the list have been reset." << endl;
			//StudentDirectory.Reset();
			break;
		case 0: cout << "You have chosen to exit." << endl;
			break;
		case 9:
			//StudentDirectory.DisplayAll();
			break;
		default: cout << "You have entered an invalid choice." << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}
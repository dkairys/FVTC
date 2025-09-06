//Dave Kairys
//Week 8 - Exam 2 Practical
//For this exam you will write a program that will utilize classes.
//The program will ask for the name and gpa of a student and then display the name and gpa.
//Then it will ask if the user wants to create another student.If the user chooses to create another student, 
//	the program will ask for the name and gpa of the new student and display the information.

#include <conio.h>
#include <iostream>
#include "Student.h"

int main()
{
	std::string studentName;
	float gpa = 0;

	//create a student on the stack
	Student student;

	//prompt for data input
	std::cout << "Enter the name of the student: ";
	std::cin >> studentName;

	//start to set members of the student
	student.SetName(studentName);
	
	//more prompts...
	std::cout << "Enter " << student.GetName() << "'s GPA: ";
	std::cin >> gpa;

	//more member setting
	student.SetGPA(gpa);

	//finally, display
	std::cout << student.GetName() << " has a GPA of " << student.GetGPA() << "\n" "\n";

	//prompt if another student should be created, on the heap this time
	char newStudent = 'N';
	std::cout << "Do you want to create another student (Y/N): ";
	std::cin >> newStudent;

	//determine what was selected
	if (newStudent == 'Y')
	{
		//create a student on the heap
		Student* pStudent = new Student;
		std::string newStudent;
		float gpa = 0;

		std::cout << "Enter the name of the student: ";
		std::cin >> studentName;

		//set stuff
		pStudent->SetName(studentName);

		std::cout << "Enter " << pStudent->GetName() << "'s GPA: ";
		std::cin >> gpa;

		//setting more stuff
		pStudent->SetGPA(gpa);

		//finally, display
		std::cout << pStudent->GetName() << " has a GPA of " << pStudent->GetGPA() << "\n" "\n";

		//clean up resources
		delete pStudent;
	}
	else
	{
		//user didn't want to create a new student
		std::cout << "No new student was created.";
	}


	(void)_getch();
	return 0;
}
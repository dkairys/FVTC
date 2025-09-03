//Dave Kairys
//Develop an application that prints a pay report for employees.
//This will display the weekly pay for each employee and the total pay for all employees

//Example output:
//Enter the number of employees : 2
//
//Enter the ID for Employee 1 : 123
//Enter the First Name for Employee 1 : John
//Enter the Last Name for Employee 1 : Doe
//Enter the Hours Worked for Employee 1 : 40
//Enter the Hourly Rate for Employee 1 : 15
//
//Enter the ID for Employee 2 : 456
//Enter the First Name for Employee 2 : Jane
//Enter the Last Name for Employee 2 : Smith
//Enter the Hours Worked for Employee 2 : 30
//Enter the Hourly Rate for Employee 2 : 20.5
//
//Pay Report
//----------
//123. John Doe : $600
//456. Jane Smith : $615
//
//Total Pay : $1215


#include <iostream>
#include <conio.h>

using namespace std;

struct Employee
{
	int ID;
	string FirstName;
	string LastName;
	float HoursWorked;
	float HourlyRate;
};

//prototyping
Employee* CreateEmployee(int numEmployees, Employee* employee);
void PrintEmployeeReport(Employee* pEmployee, int numEmployees);

/// <summary>
/// Creates the employee report
/// </summary>
/// <param name="pEmployee">employee pointer</param>
/// <param name="numEmployees">number of employees</param>
void PrintEmployeeReport(Employee* pEmployee, int numEmployees)
{
	cout << "Pay Report" << "\n";
	cout << "___________" <<"\n";

	float totalPay = 0.0f;

	for (int i = 0; i < numEmployees; i++)
	{
		cout << pEmployee[i].ID << ".  " << pEmployee[i].FirstName << " " << pEmployee[i].LastName << ": $" << pEmployee[i].HourlyRate * pEmployee[i].HoursWorked << "\n";
		totalPay += pEmployee[i].HourlyRate * pEmployee[i].HoursWorked;
	}
	
	cout << "\n";
	cout << "Total Pay: $"<< totalPay;
	
}

/// <summary>
/// Creates an array of employees
/// </summary>
/// <param name="numEmployees">how many employees to create</param>
/// <returns>array of employees</returns>
Employee* CreateEmployee(int numEmployees, Employee* employee)
{
	//create numEmployees
	for (int i = 0; i < numEmployees; i++)
	{
		
		cout << "Enter the ID for Employee " << (i + 1) << ": ";
		cin >> employee[i].ID;
				
		cout << "Enter the First Name for Employee "<< (i + 1) << ": ";
		cin >> employee[i].FirstName;

		cout << "Enter the Last Name for Employee " << (i + 1) << ": ";
		cin >> employee[i].LastName;

		cout << "Enter the Hours worked for Employee " << (i + 1) << ": ";
		cin >> employee[i].HoursWorked;

		cout << "Enter the Hourly Rate for Employee " << (i + 1) << ": ";
		cin >> employee[i].HourlyRate;

		cout << "\n";
	}

	return employee;
}

int main()
{
	//prompt user to enter number of employees
	int numEmployees = 0;
	cout << "Enter number of employees: ";
	cin >> numEmployees;

	//declare an employee array, with size of numEmployees
	Employee* employee = new Employee[numEmployees];

	employee = CreateEmployee(numEmployees, employee);

	//print out report
	PrintEmployeeReport(employee, numEmployees);

	//delete from memory
	delete[] employee;

	(void)_getch();
	return 0;
}
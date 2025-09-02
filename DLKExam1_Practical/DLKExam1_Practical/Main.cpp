//Dave Kairys
//Exam 1 - Practical
//For this exam you will write a program that will perform some basic arithmetic operations.
//The program will read two numbers from the user and then perform either addition or subtraction on the two numbers.
//The user will be able to choose which operation to perform.
// The program will then display the result of the operation.

#include <iostream>
#include <conio.h>

using namespace std;

string GetOperation();
int GetNumbers();
int PerformOperation(int firstNumber, int secondNumber, string operation);
string ReverseEngineerOperation(string operation);
void DisplayOutput(int result, string operation);

/// <summary>
/// Displays output of desired action
/// </summary>
/// <param name="result"></param>
/// <param name="operation"></param>
void DisplayOutput(int result, string operation)
{
	//display result to user
	cout << "The result of the " << operation << " is: " << result;
}


/// <summary>
/// Determines what operation the user wants to perform
/// </summary>
/// <param name="operation"></param>
/// <returns></returns>
string ReverseEngineerOperation(string operation)
{
	string action = "";

	//check what operation user selected
	if ((operation == "a") || (operation == "A"))
	{
		action = "addition";
	}
	else
	{
		action = "subtraction";
	}

	return action;
}

/// <summary>
/// either adds or subtracts numbers
/// </summary>
/// <param name="firstNumber"></param>
/// <param name="secondNumber"></param>
/// <param name="operation">a/A or s/S for addition or subtraction</param>
/// <returns></returns>
int PerformOperation(int firstNumber, int secondNumber, string operation)
{
	//variable to hold result
	int result = 0;

	//check what operation user selected
	if ((operation == "a") || (operation == "A"))
	{
		result = firstNumber + secondNumber;
	}
	else
	{
		result = firstNumber - secondNumber;
	}
	
	return result;
}

/// <summary>
/// Gets the operation (either addition or subtraction) by the user
/// </summary>
/// <returns></returns>
string GetOperation()
{
	string operationChoice = "";
	cout << "Enter either a or A for addition or s or S for subtraction: ";
	cin >> operationChoice;

	return operationChoice;
}

/// <summary>
/// gets numbers entered by user
/// </summary>
/// <returns></returns>
int GetNumbers()
{
	int numberOne = 0;

	cout << "Enter a whole number: ";
	cin >> numberOne;

	return numberOne;

}

/// <summary>
/// Calls various functions to do the work, then displays stuff
/// </summary>
/// <returns></returns>
int main()
{
	//get user option
	string option = GetOperation();

	//get first number entered by user
	int firstNumber = GetNumbers();

	//get second number entered by user
	int secondNumber = GetNumbers();

	//get result
	int result = PerformOperation(firstNumber, secondNumber, option);

	//reverse engineer operation (text) user wants to do
	string operation = ReverseEngineerOperation(option);

	//display result to user
	DisplayOutput(result, operation);
	
	(void)_getch();

	return 0;
}
//Dave Kairys
//Calculate Rectangle Area - area = length * width
//Video stated to use 0.5 * length * width (for a triangle), so I'll stick with that here.

#include <iostream>
#include <conio.h>

using namespace std;

int GetLengthFromUser();
int GetWidthFromUser();
int CalculateArea(int length, int width);
void DisplayArea(double area);

/// <summary>
/// This function will prompt the user to get the length
/// </summary>
/// <returns></returns>
int GetLengthFromUser()
{
	int length = 0;

	//prompt user for length
	cout << "Enter a positive whole number for length: ";

	//store user entered value in length variable
	cin >> length;

	return length;
}

/// <summary>
/// This function will prompt the user to get the width
/// </summary>
/// <returns></returns>
int GetWidthFromUser()
{
	int width = 0;

	//prompt for width
	cout << "Enter a positive whole number for width: ";

	//store in variable
	cin >> width;
	
	return width;
}

/// <summary>
/// This function will calculate the area of a rectangle (triangle)
/// This function could be a double to handle the triangle piece.  
/// If that's the case, the prototype and the call in main could need to be updated to be a double
/// </summary>
/// <param name="length">length of rectangle</param>
/// <param name="width">width of rectangle</param>
/// <returns></returns>
int CalculateArea(int length, int width)
{
	return 0.5 * length * width;
}

/// <summary>
/// This function will display the area of the rectangle (triangle)
/// </summary>
/// <param name="area">area of shape</param>
void DisplayArea(double area)
{
	//simple here
	cout << "The area of the rectangle (triangle) is: " << area << "\n";

}

int main()
{
	//call functions
	//get length
	int length = GetLengthFromUser();

	//get width
	int width = GetWidthFromUser();

	//calculate area
	int area = CalculateArea(length, width);

	//finally, display area to user
	DisplayArea(area);

	(void)_getch();

	return 0;

}
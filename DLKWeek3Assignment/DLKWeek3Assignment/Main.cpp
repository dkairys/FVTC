//Dave Kairys
//Week 3 Assignment

#include <iostream>
#include <conio.h>

using namespace std;

//create a struct for the input
struct Entry
{
	string type;
	string input;
};

//function prototype stuff here
void DisplayEntries(Entry entries[], int size);

//will display the values in the console for the user to enter data
void DisplayEntries(Entry entries[], int size)
{
	string value = "";

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ".  Enter a/an " << entries[i].type << ": ";		
		cin>>entries[i].input;		
	}
}

int main()
{
	//constant for array size
	const int SIZE = 12;

	//array for entries
	Entry entries[SIZE] =
	{
		{"place", ""},
		{"adjective", ""},
		{"noun", ""},
		{"famous person", ""},
		{"famous dog", ""},
		{"verb", ""},
		{"animal", ""},
		{"fish type", ""},
		{"dog name", ""},
		{"noun", ""},
		{"country", ""},
		{"river", ""}
	};

	
	DisplayEntries(entries, SIZE);

	//fix mistakes
	char fixChoice = 'n';
	int index = -1;
	string value = "";
	
	do
	{	
		//prompt if errors are to be fixed
		cout << "\n"<<"Would you like to fix any mistakes? (y/n): ";
		
		//get user choice and store it
		cin >> fixChoice;

		//check what response was
		if (fixChoice == 'y' || fixChoice == 'Y')
		{
			//pronpt user with what entry to fix
			cout << "Which entry would you like to fix (1 - " << SIZE << ")? ";
			cin >> index;

			//search array, get proper entry back that they want to fix
			if (index >= 1 && index <= SIZE)
			{
				cout << "Enter a/an " << entries[index - 1].type << ": ";				
				cin >> entries[index - 1].input;
			}
			else
			{
				//value was outside 1 - 12, so prompt to enter a correct one
				cout << "That value isn't found in the collection.  Try again. \n";
			}			
		}
		else
		{
			index = 0;
			//user doesn't want to correct any mistakes, so build mad lib for them.
			cout << "\nYour Mad Lib: \n";
			cout << "One day, I found myself in " << entries[index].input << ", surrounded by " << entries[index + 1].input << " scenery.  Out of nowhere, ";
			cout << "a " << entries[index + 2].input << " dropped from the sky, right in front of " << entries[index + 3].input << " who was walking their famous dog, ";
			cout << entries[index + 4].input << ".  Suddenly, they both started to " << entries[index + 5].input << ", chased by a wild " << entries[index + 6].input;
			cout << " that had just leapt out of the bushes!  The chaos continued as a " << entries[index + 7].input << " flew through the air, narrowly missing ";
			cout << entries[index + 8].input << ", who barked at a nearby " << entries[index + 9].input << "!";
			cout << " We all ended up in " << entries[index + 10].input << ", floating down the " << entries[index + 11].input << ", laughing at the absurdity of it all.";
			
		}
	} while (fixChoice == 'y' || fixChoice == 'Y');

	(void)_getch();
	return 0;
}
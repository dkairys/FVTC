//Dave Kairys
//Week 6 Demos
//Math Quiz
//For this project, we'll develop a math quiz program.  
//The program will generate random math problems for the user to solve.
//The user will be prompted to enter an answer to each problem and the application will keep track of the user score

#include <iostream>
#include <conio.h>
#include <vector>	//work with vectors
#include <string>	//work with strings
#include <fstream>	//files

using namespace std;

//prototyping again....
vector<string> LoadQuestions(string readFilePath);
vector<int> GenerateRandomNumbers(vector<string> questions);
vector<string> DetermineMatches(vector<int> randomNumbers, vector<string> questions);
vector<string> PopulateAnswers(vector<string> matchingQuestions);
void CreateAnswerFile(vector<string> answerList, string pathToWriteTo);

/// <summary>
/// creates the file with the questions and answers
/// </summary>
/// <param name="answerList">answers to math questions</param>
/// <param name="pathToWriteTo">path where file can be found</param>
void CreateAnswerFile(vector<string> answerList, string pathToWriteTo)
{
	//variables for writing file
	ofstream ofs(pathToWriteTo);

	//write our first line
	ofs << "Welcome to the Math Quiz!" << "\n" << "\n";

	//generate file
	for (int i = 0; i < answerList.size(); i++)
	{
		//cout << answerList[i] << "\n";
		ofs << answerList[i] << "\n";
	}

	ofs << "\n";
	ofs << "Results saved to: " << pathToWriteTo;

	//close ofs
	ofs.close();
}

/// <summary>
/// Function to generate the answer list
/// </summary>
/// <param name="matchingQuestions">the questions on the quiz</param>
/// <returns>The questions with the appropriate answers</returns>
vector<string> PopulateAnswers(vector<string> matchingQuestions)
{
	//variables to hold the answers
	string answer, result = "";
	vector<string> answerList;

	//display problem to user
	for (int i = 0; i < matchingQuestions.size(); i++)
	{
		cout << "What is the answer to question: " << matchingQuestions[i] << "  ";
		cin >> answer;

		result.append(matchingQuestions[i].append(" "));
		result.append("= ").append(answer).append("\n");
	}

	//populate answerList vector with the final questions and answers
	answerList.push_back(result);

	return answerList;
	
}

/// <summary>
/// determines what questions match the random numbers generated
/// </summary>
/// <param name="randomNumbers">the three random numbers generated earlier</param>
/// <param name="questions">the list of questions</param>
/// <returns>the questions from the questions vector that match the random numbers in randomNumbers</returns>
vector<string> DetermineMatches(vector<int> randomNumbers, vector<string> questions)
{
	//declare variable to hold matching questions
	vector<string> matchingQuestions;

	//loop over vectors, see what matches
	for (const auto& str : questions)
	{
		int num = std::stoi(str); // Convert string to integer

		//only add the unique values to the vector
		for (const auto& val : randomNumbers)
		{
			if (num == val)
			{
				matchingQuestions.push_back(str);
			}
		}
	}

	return matchingQuestions;
}

/// <summary>
/// Generate three random numbers
/// </summary>
/// <param name="questions">vector of questions to use as a max value</param>
/// <returns>three random numbers in a vector</returns>
vector<int> GenerateRandomNumbers(vector<string> questions)
{
	//get the random number initialized
	srand(time(NULL));

	//vector to hold the ints
	vector<int> randomNumbers;

	//generate the random numbers and save in a vector of ints
	for (int i = 0; i < 3; i++)
	{
		int randomNumber = rand() % questions.size() + 1;
		randomNumbers.push_back(randomNumber);
	}

	return randomNumbers;
	
}

/// <summary>
/// Function to read the file and load a vector with data
/// </summary>
/// <param name="readFilePath">path where file lives</param>
/// <returns>a vector with all the questions loaded</returns>
vector<string> LoadQuestions(string readFilePath)
{
	//seeing as we are learning about vectors, might as well use one here to hold the questions
	vector<string> questions;

	//read the file and populate the vector
	ifstream ifs(readFilePath);
	string line = "";
	while (getline(ifs, line))
	{
		questions.push_back(line);
	}
	
	return questions;
}

int main()
{
	//variable to hold file path to read the file from
	string readFilePath = "C:\\Users\\21156091\\Desktop\\FVTC - C++\\DLKAssignment5_MathQuiz\\Files\\Questions.txt";
	string pathToWriteTo = "C:\\Users\\21156091\\Desktop\\FVTC - C++\\DLKAssignment5_MathQuiz\\Files\\Answers\\QuizResults.txt";

	//vector to hold the questions
	vector<string> questions = LoadQuestions(readFilePath);

	//generate 3 random math problems for the user to solve from the ones loaded in the vector questions
	//first, get the random problems to attempt to solve
	vector<int> randomNumbers = GenerateRandomNumbers(questions);

	//now that we have the random numbers, lets pull those associated questions from the vector of questions and 
	//test the user on these complex math problems!
	//vector to hold the actual questions that match the random numbers generated
	vector<string> matchingQuestions = DetermineMatches(randomNumbers, questions);

	cout << "Welcome to the Math Quiz!" << "\n"<<"\n";

	vector<string> answerList = PopulateAnswers(matchingQuestions);
	
	CreateAnswerFile(answerList, pathToWriteTo);

	cout <<"\n"<< "The file has been created successfully.";

	(void)_getch();
	return 0;
}
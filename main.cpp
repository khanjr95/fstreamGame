#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void startMenu();
int menuValid(int);
void saveData(string, int, int);
void loadData(string &name, int &level, int &health);
//void loadData(string &pname);

void newGame();

int main()
{

	startMenu();


	system("pause");


}


void startMenu()
{
	int choice = 0;
	string name = "";
	int level = 1;
	int health = 100;


	cout << "Welcome to our game" << endl;
	cout << "1)New Game" << endl;
	cout << "2)Load Game" << endl;
	cout << "3)Quit" << endl;
	cin >> choice;

	menuValid(choice);
	system("cls");


	if (choice == 1)
	{
		newGame();
	}
	else if (choice == 2)
	{
		loadData(name, level, health);
	}
	else if (choice == 3)
	{
		cout << "Quitting Game" << endl;
	}



}

int menuValid(int choice)
{
	system("cls");
	if (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "Wrong choice selected, Please pick from 1,2,3!" << endl;
		cin >> choice;
	}

	return choice;
}

void saveData(string name, int level, int health)
{
	ofstream outputFile;
	outputFile.open("data.txt");

	outputFile << "Player Name:" << name << endl;
	outputFile << "Player Level:" << level << endl;
	outputFile << "Player Health:" << health << endl;

	outputFile.close();
}

void loadData(string &name, int &level, int &health)
{

	ifstream inputFile("data.txt");
	if (inputFile)
	{
		cout << inputFile.rdbuf();
	}
	else
	{
		cout << "No Save file has been created. Start New Game." << endl;
	}
}


void newGame()
{
	int level = 1;
	int health = 100;
	cout << "You have started a New Game" << endl;
	cout << "Enter your player name: ";
	string name = "";
	cin >> name;

	saveData(name, level, health);
}

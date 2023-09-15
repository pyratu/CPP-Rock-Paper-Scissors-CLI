#include <iostream>
#include <fstream>

using namespace std;

int winStreakUser = 0;
int winStreakAi = 0;

void menu();
string ChooseWinner(int userChoice, int aiChoice);
void saveStatsToFile();
void loadStatsFromFile();

int main()
{
    loadStatsFromFile(); // Load win streaks from a file at the beginning
    int userChoice = 0;

    do
    {
        menu();
        cin >> userChoice;

        if (userChoice == 4)
        {
            cout << "Game Over." << endl;
            cout << "Ai won " << winStreakAi << " times." << endl;
            cout << "Player won " << winStreakUser << " times." << endl;

            saveStatsToFile(); // Save win streaks to a file before exiting
            break;
        }

        int aiChoice = rand() % 3 + 1;
        string aiChoiceText = "";
        switch(aiChoice)
        {
            case 1:
            {
                aiChoiceText = "rock";
                break;
            }
            case 2:
            {
                aiChoiceText = "paper";
                break;
            }
            case 3:
            {
                aiChoiceText = "scissors";
                break;
            }
        }
        string winner = ChooseWinner(userChoice, aiChoice);
        cout << "Round ended. Ai choose "<< aiChoiceText<<" " << winner << endl
             << endl;
    } while (userChoice != 4);
}

void menu()
{
    cout << "Player wins: " << winStreakUser << endl;
    cout << "Ai wins: " << winStreakAi << endl;
    cout << "Choose " << endl;
    cout << "1 Rock" << endl;
    cout << "2 Paper" << endl;
    cout << "3 Scissors" << endl;
    cout << "4 To EXIT" << endl;
}

string ChooseWinner(int userChoice, int aiChoice)
{
    string winner = "Draw";

    if (userChoice == 1 && aiChoice == 2)
    {
        winStreakAi++;
        return "Ai wins";
    }

    if (userChoice == 1 && aiChoice == 3)
    {
        winStreakUser++;
        return "Player wins";
    }

    if (userChoice == 2 && aiChoice == 1)
    {
        winStreakUser++;
        return "Player wins";
    }

    if (userChoice == 2 && aiChoice == 3)
    {
        winStreakAi++;
        return "Ai wins";
    }

    if (userChoice == 3 && aiChoice == 1)
    {
        winStreakAi++;
        return "Ai wins";
    }

    if (userChoice == 3 && aiChoice == 2)
    {
        winStreakUser++;
        return "Player wins";
    }

    if (userChoice != 1 && userChoice != 2 && userChoice != 3)
        menu();

    return "Draw";
}

void saveStatsToFile()
{
    ofstream outputFile("stats.txt");
    if (outputFile.is_open())
    {
        outputFile << winStreakUser << " " << winStreakAi;
        outputFile.close();
        cout << "Stats saved successfully." << endl;
    }
    else
    {
        cerr << "Error opening file for writing." << endl;
    }
}

void loadStatsFromFile()
{
    ifstream inputFile("stats.txt");
    if (inputFile.is_open())
    {
        if (inputFile >> winStreakUser >> winStreakAi)
        {
            cout << "Stats loaded successfully." << endl;
        }
        else
        {
            cerr << "Error reading stats from file." << endl;
        }
        inputFile.close();
    }
    else
    {
        cerr << "Error opening file for reading. Starting with fresh stats." << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{
    const unsigned int seed = time(0);
    mt19937_64 rng(seed);
    uniform_int_distribution<int> uniform_dist(1,70);
    int numberAmount, numberGenerateChoice, matchCount=0, cashAmount=10, timesRun, winMultiplier;
    int winningTable[11][10] =
    {
        {200000, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3000, 50000, 0, 0, 0, 0, 0, 0, 0, 0},
        {250, 750, 10000, 0, 0, 0, 0, 0, 0, 0},
        {32, 100, 300, 1500, 0, 0, 0, 0, 0, 0},
        {6, 10, 44, 66, 500, 0, 0, 0, 0, 0},
        {2, 4, 8, 8, 54, 250, 0, 0, 0, 0},
        {0, 2, 2, 4, 6, 18, 60, 0, 0, 0},
        {0, 0, 0, 2, 2, 4, 4, 18, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 14, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {6, 2, 2, 0, 0, 0, 0, 0, 0, 0}
    };
    while (true)
    {
        do
        {
            system("cls");
            cout << "Bank: " << cashAmount << "$";
            cout << "\nHello! Welcome to KENO!\nHow many numbers would you like to choose?\nAmount of numbers : ";
            cin >> numberAmount;
        }while (numberAmount <= 0 || numberAmount >= 11);
    do
    {
        system("cls");
        cout << "Bank: " << cashAmount << "$";
        cout << "\n1.Try my luck\n2.Own numbers\n\nYour choice: ";
        cin >> numberGenerateChoice;
    }while (numberGenerateChoice != 1 && numberGenerateChoice != 2);
    do
    {
        cout << "Choose win multiplier (1-10): ";
        cin >> winMultiplier;
    } while (winMultiplier < 0 || winMultiplier > 10);
    vector<int> chosenNumbers;
    vector<int> winningNumbers;
    switch (numberGenerateChoice)
    {
    case 1:
        {
            int randomNumber;
            for (int i=0; i<numberAmount; i++)
                {
                    randomNumber = uniform_dist(rng);
                    if (find(chosenNumbers.begin(), chosenNumbers.end(), randomNumber) != chosenNumbers.end() == false)
                        chosenNumbers.push_back(randomNumber);
                }
        }break;
    case 2:
        {
            int chosenNumber;
            int tmp = numberAmount;
            do
            {
                cout << "\nEnter number: ";
                cin >> chosenNumber;
                if (chosenNumber >= 1 && chosenNumber <= 70)
                {
                    if (find(chosenNumbers.begin(), chosenNumbers.end(), chosenNumber) != chosenNumbers.end() == false)
                    {
                        chosenNumbers.push_back(chosenNumber);
                        tmp--;
                    }
                    else
                        cout << "This number was already chosen, try another!" << endl;
                }
                else
                    cout << "This number is out of bounds, try another!" << endl;
            }while (tmp != 0);
        }break;
    default:
        {
            break;
        }
    }
    cout << "Chosen numbers: ";
    for (int i=0; i<numberAmount; i++)
        cout << chosenNumbers[i] << " | ";
    cout << "\nWinning numbers: ";
    int tmp=20;
    do
    {
        int randomNumber;
        randomNumber = uniform_dist(rng);
        if (find(winningNumbers.begin(), winningNumbers.end(), randomNumber) != winningNumbers.end() == false)
            {
                winningNumbers.push_back(randomNumber);
                tmp--;
                cout << randomNumber << " | ";
            }
    }while (tmp > 0);
    for (int i=0; i<numberAmount; i++)
        {
            for (int j=0; j<20; j++)
            {
                if (chosenNumbers[i] == winningNumbers[j])
                    matchCount++;
            }
        }
        cout << "\nYou got : " << matchCount << " matches!";
        cashAmount -=2 * winMultiplier;
        if (chosenNumbers.size() == 1)
        {
            if (matchCount == 1)
                cashAmount += winningTable[9][9] * winMultiplier;
        }
        if (chosenNumbers.size() == 2)
        {
            if (matchCount == 2)
                cashAmount += winningTable[8][8] * winMultiplier;
        }
        if (chosenNumbers.size() == 3)
        {
            if (matchCount == 3)
                cashAmount += winningTable[7][7] * winMultiplier;
            else if (matchCount == 2)
                cashAmount += winningTable[8][7] * winMultiplier;
        }
        if (chosenNumbers.size() == 4)
        {
            if (matchCount == 4)
                cashAmount += winningTable[6][6] * winMultiplier;
            else if (matchCount == 3)
                cashAmount += winningTable[7][6] * winMultiplier;
            else if (matchCount == 2)
                cashAmount += winningTable[8][6] * winMultiplier;
        }
        if (chosenNumbers.size() == 5)
        {
            if (matchCount == 5)
                cashAmount += winningTable[5][5] * winMultiplier;
            else if (matchCount == 4)
                cashAmount += winningTable[6][5] * winMultiplier;
            else if (matchCount == 3)
                cashAmount += winningTable[7][5] * winMultiplier;
        }
        if (chosenNumbers.size() == 6)
        {
            if (matchCount == 6)
                cashAmount += winningTable[4][4] * winMultiplier;
            else if (matchCount == 5)
                cashAmount += winningTable[5][4] * winMultiplier;
            else if (matchCount == 4)
                cashAmount += winningTable[6][4] * winMultiplier;
            else if (matchCount == 3)
                cashAmount += winningTable[7][4] * winMultiplier;
        }
        if (chosenNumbers.size() == 7)
        {
            if (matchCount == 7)
                cashAmount += winningTable[3][3] * winMultiplier;
            else if (matchCount == 6)
                cashAmount += winningTable[4][3] * winMultiplier;
            else if (matchCount == 5)
                cashAmount += winningTable[5][3] * winMultiplier;
            else if (matchCount == 4)
                cashAmount += winningTable[6][3] * winMultiplier;
            else if (matchCount == 3)
                cashAmount += winningTable[7][3] * winMultiplier;
        }
        if (chosenNumbers.size() == 8)
        {
            if (matchCount == 8)
                cashAmount += winningTable[2][2] * winMultiplier;
            else if (matchCount == 7)
                cashAmount += winningTable[3][2] * winMultiplier;
            else if (matchCount == 6)
                cashAmount += winningTable[4][2] * winMultiplier;
            else if (matchCount == 5)
                cashAmount += winningTable[5][2] * winMultiplier;
            else if (matchCount == 4)
                cashAmount += winningTable[6][2] * winMultiplier;
            else if (matchCount == 0)
                cashAmount += winningTable[10][2] * winMultiplier;
        }
        if (chosenNumbers.size() == 9)
        {
            if (matchCount == 9)
                cashAmount += winningTable[1][1] * winMultiplier;
            else if (matchCount == 8)
                cashAmount += winningTable[2][1] * winMultiplier;
            else if (matchCount == 7)
                cashAmount += winningTable[3][1] * winMultiplier;
            else if (matchCount == 6)
                cashAmount += winningTable[4][1] * winMultiplier;
            else if (matchCount == 5)
                cashAmount += winningTable[5][1] * winMultiplier;
            else if (matchCount == 4)
                cashAmount += winningTable[6][1] * winMultiplier;
            else if (matchCount == 0)
                cashAmount += winningTable[10][1] * winMultiplier;
        }
        if (chosenNumbers.size() == 10)
        {
            if (matchCount == 10)
                cashAmount += winningTable[0][0] * winMultiplier;
            else if (matchCount == 9)
                cashAmount += winningTable[1][0] * winMultiplier;
            else if (matchCount == 8)
                cashAmount += winningTable[2][0] * winMultiplier;
            else if (matchCount == 7)
                cashAmount += winningTable[3][0] * winMultiplier;
            else if (matchCount == 6)
                cashAmount += winningTable[4][0] * winMultiplier;
            else if (matchCount == 5)
                cashAmount += winningTable[5][0] * winMultiplier;
            else if (matchCount == 1)
                cashAmount += winningTable[9][0] * winMultiplier;
            else if (matchCount == 0)
                cashAmount += winningTable[10][0] * winMultiplier;
        }
        chosenNumbers.clear();
        winningNumbers.clear();
        matchCount = 0;
        getch();
    }
}

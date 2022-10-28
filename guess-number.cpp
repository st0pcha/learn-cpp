#include <iostream>
#include <ctime>

using namespace std;

int main()
{
start:
    cout << "Guess the number game!" << endl;

    int number, input, difficulty = 0;

    cout << "Select the difficulty (1: low, 2: medium, 3: hard)" << endl;
    cin >> difficulty;

    if (difficulty != 1 && difficulty != 2 && difficulty != 3)
        difficulty = 1;

    srand(time(0));
    number = rand() % (100 * difficulty) + 1;

    cout << number << endl;
    cout << "Hint: number not higher than " << 100 * difficulty << endl;

    do
    {
        cout << "Input the number: " << endl;
        cin >> input;

        if (input > number)
            cout << "Your number is higher" << endl;
        else if (input < number)
            cout << "Your number is lower" << endl;
        else
        {
            cout << "Success! Your input: " << input << " equals given number " << number << "!" << endl;
            goto start;
        }
    } while (input != number);

    system("pause");
    return 0;
}
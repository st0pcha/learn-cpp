#include <iostream>
#include <Windows.h>

using namespace std;

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int nowPlayer = 1;

void changeTurn()
{

    if (nowPlayer == 1)
        nowPlayer = 2;
    else
        nowPlayer = 1;
}

char getPlayerSymbol()
{
    if (nowPlayer == 1)
        return 'X';
    else
        return 'O';
}

bool win(int player)
{
start:
    system("cls");
    cout << "Player " << player << " won the game!" << endl;
    cout << "Press escape to shutdown the game" << endl;
    return true;
}

bool checkNumbers()
{
    // 1 2 3
    if (board[1] == 'X' && board[2] == 'X' && board[3] == 'X')
        return win(1);

    if (board[1] == 'O' && board[2] == 'O' && board[3] == 'O')
        return win(2);

    // 1 4 7
    if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
        return win(1);

    if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
        return win(2);

    // 2 5 8
    if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
        return win(1);

    if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
        return win(2);

    // 3 6 9
    if (board[3] == 'X' && board[6] == 'X' && board[9] == 'X')
        return win(1);

    if (board[3] == 'O' && board[6] == 'O' && board[9] == 'O')
        return win(2);

    // 4 5 6
    if (board[4] == 'X' && board[5] == 'X' && board[6] == 'X')
        return win(1);

    if (board[4] == 'O' && board[5] == 'O' && board[6] == 'O')
        return win(2);

    // 7 8 9
    if (board[7] == 'X' && board[8] == 'X' && board[9] == 'X')
        return win(1);

    if (board[7] == 'O' && board[8] == 'O' && board[9] == 'O')
        return win(2);

    // 1 5 9
    if (board[1] == 'X' && board[5] == 'X' && board[9] == 'X')
        return win(1);

    if (board[1] == 'O' && board[5] == 'O' && board[9] == 'O')
        return win(2);

    // 3 5 7
    if (board[3] == 'X' && board[5] == 'X' && board[7] == 'X')
        return win(1);

    if (board[3] == 'O' && board[5] == 'O' && board[7] == 'O')
        return win(2);
}

void drawBoard()
{
    cout << "Tic Tac Toe game" << endl;
    cout << "Press escape to shutdown the game" << endl;
    cout << endl;

    if (!checkNumbers())
    {
        cout << "Player 1 - X" << endl;
        cout << "Player 2 - O" << endl;

        for (int i = 1; i < 10; i++)
        {
            cout << board[i] << "\t";
            if (i == 3 || i == 6 || i == 9)
                cout << endl;
        }
    }
}

int selectNumber()
{
start:
    cout << "Player " << nowPlayer << " select the number to place" << endl;
    int number;
    cin >> number;

    while (!cin)
    {
        cin.clear();
        cin.ignore();

        system("cls");
        drawBoard();
        goto start;
    }

    bool isAvailable = false;
    for (int i = 1; i < 10; i++)
    {
        if (number == i)
            isAvailable = true;
    }

    if (isAvailable)
        board[number] = getPlayerSymbol();
    else
    {
        system("cls");
        drawBoard();
        goto start;
    }
    system("cls");
    drawBoard();
    changeTurn();

    if (!checkNumbers())
        selectNumber();

    return number;
}

int main()
{
    int player = 1;

    drawBoard();
    selectNumber();

    while (true)
    {
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);
        }
    }

    // system("pause");
    return 0;
}
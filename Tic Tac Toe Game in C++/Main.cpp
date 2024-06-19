#include <iostream>

using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

char current_marker;
int current_player;

void drawBoard()
{
    system("clear"); // For Windows use "cls"
    cout << "Player 1 [X]  -  Player 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n\n";
}

bool placeMarker(int slot)
{
    int row = slot / 3;
    int col = slot % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int winner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

void swap_player_and_marker()
{
    if (current_marker == 'X')
    {
        current_marker = 'O';
        current_player = 2;
    }
    else
    {
        current_marker = 'X';
        current_player = 1;
    }
}

void game()
{
    cout << "Player 1, choose your marker: ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();
    int player_won;

    for (int i = 0; i < 9; i++)
    {
        cout << "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;
        if (slot < 1 || slot > 9)
        {
            cout << "That slot is invalid! Try another slot!";
            i--;
            continue;
        }
        if (!placeMarker(slot - 1))
        {
            cout << "That slot is occupied! Try another slot!";
            i--;
            continue;
        }
        drawBoard();
        player_won = winner();
        if (player_won == 1)
        {
            cout << "Player 1 won! Congratulations!\n";
            break;
        }
        if (player_won == 2)
        {
            cout << "Player 2 won! Congratulations!\n";
            break;
        }
        swap_player_and_marker();
    }
    if (player_won == 0)
    {
        cout << "That is a draw!\n";
    }
}

int main()
{
    game();
    return 0;
}

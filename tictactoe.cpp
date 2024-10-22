#include <iostream>
#include <ctime>
using namespace std;

void Board(char *spaces);
void PlayerMove(char *spaces, char player);
void ComputerMove(char *spaces, char computer);
bool CheckWinner(char *spaces, char player, char computer);
bool CheckTie(char *spaces);

int main() {
    char player = 'X';
    char computer = 'O';
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool running = true;

    Board(spaces);

    while (running) {
        PlayerMove(spaces, player);
        Board(spaces);

        if (CheckWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (CheckTie(spaces)) {
            running = false;
            break;
        }

        ComputerMove(spaces, computer);
        Board(spaces);

        if (CheckWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (CheckTie(spaces)) {
            running = false;
            break;
        }
    }
    cout << "Thank you for playing!!!\n";
    return 0;
}

void Board(char *spaces) {
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}

void PlayerMove(char *spaces, char player) {
    int number;
    do {
        cout << "Enter a spot to place the marker (1-9) in left to right order: ";
        cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (number >= 0 && number < 9);
}

void ComputerMove(char *spaces, char computer) {
    int number;
    srand(time(0));
    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool CheckWinner(char *spaces, char player, char computer) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (spaces[i] != ' ' && spaces[i] == spaces[i + 1] && spaces[i + 1] == spaces[i + 2]) {
            spaces[i] == player ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!\n";
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (spaces[i] != ' ' && spaces[i] == spaces[i + 3] && spaces[i + 3] == spaces[i + 6]) {
            spaces[i] == player ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!\n";
            return true;
        }
    }
    // Check diagonals
    if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        spaces[0] == player ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!\n";
        return true;
    }
    if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        spaces[2] == player ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!\n";
        return true;
    }
    return false;
}

bool CheckTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    cout << "It's a TIE!!!!!!\n";
    return true;
}

#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int player = 1;
int choice;
int game_status = -1;

void display_board();
void player_turn();
int check_game_over();

int main()
{
    printf("\n\n\tTic Tac Toe\n\n");

    do
    {
        display_board();
        player_turn();
        game_status = check_game_over();
        player = (player % 2) == 0 ? 1 : 2;
    } while (game_status == -1);

    display_board();

    if (game_status == 1)
        printf("\n\n\tPlayer %d wins!\n\n", ( player == 1 ? 2 : 1));
    else
        printf("\n\n\tGame draw!\n\n");

    return 0;
}

void display_board()
{
    printf("\n\n\tCurrent board:\n\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("\t     |     |     \n");
}

void player_turn()
{
    if (player == 1)
        printf("\n\n\tPlayer 1, enter a number: ");
    else
        printf("\n\n\tPlayer 2, enter a number: ");

    scanf("%d", &choice);

    char mark = (player == 1) ? 'X' : 'O';

    if (choice == 1 && board[0][0] == '1')
        board[0][0] = mark;
    else if (choice == 2 && board[0][1] == '2')
        board[0][1] = mark;
    else if (choice == 3 && board[0][2] == '3')
        board[0][2] = mark;
    else if (choice == 4 && board[1][0] == '4')
        board[1][0] = mark;
    else if (choice == 5 && board[1][1] == '5')
        board[1][1] = mark;
    else if (choice == 6 && board[1][2] == '6')
        board[1][2] = mark;
    else if (choice == 7 && board[2][0] == '7')
        board[2][0] = mark;
    else if (choice == 8 && board[2][1] == '8')
        board[2][1] = mark;
    else if (choice == 9 && board[2][2] == '9')
        board[2][2] = mark;
    else
    {
        printf("\n\n\tInvalid move! Please try again.\n\n");
        player--;
        getchar();
    }
}

int check_game_over()
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return 1;
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return 1;
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return 1;
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return 1;
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return 1;
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return 1;
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3'
        && board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6'
        && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
        return 0;
    else
        return -1;
}
// developed by azer ben azzouz

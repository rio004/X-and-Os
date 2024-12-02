#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[10]= {' ','1','2','3','4','5','6','7','8','9'};

void drawTable()
{
    int i;

    for(i = 0; i <= 9; i++)
    {
        if(board[i]==' ')
        {
            continue;
        }

        if(i==4|i==7)
        {
            printf("\n");
            printf(" -------------------");
        }
        if(i==4|i==7)
        {
            printf("\n");
        }
        if(i == 1|i==4|i==7)
        {
            printf(" | ");
        }

        printf(" %c ",board[i]);
        printf(" | ");
    }
    printf("\n");
    printf("\n");
}

void getMove(char player)
{
	int cell;

	do
	{
		printf("Player %c, Enter Cell Num. (1-9) ", player);
		scanf("%d", &cell);

		if(cell < 1 || cell > 9)
		{
			printf("Entered Num. is out of Cell Range");
			printf("\n");
		}
		else if(board[cell] == 'X' || board[cell] == 'O')
		{
			printf("Pick a different Cell");
			printf("\n");
		}
		else
		{
			board[cell] = player;
			return;
		}
	} while(1);
}

int isWinner(char player)
{
	if(board[7] == player && board[8] == player && board[9] == player) // top horizontal
		return 1;

	if(board[4] == player && board[5] == player && board[6] == player) // middle hor.
		return 1;

	if(board[1] == player && board[2] == player && board[3] == player) // bottom hor.
		return 1;

	if(board[7] == player && board[4] == player && board[1] == player) // left vertical
		return 1;

	if(board[8] == player && board[5] == player && board[2] == player) // middle ver.
		return 1;

	if(board[9] == player && board[6] == player && board[3] == player) // right ver.
		return 1;

	if(board[7] == player && board[5] == player && board[3] == player) //left - right diagonal
		return 1;

	if(board[9] == player && board[5] == player && board[1] == player) // right - left diagonal
		return 1;

	return 0;
}

// Checks if the board is full
int fullBoard() {
    // loops through the board
    for (int i = 1; i <= 9; i++) {
        // Checks if X and O are not in the board
        if (board[i] != 'X' && board[i] != 'O') {
            return 0;       // the game continues
        }
    }
    return 1;               // the game becomes a draw
}

void computerMove(char player) 
{
    int cell;
    srand(time(NULL));

	do {
        cell = rand() % 9 + 1;
        // Checks if X and O are not in the cell chosen
        if (board[cell] != 'X' && board[cell] != 'O') {
            // chooses a random number from 1 to 9 and plays for player
            board[cell] = player;  
            printf("Computer has chosen %d \n", cell);
            return;
        }
    } while (1);
}

int main(void)
{
    // Main menu
    int choice = 0, computer = 0, multiplayer = 0;

    // Random player
    int random;
    int player, player2;

    do { 
        printf("\nMain Menu\n");
        printf("\nMultiplayer: 1 \n");
        printf("Computer: 2 \n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 2) {
            printf("\nChoose the correct option!!!\n");
        } else {
            if (choice == 1) {
                multiplayer = 1;
            } else {
                computer = 1;
            }
            break;
        }
    } while(1);

    // TODO
    // Mahmoud: Multiplayer best of 3

    // Initial game layout
    drawTable();

    // Random player
    srand(time(NULL));
    random = rand() % 2;

    if (random == 0) {
        player = 'X';
        player2 = 'O';
    } else {
        player = 'O';
        player2 = 'X';
    }

    // Loops until the game is over
    while (1)
    {
        // player 1
        getMove(player);           // 1st player is played
        drawTable();               // redraws the board with player
        if (isWinner(player)) {    // checks if X has won the game 
            printf("\n %c has won the game!!", player);
            break;
        }
        if (fullBoard()) {         // checks if the board is full
            printf("\n Game is a draw!!");
            break;
        }

        // player 2 (could also be computer)
        if (computer) {
            computerMove(player2);
        } else {
            getMove(player2);
        }
        drawTable();
        if (isWinner(player2)) {
            printf("\n %c has won the game!!", player2);
            break;
        }
        if (fullBoard()) {
            printf("\n Game is a draw");
            break;
        }
    }

    return 0;
}

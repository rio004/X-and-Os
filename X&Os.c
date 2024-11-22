#include <stdio.h>

void drawTable()
{
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

int main(void)
{
}

#include <stdio.h>

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

int main(void)
{
    drawTable();

    while (1)
    {
        getMove('X');
        drawTable();
        if (isWinner('X')) {
            printf("\n X has won the game!!");
            break;
        }

        getMove('O');
        drawTable();
        if (isWinner('O')) {
            printf("\n O has won the game!!");
            break;
        }
    }

    return 0;
}

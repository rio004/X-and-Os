#include<stdio.h>

char board[10]={' ','1','2','3','4','5','6','7','8','9'};

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
        }
        printf("%c",board[i]);
        
    }
    //Styling still needs to be added.
}

int main()
{
    drawTable();

    return 0;
}

#include<stdio.h>

char board[10]={' ','1','2','3','4','5','6','7','8','9'};
char symb = 124;

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
    
}

int main()
{
    drawTable();

    return 0;
}

#include<stdio.h>
char board[9]={'1','2','3','4','5','6','7','8','9'};
int check();
void print_Board()
{
    
    printf("  %c  |  %c  |  %c\n",board[0],board[1],board[2]);
    printf("_____|_____|_____\n");
    printf("  %c  |  %c  |  %c\n",board[3],board[4],board[5]);
    printf("_____|_____|_____\n");
    printf("  %c  |  %c  |  %c\n",board[6],board[7],board[8]);

}
void main()
{
	int state=0,player=2,in[10],result,i=-1,j,t;
    print_Board();
    while(state==0)
    {
    	i++;
    	player=(player%2==0)? 1:2;
    	printf("PLAYER_%d ENTER THE INPUT PLACE",player);
    	scanf("%d",&in[i]);
    	if(in>9 && in<9)
    	{
    		printf("INVALID CHOICE");
		}
		for(j=0;j<=i;j++)
		{
			if(in==j)
			{
				printf("INVALID CHOICE");
			}
		}
		t=in[i]-1;
    	board[t]=(player%2==0) ? 'x':'o';
    	print_Board();
    	result=check();
    	if(result==1)
    	{
    		printf("PLAYER_%d IS WINNER",player);
    		state=1;
		}
		if(result==2)
		{
			printf("MATCH IS TIED");
			state=1;
		}    	
    
	}
}
int check()
{
	int i,count=0;
	if((board[0]=='o'&&board[1]=='o'&&board[2]=='o')|| (board[0]=='x'&&board[1]=='x'&&board[2]=='x'))
	{
		return 1;
	}
	else if((board[3]=='o'&&board[4]=='o'&&board[5]=='o')|| (board[3]=='x'&&board[4]=='x'&&board[5]=='x'))
	{
		return 1;
	}
	else if((board[6]=='o'&&board[7]=='o'&&board[8]=='o')|| (board[6]=='x'&&board[7]=='x'&&board[8]=='x'))
	{
		return 1;
	}
	else if((board[0]=='o'&&board[3]=='o'&&board[6]=='o' )||(board[0]=='x'&&board[3]=='x'&&board[6]=='x'))
	{
		return 1;
	}
	else if((board[1]=='o'&&board[4]=='o'&&board[7]=='o' )|| (board[1]=='x'&&board[4]=='x'&&board[7]=='x'))
	{
		return 1;
	}
	else if((board[2]=='o'&&board[5]=='o'&&board[8]=='o') || (board[2]=='x'&&board[5]=='x'&&board[8]=='x'))
	{
		return 1;
	}
	else if((board[0]=='o'&& board[4]=='o'&& board[8]=='o') || (board[0]=='x'&&board[4]=='x'&&board[8]=='x'))
	{
		return 1;
	}
	else if((board[2]=='o'&&board[4]=='o'&&board[6]=='o') || (board[2]=='x'&&board[4]=='x'&&board[6]=='x'))
	{
		return 1;
	}
	else 
	{
		for(i=0;i<9;i++)
		{
			if(board[i]=='o'||board[i]=='x')
			{
				count++;
			}
		}
		if(count==9)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
	
}

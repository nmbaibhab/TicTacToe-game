//tic tac toe game
#include<stdio.h>
#include<conio.h>
char a[9]={'1','2','3','4','5','6','7','8','9'};
char b[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int count=0;

//game intro
void name()
{
    printf("\n\n\n\t\t Welcome to TicTacToe Game!!\n\n\n\n");
    printf("*Reference of position numbers of the box:\n\n");

}
//display reference box
void box()
{
    printf("\t\t%c\t|\t%c\t|\t%c\n",a[0],a[1],a[2]);
    printf("\t\t________|_______________|________\n");
    printf("\t\t        |               |        \n");
    printf("\t\t%c\t|\t%c\t|\t%c\n",a[3],a[4],a[5]);
    printf("\t\t________|_______________|________\n");
    printf("\t\t%c\t|\t%c\t|\t%c\n",a[6],a[7],a[8]);
    printf("\t\t        |               |        \n");

}
//display empty box
void box1()
{
    printf("\n");
    printf("\t\t%c\t|\t%c\t|\t%c\n",b[0],b[1],b[2]);
    printf("\t\t________|_______________|________\n");
    printf("\t\t        |               |        \n");
    printf("\t\t%c\t|\t%c\t|\t%c\n",b[3],b[4],b[5]);
    printf("\t\t________|_______________|________\n");
    printf("\t\t%c\t|\t%c\t|\t%c\n",b[6],b[7],b[8]);
    printf("\t\t        |               |        \n");

}
//game instructions
void instruction()
{
    printf("\n\n\tPlayer 1 symbol: 'X'");
    printf("\n\n\tPlayer 2 symbol: 'O'");
    printf("\n\n\tLets Begin......\n\n");
}
//asks for input
void play()
{
    char p,s;
    printf("\n\nPlease input ur position no. and symbol\n");
    fflush(stdin);
    scanf("%c%c",&p,&s);
    change(p,s);
    count++;

}
//adds the symbol to the array
void change(char p,char s)
{
    for (int i = 0; i < 9; i++)
    {
        if(a[i]==p)
        {
            b[i]=s;
        }
    }
    
}
//checks for winner
int check()
{
    if((b[0]=='x'&&b[1]=='x'&&b[2]=='x')||(b[0]=='x'&&b[3]=='x'&&b[6]=='x')||(b[0]=='x'&&b[4]=='x'&&b[8]=='x'))
    {
        return 1;
    }
    else 
    {
        if((b[0]=='o'&&b[1]=='o'&&b[2]=='o')||(b[0]=='o'&&b[3]=='o'&&b[6]=='o')||(b[0]=='o'&&b[4]=='o'&&b[8]=='o'))
        {
            return 2;
        }

        else
        {
            if((b[1]=='x'&&b[4]=='x'&&b[7]=='x')||(b[2]=='x'&&b[5]=='x'&&b[8]=='x'))
            {
                return 1;
            }
            else
            {
                if((b[1]=='o'&&b[4]=='o'&&b[7]=='o')||(b[2]=='o'&&b[5]=='o'&&b[8]=='o'))
                {
                    return 2;
                }
                else
                {
                    if((b[2]=='x'&&b[4]=='x'&&b[6]=='x')||(b[3]=='x'&&b[4]=='x'&&b[5]=='x')||(b[6]=='x'&&b[7]=='x'&&b[8]=='x'))
                    {
                        return 1;
                    }
                    else
                    {
                        if((b[2]=='o'&&b[4]=='o'&&b[6]=='o')||(b[3]=='o'&&b[4]=='o'&&b[5]=='o')||(b[6]=='o'&&b[7]=='o'&&b[8]=='o'))
                        {
                            return 2;
                        }
                        else
                        {
                            return 3;
                        }
                        
                    }
                    
                }
                
            }
            
        }   
        
    }
   
    
    
}
// reiniatlize values of the game box to look empty
reinitialize(char b[])
{
    for (int i = 0; i < 9; i++)
    {
        b[i]=' ';
    }
    
}

void main()
{
    int c;
    char ch;
    labell:
    // clrscr();
    system("cls");
    name();
    box();  
    instruction();
    box1();
    play();

    label:
    system("cls");
    box1();
    play();
    c=check();
    // clrscr();
    system("cls");
    box1();
    if (c==1)
    {
        printf("\nBooyah......Player1 wins");
    }
    else
    {
        if (c==2)
        {
            printf("\nBooyah......Player2 wins");
        }
        else
        {
            if(count>=9)
            {
                printf("\n\tGame Draw!!");
            }
            else
            {
             goto label;        
            }
            
        }
        
    }
     printf("\n\nDo you want to continue again??? Press 'y' for yes and'n' for no ");
     fflush(stdin);
     scanf("%c",&ch);
    
     if(ch=='n')
    {
      printf("\n\nPress any key to exit game:");
    }
    if(ch=='y')
    {
        count=0;
      reinitialize(b);
      goto labell;
    }

    getch();
}
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>

#define Home 71
#define End 79
#define Del    127 //83



 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }


int main()
{
    int startCol , lastCol ,currCol , startRow,size;
    startCol = lastCol = currCol  = 30;
    startRow = 10;
    size = 21;
    char name[21];
    char   *curPtr;
    char *lastPtr ;
    curPtr=lastPtr=name;
    int quiteFlag = 0;
    char c;
    do
    {
        gotoxy(currCol,startRow);
        c = getch();
        switch(c)
        {
        case -32: // extended key
            c = getch();
            switch(c)
            {
            case 75: // left
                if (currCol > startCol)
                {
                    currCol--;
                    curPtr--;
                }
                break;
            case 77:  //right
                 if ( currCol<lastCol )
                {
                    currCol++;
                    curPtr++;
                }
                break;
            }
            break;
            case 27:
                quiteFlag = 1;
                break;
            case 13 ://Enter
                *lastPtr=0;
                gotoxy(startCol,startRow+1);
                printf("%s",name);
                quiteFlag = 1;
                break;
            case Home:
                    currCol = startCol;
                    curPtr = name;
                    //printf("%s",name);
                break;
            case End:
                    currCol = lastCol;
                    curPtr = lastPtr;
                break;
             case Del:
                    lastCol--;
                    lastPtr--;
                    for (int i=strlen(name) ; i>0; i-- )
                    {
                        printf("%c",name[i]);
                    }
                break;
                //backspace :- Take care the cursor where start ? wakef fin.
            default:
                if (currCol < startCol+size)
                {
                    printf("%c" , c);
                    //*curPtr++;
                    *curPtr = c;
                    if (currCol== lastCol)
                    {
                        lastCol++;
                        lastPtr++;
                    }
                    currCol++;
                    curPtr++;
                }

        }
    }while(! quiteFlag);

    //printf("Hello world!\n");

    return 0;
}

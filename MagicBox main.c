#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>



 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
int main()
{
    int col,row,i,size,totalSize;

         do{
        	printf("please enter size of magic box that is odd not even\n");
        	scanf("%i",&size);

    }while(size %2 == 0);
          totalSize =size * size ;
          printf("total magic square size %d\n",totalSize);

          //system("cls");

          // Main Loop !
          for(i=1;i<=totalSize;i++)
          {
              // Start at row = 1
              // first step in my prog.
                if(i==1)
                {
                  row =1;
                  col=(size+1)/2;
                }
                //second if i was any number except 1 check on i
                // if i was accept diversion then step into new  row+=1
                else if(((i-1) % size) == 0){
                  row++;
                }
                // if the div wasn't == 0 so the result of div is 1
                else{
                    // make up and goto left.
                  row--; col--;
                // check borders
                  if(row == 0)
                   row = size;
                  if(col == 0)
                   col = size;
                }
                // gotoxy made by ITI developer to tab.
                gotoxy(col*4,row*4);
                // finally print my lovely matrix game
                printf("%d",i);

          }


    return 0;
}




/*int size;
    do{
        printf("Enter an odd number \n");
        scanf("%i",&size);

    }while(size %2 == 0);
    printf("The size is %i",size);*/

    // Main For loop

   /* for(int i = 1; i<(size*size); i++)
    {
        gotoxy(col*4,row*4);
        printf("%i",i);

        // check if accept div back step get left put next num .
        if (i%size == 1){
            row--;
            col--;
        }else if (row <0 || col<0)
        {
             row = size-1;
            col = size -1;
        }else
        {
        row++;
        }
    }*/

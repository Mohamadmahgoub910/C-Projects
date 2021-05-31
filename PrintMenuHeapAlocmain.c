#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <Windows.h>
#define null -32
#define MenuSize 5
#include<malloc.h>


struct Employee
{
    int id;
    char name[20];
    float salary;
    char mobile[14];
};




 void MyMenu (char * ptr , int size , int curr);

 void addEmp(struct Employee *emp , int empsize);
 void editEmp(struct Employee *emp , int empsize);
 void displayemp(struct Employee *emp , int empsize);
 void displayAll(struct Employee *emp , int empsize );

void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }





int main()
{

    // Print Menu Dynamic

    printf("Hi  Smart ! \n");
    int startcol , startRow = 10 ;
    int empsize=0;
    char Menu[MenuSize][12] = {"ADD \n", "Edit \n","Display \n"  ,  "DisplayAll \n","Exit\n"};
    int quitFlag = 0;
    char ch;
    int currentCol=0;
    int indix;
    printf("Enter number of employee \n");
    scanf("%i",&empsize);
    //int  empsize = 3;
    struct Employee  emp[empsize];
    struct Employee *emptr;
    // alloc and type casting
    emptr = (struct Employee *) malloc(empsize* sizeof(struct Employee));


    // loop
    do
    {
        // my menu
        MyMenu(Menu,MenuSize,currentCol);
        ch = getch();
        switch(ch)
        {
        case -32:
            // take the char in the buffer
            ch = getch();
            // switch start
            switch(ch)
            {
                // up
            case 72:
                if (currentCol>0)
                {
                    currentCol--;
                    printf("%i \n",currentCol);
                }
                break;
                // Down
            case 80:
                if (currentCol<MenuSize-1)
                {
                     currentCol++;
                     printf("%i \n",currentCol);
                }
                 break;
            }
            break;

            //Enter
            case 13:
                switch(currentCol)
                {
                    //ADD
                    case 0:
                        system("cls");
                        printf("ADD \n");
                        addEmp(emptr,empsize);
                        getch();
                    break;
                    case 1:
                        //EDIT
                        system("cls");
                        printf("EDIT \n");
                        editEmp(emptr,empsize);
                        getch();
                    break;

                 //DisplaySpecific
                    case 2:
                        system("cls");
                        printf("DisplaySpecific \n");
                        displayemp(emptr , empsize);
                        getch();
                    break;

                    //DisplayAll
                    case 3:
                        system("cls");
                        printf("DisplayAll \n");
                        displayAll(emptr,empsize);
                        getch();
                    break;
                    case 4:
                        //system("cls");
                        quitFlag = 1;
                    break;
                }
                break;
                case 27:
                    quitFlag=1;
                break;
        }
    }while(!quitFlag );
    return 0;
}



 void MyMenu (char * ptr , int size , int curr)
 {

    int startcol =10 ; int  startRow =10;
     textattr(50);
     system("cls");
     for (int i =0;  i<size; i++)
     {
         if (i==curr)
         {
             textattr(90);
         }
         else
         {
             textattr(50);
         }
         gotoxy(startcol ,startRow+i);
         printf("%s",ptr+(i*12));
     }
     //to default
     textattr(100);
 }
 void displayAll(struct Employee  *emp , int empsize )
 {
     for (int i=0; i<empsize; i++)
     {

        printf("Display Employee number %i  \n",i+1);
        printf("ID is %i  \n",emp->id);
        printf("name is %s  \n",emp->name);
        printf("salary is %f \n",emp->salary);
        printf("mobile is  %s \n",emp->mobile);
        printf("*************************\n");
        emp++;
     }
 }

 void addEmp(struct Employee *emp , int empsize)
 {
     /*int size ;
    printf("Enter a size of employee ");
    scanf("%i",&size);
    */
    for (int i =0; i<empsize; i++)
    {
        printf("Employee number %i  \n",i+1);
        printf("ID is  \n");
        scanf("%i",&emp[i].id);
        printf("name  is  \n");
        scanf("%s",emp[i].name);
        printf("salary  is  \n");
        scanf("%f",&emp[i].salary);
        printf("mobile  is  \n");
        scanf("%s",emp[i].mobile);
        printf("************************* \n");
    }

 }

 void displayemp(struct Employee *emp , int empsize)
 {
     int index;
     printf("Enter  a number of emp to display \n");
     scanf("%i",&index);
     if (index>0 && index<=empsize)
     {
        emp += index-1;
        printf("Display Employee number %i  \n",index+1);
        printf("ID is %i  \n",emp->id);
        printf("name is %s  \n",emp->name);
        printf("salary is %f \n",emp->salary);
        printf("mobile is  %s \n",emp->mobile);
        printf("*************************\n");

     }
 }
  void editEmp(struct Employee *emp , int empsize)
  {
       int index;
     printf("Enter  a number of emp to Edit \n");
     scanf("%i",&index);
     if (index>0 && index<=empsize)
     {
        emp += index-1;
        printf("Edit Employee number %i   for ID,name Salary  and Mobile \n",index+1);
        scanf("%i \n",&emp->id);
        scanf(" %s \n",emp->name);
        scanf("%f \n",&emp->salary);
        scanf("%s \n",emp->mobile);
        printf("*************************\n");
     }

  }

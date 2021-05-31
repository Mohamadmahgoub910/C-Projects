#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

int main()
{
    // heap of reserve size of arr numbers
    printf("Hello world!\n");
    int size;
    printf("Enter a number size \n");
    scanf("%i",&size);
    // type cast and heap one piece
    int  * ptr  = (int *) malloc(size * sizeof(int));
    int ptrStart=0;
    ptrStart = ptr;

    // Take a size number of array from user
    for(int i=0; i<size; i++)
    {
        printf("The value number %i  \n",i+1);
        scanf("%i",ptr[i]);
        ptr++;
    }
    // reset the ptr
    ptr=ptrStart;

    //Display my arr
    for(int i = 0; i<size; i++)
    {
        printf("The value of % is %i \n",i+1,ptr[i]);
    }
    free(ptr); //heap , stack
    return 0;
}

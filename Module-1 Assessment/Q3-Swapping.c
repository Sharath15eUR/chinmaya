#include<stdio.h>

void swap(int *a, int *b);
void main()
{
    int num1, num2;
    scanf("%d %d",&num1,&num2);
    swap(&num1,&num2);
    printf("After swapping num1 is: %d and num2 is: %d",num1,num2);
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
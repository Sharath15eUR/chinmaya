#include <stdio.h>

void main() 
{
    int num,temp;
    scanf("%d",&num);
    temp=num;
    int count = 0;
    
    while (num)
    {
        count += num & 1;
        num = num >> 1;
    }

    printf("Count of Set bits: %d",count);
}
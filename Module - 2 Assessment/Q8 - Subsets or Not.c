#include <stdio.h>

int Subset(int arr1[], int n1, int arr2[], int n2) 
{
    int i,j,flag=1;
    for (i = 0; i < n2; i++) {
        for (j = 0; j < n1; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
        if (j == n1)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
void main() 
{
    int arr1[100],arr2[100];
    int n1,n2;
    printf("Enter the size of array 1: ");
    scanf("%d",&n1);
    printf("\nEnter the size of array 2: ");
    scanf("%d",&n2);
    printf("\nEnter the elements of array 1: ");
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("\nEnter the elements of array 2: ");
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    
    if (Subset(arr1, n1, arr2, n2)==1)
        printf("\narr2[] is a subset of arr1[]");
    else
        printf("\narr2[] is not a subset of arr1[]");

}

// Program to find the average of an array.

#include <stdio.h>
float avge(float n[], int i, int a);
int main()
{
    int a;
    printf("Enter the number of elements: ");
    scanf("%d", &a);
    float n[a];
    printf("Enter the elements: ");
    for (int i = 0;i<a;i++)
    {
        scanf("%f", &n[i]);
    }
    float avg=avge(n, 0, a);
    printf("Average = %f ", avg/a);
    return 0;
}
float avge(float n[], int i, int a)
{
    float average = 0;
    if(i<a)
        average = average + n[i] + avge(n, ++i, a);
    return average;
}

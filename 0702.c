/*#include <stdio.h>
int sum(int arr[], int n) {
	if(n<=0) return 0;
    return (arr[n-1] + sum(arr, n-1));
}
int main(){    
    int n;
	float avg= 0.0f;
	int arr[n];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }   
    avg = sum(arr,n)/n;
    printf("Sum of elements: %f", avg);   
    return 0;
}*/


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

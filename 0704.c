#include <stdio.h>
int sum (int n){
    if (n != 0) return (n % 10 + sum (n / 10));
    else return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("Sum of digits in %d is %d\n", n, sum(n));
    return 0;
}
 

// Program to find the factorial of a number.

#include <stdio.h>
int fact(int i) {
    if(i <= 1) {
        return 1;
    }
    return i * fact(i - 1);
}
int main() {
    int i;
    scanf("%d", &i);
    printf("Factorial of %d is %d\n", i, fact(i));
    return 0;
}

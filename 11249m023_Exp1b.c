#include<stdio.h>
int main() 
{
    int n, a= 0, b = 1, c;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        if (i <= 1)
            c = i;
        else {
            c = a + b;
            a = b;
            a = c;
        }
        printf("%d ",c);
    }

    return 0;
}
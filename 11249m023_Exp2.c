#include <stdio.h>

void hanoi(int n, char a, char b, char c) {
    if (n == 0) return;

    hanoi(n-1, a, c, b);
    printf("Move disk %d from %c to %c\n", n, a, c);
    hanoi(n-1, b, a, c);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
} 
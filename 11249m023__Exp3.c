#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Function to print bins */
void printBins(int bin[], int binsUsed) {
    printf("Total bins used: %d\n", binsUsed);
    for (int i = 0; i < binsUsed; i++) {
        printf("Bin %d remaining capacity: %d\n", i + 1, bin[i]);
    }
}

/* ---------------- FIRST FIT ---------------- */
void firstFit(int weight[], int n, int capacity) {
    int bin_rem[MAX];
    int binsUsed = 0;

    for (int i = 0; i < n; i++) {

        if (weight[i] > capacity) {
            printf("Item weight %d exceeds bin capacity!\n", weight[i]);
            continue;
        }

        int placed = 0;

        for (int j = 0; j < binsUsed; j++) {
            if (bin_rem[j] >= weight[i]) {
                bin_rem[j] -= weight[i];
                placed = 1;
                break;
            }
        }

        if (!placed) {
            bin_rem[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }

    printBins(bin_rem, binsUsed);
}

/* ---------------- FIRST FIT DECREASING ---------------- */

// Comparator for sorting in descending order
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void firstFitDecreasing(int weight[], int n, int capacity) {
    int sorted[MAX];

    for (int i = 0; i < n; i++)
        sorted[i] = weight[i];

    qsort(sorted, n, sizeof(int), compare);

    firstFit(sorted, n, capacity);
}

/* ---------------- BEST FIT ---------------- */
void bestFit(int weight[], int n, int capacity) {
    int bin_rem[MAX];
    int binsUsed = 0;

    for (int i = 0; i < n; i++) {

        if (weight[i] > capacity) {
            printf("Item weight %d exceeds bin capacity!\n", weight[i]);
            continue;
        }

        int min_space = capacity + 1;
        int bestIndex = -1;

        for (int j = 0; j < binsUsed; j++) {
            if (bin_rem[j] >= weight[i] &&
                bin_rem[j] - weight[i] < min_space) {

                bestIndex = j;
                min_space = bin_rem[j] - weight[i];
            }
        }

        if (bestIndex != -1) {
            bin_rem[bestIndex] -= weight[i];
        } else {
            bin_rem[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }

    printBins(bin_rem, binsUsed);
}

/* ---------------- MAIN FUNCTION ---------------- */
int main() {
    int n, capacity;
    int weight[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of items! Maximum allowed is %d.\n", MAX);
        return 1;
    }

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    if (capacity <= 0) {
        printf("Invalid bin capacity!\n");
        return 1;
    }

    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("\n--- First Fit ---\n");
    firstFit(weight, n, capacity);

    printf("\n--- First Fit Decreasing ---\n");
    firstFitDecreasing(weight, n, capacity);

    printf("\n--- Best Fit ---\n");
    bestFit(weight, n, capacity);

    return 0;
}
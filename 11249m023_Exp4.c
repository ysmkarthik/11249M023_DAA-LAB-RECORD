#include <stdio.h>

struct Item {
    int profit, weight;
    float ratio;
};

int main() {
    int n, capacity;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort by decreasing ratio
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }

    printf("\nItems selected:\n");

    for (int i = 0; i < n && capacity > 0; i++) {
        if (capacity >= item[i].weight) {
            printf("Profit %d, Weight %d (Full)\n", item[i].profit, item[i].weight);
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else {
            printf("Profit %d, Weight %d (Partial)\n", item[i].profit, item[i].weight);
            totalProfit += item[i].profit * ((float)capacity / item[i].weight);
            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}

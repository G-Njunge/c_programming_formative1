#include <stdio.h>

int total_distance(int vals[], int size);
int avg_distance();
int longest_route();
int routes_longer_than_x();

int main (void)
{
    int distances[7] = {10, 20, 30, 40, 67, 34, 84};
    int sum = total_distance(distances,7);
    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %dkm\n", sum);
    // printf(")

}

int total_distance(int vals[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += vals[i];
    }
    return (total);
}





#include <stdio.h>

int total_distance(int vals[], int size);
float avg_distance(int vals[], int size);
int longest_route(int vals[], int size);
void routes_longer_than_x(int vals[], int size);
int recursive_sum(int vals[], int size);

int main (void)
{
    int distances[7] = {10, 20, 130, 40, 67, 34, 84};
    int sum = total_distance(distances, 7);
    float avg = avg_distance(distances, 7);
    int l_route = longest_route(distances, 7);
    int rec_sum = recursive_sum(distances, 7);
    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", sum);
    printf("Average distance: %.2f km\n", avg);
    printf("Longest route: %d km\n", l_route);
    routes_longer_than_x(distances, 7);
    printf("Recursive sum: %d km\n\n",rec_sum);


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

float avg_distance(int vals[], int size)
{
    int sum = total_distance(vals, size);
    float avg = ((float)sum / size);
    return (avg);
}

int longest_route(int vals[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (vals[i] > max)
            max = vals[i];
    }
    return (max);
}
void routes_longer_than_x(int vals[], int size)
{
    int arr[7];
    int o = 0;
    int distance_limit = 24;
    for(int i = 0; i < size; i++)
    {
        if (vals[i] > distance_limit)
        {
            o++;
        }
    }
    printf("Routes above %d km: %d\n", distance_limit, o);
}

int recursive_sum(int vals[], int size)
{
    if (size == 0)
        return (0);
    size --;
    return (vals[size] + recursive_sum(vals, size));
}







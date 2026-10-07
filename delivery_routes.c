#include <stdio.h>

#define NUM_ROUTES 7

int total_distance(int vals[], int size);
float avg_distance(int vals[], int size);
int longest_route(int vals[], int size);
int routes_longer_than_x(int vals[], int size, int limit);
int recursive_sum(int vals[], int size);

int main (void)
{
    // The distances (in km) of the 7 delivery routes
    int distances[NUM_ROUTES] = {10, 20, 130, 40, 67, 34, 84};
    int sum = total_distance(distances, NUM_ROUTES);
    float avg = avg_distance(distances, NUM_ROUTES);
    int l_route = longest_route(distances, NUM_ROUTES);
    int rec_sum = recursive_sum(distances, NUM_ROUTES);
    int above_24 = routes_longer_than_x(distances, NUM_ROUTES, 24);
    int above_50 = routes_longer_than_x(distances, NUM_ROUTES, 50);

    // Show the results on the screen
    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", sum);
    printf("Average distance: %.2f km\n", avg);
    printf("Longest route: %d km\n", l_route);
    printf("Routes above 24 km: %d\n", above_24);
    printf("Routes above 50 km: %d\n", above_50);
    printf("Recursive sum: %d km\n\n", rec_sum);

    return 0;
}

// Adds up all the route distances
int total_distance(int vals[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += vals[i];
    }
    return (total);
}

// Total distance divided by the number of routes
float avg_distance(int vals[], int size)
{
    int sum = total_distance(vals, size);
    float avg = ((float)sum / size);
    return (avg);
}

// Goes through the routes and keeps the biggest one seen so far
int longest_route(int vals[], int size)
{
    int max = vals[0];
    for (int i = 1; i < size; i++)
    {
        if (vals[i] > max)
            max = vals[i];
    }
    return (max);
}

// Counts how many routes are longer than the given limit
int routes_longer_than_x(int vals[], int size, int limit)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if (vals[i] > limit)
        {
            count++;
        }
    }
    return (count);
}

// Adds the last route to the total of the rest, repeating until no routes are left
int recursive_sum(int vals[], int size)
{
    if (size == 0)
        return (0);
    size --;
    return (vals[size] + recursive_sum(vals, size));
}
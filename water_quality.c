#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calc_water_index(int temp, int turb);

int main (void)
{
    // The two readings taken from the water sample
    int temperature = 35;
    int turbidity = 40;

    // Turn the two readings into one score out of 100
    int index = calc_water_index(temperature, turbidity);
    char water_quality[10];

    // Decide if the water quality is Good, Warning or Critical based on the score
    if (index >= 80)
        strcpy(water_quality, "Good");
    else if (index >= 60)
        strcpy(water_quality, "Warning");
    else
        strcpy(water_quality, "Critical");

    printf("\n");
    printf("         WATER QUALITY REPORT\n");
    printf("  Temperature reading            %3d C\n", temperature);
    printf("  Turbidity reading              %3d NTU\n", turbidity);
    printf("  Water quality index            %3d / 100\n", index);
    printf("  Status                         %s\n\n", water_quality);

    return 0;
}

int calc_water_index(int temp, int turb)
{
    int temp_dev = abs(temp - 25);
    int turb_pen = turb / 2;
    int w_index = 100 - (temp_dev + turb_pen);
    return (w_index);
}

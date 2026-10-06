#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calc_water_index(int temp, int turb);
int main (void)
{
    int temperature = 35;
    int turbidity = 40;

    int index = calc_water_index(temperature, turbidity);
    char water_quality[10];

    if (index >= 80)
        strcpy(water_quality,"Good");
    else if (index >= 60)
        strcpy(water_quality,"Warning");
    else
        strcpy(water_quality,"Critical");

    printf("\n\t\tWATER QUALITY REPORT\n\n");
    printf("\tWater Temperature reading: %d\n", temperature);
    printf("\tTurbidity reading: %d\n", turbidity);
    printf("\tCalculated index: %d\n", index);
    printf("\tBecause the calculated water index is %d, the quality of your water is %s\n\n", index, water_quality);

}

int calc_water_index(int temp, int turb)
{
    int temp_dev = abs(temp - 25);
    int turb_pen = turb / 2;
    int w_index = 100 - (temp_dev + turb_pen);
    return (w_index);
}

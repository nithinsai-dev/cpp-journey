//
// Created by NITHIN SAI on 17-08-2026.
//

#include "System.h"
#include <cstdio>

int main() {

    int hour[4];
    float rainfall[4],soilMoisture[4],vibration[4];
    float RI[4],SF[4],FP[4];

    int highRiskHours = 0;
    int floodAlert = 0;
    float totalRI = 0;
    float minSF = 9999;
    float peakRainfall = -1;
    int peakHour = 0;

    for (int i=0;i<4;i++) {
        scanf("%d %f %f %f",&hour[i],&rainfall[i],&soilMoisture[i],&vibration[i]);
    }
    for (int i=0;i<4;i++) {
        RI[i] = rainfall[i]*soilMoisture[i];
        SF[i] = 100 - (0.5*soilMoisture[i] + 0.5*rainfall[i]);

        if (rainfall[i] > 70) {
            FP[i] = rainfall[i]*2;
        } else {
            FP[i] = 0;
        }

        totalRI += rainfall[i];
        if (rainfall[i] > peakRainfall) {
            peakRainfall = rainfall[i];
            peakHour = hour[i];
        }
        if (RI[i] > 4000 && SF[i] < 40)
        {
            highRiskHours++;

            if (rainfall[i] > 70 && FP[i] > 120)
            {
                floodAlert = 1;

                printf("Hour %d → RI: %.1f, SF: %.1f → High Landslide Risk + Flood Alert\n",
                       hour[i], RI[i], SF[i]);
            }
            else
            {
                printf("Hour %d → RI: %.1f, SF: %.1f → High Landslide Risk\n",
                       hour[i], RI[i], SF[i]);
            }
        }
        else if (rainfall[i] > 70 && FP[i] > 120)
        {
            floodAlert = 1;

            printf("Hour %d → RI: %.1f, SF: %.1f → Flood Alert\n",
                   hour[i], RI[i], SF[i]);
        }
        else
        {
            printf("Hour %d → RI: %.1f, SF: %.1f → No Risk\n",
                   hour[i], RI[i], SF[i]);
        }
    }
    printf("\nSummary:\n");
    printf("Total High Risk Hours: %d\n", highRiskHours);
    if (floodAlert)
        printf("Flood Alert: YES\n");
    else
        printf("Flood Alert: NO\n");
    printf("Average Runoff Index: %.2f\n", totalRI / 4);
    printf("Minimum Stability Factor: %.1f\n", minSF);
    printf("Peak Rainfall: %.0f mm at Hour %d\n",
    peakRainfall, peakHour);
    return 0;
}
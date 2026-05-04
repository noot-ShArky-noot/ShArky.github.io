#include <stdio.h>
#include <stdlib.h>

int main() {
    float t[4][3]={{18.2,23.8,20.6},{17.3,25.1,21.5},{15.0,20.6,18.4},{13.4,17.8,15.7}};
    int i, j, maxi=0, maxj=0, mini=0, minj=0;
    float avgday=0.0, avgtime=0.0;
    for (i=0; i<4; i++) {
        for (j=0; j<3; j++) {
            printf("%.2f ", t[i][j]);
            avgday+=t[i][j];
            if (t[i][j]>t[maxi][maxj])
                maxi=i; maxj=j;
            if (t[i][j]<t[mini][minj])
                mini=i; minj=j;
        }
        printf("average temp is %.2f", avgday/3);
        printf("\n");
        avgday=0;
    }
    for (j=0; j<3; j++) {
        for (i=0; i<4; i++) {
            avgtime+=t[i][j];
        }
        printf("average temp for time section %d is %.2f\n", j+1, avgtime/4);
        avgtime=0;
    }
    printf("highest temp is at day %d, time section %d\n", maxi+1, maxj+1);
    printf("lowest temp is at day %d, time section %d\n", mini+1, minj+1);
}


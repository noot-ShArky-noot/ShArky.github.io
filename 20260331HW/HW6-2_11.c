#include <stdio.h>
#include <stdlib.h>

int main() {
    int worktime= 85, salary=0;

    if (worktime > 75) {
        salary= (worktime - 75)*75*1.75 + 15*75*1.25 + 60*75;
        printf("Your salary is %d", salary);
    }
    else if ((worktime <= 75) && (worktime > 60)) {
        salary= (worktime - 60)*75*1.25 + 60*75;
        printf("Your salary is %d", salary);
    }
    else if ((worktime <= 60) && (worktime >0)) {
        salary= worktime*75;
        printf("Your salary is %d", salary);
    }
    else {
        printf("invalid input");
    }
}
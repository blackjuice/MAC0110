#include <stdio.h>

void convertion (int t, int *day, int *hour, int *minute, int *second);

int main () {
        int t, day, hour, minute, second;

        printf ("Time convertion: seconds into days, hours, minutes and following seconds.\n");
        printf ("Type the T>0 in seconds: ");
        scanf ("%d",&t);
        convertion (t, &day, &hour, &minute, &second);
        printf ("%d second(s) equals to:\n %d day(s), %d hour(s), %d minute(s) and %d second(s).", t, day, hour, minute, second);
        return 0;
}

void convertion (int t, int *day, int *hour, int *minute, int *second) {
        *day=t/86400;
        t=t%86400;      /*update*/
        *hour=t/3600;
        t=t%3600;       /*update*/
        *minute=t/60;
        t=t%60;         /*update*/
        *second=t;
}

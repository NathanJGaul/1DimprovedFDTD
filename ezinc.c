/* Functions to calculate the source function (i.e., the incident 
 * field). */

#include "ezinc.h"

/* global variables -- but private to this file */
static double delay, width = 0, cdtds;

/* prompt user for source-function width and delay. */
void ezIncInit(Grid *g) {

    cdtds = Cdtds;
    printf("Enter delay: ");
    scanf(" %lf", &delay);
    printf("Enter width: ");
    scanf(" %lf", &width);
    
    return;
}

/* calculate source function at given time and location */
double ezInc(double time, double location) {
    if (width <= 0) {
        fprintf(stderr,
            "ezInc: must call ezIncInit before ezInc.\n"
            "       Width must be positive.\n");
        exit(-1);
    }
    //printf("time: %f, delay: %f, location: %f, cdtds: %f, width: %f\n", time, delay, location, cdtds, width);
    return exp(-pow((time - delay - location / cdtds) / width, 2));
}
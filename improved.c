/* Imrpoved bare-bones 1D FDTD simulation. */

#include "fdtd.h"
#include "ezinc.h"

int main()
{
    Grid *g;

    ALLOC_1D(g, 1, Grid);           // allocate memory for Grid
    gridInit(g);                    // initialize the grid

    ezIncInit(g);                   // initialize source function

    /* do time stepping */
    for (Time = 0; Time < MaxTime; Time++) {
        updateH(g);                 // update magnetic field
        updateE(g);                 // update electric field
        Ez(0) = ezInc((double)Time, 0.0);   // apply source function
        printf("%g\n", Ez(50));     // print output
    } // end of time-stepping 

    return 0;
}
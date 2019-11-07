/* Imrpoved bare-bones 1D FDTD simulation. */

#include "fdtd.h"

int main()
{
    Grid *g;

    ALLOC_1D(g, 1, Grid);           // allocate memory for Grid
    gridInit(g);                    // initialize the grid
    abcInit(g);                     // initialize ABC
    tfsfInit(g);                    // initialize TFSF boundary
    snapshotInit(g);                // initialize snapshots

    /* do time stepping */
    for (Time = 0; Time < MaxTime; Time++) {
        updateH(g);                 // update magnetic field
        tfsfUpdate(g);              // correct field on TFSF boundary
        abc(g);                     // apply ABC
        updateE(g);                 // update electric field
        snapshot(g);                // take a snapshot (if appropriate)
    } // end of time-stepping 

    return 0;
}
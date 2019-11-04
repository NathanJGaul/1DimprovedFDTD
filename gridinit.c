/* Function to initialize the Grid structure */

#include "fdtd.h"

void gridInit(Grid *g) {
    SizeX = 200;                    // set the size of the grid
    MaxTime = 250;                  // set duration of simulation
    Cdtds = 1.0;                    // set Courant number

    ALLOC_1D(g->ez, SizeX, double); // allocate memory for Ez
    ALLOC_1D(g->hy, SizeX, double); // allocate memory for Hy

    return;
}
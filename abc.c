/* Functions to terminate left size of grid */

#include "fdtd.h"

// Initialize the ABC -- in this case, there is nothing to do.
void abcInit(Grid *g) {

    return;
}

// Apply the ABC -- in this case, only to the left side of the grid.
void abc(Grid *g) {

    /* simple ABC for left size of grid */
    Ez(0) = Ez(1);

    return;
}
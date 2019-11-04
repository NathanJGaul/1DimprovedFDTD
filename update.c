/* Function to update the electric and magnetic fields. */

#include "fdtd.h"

/* characteristic impedance of free space */
static double imp0 = 377.0;

/* update magnetic field */
void updateH(Grid *g) {
    int mm;

    for (mm = 0; mm < SizeX - 1; mm++)  
        Hy(mm) = Hy(mm) + (Ez(mm + 1) - Ez(mm)) / imp0;

    return;
}

void updateE(Grid *g) {
    int mm;

    for (mm = 1; mm < SizeX - 1; mm++)
        Ez(mm) = Ez(mm) + (Hy(mm) - Hy(mm - 1)) * imp0;

    return;
}
/* Function to update the electric and magnetic fields. */

#include "fdtd.h"

/* update magnetic field */
void updateH(Grid *g) {
    int mm;

    for (mm = 0; mm < SizeX - 1; mm++)  
        Hy(mm) = Chyh(mm) * Hy(mm) + 
                 Chye(mm) * (Ez(mm + 1) - Ez(mm));

    return;
}

void updateE(Grid *g) {
    int mm;

    for (mm = 1; mm < SizeX - 1; mm++)
        Ez(mm) = Ceze(mm) * Ez(mm) + 
                 Cezh(mm) * (Hy(mm) - Hy(mm - 1));

    return;
}
/* Function to take a snapshot of a 1D grid */

#include "fdtd.h"

static int temporalStride = 0, spatialStride, startTime,
    startNode, endNode;
static char basename[100];
static const char BASEDIR[] = "./results/";

void snapshotInit(Grid *g) {

    printf("For the snapshots:\n");
    printf("  Duration of simulation is %d steps.\n", MaxTime);
    printf("  Enter start time and temporal stride: ");
    scanf(" %d %d", &startTime, &temporalStride);
    printf("  Grid has %d total nodes (ranging from 0 to %d).\n",
        SizeX, SizeX-1);
    printf("  Enter first node, last node, and spatial stride: ");
    scanf(" %d %d %d", &startNode, &endNode, &spatialStride);
    printf("  Enter the base name: ");
    scanf(" %s", basename);

    return;
}

void snapshot(Grid *g) {
    int mm;
    char filename[100], format[100];
    FILE *snapshot;

    /* ensure temporal stride set to a reasonable value */
    if (temporalStride <= 0) {
        fprintf(stderr,
        "snapshot: snapshotInit must be called before snapshot.\n"
        "          Temporal stride must be set to positive value.\n");
        exit(-1);
    }

    /* get snapshot if temporal conditions met */
    if (Time >= startTime &&
        (Time - startTime) % temporalStride == 0) {
        sprintf(format, "%%s%%s.%%0%dd", countDigits(MaxTime)); // dynamic zero padding
        sprintf(filename, format, BASEDIR, basename, Time);
        snapshot = fopen(filename, "w");
        for (mm = startNode; mm <= endNode; mm += spatialStride)
            fprintf(snapshot, "%g\n", Ez(mm));
        fclose(snapshot);
    }

    return;
}

int countDigits(int n) {
    int count = 0;

    while (n != 0) {
        n /= 10;
        count++;
    }

    return count;
}
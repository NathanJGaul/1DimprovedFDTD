# 1D Improved FDTD

## compiling and running

### serial computation

```bash
gcc -Wall -O -c *.c && gcc *.o -lm -o serial.out
./serial.out
```

### threaded computation (OpenMP)

```bash
gcc -Wall -O -c *.c -fopenmp && gcc *.o -lm -o parallel.out -fopenmp
./parallel.out
```
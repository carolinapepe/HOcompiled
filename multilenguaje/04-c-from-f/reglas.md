gfortran -c f-main.f90 -o f-main_f90.o
gcc -c c-sum.c -o c-sum_c.o
gfortran f-main_f90.o c-sum_c.o -o f-main.e

Resultados de hacer make executable con los makefile provistos en cada una de las 1eras tres carpetas:

FORTRAN CON FORTRAN

gfortran -c f-main.f90 -o f-main_f90.o
gfortran -c f-sum.f90 -o f-sum_f90.o
gfortran f-main_f90.o f-sum_f90.o -o f-main.e

C CON C

gcc -c c-main.c -o c-main_c.o
gcc -c c-sum.c -o c-sum_c.o
gcc c-main_c.o c-sum_c.o -o c-main.e


C++ CON C++

g++ -c cpp-main.cpp -o cpp-main_cpp.o
g++ -c cpp-sum.cpp -o cpp-sum_cpp.o
g++ cpp-main_cpp.o cpp-sum_cpp.o -o cpp-main.e


FORTRAN CON C (subrutina)

gfortran -c f-main.f90 -o f-main_f90.o
gcc -c c-sum.c -o c-sum_c.o
gfortran f-main_f90.o c-sum_c.o -o f-main.e


OJO. TODO EN FORTRAN SON PUNTEROS. ARGUMETNOS DE FUNCIONES TIENEN QUE SER TODOS PUNTEROS. NO HACE FALTA ALOJAR LA MEMORIA EN C, YA LA ALOJA AUTOMATICAMENTE FORTRAN.
ADEMAS, AGREGAR _ EN LAS FUNCIONES EN LOS .C. FORTRAN LO AGREGA DE PREPO.CHEQUEAR EL USO DE &

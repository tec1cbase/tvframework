 ///////////////////////////////////////////////////////////////////////////
 //                        Trolley Vision NX                               
 //                    static library test README.md                     
 //                       Ubuntu Linux v20.0.4
 //                         Vande Berg Scales
 //////////////////////////////////////////////////////////////////////////

Information on building a static library, 

Building Library - static

gcc -c main.c
gcc -c calc.c
gcc -o main calc.o main.o -lm   or   gcc -o main calc.o main.o /usr/lib/libm.a
 ./main
sqrt(100)=10

 build a new library using ar.
 
 ar crv libcalc.a calc.o

make executable from the library we just built, libcalc.a

 gcc -o main main.o libcalc.a -lm   

or

 gcc -o main main.o -L. -lcalc -lm

./main

sqrt(100)=10


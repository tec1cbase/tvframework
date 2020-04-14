 ///////////////////////////////////////////////////////////////////////////////////
 //                        Trolley Vision NX                               
 //                    static library test main.cpp                       
 //                       Ubuntu Linux v20.0.4
 //                         Vande Berg Scales
 ///////////////////////////////////////////////////////////////////////////////////

// main.cpp
#include <stdio.h>
#include "mylib.h"
int main()
{
        double d = 100;
        printf("sqrt(%3.0f)=%2.0f\n",d,calcSqrt(d));
        return 0;
}



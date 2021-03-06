#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

void main () {
    int i, c ;

    #pragma omp parallel for
    for (i = 0 ; i < 1000000 ; i++) {
	if (i % 2 == 0) {
	    #pragma omp critical (modif_c)
	    c++ ;
	} else {
	    #pragma omp critical (modif_c)
	    c-- ;
	}
    }
    printf ("c = %d\n", c) ;
}

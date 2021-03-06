#include <stdio.h>

#include "banded.h"

int main(void)
{
    int i;
    sf_bands slv;
    float diag[]={2.00020409, 6.05244923, 6.31693888, 6.36918402, 6.3693881, 6.3693881, 6.36918402, 6.31693888, 6.05244923, 2.00020409};
    float offd0[]={-1.99673474, -3.87918353, -3.76163244, -3.75836706, -3.75836706, -3.75836706, -3.76163244, -3.87918353, -1.99673474};
    float offd1[]={1.00734699, 1.05959189, 1.06693888, 1.06693888, 1.06693888, 1.06693888, 1.05959189, 1.00734699};
    float offd2[]={0.00326530659, 0.00653061317, 0.00653061317, 0.00653061317, 0.00653061317, 0.00653061317, 0.00326530659};
    float offd3[]={0.000204081662, 0.000204081662, 0.000204081662, 0.000204081662, 0.000204081662, 0.000204081662};
    float *offd[4];
    float x[]={0.0285714343, 1.50000012, 1.77142882, 2.98571491, 4.00000048, 5.00000048, 5.88571548, 5.04285717, 9.68571472, 9.10000038};
    
    slv = sf_banded_init (10,4);

    offd[0]=offd0;
    offd[1]=offd1;
    offd[2]=offd2;
    offd[3]=offd3;

    sf_banded_define(slv,diag,offd);
    sf_banded_solve(slv,x);
    sf_banded_close(slv);

    for (i=0; i < 10; i++) {
	printf("%g ",x[i]);
    }
    printf("\n");

    return 0;
}
    
/* 	$Id$	 */


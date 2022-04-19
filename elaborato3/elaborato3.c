/*NB: test x=0*/


#include <stdio.h>
#include <stdlib.h> 


// #define EVAL // UNCOMMENT for testing but REMOVE from submission

int main() {
	unsigned int x;
	unsigned int res1=0, res2=0, res3=0;

    //INPUT: x must be the input value, do not overwrite it 
	printf("Enter a positive integer: "); scanf("%u", &x);
	
    //calculate here
    
    // x al contrario
    unsigned int x1 = x;
    while (x1 != 0) {
        res1 *= 10;
        res1 += (x1) % 10;
        x1 /= 10;
    };
    
    // complemento a 10 di x
    unsigned int x2 = x, potenza = 10, i;
    for (i = 0; x2 >= 10; ++i) {
        x2 /= 10;
        potenza *= 10;
    }
    res2 = (potenza) - (x); 
    
    // numero di zeri
    unsigned int x3 = x;
    do {
        if ((x3) % 10 == 0) {
            res3++;
        };
        x3 /= 10;
    } while (x3 != 0);
    

    //do NOT add code after this point
    //OUTPUT
	printf("Actual result:\n");
	printf("%u %u %u\n", res1, res2, res3);
    
    //DON'T REMOVE from submittion
    #ifdef EVAL
        eval(x,res1, res2, res3);
    #endif
	return ;
}
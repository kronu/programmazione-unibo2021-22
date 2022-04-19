#include <math.h>

/* Discriminante > 0 ritorna 2, d == 0 ritorna 1, d < 0 ritorna 0 */
#define NUM_OF_ROOTS(a,b,c) (pow(b, 2) - (4*(a)*(c))) > 0 ? 2 : (pow(b, 2) - (4*(a)*(c))) == 0 ? 1 : 0

/* Trovate le radici/punti di intersezione e distinguere tra il maggiore e minore */
#define RADICE1(a,b,c) ((-(b) + sqrt(pow(b, 2) - (4*(a)*(c))))/(2*(a)))
#define RADICE2(a,b,c) ((-(b) - sqrt(pow(b, 2) - (4*(a)*(c))))/(2*(a)))
#define  ROOT1(a,b,c) (RADICE1(a,b,c)) > (RADICE2(a,b,c)) ? (RADICE1(a,b,c)) : (RADICE2(a,b,c))
#define  ROOT2(a,b,c) (RADICE1(a,b,c)) < (RADICE2(a,b,c)) ? (RADICE1(a,b,c)) : (RADICE2(a,b,c))

/* Calcolare il punto estremo */
#define  EXTREME_POINT(a,b,c) ((-(b))/(2*(a)))

/* Se derivata seconda > 0 allora punto minimo, altrimenti punto massimo */
#define  MAXIMUM_POINT(a,b,c) (2*(a) > 0) ? 0 : 1
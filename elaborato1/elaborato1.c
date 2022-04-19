#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	char c = 'a';
	printf("TYPE: char NAME: c VALUE: %c MIN: %i MAX: %i BYTE: %i\n", c, CHAR_MIN, CHAR_MAX, sizeof(char));
	signed char sc = 'b';
	printf("TYPE: signed char NAME: sc VALUE: %c MIN: %i MAX: %i BYTE: %i\n", sc, SCHAR_MIN, SCHAR_MAX, sizeof(signed char));
	unsigned char uc = 'c';
	printf("TYPE: unsigned char NAME: uc VALUE: %c MIN: 0 MAX: %i BYTE: %i\n", uc, UCHAR_MAX, sizeof(unsigned char));

	short s = 1;
	printf("TYPE: short NAME: s VALUE: %hi MIN: %hi MAX: %hi BYTE: %i\n", s, SHRT_MIN, SHRT_MAX, sizeof(short));
	unsigned short us = 2;
	printf("TYPE: unsigned short NAME: us VALUE: %hu MIN: 0 MAX: %hu BYTE: %i\n", us, USHRT_MAX, sizeof(unsigned short));
	int i = 3;
	printf("TYPE: int NAME: i VALUE: %i MIN: %i MAX: %i BYTE: %i\n", i, INT_MIN, INT_MAX, sizeof(int));
	unsigned int ui = 4;
	printf("TYPE: unsigned int NAME: ui VALUE: %u MIN: 0 MAX: %u BYTE: %i\n", ui, UINT_MAX, sizeof(unsigned int));
	long l = 5;
	printf("TYPE: long NAME: l VALUE: %li MIN: %li MAX: %li BYTE: %i\n", l, LONG_MIN, LONG_MAX, sizeof(long));
	unsigned long ul = 6;
	printf("TYPE: unsigned long NAME: ul VALUE: %lu MIN: 0 MAX: %lu BYTE: %i\n", ul, ULONG_MAX, sizeof(unsigned long));

	float f = 1.1;
	printf("TYPE: float NAME: f VALUE: %f MIN: %f MAX: %f BYTE: %i\n", f, -FLT_MAX, FLT_MAX, sizeof(float));
	double d = 2.2;
	printf("TYPE: double NAME: d VALUE: %lf MIN: %lf MAX: %lf BYTE: %i\n", d, -DBL_MAX, DBL_MAX, sizeof(double));
	long double ld = 3.3;
	printf("TYPE: long double NAME: ld VALUE: %Lf MIN: %Lf MAX: %Lf BYTE: %i\n", ld, -LDBL_MAX, LDBL_MAX, sizeof(long double));

	return 0;
}
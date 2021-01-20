#ifndef __MATRIXMUL_H__
#define __MATRIXMUL_H__

#include <math.h>

// Compare TB vs HW C-model and/or RTL
#define HW_COSIM

#define IN_IMAGE_ROWS 512
#define IN_IMAGE_COLS 512

#define NSplit 8

#define PI 3.1415926535

typedef int mat_image;
typedef int mat_result;

// Prototype of top level function for C-synthesis
void dct(
		mat_image image[IN_IMAGE_ROWS][IN_IMAGE_COLS],
		mat_result result[IN_IMAGE_ROWS][IN_IMAGE_COLS]);

float a(unsigned char i);

#endif // __MATRIXMUL_H__ not defined


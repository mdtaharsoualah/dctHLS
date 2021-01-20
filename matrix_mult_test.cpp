#include <iostream>
#include "matrix_mult.h"

using namespace std;

int main(int argc, char **argv)
{
   mat_image in_image[5][5] = {
      {25, 245, 30, 0, 109},
	  {9, 4, 36, 24, 95},
	  {12, 125, 45, 2, 12},
      {60, 51, 100, 240, 10},
      {105, 16, 75, 43, 85}
   };
   mat_result hw_result[5][5];

   mat_result sw_result[5][5]={
	   { 311,   -4,  -26,  -52,  -45},
	   { -25,   16,   18, -178,  -43},
	   {  57,   12,   57,  -54,   15},
	   {  92,   25,  -79,   16, -110},
	   { -24,   88,   12, -134,   -3}};

   int error_count = 0;

#ifdef HW_COSIM
   // Run the Vivado HLS matrix multiplier
   dct(in_image, hw_result);
#endif

   // Print product matrix
   for (int i = 0; i < IN_IMAGE_ROWS; i++) {
      for (int j = 0; j < IN_IMAGE_COLS; j++) {
#ifdef HW_COSIM
         // Check result of HLS vs. expected
         if (hw_result[i][j] != sw_result[i][j]) {
            error_count++;
         }
#else
         cout << sw_result[i][j];
#endif
      }
   }

#ifdef HW_COSIM
   if (error_count)
      cout << "TEST FAIL: " << error_count << "Results do not match!" << endl;
   else
      cout << "Test passed!" << endl;
#endif
   return error_count;
}


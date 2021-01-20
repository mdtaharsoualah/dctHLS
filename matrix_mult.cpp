
#include "matrix_mult.h"

void dct(
		mat_image image[IN_IMAGE_ROWS][IN_IMAGE_COLS],
		mat_result result[IN_IMAGE_ROWS][IN_IMAGE_COLS])
{
	float constante = 0;
	float accumulateur = 0;
  // Iterate over the rows of the A matrix

Loop1:	 for(int IStart=0; IStart < IN_IMAGE_ROWS; IStart+=NSplit)
	    {
Loop2:	        for(int JStart=0; JStart < IN_IMAGE_COLS; JStart+=NSplit)
	        {
Loop3:	            for(int i=0; i<NSplit; i++)
	            {
Loop4:	                for(int j=0; j<NSplit; j++)
	                {
	                    accumulateur = 0;
	                    constante = (2/(float)NSplit) * a(i) * a(j);
	                    Loop5:	                    for(int k=0; k<NSplit; k++)
	                    {
	                    	float tmp = cosf((2*k+1)*i*PI/(2*NSplit));
Loop6:	                        for(int l=0; l<NSplit; l++)
	                        {
	                            accumulateur += image[k+IStart][l+JStart]*tmp*cosf((2*l+1)*j*PI/(2*NSplit));
	                        }
	                    }
	                    result[IStart+i][JStart+j] = (int)(constante*accumulateur);
	                }
		        }
	        }
	    }

}

float a(unsigned char i)
{
    if(i==0)
        return 1/sqrt(2);
    else
        return 1;
}


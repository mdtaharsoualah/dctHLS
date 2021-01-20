import os

for x in range(10,13):
    os.system(r'vivado_hls -f G:\A2_Part3\FirstHls\hls\run'+str(x)+'.tcl')
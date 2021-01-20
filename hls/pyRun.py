import os
import itertools

tabIndice =  [0, 0, 0, 0]
tmp = [2, 4, 8]
indice=0
for i in range(1,16) :
        nbrIndice = 0
        a= []
        for decalage in range(4) :
            if ((i>>(decalage))&1 != 0) :
                tabIndice[decalage]=decalage+1
                tmpList=[]
                for element in tmp :
                    tmpList.append([decalage+1, element])
                a.append(tmpList)
        a=list(itertools.product(*a))
        for iCombine in a :
            indice+=1
            with open("./Directives.tcl","w") as fileDirective :
                fileDirective.truncate()
                for jCombine in iCombine:
                    strDirective = 'set_directive_unroll -factor ' +str(jCombine[1])+ ' "dct/Loop'+str(jCombine[0])+'" \n'
                    fileDirective.write(strDirective)
            
            os.system(r'vivado_hls -f C:\Users\msouala\Desktop\FirstHls\hls\pyRun.tcl solUnroll'+str(indice))
        




    
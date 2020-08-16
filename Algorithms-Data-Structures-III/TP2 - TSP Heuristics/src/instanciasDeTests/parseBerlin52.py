#!/usr/bin/env python3
import sys
import math

if __name__ == '__main__':
    if len(sys.argv) != 3 :
        print("Uso: programa.py <archivo_in> <archivo_out>")
        exit()

    #Ruta de entrada
    in_path = sys.argv[1]
    #Ruta de salida
    out_path = sys.argv[2]
    
    archivo_in = open(in_path,'r')
    archivo_out = open(out_path,'w')
    n = int(archivo_in.readline())
    
    #Guardo datos en memoria
    matriz = []
    for i in range(n):
        matriz.append(archivo_in.readline().split(' '))
        
    #Cierro archivo entrada
    archivo_in.close()
	    
    #Proceso
    a = n * (n-1) / 2
    archivo_out.write(str(n) + ' ' + str(int(a)) + '\n')
	
    for i in range(n):
        for j in range(i+1, n):		
            l = math.sqrt(pow((float(matriz[i][1]) - float(matriz[j][1])), 2) + pow((float(matriz[i][2]) - float(matriz[j][2])), 2))
            archivo_out.write(str(i+1) + ' ' + str(j+1) + ' ' + str(round(l, 5)) + '\n')
	
    #Cierro archivo salida
    archivo_out.close()
    
    print('Listo')

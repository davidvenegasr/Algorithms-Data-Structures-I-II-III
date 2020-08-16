# Algo3-TP2 // 2020 1er Cuatrimestre (Virtual)

## Modo de uso
### **Compilacion**:
Solo se necesita estar en el directorio del proyecto y ejecutar:
```
make
```	

### **Uso del programa**:
El programa esta listo para ser ejecutado
```
./tsp [heuristica] <maxiter> <maxiter-sm> <maxtime> <memsize> <porc>
```
Donde el campo heuristica debe ser llamado con alguno de los siguientes parametros
|Valor| Heuristica|
|-----|-----------|
|H1 | Heuristica del vecino mas cercao|
|H2 | Heuristica de la arista mas corta|
|HAGM | Heuristica del arbol generador minimo |
|METAH1 | Metaheuristicas Tabu-search con memoria basada en circuitos| 
|METAH2 | Metaheuristicas Tabu-search con memoria basada en estructura (aristas)|

Los valores del tipo `<parametro>` solo sirven para las metaheuristicas, donde a continuacion se describe como usarse:
|Valor| Parametro| Default*|
|-----|----------|--------|
|maxiter | Maximas iteraciones para tabu-search|100000|
|maxiter-sm|Maximas iteraciones sin mejora para tabu-search|10000|
|maxtime|Maximo tiempo antes de terminar tabu-search**|30000|
|memsize|Largo de memoria para tabuSearch|50|
|porc|Porcentaje de vecindad (de 0 a 1)|0.1|

`* OBS: si no se ejecuta con los parametros se ejecutara con los valores por defecto`

`** OBS: si esta en 0 se desactiva el parametro`

### Especificaciones de entrada y salida del programa
- Recibe por parámetro qué algoritmos utilizar para la ejecución separados por espacios.
- Imprime por `clog` la información de ejecución de los algoritmos.
- Imprime por `cout` el resultado de algun algoritmo ejecutado.
import random, math
import pandas as pd

def save_instance(dataset, instance_name, S, W):
    with open(F"instancias/{dataset}/{instance_name}.txt", "w+") as f:
        print(len(S), W, file=f)
        for s in S:
            print(s, file=f, end=" ")

def save_index(dataset, instances):
    with open(F"instancias/{dataset}/instances.txt", "w+") as f:
        for instance in instances:
            print(instance, file=f)

filas_indice = []
for i in range(1, 1001):
    n = i * 10
    W = 1000
    S = [1 for i in range(0, n)]
    S[-1] = W
    save_instance("mejor-caso-BT", F"BT-MC-{n}", S, W)
    filas_indice.append(["mejor-caso-BT", F"BT-MC-{n}", n, W, F"instancias/mejor-caso-BT/BT-MC-{n}.txt"])
pd.DataFrame(filas_indice, columns=["dataset", "instancia", "n", "W", "archivo"]).to_csv("instancias/mejor-caso-BT/indice.csv", index=False, header=True)



import matplotlib.pyplot as mtplt
import random as rnd

f = open('solucion')

f = f.readlines()

n,m = map(int,f[0].split())

conv = []
pts = []

for i in xrange(n):
  conv.append(map(float,f[i+1].split()))

for i in xrange(m):
  pts.append(tuple(map(float,f[i+n+1].split())))
    


a = conv[0][0]
b = conv[0][1]
fa = a
fb = b

for i in xrange(n-1):
  c = conv[i+1][0]
  d = conv[i+1][1]
  x = [a,c]
  y = [b,d]
  mtplt.plot(x,y,'ro-')
  a = c
  b = d

x = [fa, a]
y = [fb, b]
mtplt.plot(x,y,'ro-')


x = []
y = []
for p in pts:
  x.append(p[0])
  y.append(p[1])
  
mtplt.plot(x,y,'*')
mtplt.figure()
mtplt.plot(x,y,'*')

mtplt.show()



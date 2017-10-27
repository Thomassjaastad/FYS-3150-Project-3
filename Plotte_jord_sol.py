from __future__ import division
from matplotlib.pyplot import *
from numpy import *


file = open("/Users/thomassjastad/Desktop/build-SolarSystem-Desktop_Qt_5_9_1_clang_64bit-Debug/positions.txt", "r")

x = []
y = []
z = []
E = []
ang_mom = []
for line in file:
	words = line.split()
	x.append(float(words[0]))
	y.append(float(words[1]))
	z.append(float(words[2]))


pos_jordx = []
pos_jordy = [] 
pos_jupx = []
pos_jupy = []


f = 0
for i in range(len(x)):
	f += 1
	if f % 3 == 0:
		pos_jupx.append(float(x[i]))
		pos_jupy.append(float(y[i]))

d = 0
for i in range(len(x)):
	d += 1
	if d % 3 == 0:
		pos_jordx.append(float(x[i]))
		pos_jordy.append(float(y[i]))

#print pos_jordx
phi = linspace(0,2*pi, len(pos_jordx))
r = sqrt(2)/200
x = r*cos(phi)
y = r*sin(phi)

plot(x,y, label = 'Sun', color ='r')
hold('on')
plot(pos_jordx, pos_jordy, label = 'Earth')
#hold('on')
#plot(pos_jupx, pos_jupy, label = 'Jupiter')
xlabel('$x [AU]$', fontsize = 30)
ylabel('$y [AU]$', fontsize = 30)
title('$Gravitational$ $force$ $1/r^{2.5}$', fontsize = 24)	
legend()
show()
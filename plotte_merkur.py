from __future__ import division
from matplotlib.pyplot import *
from numpy import *


file = open("/Users/thomassjastad/Desktop/build-SolarSystem-Desktop_Qt_5_9_1_clang_64bit-Debug/positions_mercury.txt", "r")

x = []
y = []
z = []

for line in file:
	words = line.split()
	x.append(float(words[0]))
	y.append(float(words[1]))
	z.append(float(words[2]))
	#E.append(float(words[3]))
	#ang_mom.append(float(words[4]))
pos_merkurx = []
pos_merkury = []

d = 0
for i in range(len(x)):
	d += 1
	if d % 2 == 0:
		pos_merkurx.append(float(x[i]))
		pos_merkury.append(float(y[i]))

#Suuuul
phi = linspace(0,2*pi, len(pos_merkurx))
r = sqrt(2)/200
x = r*cos(phi)
y = r*sin(phi)	


#print pos_merkurx
plot(x,y, label = 'Sun')
hold('on')
plot(pos_merkurx, pos_merkury, label = 'Mercury')
legend()
show()



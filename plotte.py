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
	#E.append(float(words[3]))
	#ang_mom.append(float(words[4]))
pos_jordx = [] 
pos_jordy = []
pos_jordz = []
pos_jupx = []
pos_jupy = []
pos_jupz = []
count = 0
for i in range(len(x)):
	count += 1
	if count % 3 == 0:
		pos_jupx.append(float(x[i]))
		pos_jupy.append(float(y[i]))	

s = 1
for i in range(len(x)):
	s += 1
	if s % 3 == 0:
		pos_jordx.append(float(x[i]))
		pos_jordy.append(float(y[i]))

#print pos_jupx


phi = linspace(0,2*pi, len(pos_jordx))
r = sqrt(2)/200
x = r*cos(phi)
y = r*sin(phi)	



#print ang_mom


plot(pos_jordx, pos_jordy, label = 'Earth')
hold('on')
plot(x,y, color = 'r', label = 'Sun')
hold('on')
plot(pos_jupx, pos_jupy, label = 'Jupiter')
xlabel('$x[AU]$', fontsize = 18)
ylabel('$y[AU]$', fontsize = 18)
title('Solar system')
legend()
show()

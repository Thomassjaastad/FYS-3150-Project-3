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
pos_marsx = []
pos_marsy = []
pos_marsz = []
pos_venusx = []
pos_venusy = []
pos_venusz = []
pos_saturnx = []
pos_saturny = []
pos_saturnz = []
pos_uranusx = []
pos_uranusy = []
pos_uranusz = []
pos_mercuryx = []
pos_mercuryy = []
pos_mercuryz = []
pos_plutox = []
pos_plutoy = []
pos_neptunx = []
pos_neptuny = []

#Too much code!


d = 0
for i in range(len(x)):
	d += 1
	if d % 10 == 0:
		pos_plutox.append(float(x[i]))
		pos_plutoy.append(float(y[i]))	


g = 1
for i in range(len(x)):
	g += 1
	if g % 10 == 0:
		pos_neptunx.append(float(x[i]))
		pos_neptuny.append(float(y[i]))	


b = 2
for i in range(len(x)):
	b += 1
	if b % 10 == 0:
		pos_uranusx.append(float(x[i]))
		pos_uranusy.append(float(y[i]))	


a = 3
for i in range(len(x)):
	a += 1
	if a % 10 == 0:
		pos_mercuryx.append(float(x[i]))
		pos_mercuryy.append(float(y[i]))	


c = 4
for i in range(len(x)):
	c += 1
	if c % 10 == 0:
		pos_saturnx.append(float(x[i]))
		pos_saturny.append(float(y[i]))	

count = 5
for i in range(len(x)):
	count += 1
	if count % 10 == 0:
		pos_venusx.append(float(x[i]))
		pos_venusy.append(float(y[i]))	

s = 6
for i in range(len(x)):
	s += 1
	if s % 10 == 0:
		pos_marsx.append(float(x[i]))
		pos_marsy.append(float(y[i]))

t = 7
for i in range(len(x)):
	t += 1
	if t % 10 == 0:
		pos_jupx.append(float(x[i]))
		pos_jupy.append(float(y[i]))

f = 8
for i in range(len(x)):
	f += 1
	if f % 10 == 0:
		pos_jordx.append(float(x[i]))
		pos_jordy.append(float(y[i]))


#print pos_jordx


phi = linspace(0,2*pi, len(pos_jordx))
r = sqrt(2)/200
x = r*cos(phi)
y = r*sin(phi)	



#print ang_mom


plot(pos_jordx, pos_jordy, label = 'Earth')
hold('on')
plot(x,y, label = 'Sun')
hold('on')
plot(pos_jupx, pos_jupy, label = 'Jupiter')
hold('on')
plot(pos_venusx, pos_venusy, label = 'Venus')
hold('on')
plot(pos_saturnx, pos_saturny, label = 'Saturn')
hold('on')
plot(pos_mercuryx, pos_mercuryy, label = 'Mercury')
hold('on')
plot(pos_uranusx, pos_uranusy, label = 'Uranus')
hold('on')
plot(pos_neptunx, pos_neptuny, label = 'Neptun')
hold('on')
plot(pos_plutox, pos_plutoy, label = 'Pluto')
hold('on')
plot(pos_marsx, pos_marsy, label = 'Mars')
xlabel('$x[AU]$', fontsize = 18)
ylabel('$y[AU]$', fontsize = 18)
title('$Solar system$', fontsize = 20)
legend()
show()

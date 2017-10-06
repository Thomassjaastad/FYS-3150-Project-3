from __future__ import division
from matplotlib.pyplot import *
from numpy import *


file = open("positions.txt", "r")

x = []
y = []
z = []
E = []
for line in file:
	words = line.split()
	x.append(float(words[0]))
	y.append(float(words[1]))
	z.append(float(words[2]))
	E.append(float(words[3]))

pos_jordx = []
pos_jordy = []
pos_jordz = []
count = 0
for i in range(len(x)):
	count += 1
	if count % 2 == 0:
		pos_jordx.append(float(x[i]))
		pos_jordy.append(float(y[i]))	

print E

plot(pos_jordx, pos_jordy)
xlabel('$x[AU]$', fontsize = 18)
ylabel('$y[AU]$', fontsize = 18)
show()

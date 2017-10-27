from __future__ import division
from matplotlib.pyplot import *
from numpy import *


file = open("/Users/thomassjastad/Desktop/build-SolarSystem-Desktop_Qt_5_9_1_clang_64bit-Debug/Merkurvinkel.txt", "r")
file_new = open("/Users/thomassjastad/Desktop/build-SolarSystem-Desktop_Qt_5_9_1_clang_64bit-Debug/Merkurvinkel_newton.txt", "r")
yr = []
angl = []
pos = []

for line in file:
	words = line.split()
	yr.append(float(words[0]))
	angl.append(float(words[1]))

angl_newt = []

angl_newt_deg = array(angl_newt)*57

angl_deg = array(angl)*57

for line in file_new:
	words = line.split()
	angl_newt.append(float(words[1]))
plot(yr, angl_deg)
hold('on')
plot(yr, angl_newt)
ylabel('degrees')
xlabel('Mercury years')
show()
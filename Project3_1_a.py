#AST-1100 Oppgave 1.B7
from __future__ import division
from matplotlib.pyplot import *
import numpy as np

#Oppgave b
AU = 149597871000      #1 AU in Meters
sun_mass = 2E30        #Sun mass in kg

G = 4*np.pi**2
#steg_aar = 100
#t = 60
#N = t*steg_aar
#dt = t/float(N-1)


dt = 0.001
N = int(1E3)

m_sun = 1
#m_earth = 6E24/2e30
 
x = np.zeros(N)
y = np.zeros(N)

vx = np.zeros(N)
vy = np.zeros(N)


x[0] = 1
y[0] = 0

vx[0] = 0
vy[0] = 2*np.pi



def Grav_earth(x,y):
	r = 1
	F_x = -G*m_sun*x/r**3
	F_y = -G*m_sun*y/r**3
	return F_x , F_y, r

#Euler-cromer
#for i in range(N-1):
#	F_x, F_y, r = Grav_earth(x[i],y[i]) 
#	vx[i+1] = vx[i] + F_x*dt  			#F_x = ax
#	vy[i+1] = vy[i] + F_y*dt			#F_y =ay
#	x[i+1] = x[i] + vx[i+1]*dt
#	y[i+1] = y[i] + vy[i+1]*dt

#VelocityVerlet
for i in range(N-1):
	F_x, F_y, r = Grav_earth(x[i], y[i])
	x[i+1] = x[i] + vx[i]*dt + 0.5*F_x*dt**2
	y[i+1] = y[i] + vy[i]*dt + 0.5*F_y*dt**2

	vx[i+1] = vx[i] + F_x*dt
	vy[i+1] = vy[i] + F_y*dt

plot(x,y)
show()



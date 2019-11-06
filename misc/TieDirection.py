from sympy import *

init_printing()
d0, d1, d2 = symbols('d_0 d_1 d_2')

D = Matrix([d0,d1,d2])
Z = Matrix([0,0,1])

pprint(D)
pprint(Z)
L = Z.cross(D)
L=L/sqrt(L.dot(L))
pprint(L)

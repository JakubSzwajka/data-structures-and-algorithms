import utils 
import city
import route
from ant import Ant
from operator import itemgetter
from string import ascii_uppercase
import networkx as nx
import matplotlib.pyplot as plt


# punkt startowy ze wzgledu na numer indeksu 3 – B
A = [1,2,'A']
B = [3,1,'B']
C = [3,6,'C']
D = [6,7,'D']
E = [5,2,'E']

nodes = [A,B,C,D,E]

ants = []
cities = []
numerator = 1
mem = []
shortest_way = []
shortest_distance = 0.0
shortest_iterator = 1
distances = []
storage = []

for node in nodes:    
    cities.append( city.City(node[2] , node[0], node[1] ))
    numerator += 1

for city in cities: 
    city.add_cities( cities )

for i in range(1000):
    ants.append( Ant( cities ))

#####################################################################

for ant in ants:
    ant.set_cities(cities)
    ant.run()
    cities = ant.return_cities()
    mem , distance = ant.get_memory( )
    # print('memory: ',mem, '    distance: ', distance)

    utils.pheromone_leak(cities)

    for city in cities:
        city.reset() # set the city as not visited yet
    
    storage.append(distance)

    if distance <= shortest_distance or shortest_distance == 0:
        shortest_distance = distance
        shortest_way.append(mem)
        if distance == shortest_distance:
            shortest_iterator += 1
    
    
for item in storage:
    setter = [ item , storage.count(item)]
    if setter not in distances:
        distances.append(setter)

print( '===========')
print( 'Shortest distnce:', shortest_distance , 'Times: ' , shortest_iterator)
print( 'Shortest path: ' , mem )
print( 'Begin nodes: ', nodes)
print( '===========')

distances.sort()    
for dist in distances:
    print(dist)


############################################################################

x = []
y = []

for node in mem:
    for nod in nodes:
        if nod[2] == node:
            x.append(nod[0])
            y.append(nod[1])

plt.plot(x,y,'-or')
plt.show()

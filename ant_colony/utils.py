
import math
import networkx as nx
import matplotlib.pyplot as plt


def count_distance( point_a, point_b):
    if point_a == point_b:
        return float(1) 
    else:
        distance = float(math.sqrt( pow(point_b.y - point_a.y , 2 ) + pow( point_b.x - point_a.x , 2))) 
        # print (distance)
        return distance

def sum_pheromone(city_from , city_to ):
    pheromone = 0
    for city in city_from.my_cities:
        if city[0] == city_to:
            pheromone += city[1]

    for city in city_to.my_cities:
        if city[0] == city_from:
            pheromone += city[1]

    return pheromone

def pheromone_leak(cities):

    for city in cities: 
        for cit in city.my_cities:
            cit[1] = cit[1] * 0.7 #pheromone leak 


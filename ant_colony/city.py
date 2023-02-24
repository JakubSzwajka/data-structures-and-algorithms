

class City( ):
    def __init__(self, ind, x , y):
        self.index = ind
        self.x = x
        self.y = y 
        self.my_cities = []
        self.visited = False

    def add_cities( self, cities):
        for city in cities:
            if city.index != self.index:
                route = [city , 1000 ] # 1000 is pheromone 
                self.my_cities.append( route )

    def set_pheromone_to_city(self, city_to, phermonoe ):
        for city in self.my_cities:
            if city[0] == city_to:
                city[1] += phermonoe

    def reset(self):
        self.visited = False 
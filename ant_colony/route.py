

class Route( ):
    def __init__(self, city_from, city_to ):
        self.cityA = city_from
        self.cityB = city_to
        self.distance = 0
        self.pheromone = 0 
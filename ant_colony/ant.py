
import utils
import random
import city
import numpy

class Ant( ):
    def __init__ (self, nodes):
        self.not_visited_locations = []
        self.all_loc_visited = False
        self.distance_travelled = 0.0
        self.route = nodes
        self.current_location = numpy.random.choice(self.route) #self.route[0]
        self.start_location = self.route.index(self.current_location)
        self.next_location = self.route[self.start_location]
        self.alpha = .5
        self.beta = 1.2 #1.2
        self.memory = []
        
    def run(self):
        self.not_visited_locations = self.route
        
        while True:
            self.current_location.visited = True
            self.memory.append(self.current_location.index)
            self.next_location = self.find_path( )
            if self.all_loc_visited == True or self.next_location == None:
                self.go_to( self.current_location, self.route[self.start_location] )
                self.memory.append(self.current_location.index)
                break

            if self.current_location != self.next_location:
                self.go_to( self.current_location , self.next_location)  

    def find_path(self):

        attractiveness = dict()
        sum_total = 0.0
        for possible_next_location in self.not_visited_locations:
            if possible_next_location.visited == False:
                pheromone_amount = float(utils.sum_pheromone(possible_next_location , self.current_location))
                distance = float(utils.count_distance(possible_next_location , self.current_location))
                
                attractiveness[possible_next_location] = pow(pheromone_amount, self.alpha)*pow(1/distance, self.beta)
                sum_total += attractiveness[possible_next_location]
        
        import random
        toss = random.random()
        
        cummulative = 0
        
        self.all_loc_visited = True
        for possible_next_location in attractiveness:
            if possible_next_location.visited == False:
                self.all_loc_visited = False
                weight = (attractiveness[possible_next_location] / sum_total)
                if toss <= weight + cummulative:
                    return possible_next_location
                cummulative += weight
    

    def go_to(self, current_location , next_location):
        self.distance_travelled = self.distance_travelled + utils.count_distance( current_location, next_location)
        self.current_location.set_pheromone_to_city(next_location , 1000 / utils.count_distance( current_location, next_location))
        self.current_location.visited = True
        self.current_location = next_location
        

    def return_cities(self):
        return self.route

    def set_cities(self, cities):
        self.route = cities

    def get_memory(self):
        return self.memory, self.distance_travelled


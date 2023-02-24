import pygame

import Settings as set 

class Base: 
    VEL = 5
    WIDTH = set.BASE_IMG.get_width()
    IMG = set.BASE_IMG

    def __init__(self, y):
        self.y = y 
        self.x1 = 0 
        self.x2 = self.WIDTH

    def move(self):
        self.x1 -= self.VEL
        self.x2 -= self.VEL

        if self.x1 + self.WIDTH < 0:
            self.x1 = self.x2 + self.WIDTH

        if self.x2 + self.WIDTH < 0:
            self.x2 = self.x1 + self.WIDTH

    def draw(self, win):
        win.blit(self.IMG, (self.x1, self.y))
        win.blit(self.IMG, (self.x2, self.y))
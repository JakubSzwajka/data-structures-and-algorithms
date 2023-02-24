import pygame 
import neat 
import time 
import os 
import random 
import pygame

import Settings as set 
from Bird import Bird
from Base import Base
from Pipe import Pipe

def draw_window(win, birds, pipes, base, score):
    win.blit(set.BG_IMG, (0,0))

    for pipe in pipes:
        pipe.draw(win)

    text = set.STAT_FONT.render("Score: " + str(score), 1,(255,255,255) )
    win.blit(text, (set.WIN_WIDTH - 10 - text.get_width(), 10 ))

    birds_quant = set.STAT_FONT.render("Birds: " + str(len(birds)), 1,(255,255,255))
    win.blit(birds_quant, (10,10))

    base.draw(win)

    for bird in birds:
        bird.draw(win)

    pygame.display.update()

def main(genomes, config):

    nets = []
    ge = []
    birds = []

    for _, g in genomes:
        net = neat.nn.FeedForwardNetwork.create(g,config)
        nets.append(net)
        birds.append(Bird(230,350))
        g.fitness = 0 
        ge.append(g)
        
    score = 0
    base = Base(730)
    pipes = [Pipe(700)]

    win = pygame.display.set_mode((set.WIN_WIDTH, set.WIN_HEIGHT))
    clock = pygame.time.Clock()
    run = True


    while run:
        clock.tick(30)

        for event in pygame.event.get():
            if event.type == pygame.QUIT: 
                run = False
                pygame.quit()
                quit()

        pipe_ind = 0

        if len(birds) > 0:
            if len(pipes) > 1 and birds[0].x > pipes[0].x + pipes[0].PIPE_TOP.get_width():
                pipe_ind = 1
        else:
            print("no birds")
            run - False
            break

        for x, bird in enumerate(birds):
            bird.move()
            ge[x].fitness += 0.1 

            output = nets[x].activate((bird.y, abs(bird.y - pipes[pipe_ind].height),
                                            abs(bird.y - pipes[pipe_ind].bottom)))

            if output[0] > 0.5:
                bird.jump()

        add_pipe = False
        rem = []
        for pipe in pipes:
            for x, bird in enumerate(birds):
                if pipe.collide(bird): 
                    ge[x].fitness -= 1 
                    birds.pop(x)
                    nets.pop(x)
                    ge.pop(x)

                if not pipe.passed and pipe.x < bird.x:
                    pipe.passed = True
                    add_pipe = True

            if pipe.x + pipe.PIPE_TOP.get_width() < 0:
                rem.append(pipe)

            pipe.move()

        if add_pipe: 
            score += 1 
            pipes.append(Pipe(700))
            
            for g in ge:
                g.fitness += 5

        for r in rem:
            pipes.remove(r)

        for x, bird in enumerate(birds):
            if bird.y >= 730 or bird.y < 0:
                birds.pop(x)
                nets.pop(x)
                ge.pop(x)  
        
        draw_window(win, birds, pipes, base, score)
    

def run(config_path):
    config = neat.config.Config(neat.DefaultGenome, 
                                neat.DefaultReproduction,
                                neat.DefaultSpeciesSet, 
                                neat.DefaultStagnation, 
                                config_path)    

    p = neat.Population(config)
    p.add_reporter(neat.StdOutReporter(True))
    stats = neat.StatisticsReporter()
    p.add_reporter(stats)

    winner = p.run(main,50)
    print(winner)

if __name__ == "__main__":
    local_dir = os.path.dirname(__file__)
    config_path = os.path.join(local_dir, "config-feedforward.txt")
    run(config_path)
    
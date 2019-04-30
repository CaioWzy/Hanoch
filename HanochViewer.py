#!/usr/bin/python3

import pygame
from pygame import Color
from enum import Enum
from random import randint
import re
import sys

size = width, height = [1024, 640]
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Hanoch")

clock = pygame.time.Clock()

class Colors(Enum):
    WHITE = (255,255,255)
    BLACK = (0, 0, 0)

def gera_cor_aleatoria():
    return tuple([randint(0, 255) for i in range (0, 4)])

class Rect(pygame.Rect):

    def __init__(self, left, top, width, height, color=None):
        self.color = color or Colors.BLACK.value
        
        super().__init__(left, top, width, height)
        
    def arrasta(self, left, top):
        self.move_ip(left - self.left,
                     top - self.top)
        
    def desenha(self):
        pygame.draw.rect(pygame.display.get_surface(),
                         self.color, self)


class Torre(Rect):

    def __init__(self, n):
        self.discos = []
        self.n = n
        self.width = 5
        self.top = 40
        self.height = height - self.top
        self.left = ((1024 / 4) * self.n) - (self.width / 2) 
        
        super().__init__(self.left, self.top, self.width, self.height)

    def empilha_disco(self, d):
        d.move_para_torre(self)
        self.discos.append(d)
    
    def desempilha_disco(self):
        if (self.discos):
            return self.discos.pop()
        return


class Disco(Rect):

    def __init__(self, peso):
        self.peso = peso
        self.width = (200 * self.peso) / 16
        self.height = 20
        self.color = gera_cor_aleatoria()
        
        super().__init__(0, 0, self.width, self.height, self.color)
    
    def move_para_torre(self, torre):
        pos_x = ((width / 4) * torre.n) - (self.width / 2)
        pos_y = height - (self.height * (len(torre.discos) + 1))
        self.arrasta(pos_x, pos_y)
        self.desenha()


def coloca_ndiscos(torre, ndiscos):
    for i in range(ndiscos, 1 - 1, -1):
            d = Disco(i)
            torre.empilha_disco(d)

def move_disco(origem, destino):
    disco = origem.desempilha_disco()
    if disco:
        destino.empilha_disco(disco)

def quit_on_close():
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()
            
def run():
    torres = [Torre(i) for i in range(1, 3 + 1)]
    move_pattern = re.compile("(A|B|C) (->|<-) (A|B|C)")
    for line in sys.stdin:
        quit_on_close()   
        if 'DISCOS:' in line:
            ndiscos = int(line.split()[1])
            coloca_ndiscos(torres[0], ndiscos)
        else:
            m = move_pattern.search(line)
            if m:
                origem = direcao = destino = 0
                
                if m.group(1) == 'A':
                   origem = 0
                elif m.group(1) == 'B':
                    origem = 1
                else:
                    origem = 2

                if m.group(2) == '->':
                   direcao = 1
                else:
                   direcao = -1
                    
                if m.group(3) == 'A':
                    destino = 0
                elif m.group(3) == 'B':
                    destino = 1
                else:
                    destino = 2
                    
                if direcao == 1:
                    move_disco(torres[origem],
                               torres[destino])
                else:
                    move_disco(torres[destino],
                               torres[origem])

        screen.fill(Colors.WHITE.value)
        
        for torre in torres:
            torre.desenha()
            for disco in torre.discos:
                disco.desenha()
        pygame.display.update()
        pygame.display.flip()
        #clock.tick(2)
        
    while True:
        quit_on_close()
        clock.tick(1)
    
if __name__ == '__main__':
    run()
 
            
            
            
            

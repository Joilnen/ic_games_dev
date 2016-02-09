import pygame, sys, time
from random import randint
from pygame.locals import *
pygame.init() #Inicialize pygame

#CONSTANTS
###############
#Window size
width = 480
height = 480
#Set up Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
#################
#default move 
addX=16
addY=0

class Snake():
    #Constructor
    def __init__(self):
        self.image= pygame.image.load("sn.png")
        self.x = 32
        self.y = 32
    #Functions
    def move(self, x, y):
        global width, height
        if x > 0: 
            if self.x + 16 < width:
                self.x += x
        else:
            if self.x > 0:
                self.x +=x
        if y > 0: 
            if self.y + 16 < height:
                self.y += y
        else:
            if self.y > 0:
                self.y +=y

    def draw(self, window):
        window.blit(self.image, (self.x, self.y))

    def key_handle(self):
        global addX, addY
        k = pygame.key.get_pressed()
        if k[K_UP]:
            addX = 0
            addY = -16
        elif k[K_DOWN]:
            addX = 0
            addY = 16
        elif k[K_LEFT]:
            addX = -16
            addY = 0 
        elif k[K_RIGHT]:
            addX = 16
            addY = 0

class Body():
    def __init__(self, head):
        self.image= pygame.image.load("sn.png")
        self.x = -16
        self.y = 0
        self.headx = head.x
        self.heady = head.y

    def follow(self, head):
        #print "x", head.x, "y", head.y
        if head.x != self.headx or head.y != self.heady:
            self.x = self.headx
            self.y = self.heady
            self.headx = head.x
            self.heady = head.y

    def draw(self, window):
        window.blit(self.image, (self.x, self.y)) 
        
class Point():
    #Constructor
    def __init__(self):
        global width, height
        self.image = pygame.image.load("point.png")
        self.x = randint(0, width - 16 )
        self.y = randint(0, height - 16 )
    #functions
    def changePosition(self):
        global width, height
        self.x = randint(0, width - 16)
        self.y = randint(0, height - 16)

    def draw(self, window):
        window.blit(self.image, (self.x, self.y))

    def collision(self, x1,y1,w1,h1):
      return x1 < self.x+16 and self.x < x1+w1 and y1 < self.y+16 and self.y < y1+h1
        
class ScoreBoard():
    def __init__(self, window):
        global WHITE, BLACK
        self.score = 0
        self.basicFont = pygame.font.SysFont(None, 18)
        self.text = self.basicFont.render('Score: ' + str(self.score), True, WHITE)
        self.textRect = self.text.get_rect()
        window.blit(self.text, (0,0))

    def draw(self, window):
        self.text = self.basicFont.render('Score: ' + str(self.score), True, WHITE)
        window.blit(self.text, self.textRect)
    

#Opening a Window
size = (width , height)
window = pygame.display.set_mode(size) 
pygame.display.set_caption("Snake v1.0")

#Background will be BLACK
window.fill(BLACK) 

#Creating the snake
snake_body = []
sn = Snake()
sn.draw(window)
snake_body.append(sn)

#Creating the point
p = Point()
p.draw(window)

#Creating a Score Board
scr = ScoreBoard(window)


pygame.display.update() #Update window


#Main loop of the Window
#clock = pygame.time.Clock()
while True:
    for event in pygame.event.get(): #User did something 
        if event.type == QUIT: #Should close when you pressed X button
            pygame.quit()
            sys.exit()
    sn.key_handle()
    snake_body[0].move(addX, addY) #Still head movement    
    for i in range(1, len(snake_body)): #Body have to follow the foward one.
        snake_body[i].follow(snake_body[i-1])
            
    if p.collision(sn.x, sn.y, 16, 16): #If the snake takes the point change it of place
        p.changePosition()
        scr.score += 1 #changing the score
        snake_size = len(snake_body) 
        snake_body.append(Body( snake_body[snake_size - 1] )) #Add a new body part

    window.fill(BLACK) #Background will be black
    
    #Redraw the objects
    for i in range(0, len(snake_body)):
        snake_body[i].draw(window)
    p.draw(window)
    scr.draw(window)
    
    pygame.display.update() #Update window
    time.sleep(0.5) #Limit of 60 frames per second

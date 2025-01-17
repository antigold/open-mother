import pygame, ommfile

placeholderImage = pygame.image.load("assets/placeholder.png")
select = pygame.image.load("assets/select.png")

pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()

def drawOnGrid(coord,image=placeholderImage, resize=True): 
    x = coord[0]
    y = coord[1]
    blockSize = 60
    gridX = (x-1) * blockSize
    gridY = (y-1) * blockSize
    
    if resize:
        image60 = pygame.transform.scale(image, (blockSize, blockSize))
        screen.blit(image60,(gridX,gridY))
    else:
        screen.blit(image,(gridX,gridY))

def cleanup():
    for i in range(len(tiles)): #checks if theres a tile already, if yes, then replace it instead of overlapping it, will be good for optimization
        if tiles[i-1].x == mousepos[0] and tiles[i-1].y == mousepos[1]:
            tiles.pop(i-1)

class Tile():
    def __init__(self, x, y, texture="placeholderImage"):
        self.x = x
        self.y = y
        self.texture = texture
    
    def render(self):
        drawOnGrid([self.x,self.y], self.texture)

tiles = []

# for i in range(10):
#     for j in range(15):
#         tiles.append(Tile(j,i,placeholderImage))

running = True

while running:
    for event in pygame.event.get():
            mousepos = [(pygame.mouse.get_pos()[0]//60)+1,(pygame.mouse.get_pos()[1]//60)+1]
            if event.type == pygame.QUIT:
                running = False
            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:
                    ommfile.savefile(tiles)
                    print("\nsaved map!!!!! hi ico")

            mouse_buttons = pygame.mouse.get_pressed()
            if mouse_buttons[0]:  #left mouse button is pressed
                cleanup()
                tiles.append(Tile(mousepos[0],mousepos[1],placeholderImage))
                
            if mouse_buttons[2]: #right click, delete tile
                for i in range(len(tiles)): #checks if theres a tile already, if yes, then replace it instead of overlapping it, will be good for optimization
                    if tiles[i-1].x == mousepos[0] and tiles[i-1].y == mousepos[1]:
                        tiles.pop(i-1)


    screen.fill((30, 30, 30))

    for tile in tiles:
        tile.render()

    drawOnGrid([int((pygame.mouse.get_pos()[0]/60)+1),
    int((pygame.mouse.get_pos()[1]/60)+1)], select)

    clock.tick()
    print(f"CURRENT FPS : {clock.get_fps()}",end="\r")
    pygame.display.flip()

pygame.quit()

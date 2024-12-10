import pygame

placeholderImage = pygame.image.load("assets/placeholder.png")

pygame.init()
screen = pygame.display.set_mode((1280, 720))

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

running = True

while running:
    for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                    print("clicks")

    screen.fill("black")

    drawOnGrid([int((pygame.mouse.get_pos()[0]/60)+1),
    int((pygame.mouse.get_pos()[1]/60)+1)])

    pygame.display.flip()



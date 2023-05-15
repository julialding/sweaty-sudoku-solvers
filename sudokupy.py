import pygame
import sys
pygame.init()

board_height = 450
board_width = 450
screen = pygame.display.set_mode((800, 450))
pygame.display.set_caption("SUDOKU")

font_title = pygame.font.Font('freesansbold.ttf', 32)
title = font_title.render("Sudoku!", True, (255, 255, 255))
title_coor = (550, 100)

x_cursor = 0
y_cursor = 0

def grid():
    blockSize = board_height//9
    for i in range(0, board_height, blockSize):
        for k in range(0, board_width, blockSize):
            if ((150<=i<=250) ^ (150<=k<=250)):
                color = (150, 150, 150)
            else:
                color = (0, 0, 0)

            cell = pygame.Rect(i, k, blockSize, blockSize)
            pygame.draw.rect(screen, color, cell)
            pygame.draw.rect(screen, (250, 250, 250), cell, width = 1)
            if cell.collidepoint(x_cursor,y_cursor):
                hover_highlight()


def hover_highlight():
    white = (255, 255, 255)
    if (x_cursor<=450):
        cell = pygame.Rect(x_cursor//50*50, y_cursor//50*50, 50, 50)
        pygame.draw.rect(screen, white, cell)


def update_xcor():
    x = pygame.mouse.get_pos()[0]
    return x

def update_ycor():
    y = pygame.mouse.get_pos()[1]
    return y

while True:
    screen.blit(title, title_coor)

    for event in pygame.event.get():
        grid()
        x_cursor = update_xcor()
        y_cursor = update_ycor()


        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    pygame.display.update()
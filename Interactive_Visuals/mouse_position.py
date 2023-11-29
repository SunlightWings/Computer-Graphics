import pygame

# Initialize Pygame
pygame.init()

# Set up display
screen = pygame.display.set_mode((400, 400))
pygame.display.set_caption('Cursor Tracker')

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Get cursor position
    cursor_position = pygame.mouse.get_pos()

    # Clear the screen
    screen.fill((255, 255, 255))

    # Draw cursor position on the screen
    font = pygame.font.Font(None, 36)
    text = font.render(f'Cursor Position: {cursor_position}', True, (0, 0, 0))
    screen.blit(text, (50, 50))

    # Update the display
    pygame.display.flip()

# Quit Pygame
pygame.quit()


# check this code later to see if it runs, i created this file here

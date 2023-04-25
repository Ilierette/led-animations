import time
import board
import neopixel

pixel_pin = board.A3
num_pixels = 7
once_run = True

pixels = neopixel.NeoPixel(pixel_pin, num_pixels, brightness=0.3, auto_write=False)

def color_chase(color, wait, sleep):
    for i in range(num_pixels):
        pixels[i] = color
        time.sleep(wait)
        pixels.show()
    time.sleep(sleep)


RED = (255,0,0)
ORANGE = (255,60,0)
YELLOW = (255, 120, 0)

GREEN = (0,128,0)
BLUE = (0, 80, 255)
PURPLE = (150, 0, 160)

OFF = (0,0,0)
WHITE = (255,255,255)

while True:
    if(once_run):
        color_chase(RED, 0.1, 4)
        color_chase(ORANGE, 0.1, 4)
        color_chase(RED, 0.1, 4)
        color_chase(ORANGE, 0.1, 4)
        color_chase(YELLOW, 0.1, 17)
        color_chase(OFF, 0.1, 0.5) #light turn off mid verse

        color_chase(GREEN, 0.1, 4)
        color_chase(BLUE, 0.1, 4)
        color_chase(GREEN, 0.1, 4)
        color_chase(BLUE, 0.1, 4)
        color_chase(PURPLE, 0.1, 17)
        color_chase(OFF, 0.1, 20) #light turn off mid verse
        once_run = False
    
    color_chase(WHITE, 0.1, 0.5)
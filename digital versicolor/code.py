import time
import board
import neopixel

pixel_pin = board.A3
num_pixels = 7
once_run = True

pixels = neopixel.NeoPixel(pixel_pin, num_pixels, brightness=1, auto_write=False)

RED = (255,0,0)
ORANGE = (255,60,0)
YELLOW = (255, 120, 0)

GREEN = (0,128,0)
BLUE = (0, 80, 255)
PURPLE = (150, 0, 160)

OFF = (0,0,0)
WHITE = (255,255,255)

def color_chase(color, wait, sleep):
    for i in range(num_pixels):
        pixels[i] = color
        time.sleep(wait)
        pixels.show()
    time.sleep(sleep)

def strobo(color,wait):
    pixels.fill(color)
    pixels.show()
    time.sleep(wait)
    pixels.fill(OFF)
    pixels.show()
    time.sleep(wait)

def verse(colorA, colorB, colorC):
    color_chase(colorA, 0.1, 4)
    color_chase(colorB, 0.1, 4)
    color_chase(colorA, 0.1, 4)
    color_chase(colorB, 0.1, 4)
    color_chase(colorC, 0.1, 17)

def rainbow(repeat, speed): #0.6
    for i in range(repeat):
        color_chase(RED, speed, speed) 
        color_chase(ORANGE, speed, speed) 
        color_chase(YELLOW, speed, speed)  
        color_chase(GREEN, speed, speed)
        color_chase(BLUE, speed, speed)
        color_chase(PURPLE, speed, speed)


while True:
    if(once_run):
        rainbow(6, 0.08)
        color_chase(OFF, 0.1, 6)

        # verse 1
        verse(RED,ORANGE,YELLOW)
        color_chase(OFF, 0.1, 0.5)

        # verse 2
        verse(GREEN,BLUE,PURPLE)
        color_chase(OFF, 0.1, 0.5)

        # bridge
        rainbow(18, 0.02)
        color_chase(OFF, 0.1, 0.5)

        color_chase(WHITE, 0.1, 161)
        once_run = False
    strobo(WHITE,0.15)
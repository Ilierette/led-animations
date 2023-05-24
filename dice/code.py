import time
import board
import neopixel

pixel_pin = board.A3
num_pixels = 7
once_run = True

pixels = neopixel.NeoPixel(pixel_pin, num_pixels, brightness=1.0, auto_write=True)


def breatheIn(sleep):
    for i in range(30,255):
        pixels.fill((0,i,i))
    time.sleep(sleep)

def breatheOut():
    for i in reversed(range(30,255)):
        pixels.fill((0,i,i))

def color_chase(color, wait):
    for i in range(num_pixels):
        pixels[i] = color
        time.sleep(wait)
        pixels.show()
    time.sleep(0.5)

ORANGE = (255,60,0)
PURPLE = (90, 0, 255)
OFF = (0,0,0)

while True:
    if(once_run):
        color_chase(PURPLE, 0.1)
        color_chase(ORANGE, 0.1)
        color_chase(OFF, 0.1)
        once_run = False

    breatheIn(0.6)
    breatheOut()
    

import time
import board
import neopixel

pixel_pin = board.A3
num_pixels = 7

pixels = neopixel.NeoPixel(pixel_pin, num_pixels, brightness=1.0, auto_write=False)

def color_chase(color, wait):
    for i in range(num_pixels):
        pixels[i] = color
        time.sleep(wait)
        pixels.show()
    time.sleep(0.5)



YELLOW = (255, 150, 0)
PURPLE = (180, 0, 255)
CYAN = (0, 255, 255)

while True:
    color_chase(YELLOW, 0.1)
    color_chase(CYAN, 0.1)
    color_chase(PURPLE, 0.1)


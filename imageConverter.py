import cv2
import numpy as np

img = cv2.imread("MAP1.png",cv2.IMREAD_COLOR)
height, width, channel = img.shape

map = []
black = [0,0,0]
white = [255,255,255]
green = [0,255,0]
red = [0,0,255]

for x in range(height):
    line = []
    for y in range(width):
        pixel = int(img[x, y])
        if pixel == black:
            line.append(1)
        elif pixel == white:
            line.append(0)
        elif pixel == green:
            line.append(2)
        elif pixel == red:
            line.append(3)
    map.append(line)



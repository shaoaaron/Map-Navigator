import cv2
import numpy as np

img = cv2.imread("MAP1.png",cv2.IMREAD_COLOR)
height, width, channel = img.shape

map = []

black = [0,0,0]
white = [255,255,255]
green = [0,255,0]
red = [0,0,255]

start = []
end = []

for x in range(height):
    line = []
    for y in range(width):
        pixel = (img[x, y])
        if np.array_equal(pixel,black):
            line.append(1)
        elif np.array_equal(pixel,white):
            line.append(0)
        elif np.array_equal(pixel,green):
            line.append(2)
            start.append(x)
            start.append(y)
        elif np.array_equal(pixel,red):
            line.append(3)
            end.append(x)
            end.append(y)
    map.append(line)

np.save("MAP1array.npy", map)

with open('positions.txt', 'w') as f:
    f.write(f"{start[0]} {start[1]}\n")
    f.write(f"{end[0]} {end[1]}\n")



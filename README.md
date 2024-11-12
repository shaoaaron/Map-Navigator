# Map Navigator

## Overview

This is a first project attempt at reading in a map (image) with python, identifying possible paths, and using depth first search to find the fastest route from the beginning pixel to the end pixel. Practiced C++ skills with data types and cnpy to write the search algorithm, and python skills with cv2 and numpy to read in the image and detect walls and paths, turning a colored image into a 2d array. 

The workflow involved reading in the image with python, using cnpy to read the python file in c++, and then execution of the algorithm to find the fastest path.

## Problems

There were many issues that came up. The reading of the npy file using cnpy was buggy and c++ did not run smoothly on vscode at all (probably local issue). The algorithm took a bit of time to implement. Learning cv2 package to read the png image also took some time.

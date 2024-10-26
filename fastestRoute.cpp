#include <iostream>
#include <vector>
#include <fstream>
#include "cnpy.h"

void load_map(const std::string& filename, std::vector<std::vector<int>>& map) {
    // Load the numpy array from file
    auto arr = cnpy::npy_load(filename);
    int* data = arr.data<int>();  // Assuming the array is of type int

    // Fill the 2D vector with the numpy data
    size_t height = arr.shape[0];
    size_t width = arr.shape[1];
    map.resize(height, std::vector<int>(width));

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            map[i][j] = data[i * width + j];
        }
    }
}

std::pair<int, int> load_position(const std::string& filename) {
    std::ifstream file(filename);
    int y, x;
    file >> y >> x;  // Read y and x coordinates
    return {y, x};
}

int main() {
    // Load the map
    std::vector<std::vector<int>> map;
    load_map("MAP1array", map);
    
    // Load start and end positions
    auto start = load_position("positions.txt");
    auto end = load_position("positions.txt");


    return 0;
}
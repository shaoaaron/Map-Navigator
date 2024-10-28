#include <iostream>
#include "cnpy/cnpy.h"

int main() {
    std::cerr<<"run";
    try {
        auto arr = cnpy::npy_load("MAP1array.npy");
        std::cerr << "Array loaded successfully with shape: " 
                  << arr.shape[0] << "x" << arr.shape[1] << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error loading array: " << e.what() << "\n";
    }
    return 0;
}

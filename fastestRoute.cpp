#include <iostream>
#include <vector>
#include <fstream>
#include "cnpy/cnpy.h"
#include <queue>
#include <set>


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
    return {x, y};
}

std::queue<std::pair<int,int>> directions(std::vector<std::vector<int>> map, std::pair<int,int> point) {
    std::queue<std::pair<int,int>> direction;

    if(point.second - 1 >= 0){
        if(map[point.first][point.second-1] == 0){
            direction.push({point.first,point.second-1});
        }
    }
    if(point.first - 1 >= 0){
        if(map[point.first-1][point.second] == 0){
            direction.push({point.first,point.second-1});
        }
    }
    if(point.second + 1 < map.size()){
        if(map[point.first][point.second+1] == 0){
            direction.push({point.first,point.second-1});
        }
    }
    if(point.first + 1 < map[0].size()){
        if(map[point.first+1][point.second] == 0){
            direction.push({point.first,point.second-1});
        }
    }

    return direction;
}

int bfs(std::pair<int,int> start, std::pair<int,int> end, std::vector<std::vector<int>> map) {
    std::set<std::pair<int,int>> visited;

    std::queue<std::pair<int,int>> check;
    check.push(start);

    int counter = -1;

    while(!check.empty()) {
        counter++;

        std::pair<int,int> next = check.front();
        visited.insert(next);

        if(next == end) {
            return counter;
            break;
        }

        std::queue<std::pair<int,int>> direction = directions(map, next);

        for(int i = 0; i < direction.size(); i++){
            if(visited.count(direction.front()) == 0) {
                visited.insert(direction.front());
                check.push(direction.front());
            }
            direction.pop();
        }

        check.pop();
    }

    return counter;
}

int main() {
    std::cout<<"hello";
    // Load the map
    std::vector<std::vector<int>> map;
    load_map("MAP1array", map);
    
    // Load start and end positions
    auto start = load_position("positions.txt");
    auto end = load_position("positions.txt");

    int steps = bfs(start, end, map);

    std::cout << steps;

    return 0;
}
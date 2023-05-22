#include <iostream>
#include <vector>
#include "aStar.hpp"

int main() {
    std::vector<std::vector<int>> grid = {
            {1, 3, 5, 7, 9},
            {0, 2, 4, 1, 3},
            {3, 5, 0 ,1 ,1},
            {1, 2, 3, 4 ,0},
            {9, 8, 4, 5, 1}
    };

    std::pair<int, int> start = {0, 0};
    std::pair<int, int> goal = {3, 4};

    std::vector<std::pair<int, int>> path = aStar(grid, start, goal);

    if (path.empty()) {
        std::cout << "Hedefe ulaşılamadı.\n";
    } else {
        std::cout << "Yol:\n";
        for (const auto& point : path) {
            std::cout << "(" << point.first << ", " << point.second << ")\n";
        }
    }

    return 0;
}

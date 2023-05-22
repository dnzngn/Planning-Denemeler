#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <vector>
#include <queue>
#include <cmath>

// Durum yapısı
struct State {
    int x;                   // Durumun x koordinatı
    int y;                   // Durumun y koordinatı
    double cost;             // Başlangıç noktasından bu duruma olan maliyet
    double heuristic;        // Hedefe olan tahmini maliyet
    State* parent;           // Ebeveyn durum

    State(int x, int y, double cost, double heuristic, State* parent)
            : x(x), y(y), cost(cost), heuristic(heuristic), parent(parent) {}

    double getTotalCost() const {
        return cost + heuristic;
    }
};

// Hedefe olan tahmini maliyeti hesaplayan fonksiyon
double calculateHeuristic(int currentX, int currentY, int goalX, int goalY);

// A* algoritması
std::vector<std::pair<int, int>> aStar(const std::vector<std::vector<int>>& grid,
                                       std::pair<int, int> start, std::pair<int, int> goal);

#endif

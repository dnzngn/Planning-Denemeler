//
// Created by deniz on 30.05.2023.
//

#ifndef MINKOWSKISUM_MINKOWSKISUM_HPP
#define MINKOWSKISUM_MINKOWSKISUM_HPP

#include <iostream>
#include <vector>
#include <algorithm>


struct Point {
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}

    Point operator + (const Point& p) const {
        return Point{x + p.x, y + p.y};
    }
    Point operator - (const Point& p) const {
        return Point{x - p.x, y - p.y};
    }
    [[nodiscard]] double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }

};

void reorder_polygon(std::vector<Point>& P){
    size_t pos = 0;
    for(size_t i = 1; i < P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }

    rotate(P.begin(), P.begin() + pos, P.end());
}

// İki poligonun Minkowski toplamını hesaplayan fonksiyon
std::vector<Point> minkowskiSum(std::vector<Point>& poly1, std::vector<Point>& poly2) {

    std::vector<Point> result;

    // Büyükten küçüğe sıralama yapılıyor
    reorder_polygon(poly1);
    reorder_polygon(poly2);

    poly1.emplace_back(poly1[0]);
    poly1.emplace_back(poly1[1]);
    poly2.emplace_back(poly2[0]);
    poly2.emplace_back(poly2[1]);

    size_t i = 0, j = 0;
    while(i < poly1.size() - 2 || j < poly2.size() - 2){
        result.emplace_back(poly1[i] + poly2[j]);
        auto cross = (poly1[i + 1] - poly1[i]).cross(poly2[j + 1] - poly2[j]);
        if(cross >= 0)
            ++i;
        if(cross <= 0)
            ++j;
    }
    return result;
}

#endif //MINKOWSKISUM_MINKOWSKISUM_HPP

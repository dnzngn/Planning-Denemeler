//
// Created by deniz on 17.04.2023.
//

#ifndef GRASSFIRE_GRASSFIRE_H
#define GRASSFIRE_GRASSFIRE_H

#include <algorithm>
#include <queue>

// Nokta yapısı
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// Mesafe yapısı
struct Distance {
    Point point;
    double distance;
    Distance(Point p, double d) : point(p), distance(d) {}
    bool operator<(const Distance& other) const { // < işaretinin Sağ tarafı other, sol taraf kıyaslanacak distance ==> p1.dist < other(p2,p3,..).dist
        return distance < other.distance;
    }
};

std::vector<std::vector<double>> grassfire(std::vector<Point>& points) {
    // En küçük öncelikli kuyruk (priority_queue) tanımla
    std::priority_queue<Distance> q;
    // Mesafe grafiği matrisi oluştur
    std::vector<std::vector<double>> distances(points.size(), vector<double>(points.size(), -1));

    // Tüm noktaları gez
    for (int i = 0; i < points.size(); i++) {
        // Başlangıç noktasını al
        Point start = points[i];
        // Başlangıç noktasına olan mesafe 0'dır
        distances[i][i] = 0;
        // Diğer tüm noktalara olan mesafeleri hesapla
        for (int j = 0; j < points.size(); j++) {
            if (i == j) {
                continue;
            }
            Point end = points[j];
            double distance = sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2));
            // Mesafe değerlerini öncelikli kuyruğa ekle
            q.push(Distance(end, distance));
        }
        // Öncelikli kuyruktan mesafe değerlerini al ve mesafe grafiği matrisine ekle
        while (!q.empty()) {
            Point p = q.top().point;
            double d = q.top().distance;
            q.pop();
            if (distances[i][p.x] == -1) {
                distances[i][p.x] = d;
                distances[p.x][i] = d;
            }
        }
    }
    // Mesafe grafiği matrisini döndür
    return distances;
}



#endif //GRASSFIRE_GRASSFIRE_H

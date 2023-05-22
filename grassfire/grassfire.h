//
// Created by deniz on 17.04.2023.
//

#ifndef GRASSFIRE_GRASSFIRE_H
#define GRASSFIRE_GRASSFIRE_H

#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
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

void printVector2D(const std::vector<std::vector<double>>& vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------------------------------------------------------------\n";
}

std::vector<std::vector<double>> grassfire(std::vector<Point>& points) {
    // En küçük öncelikli kuyruk (priority_queue) tanımla
    std::priority_queue<Distance> q; // {((x0,y0),dist0),((x1,y1),dist1),((x2,y2),dist2),((x3,y3),dist3)}
    // Mesafe grafiği matrisi oluştur
    std::vector<std::vector<double>> distances(points.size(), std::vector<double>(points.size(), -1));
    // distances(4,vector<double> dvec = {-1,-1,-1,-1})
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
            double distance = sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2)); // Noktalar arası mesafe hesaplanıyor.
            // Mesafe değerlerini öncelikli kuyruğa ekle
            q.emplace(end, distance);// {((3,0),115),((3,1),12),((3,2),11),((2,1),3),((2,0),22),((1,0),51),...} == normalde böyle q listesini oluşturması lazım
            // fakat priority_queue listesi olarak oluşturuludğu için büyükten küçüğe sıralanmış şekilde çıkar.
            // {((3,0),115),((1,0),51),((2,0),22),((3,1),12),...} ---> sadece mesafeleri karşılaştırarak sıralıyor
        }
        // Öncelikli kuyruktan mesafe değerlerini al ve mesafe grafiği matrisine ekle
        while (!q.empty()) {
            //q = {((3,0),115),((1,0),51),((2,0),22),((3,1),12),...}
            Point p = q.top().point; // Bu listedeki en büyük pointi bul ==> (3,0)
            double d = q.top().distance; // Bu listedeki en büyük distance'ı bul ==> (115)
            q.pop(); // En büyük distance'a sahip point çıkartılıyor ==> {((1,0),51),((2,0),22),((3,1),12),...}
            if (distances[i][p.x] == -1) { // distances(4,vector<double> dvec = {-1,-1,-1,-1})
                distances[i][p.x] = d; // 1.Adım: distances[0][3] = 115, 2.Adım: distances[0][2]
                distances[p.x][i] = d; // 1.Adım: distances[3][0] = 115, 2.Adım: distances[][0]
                printVector2D(distances);
            }
        }
    }
    // Mesafe grafiği matrisini döndür
    return distances;
}

#endif //GRASSFIRE_GRASSFIRE_H

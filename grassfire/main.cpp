#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Grassfire algoritması
vector<vector<double>> grassfire(vector<Point>& points) {
    // En küçük öncelikli kuyruk (priority_queue) tanımla
    priority_queue<Distance> q;
    // Mesafe grafiği matrisi oluştur
    vector<vector<double>> distances(points.size(), vector<double>(points.size(), -1));

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

int main() {
    // Noktaları tanımla
    vector<Point> points = { Point(0, 0), Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4) };
    // Grassfire algoritmasını çalıştır
    vector<vector<double>> distances = grassfire(points);
    // Mesafe grafiği matrisini ekrana yazdır
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

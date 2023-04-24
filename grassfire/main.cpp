#include <iostream>
#include <vector>
#include "grassfire.h"

using namespace std;

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

//template<typename T>
//void Print(T vec)
//{
//    auto begs = begin(vec);
//    auto ends = end(vec);
//
//    while (begs != ends){
//        std::cout << *begs++<<" ";
//    }
//    std::cout<<"\n------------------------------------------------------------------\n";
//}
//
//
//int main(){
//
//    std::vector<std::vector<double>> a(5,std::vector<double>(5,-1));
//
//    for (int i = 0; i < a.size(); ++i) {
//        for (int j = 0; j < a[i].size(); ++j) {
//            std::cout << a[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}
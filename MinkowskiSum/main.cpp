#include "minkowskiSum.hpp"

int main() {
    // Poligonları tanımla
    std::vector<Point> poligon1 = {Point(1, 1), Point(2, 1), Point(2, 2), Point(1, 2), Point(1, 3), Point(1, 4),Point(3, 3),};
    std::vector<Point> poligon2 = {Point(3, 3), Point(4, 3), Point(4, 4), Point(3, 4)};

    // Minkowski toplamını hesapla
    std::vector<Point> toplam = minkowskiSum(poligon1, poligon2);

    // Sonucu ekrana yazdır
    std::cout << "Minkowski Toplamı: ";
    for (const auto& nokta : toplam) {
        std::cout << "(" << nokta.x << ", " << nokta.y << ") ";
    }
    std::cout << std::endl;

    return 0;
}

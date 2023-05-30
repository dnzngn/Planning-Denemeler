#include "minkowskiSum.hpp"

int main() {
    // Poligonları tanımla
    std::vector<Nokta> poligon1 = {Nokta(1, 1), Nokta(2, 1), Nokta(2, 2), Nokta(1, 2)};
    std::vector<Nokta> poligon2 = {Nokta(3, 3), Nokta(4, 3), Nokta(4, 4), Nokta(3, 4)};

    // Minkowski toplamını hesapla
    std::vector<Nokta> toplam = minkowskiToplam(poligon1, poligon2);

    // Sonucu ekrana yazdır
    std::cout << "Minkowski Toplamı: ";
    for (const auto& nokta : toplam) {
        std::cout << "(" << nokta.x << ", " << nokta.y << ") ";
    }
    std::cout << std::endl;

    return 0;
}

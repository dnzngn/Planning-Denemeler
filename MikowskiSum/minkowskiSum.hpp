//
// Created by deniz on 30.05.2023.
//

#ifndef MINKOWSKISUM_MINKOWSKISUM_HPP
#define MINKOWSKISUM_MINKOWSKISUM_HPP

#include <iostream>
#include <vector>
#include <algorithm>


struct Nokta {
    double x, y;

    Nokta(double _x, double _y) : x(_x), y(_y) {}
};

// İki poligonun Minkowski toplamını hesaplayan fonksiyon
std::vector<Nokta> minkowskiToplam(const std::vector<Nokta>& poligon1, const std::vector<Nokta>& poligon2) {
    std::vector<Nokta> sonuc;

    // İki poligonun her bir noktası için toplamı hesapla
    for (const auto& nokta1 : poligon1) {
        for (const auto& nokta2 : poligon2) {
            sonuc.emplace_back(nokta1.x + nokta2.x, nokta1.y + nokta2.y); // x ve y düzleminde topla
        }
    }

    // Yinelemeleri kaldır

    // 1. Adım: Noktaları sırala
    std::sort(sonuc.begin(), sonuc.end(), [](const Nokta& nokta1, const Nokta& nokta2) {
        return (nokta1.x < nokta2.x) || (nokta1.x == nokta2.x && nokta1.y < nokta2.y);
    });

    // 2. Adım: Ardışık yinelemeleri kaldır
    sonuc.erase(std::unique(sonuc.begin(), sonuc.end(), [](const Nokta& nokta1, const Nokta& nokta2) {
        return (nokta1.x == nokta2.x) && (nokta1.y == nokta2.y);
    }), sonuc.end());

    // Sonucu döndür
    return sonuc;
}

#endif //MINKOWSKISUM_MINKOWSKISUM_HPP

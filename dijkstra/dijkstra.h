//
// Created by deniz on 17.04.2023.
//

#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void dijkstra(vector<pair<int, int>> adj[], int dist[], int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // önceliğe göre büyükten küçüğe sıralayacak şekilde tanımlanıyor.
    pq.emplace(0, src); // (0,0) ekle
    dist[src] = 0; // Başlangıç konumu uzaklığı = 0

    while (!pq.empty()) {
        int u = pq.top().second; // değeri tutuyor ve en büyük weight değerini alıyor
        pq.pop(); // daha sonra bu tutulan değeri çıkartıyor


        for (auto v : adj[u]) {
            int neighbor = v.first; // adj[u] daki tutulan pair in ilk değeri
            int weight = v.second; // adj[u] daki tutulan pair in ikinci değeri

            if (dist[neighbor] > dist[u] + weight) {
                dist[neighbor] = dist[u] + weight;
                pq.emplace(dist[neighbor], neighbor);
            }
        }
    }
}

#endif //DIJKSTRA_DIJKSTRA_H

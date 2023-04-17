#include "dijkstra.h"

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    int dist[n]; // kaç node varsa ona göre boş array oluşturuyor
    //memset(dist, 0x3f, sizeof(dist)); // C dilinden kalma fonksiyon bellek ayrımı yapıyor
    fill(dist, dist + n, INF); // C++11 ile geldi, başlangıç ve sonuna kadar olan değerleri INF yapıyor

    vector<pair<int, int>> adj[n];

    cout << "Enter the edges and their weights (node1 node2 weight): " << endl;
    for (int i = 0; i < m; i++) {
        int start, next, weight;
        cin >> start >> next >> weight;
        adj[start].emplace_back(next, weight); // sondan ekleme
        //adj[v].emplace_back(u, w); // sondan ekleme - Tek yönlü hareket sağlanması için yoruma alındı
    }

    int src,dest;
    cout << "Enter the source node: ";
    cin >> src;


    cout << "Enter the destination node: ";
    cin >> dest;
    dijkstra(adj, dist, src); // Dijkstra.h'dan geliyor..

    cout << "Shortest distances from the source node to destination node: " << dist[dest] << '\n';

    cout << "Shortest distances from the source node: " << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == 0x3f3f3f3f) { // INF yerine 0x3f3f3f3f kullanımı
            cout << "unreachable" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}

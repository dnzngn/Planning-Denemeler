#include "aStar.hpp"

// Hedefe olan tahmini maliyeti hesaplayan fonksiyon
double calculateHeuristic(int currentX, int currentY, int goalX, int goalY) {
    return std::sqrt(std::pow(currentX - goalX, 2) + std::pow(currentY - goalY, 2));
}

// A* algoritması
std::vector<std::pair<int, int>> aStar(const std::vector<std::vector<int>>& grid,
                                       std::pair<int, int> start, std::pair<int, int> goal) {
    const int rows = grid.size(); // tüm grid boyutunun ilk değeri
    const int cols = grid[0].size(); // grid ilk satır boyutu

    // Hareketlerin dört yönlü olması durumunda
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    // Öncelikli kuyruk veri yapısı, karşılaştırma işlevinin türünü belirlemek için decltype kullanılmıştır. Aşağıda açıklanan lambda ifadesi, öğelerin toplam maliyetlerine göre sıralanmasını sağlar.
    std::priority_queue<State*, std::vector<State*>,
            decltype([](const auto& a, const auto& b) { return a->getTotalCost() > b->getTotalCost(); })> openList;

    // Ziyaret edilen durumları tutan 2D vektör
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    // Başlangıç durumunu açık listeye ekle
    openList.push(new State(start.first, start.second, 0.0,
                            calculateHeuristic(start.first, start.second, goal.first, goal.second), nullptr));

    // A* algoritmasının ana döngüsü
    while (!openList.empty()) {
        // Açık listeden en düşük toplam maliyetli durumu al
        State* current = openList.top();
        openList.pop();

        int x = current->x;
        int y = current->y;

        visited[x][y] = true;

        // Hedefe ulaşıldıysa, bulunan yolun listesini oluştur ve geri dön
        if (x == goal.first && y == goal.second) {
            std::vector<std::pair<int, int>> path;
            while (current != nullptr) {
                path.emplace_back(current->x, current->y);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        // Komşu durumları kontrol et
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Geçerli konum kontrolü
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY]) {
                double newHeuristic = calculateHeuristic(newX, newY, goal.first, goal.second);
                double newCost = current->cost + 1.0/newHeuristic; // Her adım için maliyet (1/L)weight/length kabul ediliyor
                openList.push(new State(newX, newY, newCost, newHeuristic, current));
            }
        }
    }

    // Hedefe ulaşılamadı
    return {};
}

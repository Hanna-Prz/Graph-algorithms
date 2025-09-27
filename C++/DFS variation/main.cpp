#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
#include "macierz.cpp"

using namespace std;

struct Result {
    vector<int> path;
    int cost;
};

void dfs(const Graf& g, int current, vector<int>& path, vector<bool>& visited, int current_cost, int& min_total_cost, vector<int>& best_path) {
    if (path.size() > 1 && current == 1) {
        // zamknięty cykl do 1
        int min_clo = g.koszt[path[0] - 1];
        for (int v : path) {
            min_clo = min(min_clo, g.koszt[v - 1]);
        }
        int total = current_cost + (min_clo / 2);

        if (total < min_total_cost) {
            min_total_cost = total;
            best_path = path;
        }
        return;
    }

    auto neighbours = g.getNeighbourIndicesWithWeights(current);
    for (auto [next, weight] : neighbours) {
        if (next == 1 && path.size() < 2) continue; // nie wracamy do 1 od razu
        if (!visited[next] || next == 1) {
            visited[next] = true;
            path.push_back(next);
            dfs(g, next, path, visited, current_cost + weight, min_total_cost, best_path);
            path.pop_back();
            visited[next] = false;
        }
    }
}

int main() {
    Graf g;
    g.readFromFile("przemyt.txt");

    int n = g.getNumberOfVertices();
    int min_cost = INT_MAX;
    vector<int> best_path;

    vector<int> path = {1};
    vector<bool> visited(n + 1, false);
    visited[1] = true;

    dfs(g, 1, path, visited, 0, min_cost, best_path);

    if (best_path.empty()) {
        cout << "Brak cyklu wracającego do 1." << endl;
    } else {
        cout << "Najlepszy cykl: ";
        for (int v : best_path) cout << v << " ";
        cout << "\nKoszt: " << min_cost << endl;
    }

    return 0;
}

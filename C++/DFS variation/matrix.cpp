#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Graf {
public:
    int matrix[1000][1000] = {};
    int numberOfVertices = 0;
    int cost[1000] = {};
    int numberOfMetals = 0;

    Graf() {}

    void createVertices(int much) {
        if (much >= 0 && much < 1000) {
            numberOfVertices = max(numberOfVertices, much + 1);
        }
    }

    void metals(int much) {
        numberOfMetals = much;
    }

    void addEdge(int v1, int v2, int importance) {
        if (v1 >= 0 && v1 < 1000 && v2 >= 0 && v2 < 1000) {
            matrix[v1][v2] = importance; // graf skierowany
            numberOfVertices = max(numberOfVertices, max(v1 + 1, v2 + 1));
        }
    }

    bool checkEdge(int v1, int v2) const {
        return matrix[v1][v2] > 0;
    }

    int getNumberOfVertices() const {
        return numberOfVertices;
    }

    vector<pair<int, int>> getNeighbourIndicesWithWeights(int idx) const {
        vector<pair<int, int>> neighbours;
        for (int i = 0; i < numberOfVertices; i++) {
            if (matrix[idx][i] > 0) {
                neighbours.push_back({i, matrix[idx][i]});
            }
        }
        return neighbours;
    }

    void readFromFile(const string& path) {
        ifstream file(path);
        if (!file) {
            cerr << "Nie można otworzyć pliku!" << endl;
            return;
        }

        int much, v1, v2, importance, ko, met;
        file >> met;
        metals(met);
        for (int i = 0; i < met; i++) {
            file >> ko;
            cost[i] = ko;
        }

        file >> much;
        createVertices(much);
        while (file >> v1 >> v2 >> importance) {
            addEdge(v1, v2, importance);
        }

        file.close();
    }
};

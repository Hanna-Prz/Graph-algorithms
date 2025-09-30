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
    int koszt[1000] = {};
    int numberOfMetals = 0;

    Graf() {}

    void createVertices(int ile) {
        if (ile >= 0 && ile < 1000) {
            numberOfVertices = max(numberOfVertices, ile + 1);
        }
    }

    void metale(int ile) {
        numberOfMetals = ile;
    }

    void addEdge(int v1, int v2, int waga) {
        if (v1 >= 0 && v1 < 1000 && v2 >= 0 && v2 < 1000) {
            matrix[v1][v2] = waga; // graf skierowany
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

        int ile, v1, v2, waga, ko, met;
        file >> met;
        metale(met);
        for (int i = 0; i < met; i++) {
            file >> ko;
            koszt[i] = ko;
        }

        file >> ile;
        createVertices(ile);
        while (file >> v1 >> v2 >> waga) {
            addEdge(v1, v2, waga);
        }

        file.close();
    }
};

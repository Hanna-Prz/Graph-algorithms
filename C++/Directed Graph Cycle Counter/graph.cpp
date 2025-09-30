#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "edge.h"
#include "edge.cpp"

using namespace std;

class Graf {


public:
    vector<vector<edge>> vertexList; // Lista sąsiedztwa
    Graf() {}

    void createVertices(int ile) {
        if (ile >= vertexList.size()) {
            vertexList.resize(ile + 1);
        }
    }

    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2, float weight = 1.0f) {
        createVertices(max(i_Vertex_Index_1, i_Vertex_Index_2));
        if (!checkEdge(i_Vertex_Index_1, i_Vertex_Index_2)) {
            vertexList[i_Vertex_Index_1].push_back(edge(i_Vertex_Index_1, i_Vertex_Index_2, weight));
           // vertexList[i_Vertex_Index_2].push_back(edge(i_Vertex_Index_2, i_Vertex_Index_1, weight));
        }
    }

    bool removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        if (!checkEdge(i_Vertex_Index_1, i_Vertex_Index_2)) {
            cerr << "Krawędź nie istnieje!" << endl;
            return false;
        }

        auto &edges1 = vertexList[i_Vertex_Index_1];
        auto &edges2 = vertexList[i_Vertex_Index_2];

        edges1.erase(remove_if(edges1.begin(), edges1.end(),
                               [i_Vertex_Index_2](const edge &e) { return e.vertex_Index2 == i_Vertex_Index_2; }),
                     edges1.end());

        return true;
    }

    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        if (i_Vertex_Index_1 >= vertexList.size() || i_Vertex_Index_2 >= vertexList.size()) {
            return false;
        }
        for (const auto &e : vertexList[i_Vertex_Index_1]) {
            if (e.vertex_Index2 == i_Vertex_Index_2) {
                return true;
            }
        }
        return false;
    }

    int vertexDegree(int idx) {
        if (idx >= vertexList.size()) {
            cerr << "Nie ma takiego wierzchołka!" << endl;
            return -1;
        }
        return vertexList[idx].size();
    }

    vector<int> getNeighbourIndices(int idx) {
        vector<int> neighbours;
        if (idx >= vertexList.size()) {
            cerr << "Nie ma takiego wierzchołka!" << endl;
            return neighbours;
        }

        for (const auto &e : vertexList[idx]) {
            neighbours.push_back(e.vertex_Index2);
        }
        return neighbours;
    }

    void printNeighbourIndices(int idx) {
        vector<int> neighbours = getNeighbourIndices(idx);
        for (int n : neighbours) {
            cout << n << endl;
        }
    }

    int getNumberOfEdges() {
        int count = 0;
        for (const auto &edges : vertexList) {
            count += edges.size();
        }
        return count ;
    }

    void readFromFile(std::string path) {
        ifstream file(path);
        if (!file) {
            cerr << "Nie można otworzyć pliku!" << endl;
            return;
        }

        int index1, index2, much;
        file >> much;

        for (int i = 0; i < much; i++) {
            file >> index1;
            index1--;
            addEdge(index1, i);
        }

        file.close();
    }
};


#include <iostream>
#include "graph.cpp"
#include <queue>
using namespace std;

int tab[1000][2] = {0};

void check_how_many_edges_come_out(int vertex, int max, Graph *G, int t[][2]) {
    int result = 0;
    for (int i = 0; i < max; i++) {
        if (G->checkEdge(i,vertex)) {
            result++;
        }
    }
    t[vertex][0] = result;
}

int vertex_0(int max, Graph *G, int t[][2]) {
    int k = 0;
    //int h = 0;
    int result = 0;

        for (int i = 1; i < max; i++) {

            if (t[i][0] == 0 && t[i][1] == 1) {
                t[i][1] = 0;
                for (int k = 0; k < max; k++) {
                    G->removeEdge(i,k);
                    G->removeEdge(k,i);
                }
                for (int j = 0; j < max; j++) {
                    check_how_many_edges_come_out(j, max, G, t);
                }

                //return i;
            }

            if (t[i][1] == 0) {
                k++;
            }
            //h++;
        }

        if (k == max ) {
            return 0;
        }
        else{
            result ++;
        }



    return result;
}


return cycles(Graph * G){
    queue<int> list;
    prepare();
    int number = G->vertexList.size();
    for (int i = 0; i < number; i++) {
        check_how_many_edges_come_out(i, number, G, tab);
    }
    int j = 0;
    while (j >= 0) {
        j =vertex_0(number, G, tab);
    }

    if (j == -1) {
        cout << "NIE MA CYKLI w grafie 1" << endl;
    }
    if (j == -2) {
        cout << "TAK SA CYKLE w grafie 1" << endl;
    }
}

void prepare(){
    for (int i = 0; i < 1000; i++) {
        tab[i][1] = 1;
    }
}

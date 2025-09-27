#include <iostream>
#include "graf.cpp"
#include <queue>
using namespace std;

int tab[1000][2] = {0};

void sprawdz_ile_krawedzi_wychodzi(int wierzcholek, int maks, Graf *G, int t[][2]) {
    int wynik = 0;
    for (int i = 0; i < maks; i++) {
        if (G->checkEdge(i,wierzcholek)) {
            wynik++;
        }
    }
    t[wierzcholek][0] = wynik;
}

int wierzcholek_0(int maks, Graf *G, int t[][2]) {
    int k = 0;
    //int h = 0;
    int wynik = 0;

        for (int i = 1; i < maks; i++) {

            if (t[i][0] == 0 && t[i][1] == 1) {
                t[i][1] = 0;
                for (int k = 0; k < maks; k++) {
                    G->removeEdge(i,k);
                    G->removeEdge(k,i);
                }
                for (int j = 0; j < maks; j++) {
                    sprawdz_ile_krawedzi_wychodzi(j, maks, G, t);
                }

                //return i;
            }

            if (t[i][1] == 0) {
                k++;
            }
            //h++;
        }

        if (k == maks ) {
            return 0;
        }
        else{
            wynik ++;
        }



    return wynik;
}


return cykle(Graf * G){
    queue<int> lista;
    przygotuj();
    int liczba = G->vertexList.size();
    for (int i = 0; i < liczba; i++) {
        sprawdz_ile_krawedzi_wychodzi(i, liczba, G, tab);
    }
    int j = 0;
    while (j >= 0) {
        j = wierzcholek_0(liczba, G, tab);
    }

    if (j == -1) {
        cout << "NIE MA CYKLI w grafie 1" << endl;
    }
    if (j == -2) {
        cout << "TAK SA CYKLE w grafie 1" << endl;
    }
}

void przygotuj(){
    for (int i = 0; i < 1000; i++) {
        tab[i][1] = 1;
    }
}

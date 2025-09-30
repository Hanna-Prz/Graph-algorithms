#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


struct POINT {
    int x, y;
};


bool comparePoints(const POINT &a, const POINT &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}


int binarySearchLower(const vector<POINT> &points, int target, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (points[mid].x >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}


int binarySearchUpper(const vector<POINT> &points, int target, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (points[mid].x <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}


int maxPointsInRectangle(const vector<POINT> &points, int w, int h) {
    int n = points.size();
    int max_count = 0;

    for (int i = 0; i < n; ++i) {
        int x1 = points[i].x;      
        int x2 = x1 + w - 1;       


        int lower_x = binarySearchLower(points, x1, 0, n - 1);
        int upper_x = binarySearchUpper(points, x2, 0, n - 1);


        for (int j = lower_x; j <= upper_x; ++j) {
            int y1 = points[j].y;  
            int y2 = y1 + h - 1;   
            int count = 0;


            for (int k = lower_x; k <= upper_x; ++k) {
                if (points[k].y >= y1 && points[k].y <= y2) {
                    ++count;
                }
            }
            max_count = max(max_count, count);
        }
    }

    return max_count;
}

int main() {
    int w, h, n;


    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Nie można otworzyć pliku wejściowego!" << endl;
        return 1;
    }

    inputFile >> w >> h >> n;

    vector<POINT> points(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> points[i].x >> points[i].y;
    }
    inputFile.close();


    sort(points.begin(), points.end(), comparePoints);


    int max_count = maxPointsInRectangle(points, w, h);


    cout << "Max count: " << max_count << endl;

    return 0;
}

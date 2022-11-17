/*
ID: sadovay1
TASK: numtri
LANG: C++
*/
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int main() {

    int N;
    fin >> N;

    map<int, vector<int>> triangle;
    for (int i = 1; i <= N; i++) {
        vector<int> v(i + 1);
        for (int j = 1; j < (i+1); j++) {
            fin >> v[j];
        } 
        triangle[i] = v;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if (j == i) {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else if ((j != 1) && (i != j)) {
                if (triangle[i - 1][j] > triangle[i - 1][j - 1]) {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
            }
        }
    }       

    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (triangle[N][i] > res) {
            res = triangle[N][i];
        }
    }

    fout << res << endl;
    return 0;

}
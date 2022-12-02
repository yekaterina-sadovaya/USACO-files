/*
ID: sadovay1
TASK: frac1
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ifstream fin("frac1.in");
ofstream fout("frac1.out");

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);

}


int main() {

    int N;
    fin >> N;
    map<float, pair<int, int>> fracs;
    fracs[0.0] = { 0, 1 };
	fracs[1.0] = { 1, 1 };
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++) {
            float calc = (float)j / i;
            if (calc < 1) {
                if (gcd(i, j) == 1) {
                    fracs[calc] = { j, i };
                }
            }
        }
    }
   
    for (map<float, pair<int, int>>::iterator it = fracs.begin(); it != fracs.end(); it++) {
        fout << it->second.first << '/' << it->second.second << endl;
    }

    return 0;

}
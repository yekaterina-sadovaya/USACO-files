/*
ID: sadovay1
TASK: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <string>


using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

int main() {
    int n, d;
    fin >> n >> d;

    int r = n % d;
    map<int, int> m;
    string res = to_string(n / d) + ".";
    while (r != 0 && m.find(r) == m.end()) {
        m[r] = res.size();
        r *= 10;
        res += to_string(r / d);
        r %= d;
    }

    if (r != 0) {
        res.insert(m[r], "(");
        res += ")";
    }
	
	if (res.back() == '.') {
        res.push_back('0');
    }
	
    for (int i = 0; i < res.size(); i += 76) {
        fout << res.substr(i, 76) << endl;
    }

    return 0;
}
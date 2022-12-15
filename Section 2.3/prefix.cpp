/*
ID: sadovay1
TASK: prefix
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ifstream fin("prefix.in");
ofstream fout("prefix.out");


bool compare_strings(string seq, string primitive, int n) {

    for (int i = 0; i < primitive.size(); i++) {
        if (seq[n + i] != primitive[i]) {
            return false;
        }
    }
    return true;

}


int main() {

    vector<string> primitives;
    string prim = " ";
    while (prim != ".") {
        fin >> prim;
        primitives.push_back(prim);
    }
    primitives.pop_back();
    sort(primitives.begin(), primitives.end(), [](const string& a, const string& b) { return a.size() > b.size(); });
    string sequence;
    string l;
    while (fin >> l) {
        sequence += l;
    }
    vector <bool> check(sequence.size());

    int s = 0;
    for (int i = 0; i < sequence.size(); i++) {
        int count = -1;
        for (vector<string>::iterator it = primitives.begin();
            it != primitives.end(); it++) {
            string prim_i = *it;
            bool if_has = compare_strings(sequence, prim_i, i);
            count++;
            if (if_has == true) {
                for (int j = 0; j < prim_i.size(); j++) {
                    check[i+j] = true;
                }
                if (prim_i.size() > 3) {
                    i = i + prim_i.size() - 2;
                }
                break;
            }
            
        }
        if (check[i] == false) {
            // cannot continue
            break;
        }
        s = i;
    }

    if (s != 0) s++;
    fout << s << endl;
    return 0;

}
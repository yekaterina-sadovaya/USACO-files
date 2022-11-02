/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sadovay1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int look_up_in_vect(vector<pair<string, int>> vect, string name);

int main() {

    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int NP;
    vector<pair<string, int>> map_gifts;
    fin >> NP;
    string name;
    for (int i = 0; i < NP; i++) {
        fin >> name;
        map_gifts.push_back({name, 0});
    }
    string name_of_recipient;
    int gift;
    int NG;
    int money_fraction_for_each;
    int remainder = 0;
    for (int i = 0; i < NP; i++) {
        fin >> name;
        fin >> gift >> NG;
        if (NG != 0) {
            remainder = gift % NG;
            money_fraction_for_each = (int)gift / NG;
            int n = look_up_in_vect(map_gifts, name);
            map_gifts[n].second -= (gift - remainder);
            for (int j = 0; j < NG; j++) {
                fin >> name_of_recipient;
                int n = look_up_in_vect(map_gifts, name_of_recipient);
                map_gifts[n].second += money_fraction_for_each;
            }
        }
    }

    for (int i = 0; i < NP; i++) {
        fout << map_gifts[i].first << " " << map_gifts[i].second << endl;
    }

    return 0;
}

int look_up_in_vect(vector<pair<string, int>> vect, string name) {
    int n = 0;
    // look up for key in vector of pairs
    for (vector<pair<string, int>>::iterator iter = vect.begin(); iter != vect.end(); ++iter) {
        string p = iter->first;
        if (p == name) {
            break;
        }
        n += 1;
    }
    return n;
}
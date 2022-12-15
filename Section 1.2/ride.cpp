/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sadovay1
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int name2number(string name);

int main() {
    string comet_name;
    string group_name;
    ifstream fin("ride.in");
    fin >> comet_name >> group_name;

    int comet_num = name2number(comet_name);
    int group_num = name2number(group_name);

    ofstream fout("ride.out");
    if ((comet_num % 47) == (group_num % 47)) {
        fout << "GO" << endl;;
    }
    else {
        fout << "STAY" << endl;;
    }

    return 0;
}

int name2number(string name) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int res = 1;
    for (int i = 0; i < name.length(); i++) {
        int n = alphabet.find(name[i]) + 1;
        res = res * n;
    }
    return res;
}
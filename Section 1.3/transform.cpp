/*
ID: sadovay1
TASK: transform
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

vector<string> read_pattern(int& n) {
    vector<string> output(n);
    for (int i = 0; i < n; i++) {
        fin >> output[i];
    }
    return output;
}

vector<string> rotate_90deg(vector<string>& pattern_in, int& n) {
    vector<string> pattern_out(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pattern_out[j].insert(0, 1, pattern_in[i][j]);
        }
    }
    return pattern_out;
}

vector<string> reflect(vector<string>& pattern_in, int& n) {
    vector<string> pattern_out(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pattern_out[i].insert(0, 1, pattern_in[i][j]);
        }
    }
    return pattern_out;
}

bool if_same(vector<string>& pattern1, vector<string>& pattern2) {
    for (int i = 0; i < pattern1.size(); i++) {
        if (pattern1[i] != pattern2[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    int N;
    fin >> N;
    vector<string> initial_pattern(N);
    vector<string> final_pattern(N);
    initial_pattern = read_pattern(N);
    final_pattern = read_pattern(N);
    vector<string> pattern_rotated_90 = initial_pattern;
    vector<string> pattern_to_rotate = initial_pattern;
    int number_of_transformations = 0;
    while ((if_same(final_pattern, pattern_rotated_90) == false) || number_of_transformations == 0) {
        pattern_rotated_90 = rotate_90deg(pattern_to_rotate, N);
        number_of_transformations += 1;
        if (number_of_transformations == 3) {
            pattern_rotated_90 = reflect(initial_pattern, N);
            number_of_transformations += 1;
        }
        pattern_to_rotate = pattern_rotated_90;
        if (number_of_transformations >= 8) {
            break;
        }
    }
    // change the transformation codes for output
    if ((number_of_transformations < 8) && (number_of_transformations > 4)) {
        number_of_transformations = 5;
    }
    else if (number_of_transformations == 8) {
        if (if_same(initial_pattern, final_pattern) == true) {
            number_of_transformations = 6;
        }
        else {
            number_of_transformations = 7;
        }
    }
    fout << number_of_transformations << endl;

    return 0;
}
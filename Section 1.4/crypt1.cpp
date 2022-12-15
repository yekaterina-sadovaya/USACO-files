/*
ID: sadovay1
TASK: crypt1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

bool check(int num, vector<int>& digits) {

    int n = 0;
    vector<int> dgs;
    while (num) {
        dgs.push_back(num % 10);
        num = num / 10;
        n++;
    }
    vector<int> check_for_all_digits(n);
    
    for (int d = 0; d < n; d++) {
        for (int i = 0; i < digits.size(); i++) {
            if (dgs[d] == digits[i]) {
                check_for_all_digits[d] = 1;
                break;
            }
        }
    }

    int sum = accumulate(check_for_all_digits.begin(), check_for_all_digits.end(), 0);;
    if (sum != n) {
        return false;
    }
    else {
        return true;
    }
}

bool if_counted(int num, vector<int> all) {
    for (vector<int>::iterator it = all.begin(); it < all.end(); it++) {
        if (*it == num) {
            return true;
        }
    }
    return false;
}

int main() {

    int N;
    fin >> N;
    vector<int> digits(N);
    int abc, de, abc_e, abc_d, de_abc;
    for (int i = 0; i < N; i++) {
        fin >> digits[i];
    }

    int number_of_solutions = 0;
    vector<int> all_solutions;

    for (int d1 = 0; d1 < N; d1++) {
        for (int d2 = 0; d2 < N; d2++) {
            for (int d3 = 0; d3 < N; d3++) {
                abc = 100 * digits[d1] + 10 * digits[d2] + digits[d3];
                for (int d4 = 0; d4 < N; d4++) {
                    for (int d5 = 0; d5 < N; d5++) {
                        de = 10 * digits[d4] + digits[d5];
                        abc_e = abc * digits[d4];
                        abc_d = abc * digits[d5];
                        de_abc = abc * de;
                        if ((abc_e <= 999) && (abc_d <= 999) && (de_abc > 999) && (de_abc <= 9999)) {
                            if ((check(abc_e, digits) == true) && (check(abc_d, digits) == true) && (check(de_abc, digits) == true)) {
                                // check if solution is new
                                if (if_counted(de_abc, all_solutions) == false) {
                                    number_of_solutions += 1;
                                    all_solutions.push_back(de_abc);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
	
	fout << number_of_solutions << endl;
    return 0;
}
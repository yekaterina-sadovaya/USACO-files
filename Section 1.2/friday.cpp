/*
ID: sadovay1
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int N;
    fin >> N;
    int ys = 1900 + N;
    int day_num = 2;    // January 1 1900 was on a Monday
    vector<int> counter = {0,0,0,0,0,0,0};    // vector represents days of week (Saturday, Sunday, Monday, Tuesday, ..., Friday)
    for (int year = 1900; year < ys; year++) {
        int n_days_in_month;
        for (int month = 0; month < 12; month++) {
            if (month == 8 || month == 3 || month == 5 || month == 10) {
                n_days_in_month = 30;
            }
            else if (month == 1) {
                bool leap_year = false;
                if (year % 400 == 0) {
                    leap_year = true;
                }
                else if ((year % 4 == 0) && (year % 100 != 0)) {
                    leap_year = true;
                }

                if (leap_year == true) {
                    n_days_in_month = 29;    // leap year
                }
                else {
                    n_days_in_month = 28;
                }
            }
            else {
                n_days_in_month = 31;
            }
            
            int index_of_13 = day_num + 5;
            day_num += n_days_in_month - 7*((int)n_days_in_month / 7);
            if (day_num >= 7) {
                day_num = day_num - 7;
            }
            if (index_of_13 >= 7) {
                index_of_13 = index_of_13 - 7;
            }
            counter[index_of_13] += 1;
        }
    }

    for (int i = 0; i < 7; i++) {
        fout << counter[i];
        if (i != 6) {fout << " ";}
        else { fout << endl; }
    }

    return 0;
}
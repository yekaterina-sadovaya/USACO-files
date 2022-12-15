/*
ID: sadovay1
TASK: milk2
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {

    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int n_farmers;
    fin >> n_farmers;
    int t_start = 0, t_end = 0;
    int max_time_no_milking = 0, max_time_milking = 0;
    int min_time_s = 0, max_time_e = 0;
    for (int i = 0; i < n_farmers; i++) {
        int t_prev_s = t_start;
        int t_prev_e = t_end;
        fin >> t_start >> t_end;
        if ((t_start <= t_prev_e) || (max_time_milking == 0)) {
            if (t_end > max_time_e) {
                max_time_e = t_end;
            }
            if ((t_start < min_time_s) || (max_time_milking == 0)) {
                min_time_s = t_start;
            }
            max_time_milking = max_time_e - min_time_s;
        }
        int t_end = max(max_time_e, t_prev_e);
        if ((t_start > t_end) && (t_start - t_end > max_time_no_milking) && ((t_start > 20) || (t_end > 20))){
            max_time_no_milking = t_start - t_end;
        }         
    }
    fout << max_time_milking << " " << max_time_no_milking << endl;
    return 0;
}
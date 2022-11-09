/*
ID: sadovay1
TASK: milk
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("milk.in");
ofstream fout("milk.out");

int greedy_search(vector<pair<int, int>>& price_amount, int target) {
    
    int current_units = 0, current_price = 0;
    sort(price_amount.begin(), price_amount.end(), [](const std::pair<int, int>& left, const std::pair<int, int>& right) {
        return left.first < right.first;
        });
    for (int i = 0; i < price_amount.size(); i++) {
        int units_needed = min(price_amount[i].second, target - current_units);
        current_price += price_amount[i].first * units_needed;
        current_units += units_needed;
        if (current_units == target) {
            return current_price;
        }
    }

}

int main() {

    int goal, N_farmers;
    fin >> goal >> N_farmers;
    vector<pair<int,int>> data(N_farmers);
    for (int i = 0; i < N_farmers; i++) {
        fin >> data[i].first >> data[i].second;
    }
    int score = 0;
    if ((goal > 0) && (N_farmers > 0)) {
        score = greedy_search(data, goal);
    }
    fout << score << endl;

    return 0;
}
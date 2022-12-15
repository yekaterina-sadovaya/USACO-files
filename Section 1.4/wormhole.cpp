/*
ID: sadovay1
TASK: wormhole
LANG: C++
*/
#include <algorithm>
#include <fstream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using AllSetup = set<pair<pair<int, int>, pair<int, int>>>;

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");

bool com_cycle_start(const AllSetup& comb, const pair<int, int>& start_point, std::set<pair<int, int>>& visited_points) {

    if (visited_points.find(start_point) != end(visited_points)) {
        return true;
    }

    visited_points.insert(start_point);

    for (const auto& link : comb) {
        const auto& point_from = link.first;
        const auto& point_to = link.second;

        if (start_point.second == point_from.second && start_point.first < point_from.first) {
            return com_cycle_start(comb, point_to, visited_points);
        }

    }

    return false;
}

vector<AllSetup> comp_all_comb(set<pair<int, int>> points) {

    if (points.size() == 0) {
        return { {} };
    }

    auto x = *begin(points);
    points.erase(x);

    vector<AllSetup> result;

    for (auto y : points) {
        auto tail = points;
        tail.erase(y);

        auto configs = comp_all_comb(tail);
        for (auto& pairs : configs) {
            pairs.emplace(x, y);
            pairs.emplace(y, x);
        }

        result.insert(end(result), begin(configs), end(configs));
    }

    return result;
}

bool can_cycle(const AllSetup& config, const set<pair<int, int>>& points) {
    return std::any_of(begin(points), end(points), [&](const auto& start) {
        std::set<pair<int, int>> visited;
        return com_cycle_start(config, start, visited);
        });
}

int main() {

    int N_holes;
    fin >> N_holes;

    int x, y;
    set<pair<int, int>> coordinates;
    for (int i = 0; i < N_holes; i++) {
        fin >> x >> y;
        coordinates.insert({ x, y });
    }

    auto combs = comp_all_comb(coordinates);
    int N = count_if(begin(combs), end(combs), [&](const auto& comb) {return can_cycle(comb, coordinates); });
    fout << N << endl;
}
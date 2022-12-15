/*
ID: sadovay1
TASK: holstein
LANG: C++
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ifstream fin("holstein.in");
ofstream fout("holstein.out");

bool compare_vectors(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < b[i]) {
			return true;
		}
	}
	return false;
}

void dfs(vector<int>& num_vitamins, vector<vector<int> >& num_scoops, int current_num, vector<int> myans, vector<int>& ans) {
	
	bool ReqSatisfiedFlag = true;
	myans.push_back(current_num + 1);

	for (int i = 0; i < num_vitamins.size(); i++) {
		num_vitamins[i] -= num_scoops[current_num][i];
	}

	for (int i = 0; i < num_vitamins.size(); i++) {
		if (num_vitamins[i] > 0) {
			ReqSatisfiedFlag = false;
			break;
		}
	}

	if (ReqSatisfiedFlag) {
		if (myans.size() < ans.size()) { 
			ans = myans;
		}
		else if (myans.size() == ans.size() && compare_vectors(myans, ans)) {
			ans = myans;
		}
		return;
	}

	for (int i = current_num + 1; i < num_scoops.size(); i++) {
		vector<int> tmp(num_vitamins);
		dfs(tmp, num_scoops, i, myans, ans);
	}
}

int main() {

	int V, G;
	fin >> V;
	vector<int> num_vits(V);
	for (int i = 0; i < V; i++) {
		fin >> num_vits[i];
	}

	fin >> G;
	vector<vector<int>> num_scoops(G, vector<int>(V));
	for (int i = 0; i < G; i++) {
		for (int j = 0; j < V; j++) {
			fin >> num_scoops[i][j];
		}
	}

	vector<int> ans(V, V);
	vector<int> myans;
	for (int i = 0; i < num_scoops.size(); i++) {
		vector<int> tmp(num_vits);
		dfs(tmp, num_scoops, i, myans, ans);
	}

	fout << ans.size();
	for (int i = 0; i < ans.size(); i++) {
		fout << " " << ans[i];
	}
	fout << endl;

    return 0;

}
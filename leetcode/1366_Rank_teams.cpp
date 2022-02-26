#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
int rank_note[26][26];
int voter = 0;
int candidate = 0;

int stringToInt(char p) {
	return p - 'A';
}

void setup(vector<string>& votes) {

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			rank_note[i][j] = 0;
		}
	}

	for (int i = 0; i < voter; i++) {
		for (int j = 0; j < candidate; j++) {
			int num = stringToInt(votes[i][j]);
			rank_note[j][num] ++;
		}
	}

 }

int find_same_rank(vector<int>& candidate_num, int rank_num) {
	vector<int> cand_num;
	int num = candidate_num.size();
	int max_num = -1;
	for (int i = 0; i < num; i++) {
		if (max_num == rank_note[rank_num][candidate_num[i]]) {
			cand_num.push_back(candidate_num[i]);
		}
		else if (max_num < rank_note[rank_num][candidate_num[i]]) {
			max_num = rank_note[rank_num][candidate_num[i]];
			cand_num.clear();
			cand_num.push_back(candidate_num[i]);
		}
	}

	if (cand_num.size() == 1) {
		return cand_num[0];
	}
	else {
		return find_same_rank(cand_num, rank_num + 1);
	}
	return -1;
}

string calculate() {
	string answer;
	vector<int> candidate_num;

	for (int i = 0; i < candidate; i++) {
		candidate_num.clear();
		int max_num = 1;
		for (int j = 0; j < 26; j++) {
			if (rank_note[i][j] == max_num) {
				candidate_num.push_back(j);
			}
			else if (rank_note[i][j] > max_num) {
				max_num = rank_note[i][j];
				candidate_num.clear();
				candidate_num.push_back(j);
			}
		}
		if (candidate_num.size() > 1) {
			candidate_num[0] = find_same_rank(candidate_num, i+1);
		}
		answer += candidate_num[0] + 'A';
		for (int j = 0; j < 26; j++) {
			rank_note[j][candidate_num[0]] = 0;
		}
	}
	return answer;
}
string rankTeams(vector<string>& votes) {
	voter = votes.size();

	if (voter == 1) {
		return votes[0];
	}

	candidate = votes[0].size();

	setup(votes);
	return calculate();
}
*/

string rankTeams(vector<string>& votes) {
	vector<vector<int>> count(26, vector<int>(27));
	for (char& c : votes[0])
		count[c - 'A'][26] = c;

	for (string& vote : votes)
		for (int i = 0; i < vote.length(); ++i)
			--count[vote[i] - 'A'][i];
	sort(count.begin(), count.end());
	string res;
	for (int i = 0; i < votes[0].length(); ++i)
		res += count[i][26];
	return res;
}

int main(void) {
	vector<string> problem = { "ABC","ACB","ABC","ACB","ACB" };
	cout << rankTeams(problem) << endl;
	return 0;
}
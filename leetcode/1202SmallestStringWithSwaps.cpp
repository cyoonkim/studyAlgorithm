#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int getParents(vector<int>& parents, int x) {
	return (parents[x] == x) ? x : getParents(parents, parents[x]);
}

void unionParents(vector<int>& parents, int a, int b) {
	a = getParents(parents, a);
	b = getParents(parents, b);
	if (a < b) {
		parents[b] = a;
	}
	else {
		parents[a] = b;
	}
}

bool findParents(vector<int>& parents, int a, int b) {
	return (getParents(parents, a) == getParents(parents, b)) ? true : false;
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
	int s_size = s.length();
	string answer;
	answer.resize(s_size,'a');

	vector<int> parents(s_size);
	for (int i = 0; i < s_size; i++)
		parents[i] = i;
	vector<int> visits(s_size, -1);

	for (auto a : pairs) {
		unionParents(parents, a[0], a[1]);
	}

	for (int i = 0; i < s_size; i++) {
		if (visits[i] != -1) continue;
		vector<int> num;
		priority_queue<int> pq;
		pq.push(-(s[i] - 'a'));
		num.push_back(i);
		for (int j = i+1; j < s_size; j++) {
			if (!findParents(parents, i, j)) 
				continue;
			num.push_back(j);
			visits[j] = 1;
			pq.push(-(s[j] - 'a'));
		}
		for (int j = 0; j < num.size(); j++) {
			int a = pq.top();
			pq.pop();
			answer[num[j]] = -a + 'a';
		}
	}
	return answer;
}

int main(void) {
	string s = "qdwyt";
	vector<vector<int>> pairs = { {2,3},{3,2},{0,1},{4,0},{3,2} };

	cout << smallestStringWithSwaps(s, pairs);

	return 0;
}
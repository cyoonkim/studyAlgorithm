/*
Runtime : 300ms
Memory : 708MB
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int maxEvents(vector<vector<int>>& events) {
	int answer = 0;
	int last = 0;
	sort(events.begin(), events.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	int event_size = events.size();
	int i = 0;

	while (i < event_size || pq.size()) {
		if (pq.empty()) {
			last = events[i][0];
		}
		while (i < event_size && events[i][0] == last)
			pq.push(events[i++][1]);
		pq.pop();
		answer++;
		last++;
		while (pq.size() && pq.top() < last) pq.pop();
	}

	return answer;

}

int main(void) {
	vector<vector<int>> v = {
		vector<int>({1,2}),
		vector<int>({2,3}),
		vector<int>({3,4}),
		vector<int>({1,2})
	};

	cout << maxEvents(v) << endl;
}
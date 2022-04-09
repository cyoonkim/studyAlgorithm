/*
Runtime: 24 ms, faster than 92.87% of C++ online submissions for Cheapest Flights Within K Stops.
Memory Usage: 14.1 MB, less than 43.93% of C++ online submissions for Cheapest Flights Within K Stops.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	vector<vector<pair<int, int>>> route(n); //src(dst,cost)
	for (auto a : flights)
		route[a[0]].push_back({ a[1],a[2] });
	
	using arr = array<int, 3>; //cost dst k(note) 
	priority_queue<arr, vector<arr>, greater<arr>> pq;
	pq.push({ 0, src, 0 });
	vector<int> value(n, INT_MAX);

	while (!pq.empty()) {
		arr p = pq.top();
		pq.pop();
		if (p[1] == dst) return p[0];
		if (p[2] > k) continue;
		if (value[p[1]] != INT_MAX && value[p[1]] < p[2]) continue;
		value[p[1]] = p[2];
		for (auto j : route[p[1]]) {
			pq.push({ p[0] + j.second, j.first, p[2] + 1 });
		}
	}
    return -1;
}

int main(void) {
	vector<vector<int>> flights = { {0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200} };
	cout << findCheapestPrice(4, flights, 0, 3, 1)<<endl;
	return 0;
}

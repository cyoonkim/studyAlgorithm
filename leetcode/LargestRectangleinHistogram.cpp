#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Data {
	int height;
	int idx;
};

int largestRectangleArea(vector<int>& heights) {
	stack<Data> d;
	int max_size = 0;
	int vector_size = heights.size();

	d.push({ heights[0], 0 });
	max_size = heights[0];

	for (int i = 1; i < vector_size; i++) {
		if (heights[i] < d.top().height) {
			int pop_size = 0;
			int idx = 0;
			while (d.size()!= 0 && heights[i] < d.top().height) {
				idx = d.top().idx;
				max_size = max(max_size, d.top().height * (i - idx));
				d.pop();
			}
			d.push({heights[i],idx});
			
		}
		else {
			d.push({heights[i], i});
		}
	}

	int stack_size = d.size();
	for (int i = 1; i <= stack_size; i++) {
		max_size = max(max_size, d.top().height * (vector_size - d.top().idx));
		d.pop();
	}

	return max_size;
}

int main(void) {
	vector<int> v = {0,9 };
	if (largestRectangleArea(v) == 9)
		cout << "성공";
	else
		cout << "실패";
	return 0;
}


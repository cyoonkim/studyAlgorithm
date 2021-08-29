/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.7 MB, less than 21.75% of C++ online submissions for Letter Combinations of a Phone Number.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> phone = {
	{"a","b","c"},
	{"d","e","f"},
	{"g","h","i"},
	{"j","k","l"},
	{"m","n","o"},
	{"p","q","r","s"},
	{"t","u","v"},
	{"w","x","y","z"}
};

vector<string> returnValue;
string m_digit;

void letterCombine(string s, int n) {
	if (m_digit.size() == s.size()) {
		returnValue.push_back(s);
		return;
	}
	for (string x : phone[m_digit[n]-'2']) {
		letterCombine(s + x, n + 1);
	}
}

vector<string> letterCombinations(string digits) {
	if (digits.size()!=0) {
		m_digit = digits;
		letterCombine("", 0);
	}
	return returnValue;
}

int main(void) {
	string digit = "3";
	vector<string> answer = letterCombinations(digit);

	

	return 0;
}
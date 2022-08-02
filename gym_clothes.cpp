#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	vector<int> student(n + 1, 1); 

	for (int i = 0; i < lost.size(); i++) 
		student[lost[i]]--;

	for (int i = 0; i < reserve.size(); i++) 
		student[reserve[i]]++;

	for (int i = 1; i <= n; i++) {
		if (student[i])
			continue;
		if(student[i-1] == 2){ 
			student[i - 1]--;
			student[i]++;
		}
		else if(student[i+1] == 2){ 
			student[i + 1]--;
			student[i]++;
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (student[i]) 
			answer++;
	}
	return answer;
}

// 프로그래머스 메인함수
int main() {
	int n;
	vector<int> lost = { 2, 4 };
	vector<int> reserve = { 1, 3, 5 };
	int n = 5;
	cout << solution(n, lost, reserve);
}
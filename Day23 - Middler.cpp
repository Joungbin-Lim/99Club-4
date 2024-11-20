#include <string>
#include <vector>

using namespace std;

int answer = 0;
int MAXNUM = 1;
vector<int> made_numbers;
void backtrack(int n, string numbers, string cur, vector<int> check) {
    if (cur.size()) {
        int num = stoi(cur);
        made_numbers.push_back(num);
    }
    int i;
    for (i = 0; i < n; ++i) {
        if (check[i] == 1) continue;
        check[i] = 1;
        backtrack(n, numbers, cur + numbers[i], check);
        check[i] = 0;
    }
}

int solution(string numbers) {
    int n = numbers.size();
    vector<int> check(n, 0);
    int i, j;
    for (i = 0; i < n; ++i) {
        MAXNUM *= 10;
    }
    vector<int> prime(MAXNUM, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (i = 2; i * i < MAXNUM; ++i) {
        for (j = i * i; j < MAXNUM; j += i) {
            prime[j] = 0;
        }
    }
    backtrack(n, numbers, "", check);
    for (auto x: made_numbers) {
        if (prime[x] == 1) {
            prime[x] = 2;
            answer += 1;
        }
    }
    return answer;
}
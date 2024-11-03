#include <string>
#include <vector>

using namespace std;

int alp_ord[5] = {781, 156, 31, 6, 1};

int solution(string word) {
    string s = "";
    for(auto x : word) {
        if(x == 'A') s += '0';
        else if(x == 'E') s += '1';
        else if(x == 'I') s += '2';
        else if(x == 'O') s += '3';
        else s += '4';
    }
    int answer = 0;
    for(int i = 0; i < s.size(); ++i) {
        char x = s[i];
        int y = x - '0';
        answer += (alp_ord[i] * y + 1);
    }
    return answer;
}
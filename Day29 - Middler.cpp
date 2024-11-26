#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    int t;
    int n;
    int i;
    vector<ll> waves = {0, 1, 1, 1, 2, 2};
    
    for(i = 6; i <= 100; ++i) {
    	ll x = waves[i - 1] + waves[i - 5];
    	waves.push_back(x);
    }
    cin >> t;
    while(t--) {
    	cin >> n;
    	cout << waves[n] << "\n";
    }

    return 0;
}
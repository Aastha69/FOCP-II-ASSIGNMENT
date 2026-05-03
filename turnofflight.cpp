
#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

bool can(int l) {
    int ops = 0;
    
    for (int i = 0; i < n;) {
        if (s[i] == '1') {
            ops++;
            i += l;  // turn off l bulbs
        } else {
            i++;
        }
    }
    
    return ops <= k;
}

int main() {
    cin >> n >> k;
    cin >> s;

    int low = 1, high = n, ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (can(mid)) {
            ans = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}

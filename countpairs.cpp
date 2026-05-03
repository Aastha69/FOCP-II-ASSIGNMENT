#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll countDistinctPrimes(ll n) {
    ll cnt = 0;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            while (n % i == 0) n /= i;
        }
    }

    if (n > 1) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        ll n;
        cin >> n;

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        ll k = countDistinctPrimes(n);

        cout << (1LL << k) << "\n";  // FIXED
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end(), greater<int>());

        unordered_set<int> alex_taken, bob_taken;

        long long alex = 0, bob = 0;
        bool turn = 0; // 0 = Alex, 1 = Bob

        for (int i = 0; i < n; i++) {
            if (!turn) {
                if (alex_taken.find(a[i]) == alex_taken.end()) {
                    alex += a[i];
                    alex_taken.insert(a[i]);
                    turn = 1;
                }
            } else {
                if (bob_taken.find(a[i]) == bob_taken.end()) {
                    bob += a[i];
                    bob_taken.insert(a[i]);
                    turn = 0;
                }
            }
        }

        if (alex > bob) cout << "Alex\n";
        else cout << "Bob\n";
    }

    return 0;
}

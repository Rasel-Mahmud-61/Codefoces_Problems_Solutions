#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        map<int, int> consA, consB;

        int cons = 0;
        for (int i = 0; i < n; i++) {
            cons++;
            if (i == n - 1 || a[i + 1] != a[i]) {
                consA[a[i]] = max(consA[a[i]], cons);
                cons = 0;
            }
        }

        cons = 0;
        for (int i = 0; i < n; i++) {
            cons++;
            if (i == n - 1 || b[i + 1] != b[i]) {
                consB[b[i]] = max(consB[b[i]], cons);
                cons = 0;
            }
        }

        int ans = 0;
for (const auto& pair : consA) {
    int v = pair.first;
    int val = pair.second;
    ans = max(ans, val + consB[v]);
}

for (const auto& pair : consB) {
    int v = pair.first;
    int val = pair.second;
    ans = max(ans, consA[v] + val);
}
      cout<<ans<<endl; 
    }

    return 0;
}

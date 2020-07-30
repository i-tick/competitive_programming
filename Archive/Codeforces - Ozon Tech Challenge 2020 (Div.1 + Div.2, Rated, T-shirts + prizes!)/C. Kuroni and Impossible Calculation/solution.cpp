#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0, m = 0;
    cin >> n >> m;
    int ans = 1;
    vi a(n + 1);
    rf(i, 1, n) cin >> a[i];
    if (n < 1005) {
        rf(i, 1, n) rf(j, i + 1, n) ans = (1LL * ans * abs(a[i] - a[j])) % m;
        cout << ans << "\n";
        return 0;
    }
    cout << 0 << "\n";
}
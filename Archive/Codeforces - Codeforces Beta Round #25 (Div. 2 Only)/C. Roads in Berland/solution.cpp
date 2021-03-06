#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;
typedef vector<ll> vl;

const int N = 301;
int n;
int m[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> m[i][j];
    }
  }
  int k;
  cin >> k;
  while (k--) {
    int u, v, w;
    cin >> u >> v >> w;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        m[i][j] = min(m[i][j], m[u][i] + w + m[v][j]);
        m[i][j] = min(m[i][j], m[u][j] + w + m[v][i]);
      }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ans += m[i][j];
      }
    }
    cout << ans / 2 << " ";
  }
  cout << "\n";
}
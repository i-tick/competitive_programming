#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (b >= c && a <= d) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
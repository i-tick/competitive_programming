#include "bits/stdc++.h"

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

ofstream out;
stringstream in;

string TextFileToString(string filename) {
    ostringstream dosString(ios::out | ios::binary); // *** binary
    ifstream inFile(filename.c_str());

    string line;
    while (getline(inFile, line))
        dosString << line << "\r\n";

    return dosString.str();
}

// get correct input format from rawInput
void get(string name) { in << TextFileToString(name); }

int ___solve();

int main(int argc, char *argv[]) {
    string name = string(argv[1]);
    get(name);
    out.open(name);
    out << in.str();
    out.close();
    if (argv[2][0] == 't') {
        name.pop_back();
        name.pop_back();
        name.pop_back();
        out.open(name + ".out");
        out << fixed << setprecision(10);
        ___solve();
        out.close();
    }
}int ___solve() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  in >> tt;
  while (tt--) {
    int n, k;
    in >> n >> k;
    vector<int> a(n);
    int zeros = 0;
    for (int i = 0; i < n; i++) {
      in >> a[i];
      a[i] = (a[i] < k ? -1 : (a[i] > k ? 1 : 0));
      zeros += (a[i] == 0);
    }
    if (zeros == 0) {
      out << "no" << '\n';
      continue;
    }
    if (zeros == n) {
      out << "yes" << '\n';
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      ok |= (a[i] >= 0 && a[i + 1] >= 0);
    }
    for (int i = 0; i < n - 2; i++) {
      ok |= (a[i] >= 0 && a[i + 2] >= 0);
    }
    out << (ok ? "yes" : "no") << '\n';
  }
  return 0;
}

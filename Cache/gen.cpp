#include "bits/stdc++.h"

using namespace std;

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
}
const int N = 3e5 + 5;
const int INF = 1e9 + 5;
 
int n, a[N], f[N];

int ___solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  in >> n;
  for (int i = 1; i <= n; i++) {
    f[i] = N;
    in >> a[i];
  }
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] == a[i]) {
      f[i] = f[i - 1] + 1;
    }
    if (a[i - 1] > a[i]) {
      int cur = INF;
      for (int j = i - 1; j >= 1; j--) {
        if (a[j] < cur) {
          f[i] = min(f[i], f[j] + 1);
          cur = a[j];
          if (cur <= a[i]) {
            break;
          }
        }
      }
    }
    if (a[i - 1] < a[i]) {
      int cur = 0;
      for (int j = i - 1; j >= 1; j--) {
        // out << j << "\n";
        if (a[j] > cur) {
          f[i] = min(f[i], f[j] + 1);
          cur = a[j];
          if (cur >= a[i]) {
            break;
          }
        }
      }
    }
  }
  out << f[n] << "\n";
  return 0;
}

/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author cunbidun
 */

#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define rf(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) out << (#x) << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;

class Task47D {
public:

    int n, m;
    string s[11];
    int a[11];
    vi match;
    int ans = 0;

    void backtrack(int pos) {
        if (pos == n + 1) {
            ans++;
            return;
        }
        int f = 0;
        rf(i, 1, m) {
            if (s[i][pos - 1] == '1') match[i]++;
            if (match[i] > a[i]) f = 1;
            if (n - pos + 1 == a[i] - match[i] && s[i][pos - 1] == '0') f = 1;
        }
        if (!f)
            backtrack(pos + 1);
        rf(i, 1, m)if (s[i][pos - 1] == '1') match[i]--;

        f = 0;
        rf(i, 1, m) {
            if (s[i][pos - 1] == '0') match[i]++;
            if (match[i] > a[i] || n - pos + 1 < a[i] - match[i]) f = 1;
            if (n - pos + 1 == a[i] - match[i] && s[i][pos - 1] == '1') f = 1;
        }
        if (!f)
            backtrack(pos + 1);
        rf(i, 1, m)if (s[i][pos - 1] == '0') match[i]--;

    }

    void solve(istream &in, ostream &out) {
        match.assign(11, 0);
        in >> n >> m;
        rf(i, 1, m)in >> s[i] >> a[i];
        backtrack(1);
        out << ans << "\n";
    }
};

class TestCase {
public:
    static constexpr bool printWAOnly = false;
    static constexpr int numTest = 0;
    static constexpr bool haveAns = false;

    static void generateTest(ostream &test) {
    }

    static void solve(istream &in, ostream &out) {
    }
};

class Checker {
public:
    static constexpr double arg = 0.0;

    static bool check(istream &in, istream &out) {
    }
};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   	Task47D solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    out << fixed << setprecision(10);
	solver.solve(in, out);
	return 0;
}
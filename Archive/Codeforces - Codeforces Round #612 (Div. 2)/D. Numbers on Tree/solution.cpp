/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author cunbidun
 */

#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef vector<int> vi;

const int N = 2e3 + 1;

class Task1287D {
public:
    int n, root = -1, c[N], ans[N], size[N];
    bool used[N], done = 0;
    vi tree[N];

    void dfs(int u, std::ostream &out) {
        int cnt = 0;
        int val = 0;
        size[u] = 1;
        while (cnt <= c[u]) {
            val++;
            if (val > n)
                done = true;
            if (!used[val])
                cnt++;
        }
        ans[u] = val;
        used[val] = true;
        for (int v : tree[u]) {
            dfs(v, out);
            size[u] += size[v];
        }
        if (c[u] >= size[u])
            done = true;
    }

    void solve(std::istream &in, std::ostream &out) {
        in >> n;
        for (int i = 1; i <= n; i++) {
            used[i] = false;
            int p;
            in >> p >> c[i];
            if (p == 0) root = i;
            else
                tree[p].pb(i);
        }
        dfs(root, out);
        if (!done) {
            out << "YES" << "\n";
            for (int i = 1; i <= n; i++)
                out << ans[i] << " ";
            out << "\n";
        } else
            out << "NO" << "\n";
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Task1287D solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
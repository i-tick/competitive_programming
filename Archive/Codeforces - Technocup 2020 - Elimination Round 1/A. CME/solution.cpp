/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author cunbidun
 */

#include <bits/stdc++.h>

using namespace std;

class ACME {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            int n;
            in >> n;

            if (n < 4) {
                out << 4 - n << "\n";
                continue;
            }

            out << n % 2 << "\n";
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ACME solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
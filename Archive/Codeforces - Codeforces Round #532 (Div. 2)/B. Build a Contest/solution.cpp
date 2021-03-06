#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, cnt[MAXA],m, num;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    rf(i, 1, m) {
        int x;
        cin >> x;
        if(cnt[x] == 0) {
            cnt[x]++;
            num ++;
        }
        else cnt[x]++;
        if(num == n) {
            cout << "1";
            rf(j, 1, n) {
                cnt[j]--;
                if(cnt[j] == 0) num --;
            }

        } else cout << "0";
    }
    return 0;
}
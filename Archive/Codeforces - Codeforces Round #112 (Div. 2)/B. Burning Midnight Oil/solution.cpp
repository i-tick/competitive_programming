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
#define reset(a,v,b) rf(i, 0, b) a[i] = v

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,k;
bool check(int m) {
    ll kk = 1;
    ll ans = 0LL;
    rf(i,0,40) {
        ans += 1LL * m /kk;
        kk *= k;
        if(m/kk == 0) return (ans >= n);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> k;
    int l = 1, r = n;
    while(l != r) {
        if(l == r - 1) {
            if(check(l)) r = l;
            else l = r;
        }
        int m = (l + r) >> 1;
        if(check(m)) r = m;
        else l = m + 1;
    }
    cout << l;
    return 0;
}
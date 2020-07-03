#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
  return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  os << '[';
  for (unsigned int i = 0; i < a.size(); i++)
    os << a[i] << (i < a.size() - 1 ? ", " : "");
  os << ']';
  return os;
}

template <class T>
class Matrix {
  vector<vector<T>> a;
  int r, c;

public:
  void init(int r, int c) {
    this->r = r;
    this->c = c;
    a.resize(r);
    for (int i = 0; i < r; i++) {
      a[i].resize(c);
    }
  }

  Matrix operator+(const Matrix &o) const {
    Matrix res;
    res.init(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        res.a[i][j] = a[i][j] + o.a[i][j];
      }
    }
    return res;
  }

  Matrix operator*(const Matrix &o) const {
    Matrix res;
    res.init(r, o.c);
    for (int i = 0; i < r; i++) {
      for (int j = i; j < r; j++)
        for (int k = i; k <= j; k++) {
          res.a[i][j] = max(res.a[i][j], a[i][k] + o.a[k][j]);
        }
    }
    return res;
  }

  Matrix power(int p) const {
    if (p == 0) {
      Matrix res;
      res.init(r, r);
      return res;
    }
    if (p == 1) {
      Matrix res(*this);
      return res;
    }
    Matrix tmp = power(p / 2);
    if (p % 2 == 0) {
      return tmp * tmp;
    }
    return *this * tmp * tmp;
  }

  vector<T> &operator[](int i) {
    return a[i];
  }

  friend std::ostream &operator<<(std::ostream &stream, const Matrix &matrix) {
    for (int i = 0; i < matrix.r; i++) {
      for (int j = 0; j < matrix.c; j++) {
        stream << matrix.a[i][j] << " ";
      }
      stream << endl;
    }
    return stream;
  }
};

int n, T;
int a[101];
vi l;
map<int, int> mp;
void compress() {
  sort(all(l));
  l.resize(distance(l.begin(), unique(all(l))));
  for (int i : l)
    mp[i] = sz(mp) + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l.push_back(a[i]);
  }
  compress();
  for (int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
  }

  Matrix<int> base;
  base.init(n, n);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      vi tmp;
      tmp.push_back(0);
      for (int k = 1; k <= n; k++) {
        if (a[k] >= i && a[k] <= j) {
          tmp.push_back(a[k]);
        }
      }
      vi arr(n + 1);
      arr[1] = 1;
      int res = 1;
      for (int k = 2; k < sz(tmp); k++) {
        int cur = 0;
        for (int x = 1; x < k; x++) {
          if (tmp[k] >= tmp[x]) {
            cur = max(cur, arr[x]);
          }
        }
        arr[k] = cur + 1;
        res = max(res, arr[k]);
      }
      base[i - 1][j - 1] = res;
    }
  }

  base = base.power(T);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = max(ans, base[i - 1][j - 1]);
    }
  }
  cout << ans << "\n";
}
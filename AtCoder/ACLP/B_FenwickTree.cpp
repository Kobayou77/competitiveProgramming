#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int>  pint;
typedef pair<ll,ll>    pll;
typedef vector<int>    vint;
typedef vector<ll>     vll;
typedef vector<string> vstr;
typedef vector<pint>   vpint;
typedef vector<pll>    vpll;

#define vint2(v,n,m,init) vector<vector<int>> v(n, vector<int>(m, init))
#define vll2(v,n,m,init)  vector<vector<ll>>  v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vint var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vstr var(n); rep(i,n){cin >> var[i];}
#define ALL(var)         (var).begin(), (var).end()
#define sortall(var)     sort(ALL(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());

#define prt(var)         cout << (var) << "\n"
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//-----------------------------------------------------------------------------
class FenwickTree{

public:
  int n;
  vector<ll> dat;

  FenwickTree(int _n){
    n = _n;
    dat.resize(n, 0);
  }
  ~FenwickTree(){}

  void add(int p, ll x) {
      assert(0 <= p && p < n);
      p++;
      while (p <= n) {
          dat[p - 1] += x;
          p += p & -p;
      }
  }

  ll sum(int l, int r) {
      assert(0 <= l && l <= r && r <= n);
      return sum(r) - sum(l);
  }

private:
  ll sum(int r) {
      ll s = 0;
      while (r > 0) {
          s += dat[r - 1];
          r -= r & -r;
      }
      return s;
  }
};

int main(void){
  int n, q;
  cin >> n >> q;
  FenwickTree ft(n);
  arr(a,n);

  rep(i,n){
    ft.add(i, a[i]);
  }

  vll ans;
  rep(i,q){
    int t;
    cin >> t;
    if(t==0){
      int i;
      ll x;
      cin >> i >> x;
      ft.add(i, x);
    } else {
      int l, r;
      cin >> l >> r;
      ans.push_back(ft.sum(l, r));
    }
  }

  for(auto k: ans){
    prt(k);
  }
}

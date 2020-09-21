#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec                vector<int>
#define vecll              vector<ll>
#define vecd               vector<double>
#define vecst              vector<string>
#define vecb               vector<bool>
#define vec2(var, n, m)    vector<vector<int>> var(n, vector<int>(m, 0))
#define vecll2(var, n, m)  vector<vector<ll>> var(n, vector<ll>(m, 0))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define f_sum(var)       accumulate(all(var), 0)
#define f_sumll(var)     accumulate(all(var), 0LL)
#define chmin(v1, v2)    v1 = min(v1, v2)
#define chmax(v1, v2)    v1 = max(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << var;
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt(ok ? "yes" : "no");}
//----------------------------------------------------------------
#define bitrep(i, n)     for(ll i=0; i<(ll) (1<<(n)); i++)
#define bis(i, j)        i & (1<<j)

int main(void) {
  int n;
  cin >> n;
  vecd x(n), y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }

  vec v;
  rep(i,n){
    v.pb(i);
  }

  double ans=0.0;
  double num=0.0;
  do {
    //prtall(v);
    rep(i,n-1){
      double d=0;
      d += (x[v[i+1]] - x[v[i]])*(x[v[i+1]] - x[v[i]]);
      d += (y[v[i+1]] - y[v[i]])*(y[v[i+1]] - y[v[i]]);
      d = sqrt(d);
      ans+=d;
    }
    num+=1.0;
  } while(next_permutation(all(v)));
  ans /= num;
  prtd(10, ans);
}

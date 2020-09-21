#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec              vector<int>
#define vecll            vector<ll>
#define vecd             vector<double>
#define vecst            vector<string>
#define vecb             vector<bool>
#define v2(v,n,m,init)   vector<vector<int>>  v(n, vector<int>(m, init))
#define vb2(v,n,m,init)  vector<vector<bool>> v(n, vector<bool>(m, init))
#define vll2(v,n,m,init) vector<vector<ll>>   v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//------------------------------------------------------------------
ll power(ll x, ll y){
  if(y==0) return 1;
  if(y==1) return x;
  if(y%2==1){
    ll t = power(x, y/2);
    return (((x * t)%MOD) * t) % MOD;
  } else {
    ll t = power(x, y/2);
    return (t * t)%MOD;
  }
}

int main(void){
  int n, q;
  cin >> n >> q;
  arrll(a,n);
  vec c(q+2);
  c[0] = 0;
  c[q+1] = 0;
  rep(i,q){
    cin >> c[i+1];
    c[i+1]--;
  }

  vecll sum(n);
  sum[0] = 0;
  rep(i,n-1){
    sum[i+1] = power(a[i], a[i+1]) + sum[i];
    sum[i+1] %= MOD;
  }

  ll ans=0;
  rep(i,q+1){
    if(c[i+1]>c[i]) ans += sum[c[i+1]] - sum[c[i]];
    else ans += sum[c[i]] - sum[c[i+1]];
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
  }

  prt(ans);
}

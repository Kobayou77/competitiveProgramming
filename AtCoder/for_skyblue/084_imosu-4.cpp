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

int main(void){
  int n, m;
  cin >> n >> m;
  vec a(m), b(m), x(m);
  rep(i,m){
    cin >> a[i] >> b[i] >>x[i];
    a[i]--, b[i]--;
  }

  v2(sum, n+2, n+2, 0);

  rep(i,m){
    sum[a[i]][b[i]]++;
    sum[a[i]][b[i]+1]--;
    sum[a[i]+x[i]+1][b[i]]--;
    sum[a[i]+x[i]+2][b[i]+1]++;
    sum[a[i]+x[i]+1][b[i]+x[i]+2]++;
    sum[a[i]+x[i]+2][b[i]+x[i]+2]--;
  }

  rep(i,n+1){
    rep(j,n+1){
      sum[i][j+1] += sum[i][j];
    }
  }
  rep(i,n+1){
    rep(j,n+1){
      sum[j+1][i]+=sum[j][i];
    }
  }
  rep(i,n){
    rep(j,n-i-1){
      sum[i+j+1][j+1]+=sum[i+j][j];
    }
  }

  int ans=0;
  rep(i,n){
    rep(j,n){
      if(sum[i][j]>0) ans++;
    }
  }

  prt(ans);

}

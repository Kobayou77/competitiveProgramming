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
//----------------------------------------------------------------

int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  rep(i,n){
    if(s[i]=='J') s[i]='0';
    if(s[i]=='O') s[i]='1';
    if(s[i]=='I') s[i]='2';
  }

  vll2(dp, n+1, 8, 0);
  dp[0][1] = 1;

  rep(i,n){
    rep(j,8){
      rep(k,8){
        bool ok=false;
        rep(chk,3){
          if(j&(1<<chk) && k&(1<<chk)) ok=true;
        }
        if(!(k&(1<<(s[i]-'0')))) ok=false;
        if(!ok) continue;
        dp[i+1][k] += dp[i][j];
        dp[i+1][k] %= 10007;
      }
    }
  }
/*
  rep(i,n+1){
    rep(j,8){
      cout << dp[i][j] << (j!=7 ? " " : "\n");
    }
  }
*/
  int ans=0;
  rep(i,8){
    ans += dp[n][i];
    ans %= 10007;
  }

  prt(ans);
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec                vector<int>
#define vecll              vector<ll>
#define vecd               vector<double>
#define vecst              vector<string>
#define vecb               vector<bool>
#define vec2(var, n, m)    vector<vector<int>>  var(n, vector<int>(m, 0))
#define vecb2(var, n, m)   vector<vector<bool>> var(n, vector<bool>(m, false))
#define vecll2(var, n, m)  vector<vector<ll>>   var(n, vector<ll>(m, INF))

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
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt(ok ? "Yes" : "No");}
//----------------------------------------------------------------

int main(void) {
  int n;
  cin >> n;
  arrll(a,n);
  rep(i,n){
    a.pb(a[i]);
  }

  //prtall(a);

  ll INF = -1e18;
  vecll2(dp, 2*n, 2*n);

  rep(i,2*n){
    dp[i][i] = a[i];
  }

  REP(num,2,n+1){
    rep(i,2*n+1-num){
      int j=i+num-1;
      if(num&1){
        ll tmp1 = dp[i+1][j] + a[i];
        ll tmp2 = dp[i][j-1] + a[j];
        dp[i][j] = max(tmp1, tmp2);
      } else {
        ll tmp1 = INF;
        ll tmp2 = INF;
        if(num==n){
          tmp1 = dp[i+1][j];
          tmp2 = dp[i][j-1];
        } else {
          if(j+1!=2*n){
            if(a[i]>a[j+1]){
              tmp1 = dp[i+1][j];
            }
          }
          if(i-1!=-1){
            if(a[i-1]<a[j]){
              tmp2 = dp[i][j-1];
            }
          }
        }
        dp[i][j]=max(tmp1, tmp2);
      }
      //prt3(i, j, dp[i][j]);
    }
  }

  ll ans=INF;
  rep(i,n){
    chmax(ans, dp[i][i+n-1]);
  }

  prt(ans);


}

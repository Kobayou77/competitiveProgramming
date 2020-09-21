#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec                vector<int>
#define vecll              vector<ll>
#define vecd               vector<double>
#define vecst              vector<string>
#define vecb               vector<bool>
#define vec2(var, n, m)    vector<vector<int>>  var(n, vector<int>(m, INF))
#define vecb2(var, n, m)   vector<vector<bool>> var(n, vector<bool>(m, false))
#define vecll2(var, n, m)  vector<vector<ll>>   var(n, vector<ll>(m, 0))

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
  int INF = 1e9;
  vec2(flag, 5, n);
  rep(i,5){
    rep(j,n){
      char tmp;
      cin >> tmp;
      if(tmp=='R') flag[i][j]=0;
      if(tmp=='B') flag[i][j]=1;
      if(tmp=='W') flag[i][j]=2;
      if(tmp=='#') flag[i][j]=-1;
    }
  }


  vec2(dp, n+1, 3);
  rep(i,3){
    dp[0][i]=0;
  }
  rep(i,n){
    vec num(3);
    rep(j,5){
      rep(k,3){
        if(flag[j][i]!=k) num[k]++;
      }
    }
    //prtall(num);
    rep(j,3){
      rep(k,3){
        if(j!=k) chmin(dp[i+1][j], dp[i][k]+num[j]);
      }
    }
  }

  prt(min({dp[n][0], dp[n][1], dp[n][2]}));
}

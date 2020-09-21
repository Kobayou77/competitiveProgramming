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
  int v, e;
  cin >> v >> e;
  vector<vector<ll>> dist(v, vector<ll>(v, -1));
  rep(i,e){
    ll a, b, d;
    cin >> a >> b >> d;
    dist[a][b] = d;
  }

  ll INF = 1e18;
  vector<vector<ll>> dp((1<<v), vector<ll>(v, INF));
  dp[1][0] = 0;
  rep(i,(1<<v)){
    rep(j,v){
      if(dp[i][j]==INF) continue;
      rep(k,v){
        if(i&(1<<k)) continue;
        if(dist[j][k]<0) continue;

        int next_i = i | (1<<k);
        chmin(dp[next_i][k], dp[i][j] + dist[j][k]);
      }
    }
  }

  ll ans=INF;
  rep(i,v){
    if(dist[i][0]<0)continue;
    chmin(ans, dp[(1<<v)-1][i] + dist[i][0]);
  }

  if(ans==INF){
    prt(-1);
  } else {
    prt(ans);
  }

}

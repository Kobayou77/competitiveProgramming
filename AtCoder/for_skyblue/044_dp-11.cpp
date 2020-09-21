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
  int n = 1000000;
  int INF = 1e9;
  vec dp1(n+1, INF), dp2(n+1, INF);
  vec simen, simen_odd;
  REP(i,1,200){
    int tmp = i*(i+1)*(i+2)/6;
    if(tmp>1000000) break;
    simen.pb(tmp);
    if(tmp%2==1) simen_odd.pb(tmp);
  }
  dp1[0]=0;
  dp2[0]=0;

  REP(i,1,1000000){
    rep(j,simen.size()){
      if(i-simen[j]>= 0) chmin(dp1[i], dp1[i-simen[j]]+1);
    }
    rep(j,simen_odd.size()){
      if(i-simen_odd[j]>= 0) chmin(dp2[i], dp2[i-simen_odd[j]]+1);
    }
  }

  while(1){
    int q;
    cin >> q;
    if(q==0) break;

    prt2(dp1[q], dp2[q]);
  }
}

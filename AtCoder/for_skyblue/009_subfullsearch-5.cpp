#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec                vector<int>
#define vecll              vector<ll>
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
void prtok(bool ok){prt(ok ? "Yes" : "No");}
//----------------------------------------------------------------

int main(void) {
  int m;
  cin >> m;
  vecll star_x(m), star_y(m);
  ll offset_x, offset_y;
  rep(i,m){
    cin >> star_x[i] >> star_y[i];
    if(i==0){
      offset_x = star_x[0];
      offset_y = star_y[0];
    }
    star_x[i]-= offset_x;
    star_y[i]-= offset_y;
  }
  int n;
  cin >> n;
  vecll sky_x(n), sky_y(n);
  map<pair<ll, ll>, int> exist;
  rep(i,n){
    cin >> sky_x[i] >> sky_y[i];
    exist.emplace(make_pair(sky_x[i], sky_y[i]), 1);
  }
  rep(i,n){
    ll set_x=sky_x[i], set_y=sky_y[i];
    bool ok=true;
    REP(j,1,m){
      if(exist.find(make_pair(set_x+star_x[j],set_y+star_y[j]))==exist.end()){
        ok=false;
      }
    }
    if(ok) {
      //prt2("----->", i);
      prt2(set_x-offset_x, set_y-offset_y);
    }
  }

}

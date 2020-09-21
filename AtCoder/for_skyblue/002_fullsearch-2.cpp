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
#define mp(v1, v2)       make_pair(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << var;
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt(ok ? "Yes" : "No");}
//----------------------------------------------------------------
void make_divisors(vector<ll> &v, ll x){
  for(ll i=1; i*i<=x; i++){
    if(x%i==0){
      v.push_back(i);
      if(i!=x/i) v.push_back(x/i);
    }
  }
  sort(v.begin(), v.end());
}

int main(void) {
  int n;
  cin >> n;

  int ans=0;
  REP(i,1,n+1){
    if(i%2==0) continue;
    vecll v;
    make_divisors(v, i);
    if(v.size()==8) ans++;
  }

  prt(ans);

}

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

int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans=0;
  rep(k1,10){
    int i=0;
    while(1){
      if(s[i]-'0'==k1) break;
      else {
        i++;
        if(i==n) break;
      }
    }
    if(i>n-3) continue;
    rep(k2,10){
      int j=i+1;
      while(1){
        if(s[j]-'0'==k2) break;
        else {
          j++;
          if(j==n) break;
        }
      }
      if(j>n-2) continue;
      rep(k3,10){
        int k=j+1;
        while(1){
          if(s[k]-'0'==k3) break;
          else {
            k++;
            if(k==n) break;
          }
        }
        if(k<n){
          ans++;
          //prt3(k1, k2, k3);
        }
      }
    }
  }

  prt(ans);
}

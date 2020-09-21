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
void prtok(bool ok){prt(ok ? "yes" : "no");}
//----------------------------------------------------------------
#define bitrep(i, n)     for(ll i=0; i<(ll) (1<<n); i++)
#define bis(i, j)        i & (1<<j)

int main(void) {
  int n, m;
  cin >> n >> m;
  bool light[m][n];
  rep(i,m){
    rep(j,n){
      light[i][j]=false;
    }
  }
  rep(i,m){
    int num;
    cin >> num;
    rep(j,num){
      int tmp;
      cin >> tmp;
      tmp--;
      light[i][tmp]=true;
    }
  }
  arr(p,m);

  int ans=0;
  bitrep(i,n){
    int lightnum=0;
    rep(j,m){
      int on=0;
      rep(k,n){
        if(bis(i,k)){
           if(light[j][k]) {on++;}
        }
      }
      if(on%2==p[j]){lightnum++;}
    }
    if(lightnum==m){ans++;}
  }

  prt(ans);
}

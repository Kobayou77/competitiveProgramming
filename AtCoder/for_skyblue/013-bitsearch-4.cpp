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
  int r, c;
  cin >> r >> c;
  vec2(a, r, c);
  vec2(b, r, c);
  vec ura(c, 0);
  rep(i,r){
    rep(j,c){
      cin >> a[i][j];
      b[i][j] = a[i][j];
      if(!b[i][j]) ura[j]++;
    }
  }

  int ans=0;
  bitrep(i,r){
    vec uratmp = ura;
    rep(j,r){
      if(bis(i,j)){
        rep(k,c){
          b[j][k] = (a[j][k] ? 0 : 1);
          uratmp[k] += (a[j][k] ? 1 : -1);
        }
      } else {
        rep(k,c){
          b[j][k] = a[j][k];
        }
      }
    }
    //prt("===Deb");
    //prtall(uratmp);
    /*
    rep(j,r){
      rep(k,c){
        cout << b[j][k] << (k!=c-1 ? " " : "\n");
      }
    }
    */

    int tmp=0;
    rep(j,c){
      tmp += max(uratmp[j], r-uratmp[j]);
    }
    chmax(ans, tmp);
  }

  prt(ans);
}

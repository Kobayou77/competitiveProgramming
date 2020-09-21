#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec                vector<int>
#define vecll              vector<ll>
#define vecd               vector<double>
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

int main(void) {
  int k;
  cin >> k;
  vec row(8, -1);
  rep(i,k){
    int r, c;
    cin >> r >> c;
    row[r]=c;
  }
  vec v(8);
  rep(i,8){
    v[i] = i;
  }

  do {
    bool ok=true;
    rep(i,8){
      if(row[i] >0 && v[i]!=row[i]){
        ok=false;
      }
    }
    if(!ok) continue;

    rep(i,8){
      rep(j,8){
        if(i==j) continue;
        if(v[j]==v[i]-abs(i-j)) ok=false;
        if(v[j]==v[i]+abs(i-j)) ok=false;
        if(v[j]==v[i]) ok=false;
      }
    }

    if(ok){
      rep(i,8){
        rep(j,8){
          cout << (v[i]==j ? 'Q' : '.');
        }
        cout << "\n";
      }
      return 0;
    }
  } while(next_permutation(all(v)));
}

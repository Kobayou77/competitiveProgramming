#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec              vector<int>
#define vecll            vector<ll>
#define vecd             vector<double>
#define vecst            vector<string>
#define vecb             vector<bool>
#define v2(v,n,m,init)   vector<vector<int>>  v(n, vector<int>(m, init))
#define vb2(v,n,m,init)  vector<vector<bool>> v(n, vector<bool>(m, init))
#define vll2(v,n,m,init) vector<vector<ll>>   v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//------------------------------------------------------------------

int main(void){
  int h, w;
  ll k, v;
  cin >> h >> w >> k >> v;
  vll2(a, h+1, w+1, 0);
  rep(i,h){
    rep(j,w){
      cin >> a[i+1][j+1];
    }
  }

  vll2(sum, h+1, w+1, 0);
  rep(i,h){
    rep(j,w){
      sum[i+1][j+1] = sum[i+1][j]+sum[i][j+1]-sum[i][j]+a[i+1][j+1];
    }
  }

  int maxS=0;
  REP(h1,1,h+1){
    REP(w1,1,w+1){
      REP(h2,h1,h+1){
        REP(w2,w1,w+1){
          int tmpS = (h2-h1+1)*(w2-w1+1);
          ll tmpV = sum[h2][w2]-sum[h1-1][w2]-sum[h2][w1-1]+sum[h1-1][w1-1];
          tmpV += k*tmpS;
          if(tmpV>v) continue;
          chmax(maxS, tmpS);
        }
      }
    }
  }

  prt(maxS);

}

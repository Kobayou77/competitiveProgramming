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
vecd x(201), y(201), r(201);

double dist(int a, int b){
  return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int main(void){
  int n, m;
  cin >> n >> m;

  rep(i,201){
    r[i] = 1e9;
  }
  rep(i,n){
    cin >> x[i] >> y[i] >> r[i];
  }
  rep(i,m){
    cin >> x[n+i] >> y[n+i];
  }

  double ans=1e9;
  rep(i,n+m){
    REP(j,i+1,n+m){
      if(i<n && j<n){
        chmin(ans, r[i]);
        chmin(ans, r[j]);
      } else if(i<n && j>n-1){
        r[j] = dist(i,j)-r[i];
        chmin(ans, r[i]);
        chmin(ans, r[j]);
      } else {
        chmin(r[i], dist(i,j)/2.0);
        chmin(r[j], dist(i,j)/2.0);
        chmin(ans, r[i]);
        chmin(ans, r[j]);
      }
    }
  }

  prtd(10, ans);
}

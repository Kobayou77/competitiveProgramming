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
  int m, n, k;
  cin >> m >> n >> k;
  arrst(s,m);
  vec x1(k), y1(k), x2(k), y2(k);
  rep(i,k){
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  }

  v2(jangle, m+1, n+1, 0);
  v2(ocean, m+1, n+1, 0);
  v2(ice, m+1, n+1, 0);
  rep(i,m){
    rep(j,n){
      jangle[i+1][j+1]=jangle[i][j+1]+jangle[i+1][j]-jangle[i][j]+(s[i][j]=='J');
      ocean[i+1][j+1]=ocean[i][j+1]+ocean[i+1][j]-ocean[i][j]+(s[i][j]=='O');
      ice[i+1][j+1]=ice[i][j+1]+ice[i+1][j]-ice[i][j]+(s[i][j]=='I');
    }
  }

  rep(i,k){
    int J=jangle[x2[i]][y2[i]]-jangle[x2[i]][y1[i]-1]-jangle[x1[i]-1][y2[i]]+jangle[x1[i]-1][y1[i]-1];
    int O=ocean[x2[i]][y2[i]]-ocean[x2[i]][y1[i]-1]-ocean[x1[i]-1][y2[i]]+ocean[x1[i]-1][y1[i]-1];
    int I=ice[x2[i]][y2[i]]-ice[x2[i]][y1[i]-1]-ice[x1[i]-1][y2[i]]+ice[x1[i]-1][y1[i]-1];
    prt3(J, O, I);
  }

}

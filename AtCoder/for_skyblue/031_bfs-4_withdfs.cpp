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
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt(ok ? "Yes" : "No");}
//----------------------------------------------------------------
ll ans=0;
class Honeycomb{

  // [.] --> path, [#] --> wall
  // Grid is *RECTANGULAR*

public:
  vector<vector<bool>> bee;
  vector<vector<bool>> check;
  vector<vector<ll>> dist;
  queue<pair<int, int>> q;

  Honeycomb(int h, int w){
    initCheck(h, w);
    //initDist(h, w);
    addSquare(h,w);
  }
  ~Honeycomb(){}

  void initCheck(int h, int w){
    check.resize(h+2);
    rep(i,h+2){
      rep(j,w+2){
        check[i].push_back(false);
      }
    }
  }

  void addSquare(int h, int w){
    rep(i,h+2){
      vector<bool> tmp;
      rep(j,w+2){
        if(j==0 || j==w+1 || i==0 || i==h+1){
          tmp.pb(false);
        } else {
          int c;
          cin >> c;
          tmp.pb(c>0 ? true : false);
        }
      }
      bee.pb(tmp);
    }
  }

  bool to_1(int h, int w){
    if(h==0) return false;
    if(h%2==0){
      if(w==0) return false;
      if(check[h-1][w-1]) return false;
      if(bee[h-1][w-1]) ans++;
      return !bee[h-1][w-1];
    } else {
      if(check[h-1][w]) return false;
      if(bee[h-1][w]) ans++;
      return !bee[h-1][w];
    }
  }
  bool to_2(int h, int w){
    if(h==0) return false;
    if(h%2==0){
      if(check[h-1][w]) return false;
      if(bee[h-1][w]) ans++;
      return !bee[h-1][w];
    } else {
      if(w==bee[0].size()-1) return false;
      if(check[h-1][w+1]) return false;
      if(bee[h-1][w+1]) ans++;
      return !bee[h-1][w+1];
    }
  }
  bool to_3(int h, int w){
    if(w==0) return false;
    if(check[h][w-1]) return false;
    if(bee[h][w-1]) ans++;
    return !bee[h][w-1];
  }
  bool to_4(int h, int w){
    if(w==bee[0].size()-1) return false;
    if(check[h][w+1]) return false;
    if(bee[h][w+1]) ans++;
    return !bee[h][w+1];
  }
  bool to_5(int h, int w){
    if(h==bee.size()-1) return false;
    if(h%2==0){
      if(w==0) return false;
      if(check[h+1][w-1]) return false;
      if(bee[h+1][w-1]) ans++;
      return !bee[h+1][w-1];
    } else {
      if(bee[h+1][w]) ans++;
      if(check[h+1][w]) return false;
      return !bee[h+1][w];
    }
  }
  bool to_6(int h, int w){
    if(h==bee.size()-1) return false;
    if(h%2==0){
      if(bee[h+1][w]) ans++;
      if(check[h+1][w]) return false;
      return !bee[h+1][w];
    } else {
      if(w==bee[0].size()-1) return false;
      if(check[h+1][w+1]) return false;
      if(bee[h+1][w+1]) ans++;
      return !bee[h+1][w+1];
    }
  }

  void dfs(int h, int w){
    //prt2(h, w);
    check[h][w] = true;

    if(to_1(h,w)){
      if(h%2==0) dfs(h-1,w-1);
      else dfs(h-1,w);
    }
    if(to_2(h,w)){
      if(h%2==0) dfs(h-1,w);
      else dfs(h-1,w+1);
    }
    if(to_3(h,w)){dfs(h,w-1);}
    if(to_4(h,w)){dfs(h,w+1);}
    if(to_5(h,w)){
      if(h%2==0) dfs(h+1,w-1);
      else dfs(h+1,w);
    }
    if(to_6(h,w)){
      if(h%2==0) dfs(h+1,w);
      else dfs(h+1,w+1);
    }
  }
};


int main(void) {
  int h, w;
  cin >> w >> h;
  Honeycomb hc(h, w);
/*
  rep(i,h+2){
    rep(j,w+2){
      cout << hc.bee[i][j] << (j!=w+1 ? " " : "\n");
    }
  }
*/
  hc.dfs(0,0);
  prt(ans);


}

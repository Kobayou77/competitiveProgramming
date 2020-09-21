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
void prtok(bool ok){prt(ok ? "yes" : "no");}
//----------------------------------------------------------------
bool ice[92][92];
int h, w;
int ans=0;

void dfs(int i, int j, int watta){
  //prt3("--->", i, j);
  ice[i][j] = false;
  watta++;
  bool up=true, down=true, left=true, right=true;

  if(i==0) up=false;
  if(i==h-1) down=false;
  if(j==0) left=false;
  if(j==w-1) right=false;

  if(up) {if(ice[i-1][j]) dfs(i-1, j, watta);}
  if(left) {if(ice[i][j-1]) dfs(i, j-1, watta);}
  if(right) {if(ice[i][j+1]) dfs(i, j+1, watta);}
  if(down) {if(ice[i+1][j]) dfs(i+1, j, watta);}
  chmax(ans, watta);
  ice[i][j] = true;
}

int main(void) {
  rep(i,92){
    rep(j,92){
      ice[i][j]=false;
    }
  }

  int h, w;
  cin >> w >> h;

  rep(i,h){
    rep(j,w){
      int tmp;
      cin >> tmp;
      ice[i][j] = (tmp>0 ? true : false);
    }
  }

  rep(i,h){
    rep(j,w){
      if(ice[i][j]){
        dfs(i, j, 0);
      }
    }
  }

  prt(ans);

}

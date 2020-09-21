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
bool ch[51][51];
int h, w;

void dfs(vector<vector<bool>> mp, int i, int j){
  //prt3("--->", i, j);
  ch[i][j] = true;
  bool up=true, down=true, left=true, right=true;

  if(i==0) up=false;
  if(i==h-1) down=false;
  if(j==0) left=false;
  if(j==w-1) right=false;

  if(up && left){if(mp[i-1][j-1] && !ch[i-1][j-1]) dfs(mp, i-1, j-1);}
  if(up) {if(mp[i-1][j] && !ch[i-1][j]) dfs(mp, i-1, j);}
  if(up && right) {if(mp[i-1][j+1] && !ch[i-1][j+1]) dfs(mp, i-1, j+1);}
  if(left) {if(mp[i][j-1] && !ch[i][j-1]) dfs(mp, i, j-1);}
  if(right) {if(mp[i][j+1] && !ch[i][j+1]) dfs(mp, i, j+1);}
  if(down && left) {if(mp[i+1][j-1] && !ch[i+1][j-1]) dfs(mp, i+1, j-1);}
  if(down) {if(mp[i+1][j] && !ch[i+1][j]) dfs(mp, i+1, j);}
  if(down && right) {if(mp[i+1][j+1] && !ch[i+1][j+1]) dfs(mp, i+1, j+1);}
}

int main(void) {
  while(1){
    rep(i,51){
      rep(j,51){
        ch[i][j]=false;
      }
    }
    cin >> w >> h;

    if(w==0 && h==0){break;}
    vector<vector<bool>> mp(h, vector<bool>(w, false));
    rep(i,h){
      rep(j,w){
        int tmp;
        cin >> tmp;
        mp[i][j] = (tmp>0 ? true : false);
      }
    }

    int ans=0;
    rep(i,h){
      rep(j,w){
        if(!ch[i][j] && mp[i][j]){
          ans++;
          dfs(mp, i, j);
        }
      }
    }
    prt(ans);
  }
}

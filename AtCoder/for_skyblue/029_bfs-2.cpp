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
class Grid{

  // [.] --> path, [#] --> wall
  // Grid is *RECTANGULAR*

public:
  vector<string> square;
  vector<vector<bool>> check;
  vector<vector<ll>> dist;
  queue<pair<int, int>> q;

  Grid(int height, int width){
    initCheck(height, width);
    initDist(height, width);
    addSquare(height);
  }
  ~Grid(){}

  void initCheck(int h, int w){
    check.resize(h);
    rep(i,h){
      rep(j,w){
        check[i].push_back(false);
      }
    }
  }
  void initDist(int h, int w){
    dist.resize(h);
    rep(i,h){
      rep(j,w){
        dist[i].push_back(-1);
      }
    }
  }

  void resetDist(){
    rep(i,dist.size()){
      rep(j,dist[i].size()){
        dist[i][j]=-1;
      }
    }
  }

  void addSquare(int h){
    rep(i,h){
      string s;
      cin >> s;
      square.push_back(s);
    }
  }

  bool up(int h, int w){
    if(h==0){return false;}
    if(square[h-1][w]=='#'){return false;}
    if(check[h-1][w]==true){return false;}
    if(dist[h-1][w]>-1){return false;}
    return true;
  }
  bool down(int h, int w){
    if(h==square.size()-1){return false;}
    if(square[h+1][w]=='#'){return false;}
    if(check[h+1][w]==true){return false;}
    if(dist[h+1][w]>-1){return false;}
    return true;
  }
  bool left(int h, int w){
    if(w==0){return false;}
    if(square[h][w-1]=='#'){return false;}
    if(check[h][w-1]==true){return false;}
    if(dist[h][w-1]>-1){return false;}
    return true;
  }
  bool right(int h, int w){
    if(w==square[h].size()-1){return false;}
    if(square[h][w+1]=='#'){return false;}
    if(check[h][w+1]==true){return false;}
    if(dist[h][w+1]>-1){return false;}
    return true;
  }

  void dfs(int h, int w){
    check[h][w] = true;

    if(up(h,w)){dfs(h-1,w);}
    if(down(h,w)){dfs(h+1,w);}
    if(left(h,w)){dfs(h,w-1);}
    if(right(h,w)){dfs(h,w+1);}
  }

  void bfs(int h, int w){
    dist[h][w] = 0;
    q.push(make_pair(h, w));

    while(!q.empty()){
      int cur_h = q.front().first;
      int cur_w = q.front().second;
      q.pop();

      if(up(cur_h, cur_w)){
        dist[cur_h-1][cur_w] = dist[cur_h][cur_w]+1;
        q.push(make_pair(cur_h-1, cur_w));
      }
      if(down(cur_h, cur_w)){
        dist[cur_h+1][cur_w] = dist[cur_h][cur_w]+1;
        q.push(make_pair(cur_h+1, cur_w));
      }
      if(left(cur_h, cur_w)){
        dist[cur_h][cur_w-1] = dist[cur_h][cur_w]+1;
        q.push(make_pair(cur_h, cur_w-1));
      }
      if(right(cur_h, cur_w)){
        dist[cur_h][cur_w+1] = dist[cur_h][cur_w]+1;
        q.push(make_pair(cur_h, cur_w+1));
      }
    }
  }

};

int main(void) {
  int h, w;
  cin >> h >> w;
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  sx--; sy--; gx--; gy--;
  Grid g(h, w);

  g.bfs(sx, sy);

  prt(g.dist[gx][gy]);

}

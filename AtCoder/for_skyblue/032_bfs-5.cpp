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
int main(void) {
  vec ans;
  while(1){
    int w, h;
    cin >> w >> h;

    if(w==0 && h==0) break;

    vector<vector<int>> lr(h);
    vector<vector<int>> ud(h-1);
    rep(i,2*h-1){
      if(i%2==0){
        rep(j,w-1){
          int tmp;
          cin >> tmp;
          lr[i/2].push_back(tmp);
        }
      } else {
        rep(j,w){
          int tmp;
          cin >> tmp;
          ud[i/2].push_back(tmp);
        }
      }
    }

    ll maze[h][w];
    rep(i,h){
      rep(j,w){
        maze[i][j]=-1;
      }
    }

    queue<pair<int, int>> q;
    maze[0][0] = 1;
    q.push(make_pair(0, 0));

    while(!q.empty()){
      int cur_h = q.front().first;
      int cur_w = q.front().second;
      q.pop();

      // up
      if(cur_h!=0){
        if(maze[cur_h-1][cur_w] == -1 && ud[cur_h-1][cur_w] == 0){
          maze[cur_h-1][cur_w] = maze[cur_h][cur_w] + 1;
          q.push(make_pair(cur_h-1, cur_w));
        }
      }

      // left
      if(cur_w!=0){
        if(maze[cur_h][cur_w-1] == -1 && lr[cur_h][cur_w-1] == 0){
          maze[cur_h][cur_w-1] = maze[cur_h][cur_w] + 1;
          q.push(make_pair(cur_h, cur_w-1));
        }
      }

      // right
      if(cur_w!=w-1){
        if(maze[cur_h][cur_w+1] == -1 && lr[cur_h][cur_w] == 0){
          maze[cur_h][cur_w+1] = maze[cur_h][cur_w] + 1;
          q.push(make_pair(cur_h, cur_w+1));
        }
      }

      // down
      if(cur_h!=h-1){
        if(maze[cur_h+1][cur_w] == -1 && ud[cur_h][cur_w] == 0){
          maze[cur_h+1][cur_w] = maze[cur_h][cur_w] + 1;
          q.push(make_pair(cur_h+1, cur_w));

        }
      }
    }
    if(maze[h-1][w-1]==-1){
      ans.push_back(0);
    } else {
      ans.push_back(maze[h-1][w-1]);
    }
  }
  rep(i,ans.size()){
    prt(ans[i]);
  }
}

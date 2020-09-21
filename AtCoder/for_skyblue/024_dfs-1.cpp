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
class Graph{

public:
  vector<vector<int> > graphs;
  vector<bool> check; // For DFS
  vector<ll> dist;   // For BFS
  queue<int> q; // For BFS

  vector<int> d;
  vector<int> f;
  int t;

  Graph(int n){
    graphs.resize(n);
    init(n);
  }
  ~Graph(){}

  void addedge(int u, int v){
    u--; v--;
    graphs[u].push_back(v);
    graphs[v].push_back(u);
  }

  void addedge_cin(int m){
    rep(i,m){
      int a, b;
      cin >> a >> b;
      addedge(a, b);
    }
  }

  void init(int n){
    check.resize(n, false);
    dist.resize(n, -1);
    d.resize(n, -1);
    f.resize(n, -1);
  }

  void reset(){
    rep(i,check.size()){
      check[i]=false;
      dist[i]=-1;
    }
  }

  void dfs(int v)
  {
    t++;
    check[v] = true;
    d[v] = t;

    for(int next_v : graphs[v]){
      if(check[next_v]) continue;
      dfs(next_v);
    }
    t++;
    f[v] = t;
  }

  void bfs(int v)//----------------------
  {
    dist[v] = 0;
    q.push(v);

    while(!q.empty()){
      int cur_v = q.front();
      q.pop();

      for(int next_v : graphs[cur_v]){
        if(dist[next_v] != -1){
          continue;
        }

        dist[next_v] = dist[cur_v] + 1;
        q.push(next_v);
      }
    }
  }//-----------------------

};

int main(void) {
  int n;
  cin >> n;
  Graph g(n);

  rep(i,n){
    int vertex, num;
    cin >> vertex >> num;
    vertex--;
    if(num==0) continue;
    rep(j,num){
      int tmp;
      cin >> tmp;
      tmp--;
      g.graphs[vertex].pb(tmp);
    }
    sortall(g.graphs[vertex]);
  }

  g.t = 0;
  rep(i,n){
    if(!g.check[i]){
      g.dfs(i);
    }
  }

  rep(i,n){
    prt3(i+1, g.d[i], g.f[i]);
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int>  pint;
typedef pair<ll,ll>    pll;
typedef vector<int>    vint;
typedef vector<ll>     vll;
typedef vector<string> vstr;
typedef vector<pint>   vpint;
typedef vector<pll>    vpll;

#define vint2(v,n,m,init) vector<vector<int>> v(n, vector<int>(m, init))
#define vll2(v,n,m,init)  vector<vector<ll>>  v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vint var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vstr var(n); rep(i,n){cin >> var[i];}
#define ALL(var)         (var).begin(), (var).end()
#define sortall(var)     sort(ALL(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());

#define prt(var)         cout << (var) << "\n"
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//-----------------------------------------------------------------------------
class UnionFind{

public:
  int vertexNumber;
  vector<int> parents;

  UnionFind(int n){
    vertexNumber = n;
    parents.assign(n, -1);
  }
  ~UnionFind(){}

  int find(int x){
    if(parents[x]<0){return x;}
    else {return find(parents[x]);}
  }

  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y){return;}

    if(parents[x]>parents[y]){
      int tmp = x;
      x = y;
      y = tmp;
    }

    parents[x] += parents[y];
    parents[y] = x;
  }

  int size(int x){return -parents[find(x)];}

  bool is_same(int x, int y){return find(x) == find(y);}

  int count_roots(){
    int ct=0;
    for(int i=0; i<vertexNumber; i++){
      if(parents[i]<0){ct++;}
    }
    return ct;
  }
};

int main(void){
  int n, q;
  cin >> n >> q;

  UnionFind uf(n);
  vint ans;
  rep(i,q){
    int t, u, v;
    cin >> t >> u >> v;
    if(t) ans.push_back(uf.is_same(u, v));
    else uf.unite(u, v);
  }

  for(auto x : ans){
    prt(x);
  }
}

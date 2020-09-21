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
  ll n, m;
  cin >> n >> m;
  vec a(m), b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  UnionFind uf(n);

  vecll ans;
  ll tmp=n*(n-1)/2;
  rep(i,m){
    ans.push_back(tmp);
    if(uf.is_same(a[m-i-1], b[m-i-1])) continue;
    ll n1 = uf.size(a[m-i-1]);
    ll n2 = uf.size(b[m-i-1]);
    tmp -= n1*n2;
    uf.unite(a[m-i-1], b[m-i-1]);
  }

  rep(i,m){
    prt(ans[m-i-1]);
  }

}

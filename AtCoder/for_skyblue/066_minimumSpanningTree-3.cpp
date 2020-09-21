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
//----------------------------------------------------------------
class UnionFind{

public:
  vector<int> parents;

  UnionFind(int n){
    parents.assign(n, -1);
  }
  ~UnionFind(){}

  int find(int x){
    if(parents[x]<0){
      return x;
    } else {
      return find(parents[x]);
    }
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

  int size(int x){
    return -parents[find(x)];
  }

  int count_roots(){
    int ct=0;
    for(int i=0; i<parents.size(); i++){
      if(parents[i]<0){ct++;}
    }
    return ct;
  }

  bool is_same(int x, int y){
    return find(x) == find(y);
  }
};

int main(void) {
  vector<double> ans;
  while(1){
    int n;
    cin >> n;
    if(n==0) break;
    vecd x(n), y(n), z(n), r(n);
    rep(i,n){
      cin >> x[i] >> y[i] >> z[i] >> r[i];
    }

    vector<vector<double>> d(n, vector<double>(n, 0.0));
    rep(i,n){
      rep(j,n){
        if(i==j) d[i][j]=0;
        else {
          double tmp=0.0;
          tmp+=(x[i]-x[j])*(x[i]-x[j]);
          tmp+=(y[i]-y[j])*(y[i]-y[j]);
          tmp+=(z[i]-z[j])*(z[i]-z[j]);
          if(tmp<=(r[i]+r[j])*(r[i]+r[j])) d[i][j]=0.0;
          else d[i][j]=sqrt(tmp)-r[i]-r[j];
        }
      }
    }

    vector<pair<double, pair<int, int>>> p;
    rep(i,n){
      REP(j,i+1,n){
        p.push_back(make_pair(d[i][j], make_pair(i,j)));
      }
    }
    sortall(p);

    UnionFind uf(n);
    int ct=0;
    double tmpans=0.0;
    rep(i,p.size()){
      if(!uf.is_same(p[i].second.first, p[i].second.second)){
        uf.unite(p[i].second.first, p[i].second.second);
        tmpans+=p[i].first;
        ct++;
      }
      if(ct==n-1) break;
    }

    ans.push_back(tmpans);
  }
  rep(i,ans.size()){
    prtd(3,ans[i]);
  }
}

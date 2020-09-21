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
  vec ans;
  while(1){
    int n;
    cin >> n;
    if(n==0) break;
    vec sum(24*60*60+1, 0);
    rep(i,n){
      string s1, s2;
      cin >> s1 >> s2;
      int a=0, b=0;
      a += ((s1[0]-'0')*10 + (s1[1]-'0'))*60*60;
      a += ((s1[3]-'0')*10 + (s1[4]-'0'))*60;
      a += ((s1[6]-'0')*10 + (s1[7]-'0'));
      b += ((s2[0]-'0')*10 + (s2[1]-'0'))*60*60;
      b += ((s2[3]-'0')*10 + (s2[4]-'0'))*60;
      b += ((s2[6]-'0')*10 + (s2[7]-'0'));
      sum[a]++;
      sum[b]--;
    }

    int res=sum[0];
    rep(i,24*60*60){
      sum[i+1] += sum[i];
      chmax(res, sum[i+1]);
    }

    ans.push_back(res);
  }

  for(auto t : ans){
    prt(t);
  }
}

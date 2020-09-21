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
class PrimeTool{

public:
  vector<ll> myMinPrime;

  PrimeTool(){
    myMinPrime.resize(1000001, -1);
    eratosthenes();
  }
  ~PrimeTool(){}

  void eratosthenes(){
    for(ll i=2; i<1000001; i++){
      if(myMinPrime[i]>0) continue;
      ll j=1;
      while(i*j<1000001){
        myMinPrime[i*j]=i;
        j++;
      }
    }
  }

  vector<ll> divisors(ll x){
    vector<ll> v;
    for(ll i=1; i*i<=x; i++){
      if(x%i==0){
        v.push_back(i);
        if(i!=x/i) v.push_back(x/i);
      }
    }
    sort(v.begin(), v.end());
    return v;
  }

  bool isPrime(ll x){
    if (x<2) return false;
    else if (x<1000001){
      return myMinPrime[x]==x;
    } else {
      for (ll i = 3; i*i <= x; i += 2){
        if (x % i == 0) return false;
      }
      return true;
    }
  }

  map<ll, ll> factorize(ll x){
    map<ll, ll> mp;
    if(x<2) return mp;
    // fast prime Factorization
    if(x<1000001){
      while(x>1){
        mp[myMinPrime[x]]++;
        x/=myMinPrime[x];
      }
    }
    // slow prime Factorization
    else {
      while(x%2==0){
        mp[2]++;
        x/=2;
      }
      for(ll i=3; i*i<=x; i+=2){
        while(x%i==0){
          mp[i]++;
          x/=i;
        }
      }
      if(x!=1) mp[x] = 1;
    }
    return mp;
  }
};

int main(void){
  int q;
  cin >> q;
  vec l(q), r(q);
  rep(i,q){
    cin >> l[i] >> r[i];
  }

  PrimeTool p;
  vecb isOK(100001);
  REP(i,1,100001){
    if(p.isPrime(i) && p.isPrime((i+1)/2)) isOK[i]=true;
  }
  vec sum(100001);
  REP(i,1,100001){
    sum[i] = sum[i-1] + isOK[i];
  }

  rep(i,q){
    prt(sum[r[i]]-sum[l[i]-1]);
  }
}

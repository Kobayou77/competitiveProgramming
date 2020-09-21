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
    int h;
    cin >> h;
    if(h==0) break;
    v2(s, h, 5, 0);
    rep(i,h){
      rep(j,5){
        cin >> s[i][j];
      }
    }

    int score=0;
    rep(a,20){
      vecb already(h, false);
      rep(i,h){
        rep(j,3){
          rep(k,j+1){
            if(already[i]) continue;
            bool ok=true;
            int tmp=s[i][k];
            rep(l,5-j){
              if(tmp!=s[i][k+l]) ok=false;
            }
            if(ok){
              already[i]=true;
              rep(l,5-j){
                score += s[i][k+l];
                s[i][k+l] = 0;
              }
              rep(l,i){
                rep(m,5-j){
                  s[i-l][k+m] = s[i-l-1][k+m];
                  s[i-l-1][k+m] = 0;
                }
              }
              /*
              cout << "===== ";
              prt3(i, j, k);
              rep(a,h){
                rep(b,5){
                  cout << s[a][b] << (b!=4 ? " " : "\n");
                }
              }
              prt2("----->", score);
              */
            }
          }
        }
      }
    }
    ans.push_back(score);
  }
  rep(i,ans.size()){
    prt(ans[i]);
  }
}

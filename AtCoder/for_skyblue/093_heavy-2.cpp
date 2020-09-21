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

vector<string> drop(vector<string> s){
  vector<string> r;
  int h = s.size();
  int w = s[0].size();
  rep(i,h){
    string tmp="";
    rep(j,w){
      tmp.push_back('0');
    }
    r.push_back(tmp);
  }
  rep(i,w){
    int id=h-1;
    for(int j=h-1; j>-1; j--){
      if(s[j][i]!='0'){
        r[id][i]=s[j][i];
        id--;
      }
    }
  }
  return r;
}

int main(void){
  int h, w, k;
  cin >> h >> w >> k;
  arrst(s,h);

  int ans=0;
  if(k>=4){
    prt(ans);
    return 0;
  }
  rep(delh,h){
    rep(delw,w){
      int anstmp=0;
      vector<string> t = s;
      t[delh][delw] = '0';
      t = drop(t);
      int p=1;
      //prt("-----------------------");
      rep(x,h+2){
        if(x!=0) p*=2;
        int add=0;
        /*
        prt2("from =====>", x);

        rep(p,h){
          rep(q,w){
            cout << t[p][q] << (q!=w-1 ? " " : "\n");
          }
        }
        */

        rep(a,h){
          rep(b,w){
            int tmp = t[a][b];
            if(tmp=='0') continue;
            int c=b;
            int ct=0;
            while(c<w){
              if(t[a][c]==tmp) ct++, c++;
              else {
                break;
              }
            }
            if(ct>=k){
              rep(i,ct){
                add += t[a][b+i]-'0';
                t[a][b+i]='0';
              }
            }
          }
        }
        /*
        prt2("to =====>", x);
        rep(p,h){
          rep(q,w){
            cout << t[p][q] << (q!=w-1 ? " " : "\n");
          }
        }
        */

        anstmp += add*p;
        //prt3("score :", anstmp, add*p);
        t = drop(t);
      }
      chmax(ans, anstmp);
    }
  }


  prt(ans);
}

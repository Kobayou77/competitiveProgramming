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
	vector<vector<int>> ans;
	while(1){
		int n, w, d;
		cin >> n >> w >> d;
		if(n==0 && w==0 && d==0) break;
		vec p(n), s(n);
		rep(i,n){
			cin >> p[i] >> s[i];
		}

		vector<pair<int, int>> v;
		v.push_back(make_pair(w, d));

		rep(i,n){
			auto k = v[p[i]-1];
			int tw = k.first;
			int td = k.second;
			int pt = s[i]%(tw+td);
			v.erase(v.begin()+p[i]-1);
			if(pt<tw){
				v.push_back(make_pair(min(pt, tw-pt), td));
				v.push_back(make_pair(max(pt, tw-pt), td));
			} else {
				v.push_back(make_pair(tw, min(pt-tw, td-pt+tw)));
				v.push_back(make_pair(tw, max(pt-tw, td-pt+tw)));
			}
		}

		vector<int> tmp;
		for(auto k : v){
			tmp.push_back(k.first*k.second);
		}
		sortall(tmp);
		ans.push_back(tmp);
	}

	for(auto k: ans){
		prtall(k);
	}
}

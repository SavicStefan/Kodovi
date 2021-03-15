#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,ll> pii;
const int maxn = 200005;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n;
ll L;

vector<pii> g[maxn];

ll pref[maxn];
void dfs1(int v, int p){
	for(auto c : g[v]){
		int u = c.fi;
		ll w = c.se;
		if(u != p){
			pref[u] = pref[v] + w;
			dfs1(u, v);
		}
	}
}

multiset<ll> dt[maxn];
void comb(int x, int y){
	if(sz(dt[x]) < sz(dt[y]))swap(dt[x], dt[y]);
	for(auto c : dt[y]){
		dt[x].insert(c);
	}
}

int res[maxn];
void dfs2(int v, int p){
	dt[v].insert(pref[v] - L);
	for(auto c : g[v]){
		int u = c.fi;
		ll w = c.se;
		if(u != p){
			dfs2(u, v);
			comb(v, u);
		}
	}
	while(!dt[v].empty()){
		ll x = *dt[v].rbegin();
		if(x <= pref[v])break;
		dt[v].erase(dt[v].find(x));
	}
	res[v] = sz(dt[v]);
}

int main()
{
   	ios::sync_with_stdio(false);
   	cout.tie(nullptr);
  	cin.tie(nullptr);
	ifstream cin("runaway.in");
	ofstream cout("runaway.out");
	cin >> n >> L;
	ff(i,2,n){
		int x;
		ll y;
		cin >> x >> y;
		g[i].pb({x, y});
		g[x].pb({i, y});
	}
	dfs1(1, -1);
	dfs2(1, -1);
	ff(i,1,n)cout << res[i] << endl;
   	return 0;
}
/**

4 5
1 4
2 3
1 5

// probati bojenje sahovski ili slicno

**/



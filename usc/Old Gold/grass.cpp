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
typedef pair<int,int> pii;
const int maxn = 100005;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n, m;

vector<int> g[maxn];
vector<int> rg[maxn];

vector<int> todo;
bool visited[maxn];
void dfs1(int v){
    visited[v] = 1;
    for(auto u : g[v]){
        if(!visited[u])dfs1(u);
    }
    todo.pb(v);
}
int br = 0;
int kol[maxn];
int comp[maxn];
void dfs2(int v, int clr){
    comp[v] = clr;
    br += 1;
	for(auto u : rg[v]){
        if(!comp[u])dfs2(u, clr);
    }
}
vector<int> all;
void kosaraju(){
    ff(i,1,n){
        visited[i] = 0;
        comp[i] = 0;
    }
    ff(i,1,n){
        if(visited[i])continue;
        dfs1(i);
    }
    reverse(all(todo));
    for(auto c : todo){
        if(comp[c] == 0){
        	br = 0;
            dfs2(c, c);
            kol[c] = br; 
			all.pb(c);
        }
    }
}

vector<int> e[maxn];
vector<int> re[maxn];

int dp1[maxn];
void dfs3(int v){
	for(auto u : e[v]){
		if(dp1[v] + kol[u] > dp1[u]){
			dp1[u] = kol[u] + dp1[v];
			dfs3(u);
		}
	}
}

int dp2[maxn];
void dfs4(int v){
	for(auto u : re[v]){
		if(dp2[v] + kol[u] > dp2[u]){
			dp2[u] = dp2[v] + kol[u];
			dfs4(u);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
   	cout.tie(nullptr);
  	cin.tie(nullptr);
	ifstream cin ("grass.in");
	ofstream cout ("grass.out");
	cin >> n >> m;
	vector<pii> grana;
	ff(i,1,m){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		rg[v].pb(u);
		grana.pb({u, v});
	}
	kosaraju();
	vector<pii> vec;
	for(auto c : grana){
		int u = c.fi;
		int v = c.se;
		if(comp[u] != comp[v]){
			vec.pb({comp[u], comp[v]});
			e[comp[u]].pb(comp[v]);
			re[comp[v]].pb(comp[u]);
		}
	}
	// dp1[i] - najduzi put od 1 do i
   	// dp2[i] - najduzi put od i do 1
   	// rez = max(rez, dp1[i] + dp2[j]), gde postoji veza imedju (i, j)
	ff(i,1,n)dp1[i] = -inf;
	ff(i,1,n)dp2[i] = -inf;
	
	dp1[1] = 0;
	dfs3(1);
	dp2[1] = 0;
	dfs4(1);
	
	int rez = kol[1];
	ff(i,1,n){
		if(dp1[i] != -inf){
			for(auto c : re[i]){
				if(dp2[c] != -inf)rez = max(rez, kol[1] + dp1[i] + dp2[c]);
			}
		}
	}
	cout << rez << endl;
	return 0;
}
/**

7 10
1 2
3 1
2 5
2 4
3 7
3 5
3 6
6 5
7 2
4 7

// probati bojenje sahovski ili slicno

**/

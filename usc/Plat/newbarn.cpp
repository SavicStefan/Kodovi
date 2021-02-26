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
const int maxn = 200005;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n, q;

pii dia[maxn];
int komp[maxn]; // sluzi posto mozda moze da bude disconnected stablo (da ih bude vise) 

int d[maxn];
int deda[maxn][25];
int lca(int x, int y){
    if(d[x] < d[y])swap(x, y);
    fb(i,19,0){
        if((d[x] - d[y]) & (1 << i))x = deda[x][i];
    }
    if(x == y)return x;
    fb(i,19,0){
        if(deda[x][i] != deda[y][i]){
            x = deda[x][i];
            y = deda[y][i];
        }
    }
    return deda[x][0];
}
int dist(int x, int y){
    return d[x] + d[y] - 2 * d[lca(x, y)];
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    ifstream cin("newbarn.in");
    ofstream cout("newbarn.out");
	cin >> q;
    int a = 1, b = 1;
	ff(i,1,q){
		int x;
		char t;
		cin >> t >> x;
		if(t == 'B'){
		    n += 1;
			if(x == -1){
				dia[n] = {a, b};
				komp[n] = n;
				continue;
			}
			d[n] = d[x] + 1;
			komp[n] = komp[x];
			
	        deda[n][0] = x;
	        ff(j,1,19)deda[n][j] = deda[deda[n][j - 1]][j - 1];
	        
	        int ndia0 = dist(dia[komp[n]].fi, dia[komp[n]].se);
	        int ndia1 = dist(dia[komp[n]].fi, n);
	        int ndia2 = dist(dia[komp[n]].se, n);
	        int mx = max({ndia0, ndia1, ndia2});
	        if(mx == ndia1)dia[komp[n]].se = n;
	        else if(mx == ndia2)dia[komp[n]].fi = n;
	        
		}
		if(t == 'Q')cout << max(dist(x, dia[komp[x]].fi), dist(x, dia[komp[x]].se)) << endl;
    }
    return 0;
}
/**



// probati bojenje sahovski ili slicno

**/



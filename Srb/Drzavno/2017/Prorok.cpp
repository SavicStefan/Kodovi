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

int n;
pii niz[maxn];

int da[maxn];
int ne[maxn];

int main()
{
   	ios::sync_with_stdio(false);
   	cout.tie(nullptr);
  	cin.tie(nullptr);
	cin >> n;
	ff(i,1,n){
		int X; string s;
		cin >> X >> s;
		niz[i] = {X, s == "da" ? 1 : 0};		
	}
		
	vector<int> all;
	ff(i,1,n)all.pb(niz[i].fi);
	sort(all(all)); all.erase(unique(all(all)), all.end());
	ff(i,1,n)niz[i].fi = lower_bound(all(all), niz[i].fi) - all.begin() + 1;
		
	ff(i,1,n){
		if(niz[i].se == 1)da[niz[i].fi] += 1;
		else ne[niz[i].fi] += 1;
	}
	
	ff(K,2,n){
		
		for(int i = K; i <= n; i += K){
			if(niz[i].se == 1){
				da[niz[i].fi] -= 1;
				ne[niz[i].fi] += 1;
			}
			else{
				ne[niz[i].fi] -= 1;
				da[niz[i].fi] += 1;
			}
		}
			
		bool ok = 1;
		ff(i,1,sz(all)){
			if(!(da[i] == 0 || ne[i] == 0)){
				ok = 0;
				break;
			}
		}
		
		if(ok)return cout << K, 0;
		
		for(int i = K; i <= n; i += K){
			if(niz[i].se == 1){
				da[niz[i].fi] += 1;
				ne[niz[i].fi] -= 1;
			}
			else{
				ne[niz[i].fi] += 1;
				da[niz[i].fi] -= 1;
			}
		}
				
	}
			
	cout << -1 << endl;
	
   	return 0;
}
/**



// probati bojenje sahovski ili slicno

**/




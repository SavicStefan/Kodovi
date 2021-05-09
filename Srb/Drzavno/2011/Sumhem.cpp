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
int niz[maxn];

int cnt[35];

int main()
{
   	ios::sync_with_stdio(false);
   	cout.tie(nullptr);
  	cin.tie(nullptr);
	cin >> n;
	ff(i,1,n)cin >> niz[i];
	
	ll rez = 0;
	ff(i,1,n){
		int X = niz[i];		
		
		ff(bt,0,30){
			if(X & (1 << bt))rez += i - 1 - cnt[bt];
			else rez += cnt[bt];	
		}	
		
		ff(bt,0,30){
			if(X & (1 << bt))cnt[bt] += 1;
		}
			
	}
	
	cout << rez << endl;
	
   	return 0;
}
/**



// probati bojenje sahovski ili slicno

**/




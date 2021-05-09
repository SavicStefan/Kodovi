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
const ll inf = 1e18 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n;
ll niz[maxn];

int cnt[65];

ll gore(ll X, int bt){
	if(X & (1ll << bt))return X;
	
	ll Y = (X | (1ll << bt));
	Y &= (~((1ll << bt) - 1));
	
	return Y;
}

ll dole(ll X, int bt){
	if(X & (1ll << bt))return X;
	if(63 - __builtin_clzll(X) < bt)return -inf;

	ll Y = X | ((1ll << (bt + 1)) - 1);
	// prvi bit posle bt, koji je ukljucen
//	int Z = ~((1 << (bt + 1)) - 1);
	
	ff(mask,bt + 1,20){
		if(X & (1ll << mask)){
			Y ^= (1ll << mask);
			break;
		}
		else Y |= (1ll << mask);
	}
	
	return Y;
	
}

int main()
{
   	ios::sync_with_stdio(false);
   	cout.tie(nullptr);
  	cin.tie(nullptr);
	cin >> n;
	ff(i,1,n)cin >> niz[i];

	ll rez = inf;
	ff(bt,0,60){
		
		ll add = 0;
		ff(i,1,n){
			if(niz[i] & (1 << bt))continue;
			
			// najblizi broj niz[i], tako da ima bit "bt"
			
			ll X = 0;
			
			ll A = gore(niz[i], bt);
			ll B = dole(niz[i], bt);
			if(A - niz[i] > niz[i] - B){
				add += A - niz[i];
				X = A;
			}
			else{
				add += niz[i] - B;
				X = B;
			}
			
			
			
		}
		
		if(n % 2 == 1){
			rez = min(rez, add);
			continue;
		}
		
		// ako je n parno? kako napraviti da je xor > 0
		
		// xor > 0, to znaci da barem jedan bit mora da se pojavljuje neparan broj puta
		
		
	}
	
	cout << rez << endl;
	
   	return 0;
}
/**



// probati bojenje sahovski ili slicno

**/




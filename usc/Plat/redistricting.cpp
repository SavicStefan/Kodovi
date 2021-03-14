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
const int maxn = 300005;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n, k;
string s;

int dp[maxn];

int cntg[maxn];
int cnth[maxn];

ll bor[8*maxn];
void build(int v, int tl, int tr){
	if(tl == tr){
		bor[v] = inf;
		return;
	}
	int mid = (tl + tr) / 2;
	build(v * 2, tl, mid); build(v * 2 + 1, mid + 1, tr);
	bor[v] = min(bor[v * 2], bor[v * 2 + 1]);
}
multiset<int> ms[8*maxn];
void update(int v, int tl, int tr, int poz, ll vre, int sgn){
	if(tl == tr){
		if(sgn == 1){
			bor[v] = min(bor[v], vre);
			ms[v].insert(vre);
		}
		else{
			ms[v].erase(ms[v].find(vre));
			if(ms[v].empty())bor[v] = inf;
			else bor[v] = *ms[v].begin();
		}
		return;
	}
	int mid = (tl + tr) / 2;
	if(poz <= mid)update(v * 2, tl, mid, poz, vre, sgn);
	else update(v * 2 + 1, mid + 1, tr, poz, vre, sgn);
	bor[v] = min(bor[v * 2], bor[v * 2 + 1]);
}
int kveri(int v, int tl, int tr, int l, int r){
	if(tl > r || l > tr)return inf;
	if(tl >= l && tr <= r)return bor[v];
	int mid = (tl + tr) / 2;
	return min(kveri(v * 2, tl, mid, l, r), kveri(v * 2 + 1, mid + 1, tr, l, r));
}

int main()
{
   	ios::sync_with_stdio(false);
   	cout.tie(nullptr);
  	cin.tie(nullptr);
	ifstream cin ("redistricting.in");
	ofstream cout ("redistricting.out");
	cin >> n >> k >> s;
	s = ' ' + s;

	ff(i,1,n)cntg[i] = cntg[i - 1] + (s[i] == 'G');
	ff(i,1,n)cnth[i] = cnth[i - 1] + (s[i] == 'H');

	build(1,1,2 * n);
	update(1,1,2 * n,n,0,1);
	ff(i,1,k){
		int raz = cntg[i] - cnth[i] + n;
		dp[i] = min(kveri(1,1,2 * n,0,raz) + 1, kveri(1,1,2 * n,raz + 1, 2 * n));
		update(1,1,2 * n,raz,dp[i], 1);
	}

	ff(i,k + 1,n){
		int raz = cntg[i] - cnth[i] + n;
		update(1,1,2 * n,cntg[i - k - 1] - cnth[i - k - 1] + n, dp[i - k - 1], -1);
		dp[i] = min(kveri(1,1,2 * n,raz + 1, 2 * n), kveri(1,1,2 * n,0,raz) + 1);
		update(1,1,2 * n,raz,dp[i], 1);
	}
	cout << dp[n] << endl;
   	return 0;
}
/**

7 2
HGHGGHG

// probati bojenje sahovski ili slicno

**/



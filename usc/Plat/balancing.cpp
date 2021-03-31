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

const int N = (int)1e6;

ll dud1[N + 5];
void upd1(int x, ll val) {
	while(x <= N) {
		dud1[x] += val;
		x += x&(-x);
	}
}
ll query1(int x) {
	ll sum = 0;
	while(x > 0) {
		sum += dud1[x];
		x -= x&(-x);
	}
	return sum;
}

ll dud2[N + 5];
void upd2(int x, ll val) {
	while(x <= N) {
		dud2[x] += val;
		x += x&(-x);
	}
}
ll query2(int x) {
	ll sum = 0;
	while(x > 0) {
		sum += dud2[x];
		x -= x&(-x);
	}
	return sum;
}

bool check(int x) {
	// da li mogu da podelim da u svakom delu ima max x krava

	memset(dud1, 0, sizeof(dud1));
	memset(dud2, 0, sizeof(dud2));

	ff(i,1,n)upd2(niz[i].se, 1);

	bool ok = 0;
	ff(i,1,n) {
		int a = niz[i].fi;
		int b = niz[i].se;

		// povlacim pravu na x = a + 1, biram y pravu tako da nemam vise od x krava

		upd1(niz[i].se, 1);
		upd2(niz[i].se, -1);

		int j = i;
		while(j + 1 <= n && niz[j + 1].fi == niz[i].fi) {
			upd1(niz[j + 1].se, 1);
			upd2(niz[j + 1].se, -1);
			j += 1;
		}

		int ans1 = 0;
		{
			int sum = 0;
			fb(j,20,0) {
				if(ans1 + (1 << j) <= N && sum + dud1[ans1 + (1 << j)] <= x) {
					sum += dud1[ans1 + (1 << j)];
					ans1 += (1 << j);
				}
			}
		}
		int ans2 = 0;
		{
			int sum = 0;
			fb(j,20,0) {
				if(ans2 + (1 << j) <= N && sum + dud2[ans2 + (1 << j)] <= x) {
					sum += dud2[ans2 + (1 << j)];
					ans2 += (1 << j);
				}
			}

		}

		int mn = min(ans1, ans2);
		if(query1(mn) <= x && query1(N - 1) - query1(mn - 1) <= x && query2(mn) <= x && query2(N - 1) - query2(mn - 1) <= x)return 1;

		i = j;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	ifstream cin("balancing.in");
	ofstream cout("balancing.out");

	cin >> n;
	ff(i,1,n)cin >> niz[i].fi >> niz[i].se;
	sort(niz + 1, niz + n + 1);

	int l = 0, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = mid - 1;
			ans = mid;
		} else l = mid + 1;
	}

	cout << ans << endl;

	return 0;
}
/**



// probati bojenje sahovski ili slicno

**/


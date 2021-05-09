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

int n, K;
int niz[maxn];

int cnt[maxn];

int main() 
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> K;
    ff(i,1,n)cin >> niz[i];

    vector<int> deli;
    for(int i = 1; i * i <= n; i += 1) {
        if(n % i == 0) {
            deli.pb(i);
            if(n / i != i)deli.pb(n / i);
        }
    }

	{
		vector<int> all;
		ff(i,1,n)all.pb(niz[i]);
		sort(all(all));
		all.erase(unique(all(all)), all.end()); 
		ff(i,1,n)niz[i] = lower_bound(all(all), niz[i]) - all.begin() + 1;  
	}
	
    int rez = 0;
    for(auto c : deli) {

        bool ok = 1;
        for(int i = 1; i <= n; i += c) {
            int L = i, R = i + c - 1;

            ff(j,L,R) {
                cnt[niz[j]] += 1;
                if(cnt[niz[j]] > K) {
                    ok = 0;
                    break;
                }
            }
            
            ff(j,L,R)cnt[niz[j]] = 0;

            if(!ok)break;

        }

        if(ok)rez += 1;

    }

    cout << rez << endl;

    return 0;
}
/**



// probati bojenje sahovski ili slicno

**/




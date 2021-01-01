#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn = 200005;
const ll inf = 1e18 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n, q;
ll niz[maxn];

int BLOCK;
ll sqd[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> q;
    ff(i,1,n)cin >> niz[i];
    BLOCK = sqrt(n);
    ff(i,1,n)sqd[(i - 1) / BLOCK] += niz[i];
	ff(i,1,q){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            ff(i,l,r){
                if((i - 1) % BLOCK == 0 && i + BLOCK - 1 <= r){
                    sqd[(i - 1) / BLOCK] += (i - l + 1 + BLOCK - 1) * (i - l + 1 + BLOCK) / 2 - (i - l) * (i - l + 1) / 2;
                    i += BLOCK;
                }
                else{
                    niz[i] += (ll)(i - l + 1);
                    sqd[(i - 1) / BLOCK] += (ll)(i - l + 1);
                }
            }
        }
        if(t == 2){
            ll ans = 0;
            ff(i,l,r){
                if((i - 1) % BLOCK == 0 && i + BLOCK - 1 <= r){
                    ans += sqd[(i - 1) / BLOCK];
                    i += BLOCK;
                }
                else{
                    ans += niz[i];
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
/**
4 4
4 3 4 3 
1 2 3
1 1 2
2 1 3

4 10
4 3 4 3 
2 2 3
1 2 3
1 1 2
2 1 3
2 1 1
1 3 4
2 2 3
1 2 4
2 3 4
1 1 3


5 1
1 2 3 4 5
2 1 5

// probati bojenje sahovski ili slicno

**/



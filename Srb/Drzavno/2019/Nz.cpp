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
const int maxn = 500005;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n, K;
int niz[maxn];

bool los[maxn];

int bor[4 * maxn];
void update(int v, int tl, int tr, int pos, int val) {
    if(tl == tr) {
        bor[v] = val;
        return;
    }
    int mid = (tl + tr) / 2;
    if(pos <= mid)update(v * 2, tl, mid, pos, val);
    else update(v * 2 + 1, mid + 1, tr, pos, val);
    bor[v] = max(bor[v * 2], bor[v * 2 + 1]);
}

pii kth(int v, int tl, int tr, int X) {
    if(tl == tr)return {bor[v], tl};
    int mid = (tl + tr) / 2;
    if(bor[v * 2 + 1] > X)return kth(v * 2 + 1, mid + 1, tr, X);
    else return kth(v * 2, tl, mid, X);
}

int main() 
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> K;
    ff(i,1,n)cin >> niz[i];
    int treba = n - K;

    memset(bor, -inf, sizeof(bor));
    ff(i,1,n) {
        if(K == 0)break;
        // prvi veci od niz[i], koje nije lose

        while(K > 0) {
            auto A = kth(1,1,n,niz[i]);
            if(niz[i] >= A.fi)break;
            update(1,1,n,A.se,-inf);
            los[A.se] = 1;
            K -= 1;
        }

        update(1,1,n,i,niz[i]);

//		fb(j,i - 1,1){
//			if(!los[j] && niz[j] > niz[i] && K > 0){
//				los[j] = 1;
//				K -= 1;
//			}
//		}

    }

    vector<int> res;
    ff(i,1,n) {
        if(!los[i])res.pb(niz[i]);
    }

    ff(i,0,min(treba, sz(res)) - 1) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
/**

5 3
2 10 6 2 6

4 3
4 8 6 3

8 7
6 0 3 1 4 2 1 7

// probati bojenje sahovski ili slicno

**/




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

int n, K;
int niz[maxn];

int pref[maxn];
const int N = (int)1e5;

ll dud[2 * maxn];
void upd(int x, ll val) {
    while(x <= 2 * maxn) {
        dud[x] += val;
        x += x&(-x);
    }
}
ll query(int x) {
    ll sum = 0;
    while(x > 0) {
        sum += dud[x];
        x -= x&(-x);
    }
    return sum;
}


int main() 
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ifstream cin("median.in");
    ofstream cout("median.out");

    cin >> n >> K;
    ff(i,1,n) {
        int X;
        cin >> X;
        niz[i] = (X >= K ? 1 : -1);
    }

    ff(i,1,n)pref[i] = pref[i - 1] + niz[i];


    ll rez = 0;

    upd(N, 1);
    ff(i,1,n) {
        int X = pref[i] + N;

        rez += query(X);
        upd(X, 1);

    }

    cout << rez << endl;

    return 0;
}
/**



// probati bojenje sahovski ili slicno

**/



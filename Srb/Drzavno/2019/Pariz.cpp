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
typedef pair<ll,ll> pii;
const int maxn = 200005;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n;
ll T;

ll niz[maxn];
pii graf[maxn];

vector<pii> g[maxn];

ll cost[maxn];

vector<int> krug;
vector<int> cuvaj;

int par[maxn];
int visited[maxn];
void dfs1(int v, int p) {
    par[v] = p;
    visited[v] = 1;

    cuvaj.pb(v);
    for(auto c : g[v]) {
        int u = c.fi;
        int w = c.se;
        if(!visited[u])dfs1(u, v);
        else {
            if(visited[u] == 1) {
                for(int A = v; A != u; A = par[A]) {
                    krug.pb(A);
                }
                krug.pb(u);
            }
        }
    }

    visited[v] = 2;
}

ll cena[maxn];
ll pref[maxn];

ll rez = 0;
ll zbir = 0;
ll len = 0;

int d[maxn];
ll dist[maxn];
ll ovaj[maxn];
int poz[maxn];
ll resi(int v, int cale) {
    if(dist[v] > T)return 0;

    ll ost = T - dist[v];
    ll kol = ovaj[v] + 1ll * (ost / len) * zbir;
    ost %= len;

    int l = 1, r = poz[cale], ans = poz[cale] + 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(pref[poz[cale]] - pref[mid] <= ost) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    kol += cena[poz[cale]] - cena[ans - 1];
    return kol;

}

bool bio[maxn];
void dfs2(int v, int cale) {
    bio[v] = 1;
    if(v != cale)ovaj[v] += niz[v];

    rez = max(rez, resi(v, cale));

    for(auto c : g[v]) {
        int u = c.fi;
        int w = c.se;
        if(!bio[u]) {
            d[u] = d[v] + 1;
            ovaj[u] = ovaj[v];
            dist[u] = dist[v] + w;
            dfs2(u, cale);
        }
    }
}

int lift[maxn][20];
bool was[maxn];
void dfs3(int v, int p) {

    lift[v][0] = p;
    ff(i,1,19)lift[v][i] = lift[lift[v][i - 1]][i - 1];

    if(dist[v] > T) {

        int u = v;
        fb(i,19,0) {
            if(lift[u][i] != 0 && dist[v] - dist[lift[u][i]] <= T) {
                u = lift[u][i];
            }
        }

        rez = max(rez, ovaj[v] - ovaj[lift[u][0]]);

    }

    for(auto c : g[v]) {
        int u = c.fi;
        int w = c.se;
        if(!was[u])dfs3(u, v);
    }
}

void Solve(int v) {
    // resavam za komponentnu gde je v
    krug.clear(), cuvaj.clear();
    dfs1(v, 0);

    if(!sz(krug)) {
        for(auto c : cuvaj)visited[c] = 0;
        return;
    }
    reverse(all(krug));

    zbir = 0, len = 0;
    for(auto c : krug)len += cost[c], zbir += niz[c];

    pref[1] = 0, cena[1] = niz[krug[0]];
    int L = sz(krug);
    ff(i,1,L - 1) {
        pref[i + 1] = pref[i] + cost[krug[i]];
        cena[i + 1] = cena[i] + niz[krug[i]];
    }

    ff(i,0,L - 1) {
        pref[L + i + 1] = pref[L + i] + cost[krug[i]];
        cena[L + i + 1] = cena[L + i] + niz[krug[i]];
        poz[krug[i]] = i + 1 + L;
    }

    for(auto c : krug)bio[c] = 1, was[c] = 1;
    for(auto c : krug)dfs2(c, c);

    for(auto c : krug)dfs3(c, 0);

}

int main() 
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> T;
    ff(i,1,n)cin >> niz[i];
    ff(i,1,n)cin >> graf[i].fi;
    ff(i,1,n)cin >> graf[i].se;

    ff(i,1,n) {
        int u = graf[i].fi;
        int v = i;
        ll w = graf[i].se;
        g[u].pb({v, w});

        cost[v] = w;

    }

    ff(i,1,n)Solve(i);
    cout << rez << endl;

    return 0;
}
/**

6 15
5 2 3 1 9 6
3 1 2 2 4 4
3 1 2 5 4 1

// probati bojenje sahovski ili slicno

**/




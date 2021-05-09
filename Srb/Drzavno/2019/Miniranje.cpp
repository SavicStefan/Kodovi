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
const int maxn = 505;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n, M;
char mat[maxn][maxn];

int pref[maxn][maxn];

bool A[maxn][maxn];
bool da_li_A(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n && mat[x][y] != 'X' && !A[x][y]);
}

void dfsA(int x, int y) {
    A[x][y] = 1;
    if(da_li_A(x - 1, y))dfsA(x - 1, y);
    if(da_li_A(x + 1, y))dfsA(x + 1, y);
    if(da_li_A(x, y - 1))dfsA(x, y - 1);
    if(da_li_A(x, y + 1))dfsA(x, y + 1);
}

bool B[maxn][maxn];
bool da_li_B(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n && mat[x][y] != 'X' && !B[x][y]);
}

void dfsB(int x, int y) {
    B[x][y] = 1;
    if(da_li_B(x - 1, y))dfsB(x - 1, y);
    if(da_li_B(x + 1, y))dfsB(x + 1, y);
    if(da_li_B(x, y - 1))dfsB(x, y - 1);
    if(da_li_B(x, y + 1))dfsB(x, y + 1);
}

int Solve1(){
   	// ako imam samo jednu minu

    // treba da pogledam na koja sve polja A, moze da dodje, pogledam na koja sva polja B moze dodje
    // i onda samo na svakom polju gde A moze da dodje probam da stavim minu i to je to

    pii pozA = {0, 0}, pozB = {0, 0};
    ff(i,1,n)ff(j,1,n) {
        if(mat[i][j] == 'A')pozA = {i, j};
        if(mat[i][j] == 'B')pozB = {i, j};
    }

    dfsA(pozA.fi, pozA.se);
    dfsB(pozB.fi, pozB.se);

    if(A[pozB.fi][pozB.se] == 1)return -1;

    vector<pii> polja;
    ff(i,1,n)ff(j,1,n)if(A[i][j] == 1)polja.pb({i, j});

    ff(i,1,n)ff(j,1,n)pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + B[i][j];
    auto get = [&](int x1, int y1, int x2, int y2) {
        return pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1];
    };


    auto check = [&](int K) {
        for(auto c : polja) {
            int x = c.fi;
            int y = c.se;

            pii dole = {max(1,x - K), max(1, y - K)};
            pii gore = {min(n,x + K), min(n, y + K)};
			
            if(get(dole.fi, dole.se, gore.fi, gore.se) > 0)return 1;

            ff(i,dole.se,gore.se)if(B[gore.fi + 1][i] || B[dole.fi - 1][i])return 1;
            ff(i,dole.fi,gore.fi)if(B[i][dole.se - 1] || B[i][gore.se + 1])return 1;

        }
        return 0;
    };

    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

	return ans;
}

int visited[maxn][maxn];
bool da_li(int x, int y){
	return (x >= 1 && x <= n && y >= 1 && y <= n && mat[x][y] != 'X' && visited[x][y] == 0);
}

vector<pii> g[maxn * maxn];

void dfs(int x, int y, int br){
	visited[x][y] = br;
	g[br].pb({x, y});
	
	if(da_li(x - 1, y))dfs(x - 1, y, br);
	if(da_li(x + 1, y))dfs(x + 1, y, br);
	if(da_li(x, y - 1))dfs(x, y - 1, br);
	if(da_li(x, y + 1))dfs(x, y + 1, br);
}

int main() 
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> M;
    ff(i,1,n)ff(j,1,n)cin >> mat[i][j];

    if(M == 1) {
		cout << Solve1();

    } else {
		// sad treba videti za dve mine
		
		int br = 0;
		ff(i,1,n){
			ff(j,1,n){
				if(!visited[i][j] && mat[i][j] != 'X'){
					br += 1;
					dfs(i, j, br);
				}
			}
		}
				
		pii pozA = {0, 0}, pozB = {0, 0};
	    ff(i,1,n)ff(j,1,n) {
	        if(mat[i][j] == 'A')pozA = {i, j};
	        if(mat[i][j] == 'B')pozB = {i, j};
	    }
	
	    dfsA(pozA.fi, pozA.se);
	    dfsB(pozB.fi, pozB.se);
	
	    if(A[pozB.fi][pozB.se] == 1)return cout << -1, 0;
	    
		ff(i,1,n)ff(j,1,n)pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + B[i][j];
	    
		auto get = [&](int x1, int y1, int x2, int y2) {
	        return pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1];
	    };
		
	    auto check = [&](int K) {
	        for(auto c : g[visited[pozA.fi][pozA.se]]) {
	        	
				cout << "polje: " << c.fi << " " << c.se << endl;
	        	
				auto pipa = [&](int x, int y){
					for(auto f : g[visited[x][y]]){
						if(B[f.fi][f.se])return 1;
					}				
					
					pii X = {max(1,x - K), max(1, y - K)};
			    	pii Y = {min(n,x + K), min(n, y + K)};
					
					if(get(X.fi, X.se, Y.fi, Y.se) > 0)return 1;
					
					ff(i,X.se,Y.se){
						if(mat[Y.fi + 1][i] != 'X'){
							for(auto f : g[visited[Y.fi + 1][i]]){
								if(B[f.fi][f.se])return 1;
							}
						}
						if(mat[X.fi - 1][i] != 'X'){
							for(auto f : g[visited[X.fi - 1][i]]){
								if(B[f.fi][f.se])return 1;
							}
						}
					}
					
					ff(i,X.fi,Y.fi){
						if(mat[i][X.se - 1] != 'X'){
							for(auto f : g[visited[i][X.se - 1]]){
								if(B[f.fi][f.se])return 1;
							}
						}
						if(mat[i][Y.se + 1] != 'X'){
							for(auto f : g[visited[i][Y.se + 1]]){
								if(B[f.fi][f.se])return 1;
							}
						}	
					}
						
					return 0;
				};
	
				if(pipa(c.fi,c.se))return 1;
			
				int x = c.fi, y = c.se;
				ff(i,max(1,x - K),min(n, x + K)){
					ff(j,max(1,y - K),min(n, y + K)){
						// ako sad negde ovde stavim minu
						if(mat[i][j] == 'X')continue;
						for(auto f : g[visited[i][j]]){
							if(pipa(f.fi, f.se))return 1;
						}
					}
				} 
				
				pii X = {max(1,x - K), max(1, y - K)};
		    	pii Y = {min(n,x + K), min(n, y + K)};
				
				ff(i,X.se,Y.se){
					if(mat[Y.fi + 1][i] != 'X'){
						for(auto f : g[visited[Y.fi + 1][i]]){
							if(pipa(f.fi, f.se))return 1;
						}
					}
					if(mat[X.fi - 1][i] != 'X'){
						for(auto f : g[visited[X.fi - 1][i]]){
							if(pipa(X.fi - 1, i))return 1;
						}
					}
				}
				
				ff(i,X.fi,Y.fi){
					if(mat[i][X.se - 1] != 'X'){
						for(auto f : g[visited[i][X.se - 1]]){
							if(pipa(i, X.se - 1))return 1;
						}
					}
					if(mat[i][Y.se + 1] != 'X'){
						for(auto f : g[visited[i][Y.se + 1]]){
							if(pipa(i, Y.se + 1))return 1;
						}
					}	
				}
				
	        }
	        
	        return 0;
	    };
	
		cout << check(8) << endl;
		return 0;
	
	    int l = 1, r = n, ans = 0;
	    while(l <= r) {
	        int mid = (l + r) / 2;
	        if(check(mid)) {
	            ans = mid;
	            r = mid - 1;
	        } else l = mid + 1;
	    }
	
		cout << ans;
								
    }

    return 0;
}
/**

4 1
AXXB
XXXX
XXXX
XXXX

3 1
AXX
XXX
XXB

// probati bojenje sahovski ili slicno

**/

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
const int maxn = 105;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n, m;
int mat[maxn][maxn];
int C[maxn][maxn];
int B[maxn * maxn];

const int mod = 1e9 + 7;
ll add(ll a, ll b){
	return (a + b) % mod;
}
ll mul(ll a, ll b){
	return (a * b) % mod;
}

ll zbir[maxn][maxn];
ll pom[maxn][maxn];
void calc(int i){
	memset(pom, 0, sizeof(pom));
	ff(l,1,m)pom[1][l] = mat[i][l];
	
	ff(j,2,m){
		// ako uzimam j utakmica
		ll sum = 0;
		fb(l,m,1){
			pom[j][l] = add(pom[j][l], mul(sum, mat[i][l]));
			sum = add(sum, pom[j - 1][l]);
		}
	}
	
	ff(j,1,m){
		ff(l,1,m)zbir[i][j] = add(zbir[i][j], pom[j][l]);
	}
	
}

ll dp[maxn][maxn * maxn];

int main()
{
   	ios::sync_with_stdio(false);
   	cout.tie(nullptr);
  	cin.tie(nullptr);
	cin >> n >> m;
	ff(i,1,n)ff(j,1,m)cin >> mat[i][j];
	ff(i,1,n)ff(j,1,m)cin >> C[i][j];
	ff(i,1,n * m)cin >> B[i];
	
	ff(i,1,n)calc(i);				
	
	dp[0][0] = 1;
	ff(i,1,n){
		ff(j,1,n * m){
			ff(l,1,min(j, m)){
				if(C[i][l] == 1 && j >= l){
					dp[i][j] = add(dp[i][j], mul(zbir[i][l], dp[i - 1][j - l]));
				}
			}
		}
	}
	
	ll rez = 0;
	ff(j,1,n * m)rez = add(rez, mul(B[j], dp[n][j]));
	cout << rez << endl;
		
   	return 0;
}
/**

2 3
2 3 4
5 6 7
1 0 1
0 1 1
10 20 30 40 50 60

535290

// probati bojenje sahovski ili slicno

**/




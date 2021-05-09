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
const int maxn = 2000005;
const int inf = 1e9 + 5;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

int n;
int niz[maxn];

int cnt1[7];
int cnt2[7];

int pom1[7];
int pom2[7];
int resi(){
//	ff(i,1,6)cout << cnt1[i] << " ";
//	cout << endl;
//	ff(i,1,6)cout << cnt2[i] << " ";
//	cout << endl;
	
	ff(i,1,6){
		pom1[i] = cnt1[i];
		pom2[i] = cnt2[i];
	}
	
	int kol = 0;
	ff(i,1,6){
		if(pom1[i] == 0)continue;
//		cout << "i: " << i << endl;
		ff(j,1,6){
			if(pom1[i] == 0)break;
			int mn = min(pom1[i], pom2[j]);
//			cout << "mn & j: " << mn << " " << j << endl;
			pom2[j] -= mn;
			pom1[i] -= mn;		
			if(i > j)kol += mn;
		}
//		cout << endl;
		
	}
	
//	cout << "kol: " << kol << endl;
//	cout << "-------------------" << endl;
//	cout << endl;
	
	return kol;
	
}

int main()
{
   	ios::sync_with_stdio(false);
   	cout.tie(nullptr);
  	cin.tie(nullptr);
	cin >> n;
	ff(i,1,2 * n)cin >> niz[i];

	int mx = 0, ko = 0, A = 3, B = 4;
	ff(k,1,n){
		if(k == 1){
			cnt1[niz[k]] += 1;
			cnt2[niz[k + 1]] += 1;
		}
		else{
			cnt1[niz[k]] += 1;
			cnt2[niz[k]] -= 1;
			cnt2[niz[A]] += 1, A += 2;
			cnt2[niz[B]] += 1, B += 2;
			
		}
		
		int kol = resi();
		if(kol > mx){
			mx = kol;
			ko = k;
		}
		
	}
	
	cout << ko << endl;
	
   	return 0;
}
/**

4
2 4 6 1 5 3 5 2

// probati bojenje sahovski ili slicno

**/




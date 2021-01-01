#include<bits/stdc++.h>

#define ff(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b){
	return a + rng() % (b - a + 1);
}

int main()
{
	int n = rand(2, 5);
	int q = 10;
	cout << n << " " << q << endl;
	ff(i,1,n){
		int x = rand(2, 5);
		cout << x << " ";
	}
	cout << endl;
	ff(i,1,q){
		int t = rand(1, 2);
		int l = rand(1, n);
		int r = rand(1, n);
		if(l > r)swap(l, r);
		cout << t << " " << l << " " << r << endl;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define lop(a,b,c) for(int (a) = (b); (a) < (c); (a)++)
#define lopd(a,b,c) for(int (a) = (b); (a) >= (c); (a)--)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
/* ========== YOUR CODE HERE ========= */

ll n, x, y;
bool check(ll val) {
	return ((val / x) + (val - x) / y)  >= n;
}


void solution() {
	cin >> n >> x >> y;
	ll l = 1, r = 1;
	if (x > y)
		swap(x, y);
	while (!check(r))
		r *= 2;
	while (r > l + 1) {
		ll mid = l + (r - l) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r;
}

/* ========== YOUR CODE HERE ========= */
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solution();
	cout << "\n";

	return 0;
}

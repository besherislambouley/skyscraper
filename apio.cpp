/*
 * https://codeforces.com/blog/entry/17717?#comment-226989
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
int n , m , sta , en ;
vpi v[30009] ;
unordered_set<int>s[30009];
int dis[30009] ;
int main () {
	scanf("%d%d",&n,&m);
	for ( int i = 0 ; i < m ; i ++ ) {
		int pos , x ;
		scanf("%d%d",&pos,&x);
		if ( i == 0 ) sta = pos ;
		if ( i == 1 ) en  = pos ;
		s[pos].ins ( x ) ;
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		dis [i] = 1e9 ;
		for ( auto u : s[i] ) {
			int len = 0 ;
			for ( int j = i + u ; j < n ; j += u ) {
				len ++ ;
				v[i].pb ( { j , len } ) ;
				if ( s[j] .count ( u ) ) break ;
			}
			len = 0 ;
			for ( int j = i - u ; j >= 0 ; j -= u ) {
				len ++ ;
				v[i].pb ( { j , len } ) ;
				if ( s[j] .count ( u ) ) break ;
			}
		}
	}
	priority_queue< pair<int , int> , vector< pair<int , int> > , greater< pair<int , int> > > st ;
	dis [sta] = 0 ;
	st .push ( { 0 , sta } ) ;
	while ( st.size() ) {
		int node = st.top().se;
		int t = st.top().fi;
		st .pop();
		if ( node == en ) {
			printf("%d\n",t);
			exit(0);
		}
		if ( t > dis[node] ) C ;
		for ( auto U : v[node] ) {
			int u = U.fi ;
			int x = U.se ;
			if ( t + x < dis [u] ) {
				dis [u] = t + x ;
				st.push ( { dis[u] , u } ) ;
			}
		}
	}
	printf("-1\n");
}

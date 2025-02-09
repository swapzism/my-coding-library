#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define umpii unordered_map<int,int>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define setBits(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 
const double pi = acos(-1);
int power(int a,int b,int m=MOD)
{int ans=1;while(b>0){if(b&1)ans=((ans%m)*(a%m))%m;
a=((a%m)*(a%m))%m;b>>=1;}return ans;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};

const int N = 1e5+1;
vi fact,inv;

void factorial(int MAXN,int m=MOD)
{
    fact=vi (MAXN);
    fact[0]=1;
    for(int i=1;i<=MAXN;i++)
    fact[i]=(fact[i-1]*i)%m;
}

void invfact(int MAXN,int m=MOD)
{
    inv=vi (MAXN);
    inv[0]=1;
    for(int i=1;i<=MAXN;i++)
    inv[i]=power(fact[i],m-2,m);
}

int C(int n,int r,int m=MOD)
{
    if(n<r or n<0 or r<0)
        return 0;
    int ans=fact[n];
    ans=(ans*inv[r])%m;
    ans=(ans*inv[n-r])%m;
    return ans;
}

void precomp()
{
	factorial(N);
	invfact(N);
}

void solve()
{
	int i,j,n,r;
	cin>>n>>r;
	cout<<C(n,r)<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	cin>>t;
	precomp();
	while(t--)
		solve();
}
//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

void Redirect() {
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int l,n;
int a[1005];

bool check(double d) {
	double covered = 0;
	for(int i=1;i<=n;++i) {
		if(covered-(a[i]-d)>1e-11) {
			covered=a[i]+d;	
		} else {
			return 0;
		}
	}
	return covered>l;
}

int main() {
	R(n); R(l);
	rep(i,1,n,1) {
		R(a[i]);
	}
	sort(a+1,a+n+1);
	double l=0,r=1e9;
	while(r-l>1e-10) {
		double mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%.10f\n",r);
}



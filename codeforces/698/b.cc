//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
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
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar(); } 
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n,cnt;
int ori[200050];
int f[200050];
int ans[200500];
int root;
int getf(int x) {
	int cur=x;
	while(f[cur]!=cur) {
		cur=f[cur];
		if(cur==x) return -1;
	}
	int r=cur; int la;
	while(f[x]!=x) {
		la=x;
		x=f[x];
		f[x]=r;
	}
}
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(ori[i]);
		f[i]=ori[i]; ans[i]=ori[i];
		if(ori[i]==i) root=i;
	}
	if(root<1) {
		root=getf(1);
	}
	if(root<1) {
		root=1; cnt++;
	}
	f[root]=root;
	ans[root]=root;
	for(int i=2;i<=n;++i) {
		int 
	}
}



#include <iostream>
#define ll long long
using namespace std;
ll v[100005];

int main(){
	ll n, r, m, j=0, T=0, atv=0, k=0, tlocal=0, L=0, x=0, y=0, vi=0;
	scanf("%lld %lld", &n, &r);
	ll l[n], t[n];
	scanf("%lld", &l[0]);
	for(int i=1; i<n; i++){
		scanf("%lld", &m);
		l[i]=l[i-1]+m;
	}
	scanf("%lld", &t[0]);
	if(t[0]<l[0]){
		printf("-1");
		return 0;
	}
	for(int i=1; i<n; i++){
		scanf("%lld", &t[i]);
		if(t[i]<l[i]-l[i-1]){
			printf("-1");
			return 0;
		}
	}
	
	while(true){
		if(L==l[j]){
			if(j==n-1) break;
			j++;
			tlocal=0;
		}
		if(atv>=l[j]-L){
			T+=l[j]-L; 
			atv-=(l[j]-L);
			L=l[j];
			continue;
		}else{
			T+=atv;
			L+=atv;
			tlocal+=atv;
			atv=0;
		}
		if((l[j]-L)*2<=(t[j]-tlocal)){
			T+=(l[j]-L)*2;
			L=l[j];
			continue;
		}else if((t[j]-tlocal)!=(l[j]-L)){
			x=t[j]-tlocal+L-l[j];
			T+=2*x;
			tlocal+=2*x;
			L+=x;
		}	
		
		y=(l[j]-L)/r;
		
		if(vi==1 || y+k>100000) vi=1;
		else for(int i=0; i<y; i++) v[k+i+1]=T+r*i;
		k+=y;
		T+=y*r;
		L+=y*r;
		tlocal+=y*r;
		if(L==l[j]) continue;
		atv=r;
		k++;
		if(k<=100000) v[k]=T;
		T+=l[j]-L; 
		atv-=(l[j]-L); 
		L=l[j];
	}
	
	
	printf("%lld\n", k);
	if(k<=100000)for(int i=1; i<=k; i++) printf("%lld ", v[i]);
	return 0;
}
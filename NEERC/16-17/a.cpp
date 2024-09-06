#include <bits/stdc++.h>
using namespace std;

bool op[10005][105];
pair<int, int> v[101] ;

int main(){
	int n, j=0, f;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i].first);
		v[i].second=i;	
	}
	
	while(true){
		sort(v, v+n);
		if(v[0].first==v[n-1].first || v[n-1].first==0) break;
		j++;
		f=1;
		for(int i=1; i<=n; i++){
			if(v[n-i].first==v[n-i-1].first) f++;
			else break;
		}
		if(v[n-1].first==v[n-2].first && f%2==1){
			op[j-1][v[n-1].second]=1;
			op[j-1][v[n-2].second]=1;
			op[j-1][v[n-3].second]=1;
			v[n-1].first--;
			v[n-2].first--;
			v[n-3].first--;
		}else{
			op[j-1][v[n-1].second]=1;
			op[j-1][v[n-2].second]=1;
			v[n-1].first--;
			v[n-2].first--;
		}
	}
	printf("%d \n", v[n-1]);
	printf("%d \n", j);
	for(int i=0; i<j; i++){
		for(int k=0; k<n; k++){
			printf("%d", op[i][k]);
		}
		printf("\n");
	}
	return 0;
}
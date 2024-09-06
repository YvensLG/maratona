#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, s, d, l=0, k=0, m=0, inicio, fim;
	vector< pair<int, int> > v;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		sort(v.begin(), v.end());
		l=0;
		m=0;
		k=0;
		scanf("%d %d", &s, &d);
		if(v.empty() || v[v.size()-1].second<s){
			v.push_back(make_pair(s, s+d-1));
			inicio=s;
			fim=s+d-1;
		}else{
			for(int i=0; i<v.size(); i++){
				if(v[i].first>s){
					if(i==0 || v[i-1].second<s){
						if(s+d-1<v[i].first){
							v.push_back(make_pair(s, s+d-1));
							l=1;
							inicio=s;
							fim=s+d-1;
						}
					}
					break;
				}
			}
			if(l!=1){
				if(d<v[0].first){
					v.push_back(make_pair(1, d));
					inicio=1;
					fim=d;
				}else{
					for(int i=0; i<v.size()-1; i++){
						if((v[i+1].first-v[i].second-1)>=d){
							v.push_back(make_pair(v[i].second+1, v[i].second+d));
							inicio=v[i].second+1;
							fim=v[i].second+d;
							m=1;
							break;
						}
					}
					if(m==0){
						inicio=v[v.size()-1].second+1;
						fim=v[v.size()-1].second+d;
						v.push_back(make_pair(v[v.size()-1].second+1, v[v.size()-1].second+d));
					}
				}
			}
		}
		printf("%d %d\n", inicio, fim);
	}
	return 0;
}
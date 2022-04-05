#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--){
        vector<int> v[30];
        int num[30]={0};
		string s,t;
		cin>>s>>t;
		for(int i = 0;i<s.length();i++){
			v[s[i]-'a'].push_back(i);
			++num[s[i]-'a'];
		}
		int ans = 1;
		int p = -1;
		for(int i = 0;i<t.length();i++){
			if(!num[t[i]-'a']){
				ans = -1;
				break;
			}
			else if(p>=v[t[i]-'a'][num[t[i]-'a']-1]){	
				++ans;
				p = v[t[i] - 'a'][0];
			}
			else
				p = v[t[i]-'a'][upper_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),p)-v[t[i]-'a'].begin()];
		}
		cout<<ans<<endl;
	}

	return 0;
}
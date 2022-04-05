#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
static int N=500;
int lcs(string X,string Y){
	int c[N+1][N+1];//二維陣列表示的是 Xi與Yi的 lcs的大小 
	int maxl=0;//最終返回的lcs
	int m=X.size();
	int n=Y.size();
	X=' '+X;
	Y=' '+Y;
	for(int i=0;i<=m;i++)  c[i][0]=0; 
	for(int j=0;j<=n;j++)  c[j][0]=0; 
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(X[i]==Y[j]){//如果最後的尾數相等，就為上 c[i-1][j-1]+1(詳見公式) 
				c[i][j]=c[i-1][j-1]+1;
			}else if(X[i]!=Y[j]){//如果不是
				c[i][j]=max(c[i-1][j],c[i][j-1]); 
			}
			maxl=max(maxl,c[i][j]);//不斷更新最後需要輸出的 lcs（不需要額外的用一個迴圈遍歷了） 
		}
	}
	return maxl;
}

int main(){
	string x,y;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		cout<<lcs(x,y)<<endl;
	} 
	return 0;
}
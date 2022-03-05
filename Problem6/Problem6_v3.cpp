#include <iostream>
using namespace std;

int sum[100];
void function(int m, int k)
{
    int i, j;
    for (i = m; i >= k; i--)
    {
        a[k] = i;
        if (k > 1)
        {
            function(i - 1, k - 1);
        }
        else
        {
            for (j = a[0]; j > 0; j--){
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
	int n,r;
	cout<<"請輸入n和r的值:"<<endl;
	cin>>n>>r;
	if(r>n)
		cout<<"輸入n和r的值錯誤!"<<endl;
	else
	{
		a[0]=r;
		function(n,r);
	}
	return 0;
}
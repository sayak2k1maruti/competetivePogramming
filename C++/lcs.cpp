
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b);


int lcs( char *X, char *Y, int m, int n )
{
	int L[m + 1][n + 1];
	int i, j;
	
	
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
		if (i == 0 || j == 0)
			L[i][j] = 0;
	
		else if (X[i - 1] == Y[j - 1])
			L[i][j] = L[i - 1][j - 1] + 1;
	
		else
			L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        
		}
		
	}
	for(int i=0;i<=m;i++)
  {
    for(int j=1;j<=i;j++)
    {
        cout<<"0 ";
    }
    for(int j=i;j<=n;j++)
    {
      cout<<L[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n";	
	
	return L[m][n];
}
int max(int a, int b)
{
	return (a > b)? a : b;
}

int main()
{
	char X[] = "BD";
	char Y[] = "ABCD";
	
	int m = strlen(X);
	int n = strlen(Y);
	
	cout << "Dp table followed by Length of LCS is "<<"\n"
		<< lcs( X, Y, m, n );
	
	return 0;
}


#include <iostream>
using namespace std;

int findGroups(int** a, int n);

int main()
{
	return 0;
}

void dfs(int u, int *check, int **a, int n){
	cout<<u<<" ";
	for (int v=0;v<n;v++){
		if (a[u][v] == 1) {
			if (check[v]==0){
				check[v]=1;
				dfs(v,check,a,n);
			}
		}
	}
}
// print out the list of each disconnected group and return the number of groups
int findGroups(int** a, int n)
{
	int *check; int dem=0;
	check = new int[n];
	for (int i=0;i<n;i++) check[i]=0;
	for (int i=0;i<n;i++){
		if (check[i]==0){
			check[i]=1;
			dem++;
			cout<<"Group "<<dem<<": ";
			dfs(i, check, a, n);
			cout<<endl;
		}
	}
	cout<<"Total: "<<dem;
}
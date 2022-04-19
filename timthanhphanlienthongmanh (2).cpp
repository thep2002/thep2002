#include<bits/stdc++.h>
#include<stdio.h>
#define MAX 100
#include <algorithm>
#include<deque>  
using namespace std;
deque<int> p1;
string s[6000];
bool E[6000][6000];
int n;
int visited[6000];
int pre[6000], post[6000];
int Clock = 0;
int dem=0;
void doc()
{
	ifstream fileInput("nhap.txt");

	if (fileInput.fail())
	{
		cout << "Failed to open this file!" << endl;
	}
	else
		{
				n = 1;
				while (!fileInput.eof())
				{
					fileInput >> s[n];
					n++;
				}
				n--;
				cout << n << endl;
		}
	fileInput.close();
}
void docx()
{	bool d;
	ifstream fileInput("nhaplieu.txt");

	if (fileInput.fail())
	{
		cout << "Failed to open this file!" << endl;
	}
	else
		{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{	
				fileInput>>d;
				E [i][j] = d;
			}
		}
	fileInput.close();
}
void explore(int v)
{	p1.push_back(v);
    visited[v]=1; 
    pre[v]=Clock;
    post[v]=Clock;
    Clock++;
	for(int u=1; u <= n; u++)
        if (E[v][u] == 1){
            if (visited[u]==0) 
				{
				explore(u);
				if(post[v]>post[u]) post[v]=post[u];
				}
        	else if  (visited[u]==1)
        		if (post[v]>pre[u]) post[v]=pre[u];
    
}
	if (post[v] == pre[v]) {  
        int u;
		do {u=p1.back();
		printf("%d ",u);
            p1.pop_back();
        } while (u != v);
		dem++;
    }
}

void dfs ()
{  
    for (int v=1; v<=n; v++)
        visited[v]=0;
    for (int v=1; v<=n; v++)
        if (visited[v]==0) {
			explore(v);
			for (int i=1; i<=n; i++)
        {
        	if (visited[i]==1) visited[i]=-1;
		}}
        
}
int main()
{
    doc();
    docx();
    dfs();
    cout<<dem;
    return 0;
}

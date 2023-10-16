#include<bits/stdc++.h>
#include<vector>

using namespace std;


int n, m ; 
vector<int> adj[1000000] ; 
bool visited[1000000] ; 


void input() 
    {    
    	 cin >> n >> m ;
    	 for(int i=0; i<m; i++) 
    	  {
    	  	int x, y ; cin >> x >> y ; 
    	    adj[x].push_back(y) ; 
    	    adj[y].push_back(x) ; 
		  } 
		  
		 memset(visited, false, sizeof(visited)) ;  
	}
	
void BFS(int u)	 
    {
    	queue<int> q ;
    	q.push(u) ; 
    	visited[u] = true ; 
    	
    	while(!q.empty()) 
    	 {
    	 	int v = q.front() ; 
    	 	q.pop() ; 
    	 	for(int x : adj[v]) 
    	 	 {
    	 	 	if(!visited[x]) 
    	 	 	 {
    	 	 	 	q.push(x) ; 
    	 	 	 	visited[x] = true ; 
				   }
			  }
		 }
	}

void CC() 
  { 
    memset(visited, false, sizeof(visited)) ; 
  	int cnt = 0 ; 
  	for(int i=1; i<=n; i++) 
  	 {
  	 		if(!visited[i])
  	 		{
  	 			cnt++ ; 
  	 			BFS(i) ; 
			}
	 }
	cout << endl << cnt ; 
  }
int main() {
	input() ; 
	BFS(1) ; 
	CC() ; 
    return 0 ; 
}

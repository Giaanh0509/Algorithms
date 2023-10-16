#include<bits/stdc++.h> 

using namespace std ;

int n, m ;
vector<int> adj[1000] ; 
bool visited[1001] ; 
int c[1000] ; 
int s=0 ; 

void input() 
    {
    	cin >> n >> m ;
    	for(int i=1; i<=n; i++) 
    	  cin >> c[i] ; 
    	for(int i=0; i < m; i++)
    	 {
    	 	 int x, y; cin >> x >> y ;
    	 	 adj[x].push_back(y) ; 
		 }
		 
	  memset(visited, false, sizeof(visited)) ; 	 
	}

void BFS(int u) 
   {
     queue<int> que ; 
	 que.push(u) ;	
	 visited[u] = true ;
	 
	 while(!que.empty())
	  {
	  	 int now = que.front() ;
	  	 que.pop() ;
	   	cout << now << " " ;   
	  	 s += c[now] ; 
	  	 for(int x : adj[now])
	  	  {
	  	  	if(!visited[x])
	  	  	 {
	  	  	   que.push(x) ; 
			   visited[x] = true ; 	
			 }
	  	   	
		  }
	  }
	cout << s << " " ;   
   }
   
int main()
    {
     input() ;
     BFS(4) ; 
     return 0 ;
	}

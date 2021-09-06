#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define ll long long
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<ll>st;ll vis[5001];
	void dfs2(ll node,vector<vector<ll > >&v1)
    {
        vis[node] = 1;
        for(auto i : v1[node])
        {
            if(!vis[i])
            dfs2(i,v1);
        }
    }
	void dfs(ll node,vector<int> adj[])
    {
        vis[node] = 1;
        for(auto i: adj[node])
        {
            if(!vis[i])
            {
                dfs(i,adj);
            }
        }
        st.push(node);
    }

    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        memset(vis,0,sizeof(vis));
        for(int i = 0  ; i < V ; i++)
        {
            if(!vis[i])
            dfs(i,adj);
        }
        vector<vector<ll> >v1(V);
        for(int i = 0 ; i < V ; i++)
        {
            for(int j =0 ; j  < adj[i].size(); j++)
            {
                int val = adj[i][j];
                v1[val].push_back(i);
            }
        }
        memset(vis,0,sizeof(vis));
        ll cnt = 0; 
        while(!st.empty())
        {
            ll x = st.top();
            if(!vis[x])
            {
                st.pop();
                cnt += 1;
                dfs2(x,v1);
            }
            else
            st.pop();
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
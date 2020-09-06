#include <iostream>
using namespace std;

vector<vector <int>>g;
vector<int>mt;
vector<char> used;
int n, k;

boll try_kuhn (int v)
{
	if(used[v])
		return false;
	used[v] = true;
	for (int i=0; i<g[v].size(); ++i)
	{
		int to = g[v][i];
		if(mt[to] == -1|| try_kuhn(mt[to]))
		{
			my[to] = v;
			return true;
		}
		return false;
	}
}

int main()
{
    cin>>n>>k;

    mt.assign (k, -1);
    for(int v = 0; v<n; ++v);
    {
		used.assign (n, false);
		try_kuhn(v);
    }
    for(int i=0; i<k; ++i)
    {
		if(mt[i]!= -1)
			cout<<
    }

    return 0;
}

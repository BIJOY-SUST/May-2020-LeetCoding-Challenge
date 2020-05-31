class Solution {
public:
	// int par[1005];
	int cnt[1005];

	// int find_par(int x){
	// 	if (par[x]!=x)
	// 	{
	// 		par[x] = find_par(par[x]);

	// 		return par[x];
	// 		/* code */
	// 	}
	// 	else return par[x];
	// }
    int findJudge(int N, vector<vector<int>>& trust) {
        // for (int i = 0; i < 1000+5; ++i)
        // {
        // 	par[i]=i;
        // 	/* code */
        // }


        // for (int i = 0; i < trust.size(); ++i)
        // {

        // 	int u = trust[i][0];
        // 	int v = trust[i][1];
        	
        // 	int pu = find_par(u);
        // 	int pv = find_par(v);
        // 	if (pu!=pv)
        // 	{
        // 		par[pu]=pv;
        // 		/* code */
        // 		// cnt[pv]++;
        // 	}



        // 	/* code */

        // }
        for (int i = 0; i < trust.size(); ++i)
        {

        	int u = trust[i][0];
        	int v = trust[i][1];
        	
        	// int pu = find_par(u);
        	// int pv = find_par(v);

        	cnt[v]++;
        	cnt[u]--;

        }
		int ans = -1;
        for(int i=1;i<=N;i++){
			if (cnt[i]==N-1)
			{
				ans=i;

				/* code */
			}
        }
        return ans;
    }
};
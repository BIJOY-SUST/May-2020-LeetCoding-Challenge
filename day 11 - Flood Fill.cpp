class Solution {
public:
	vector<vector<int> > result;
	int vis[101][101];
	int first_col;
	
	int tx[4] = {-1,0,1,0};
	int ty[4] = {0,1,0,-1};
	
	void dfs(vector<vector<int>>& image,int sr,int sc,int newColor){

		vis[sr][sc]=1;

		for (int i = 0; i < 4; ++i)
		{
			int rr = sr+tx[i];
			int cc = sc+ty[i];

        	if(rr>=0&&rr<(int)image.size()&&cc>=0&&cc<(int)image[0].size()){
            	if(vis[rr][cc]==0 and result[rr][cc]==first_col){
                	result[rr][cc]=newColor;
                	dfs(image, rr,cc,newColor);
            	}
        	}

			/* code */
		}
		return;

	}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

    	result.resize(image.size());
        
		for (int i = 0; i < image.size(); ++i)
		{
			for (int j = 0; j < image[i].size(); ++j)
			{
				result[i].push_back(image[i][j]);
				/* code */
			}
			/* code */
		}

		first_col = image[sr][sc];
		result[sr][sc] = newColor;
		
		dfs(image, sr,sc,newColor);

		return result;

    }
};
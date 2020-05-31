class Solution {
public:
    int gcd(int a, int b){
      return !b?a:gcd(b,a%b);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool ans =true;
        bool samex = true;
        bool samey = true;
        int a = coordinates[1][0]-coordinates[0][0];
        int b = coordinates[1][1]-coordinates[0][1];
        int cc = gcd(a,b);
        a/=cc;
        b/=cc;
        for(int i =1;i<coordinates.size();i++){
         int x = coordinates[i][0]-coordinates[i-1][0];
         int y = coordinates[i][1]-coordinates[i-1][1];
         int z = gcd(x,y);
         x/=z;
         y/=z;
         ans =ans &&(x == a )&& (y == b );
        }
        return ans;
    }
};
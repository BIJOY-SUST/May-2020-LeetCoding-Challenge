class Solution {
public:
    bool isPerfectSquare(long double x) {
          long double sr = sqrt(x); 
  
          // If square root is an integer 
          return ((sr - floor(sr)) == 0);
    }
};
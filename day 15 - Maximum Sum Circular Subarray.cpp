class Solution {
public:
    // Standard Kadane's algorithm to find maximum subarray sum  
    int kadane(vector<int>& a, int n)  
    {  
        int max_so_far = INT_MIN, max_ending_here = 0;  
        int i;  
        for (i = 0; i < n; i++)  
        {  
             
            if (max_ending_here < 0)  
                max_ending_here = a[i];
            else
                max_ending_here = max_ending_here + a[i]; 
              
            max_so_far = max(max_ending_here,max_so_far);  
        }  
        return max_so_far;  
    }
    int maxSubarraySumCircular(vector<int>& a) {

        // Case 1: get the maximum sum using standard kadane'  
        // s algorithm  
        int n = a.size();
        
        int max_kadane = kadane(a, n);  
        
        if(max_kadane<0){
            return max_kadane;
        }
        
        
        
        // Case 2: Now find the maximum sum that includes  
        // corner elements.  
        int max_wrap = 0, i;  
        for (i = 0; i < n; i++)  
        {  
                max_wrap += a[i]; // Calculate array-sum  
                a[i] = -a[i]; // invert the array (change sign)  
        }  
        
        // max sum with corner elements will be:  
        // array-sum - (-max subarray sum of inverted array)  
        max_wrap = max_wrap + kadane(a, n);  
        
        // The maximum circular sum will be maximum of two sums  
        return (max_wrap > max_kadane)? max_wrap: max_kadane;  

    }
};
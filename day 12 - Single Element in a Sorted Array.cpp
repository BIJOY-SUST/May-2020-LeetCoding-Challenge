class Solution {
public:
    int ans;
    void search(vector<int>& arr, int low, int high) 
    { 
        if (low > high) 
           return; 

        if (low==high) 
        { 
            ans = arr[low];
            return; 
        } 

        int mid = (low + high) / 2; 

        if (mid%2 == 0) 
        { 
            if (arr[mid] == arr[mid+1]) 
                search(arr, mid+2, high); 
            else
                search(arr, low, mid); 
        } 
        else  
        { 
            if (arr[mid] == arr[mid-1]) 
                search(arr, mid+1, high); 
            else
                search(arr, low, mid-1); 
        } 
    } 
    int singleNonDuplicate(vector<int>& nums) {
        search(nums,0,nums.size()-1);
        return ans;
    }
};
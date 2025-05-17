class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i = 0; 
        int j = nums.size()-1;
        
        while(i <= j)
        {
            if(nums[i] == 0)
            {
                i++;
            }
            
            else if(nums[j] == 1 || nums[j] == 2)
            {
                j--;
            }
            
            else
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        
        i = 0;
        j = nums.size() - 1;
        while(i <= j)
        {
            if(nums[i] == 0 || nums[i] == 1)
            {
                i++;
            }
            
            else if(nums[j] == 2)
            {
                j--;
            }
            
            else
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
    }
};
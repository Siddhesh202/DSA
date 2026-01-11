class Solution {
public:
    
// MAH Code Starts
    vector<int> nearest_smallest_to_left(vector<int>& heights)
    {
        vector<int> ans(heights.size());
        stack<int> s;
        s.push(-1);
        
        for(int i = 0; i < heights.size(); i++)
        {
            while(s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    vector<int> nearest_smallest_to_right(vector<int>& heights)
    {
        vector<int> ans(heights.size());
        stack<int> s;
        s.push(-1);
        
        for(int i = heights.size()-1; i >= 0; i--)
        {
            while(s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }
        
    int largestRectangleArea(vector<int>& heights) 
    {
        
        int n = heights.size();
        vector<int> next(n);
        next = nearest_smallest_to_right(heights);
        
        vector<int> prev(n);
        prev = nearest_smallest_to_left(heights);
        
        int maxArea = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            int l = heights[i];
            
            if(next[i] == -1)
                next[i] = n;
            
            int b = next[i] - prev[i] - 1;
            
            int newArea = l * b;
            
            maxArea = max(maxArea, newArea);
        }
        
        return maxArea;
        
    }

// MAH Code ends
    
// Function to convert char matrix to int matrix

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> v(matrix[0].size());
        int ans = INT_MIN;
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == '1')
                    v[j]++;
                
                else
                    v[j] = 0;
                
            }
            
            int area = largestRectangleArea(v);
			ans = max(ans, area);
        }
        
        return ans;
        
    }
    
};
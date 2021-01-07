class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> v(n);

        int answer = 0;
        int max_idx = 0;
        int max_val = -1;
        int before_val = -1;
        
        for(int i = 0; i < n; i++){
            if(max_val <= height[i]){
                for(int j = max_idx; j < i; j++){
                    v[j] = height[max_idx] - height[j];
                }
                max_idx = i;
                max_val = height[i];
            }else if(before_val < height[i]){
                int j = i-1;
                while(height[j] < height[i] && j>=0){
                    v[j] = height[i] - height[j];
                    j--;
                }
            }
            before_val = height[i];
        }
        for(int i=0;i<n;i++){
            answer+=v[i];
        }
        return answer;
    }
};
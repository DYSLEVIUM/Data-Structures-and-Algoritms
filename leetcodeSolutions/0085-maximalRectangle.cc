class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      int rows = matrix.size();
      if(!rows) {
        return 0;
      }
      int cols = matrix[0].size();
      
      //  using largest histogram
      auto get_largest_histogram = [](const vector<int> &heights){
        int n = heights.size();
        if(!n) {
          return 0;
        }
        
        stack<int> st;
        vector<int> next_smaller_element(n);
        for(int i = n - 1; i >= 0; --i) {
          while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
          }
          
          if(st.empty()) {
            next_smaller_element[i] = n - 1;
          } else {
            next_smaller_element[i] = st.top() - 1;
          }
          
          st.push(i);
        }
        
        while(!st.empty()) {
          st.pop();
        }
        
        vector<int> prev_smaller_element(n);
        for(int i = 0; i < n; ++i) {
          while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
          }
          
          if(st.empty()) {
            prev_smaller_element[i] = 0;
          } else {
            prev_smaller_element[i] = st.top() + 1;
          }
          
          st.push(i);
        }
        
        int max_area = 0;
        for(int i = 0; i < n; ++i) {
          int width = next_smaller_element[i] - prev_smaller_element[i] + 1;
          max_area = max(max_area, width * heights[i]);
        }
        
        return max_area;
      };
      
      int max_area = INT_MIN;
      vector<int> prev_row(cols), curr_row(cols);
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          if(matrix[row][col] - '0') {
            curr_row[col] = prev_row[col] + (matrix[row][col] - '0');
          } else {
            curr_row[col] = 0;
          }
        }
        
        max_area = max(max_area, get_largest_histogram(curr_row));
        prev_row = curr_row;
      }
      
      return max_area;
    }
};

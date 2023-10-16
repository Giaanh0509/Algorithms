#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));

    // Nh?p ma tr?n A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }


    vector<vector<int>> height(n, vector<int>(m, 0));

    // Tinh chi?u cao c?a hinh ch? nh?t theo t?ng dong
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 1) {
                height[i][j] = 1;
                if (i > 0) {
                    height[i][j] += height[i - 1][j];
                }
            }
        }
    }

    int maxRectangleArea = 0;



    // Tinh di?n tich c?a hinh ch? nh?t l?n nh?t
    for (int i = 0; i < n; i++) {
        vector<int> stack;
        for (int j = 0; j < m; j++) {
            while (!stack.empty() && height[i][j] <= height[i][stack.back()]) {
                int h = height[i][stack.back()];
                stack.pop_back();
                int w = stack.empty() ? -1 : stack.back();
                maxRectangleArea = max(maxRectangleArea, h * (j - w - 1));
            }
            stack.push_back(j);
        }
        
        
        while (!stack.empty()) {
            int h = height[i][stack.back()];
            stack.pop_back();
            int w = stack.empty() ? -1 : stack.back();
            maxRectangleArea = max(maxRectangleArea, h * (m - w - 1));
        }
    }

    cout << maxRectangleArea << endl;

    return 0;
}

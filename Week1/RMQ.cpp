#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;


struct Node {
    int minValue;
};



void build(vector<int>& arr, vector<Node>& tree, int left, int right, int index) {
    if (left == right) {
        
        tree[index].minValue = arr[left];
    } else {
        int mid = (left + right) / 2;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

    
        build(arr, tree, left, mid, leftChild);
        build(arr, tree, mid + 1, right, rightChild);

        tree[index].minValue = min(tree[leftChild].minValue, tree[rightChild].minValue);
    }
}



int query(vector<Node>& tree, int left, int right, int queryLeft, int queryRight, int index) {
    if (queryLeft <= left && queryRight >= right) {
       
        return tree[index].minValue;
    }

    if (queryLeft > right || queryRight < left) {
       
        return INT_MAX;
    }

    int mid = (left + right) / 2;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    
    int leftMin = query(tree, left, mid, queryLeft, queryRight, leftChild);
    int rightMin = query(tree, mid + 1, right, queryLeft, queryRight, rightChild);

    return min(leftMin, rightMin);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<Node> tree(4 * n);

    build(arr, tree, 0, n - 1, 0);

    int m;
    cin >> m;

    int Q = 0;
    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        int result = query(tree, 0, n - 1, i, j, 0);
        Q += result;
    }

    cout << Q << endl;

    return 0;
}

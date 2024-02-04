/*

You are given an integer array nums and you have to return a new 
counts array. The counts array has the property where counts[i] 
is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

*/

// Binary Search Tree
class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    
    int insert(Node *&root, int v) {
        if (!root) {
            root = new Node(v, 0); 
            return 0;
        }
        
        if (v < root->val) {
            root->smaller++; 
            return insert(root->left, v);
        }
        
        else {
            return insert(root->right, v) + root->smaller + (v > root->val ? 1 : 0);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};


class Solution1 {
public:
    vector<int> count;
    vector<int> countSmaller(vector<int>& nums) {    
        vector<int> indexes(nums.size());
        count.resize(nums.size());
        for(int i = 0; i < nums.size(); i++){
            indexes[i] = i;
        }
        mergesort(nums, indexes, 0, nums.size() - 1);
        return count;
    }
    void mergesort(vector<int>& nums, vector<int>& indexes, int start, int end){
        if(end <= start){
            return;
        }
        int mid = (start + end) / 2;
        mergesort(nums, indexes, start, mid);
        mergesort(nums, indexes, mid + 1, end);
        merge(nums, indexes, start, end);
    }
    void merge(vector<int>& nums, vector<int>& indexes, int start, int end) {
        int mid = (start + end) / 2;
        int i = start;
        int j = mid+1;
        int rightcount = 0;     
        vector<int> new_indexes (end - start + 1);
        int k = 0;
        while(i <= mid && j <= end){
            if(nums[indexes[j]] < nums[indexes[i]]) {
                new_indexes[k] = indexes[j];
                rightcount++;
                j++;
            }
            else {
                new_indexes[k] = indexes[i];
                count[indexes[i]] += rightcount;
                i++;
            }
            k++;
        }
        while(i <= mid){
            new_indexes[k] = indexes[i];
            count[indexes[i]] += rightcount;
            i++;
            k++;
        }
        while(j <= end){
            new_indexes[k++] = indexes[j++];
        }
        for(int i = start; i <= end; i++) {
            indexes[i] = new_indexes[i - start];
        }
    }
    
};


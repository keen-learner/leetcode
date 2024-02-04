/*

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/

// Quick Select algo

class Solution {
public:
    int findKthLargest(vector<int>& nums, int n) {
        /*
        kth largest where k is [1,n], n - size of array
        kth largest = n-k+1 smallest number if indices from [1,n]
                    = n-k smallest number if indices from [0,n-1]
        */
        int k = nums.size() - n;
        random_shuffle(nums.begin(), nums.end()); // prevent worst case scenario of quick select
        int l = 0;
        int r = nums.size() - 1;
        while(true) {
            int piv = partition(nums, l, r);
            if(piv == k) break;
            else if (piv < k) l = piv+1;
            else r = piv - 1;
        }
        return nums[k];
    }
    
    int partition(vector<int>& nums, int l , int r) {
        int i = l;
        for (int j = i + 1; j <= r; ++j) {
            if (nums[j] <= nums[l]) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i], nums[l]);
        return i;
    }
};

// using max heap
class Solution2 {
public:   
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--)
            max_heapify(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[0], nums[heap_size - 1]);
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[heap_size];
    }
private:
    int heap_size;
};

// using stl priority queue (default max priority queue)
class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop(); 
        return pq.top();
    }
}; 

// using STL multi set
class Solution4 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        int n = nums.size();
        for (int i = 0; i < n; i++) { 
            mset.insert(nums[i]);
            if (mset.size() > k)
                mset.erase(mset.begin());
        }
        return *mset.begin();
    }
};

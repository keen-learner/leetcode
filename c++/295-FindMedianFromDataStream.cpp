/*

Median is the middle value in an ordered integer list. If the size of the list 
is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2


class MedianFinder {
public:
    // initialize your data structure here. 
    MedianFinder() {        
    }
    
    void addNum(int num) {
    }
    
    double findMedian() {
    }
};

*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

// Priority queue solutions
class MedianFinder {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num) {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (lo.size() < hi.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};


class MedianFinder1 {
private:
    // max_pq stores the smaller first half of the stream
    priority_queue<int, vector<int>, less<int>> max_pq;
    // min_pq stores the larger second half of the stream
    priority_queue<int, vector<int>, greater<int>> min_pq;

public:
    
    void addNum(int num) {
        /*
        if(max_pq.empty() || ((!min_pq.empty()) && num < min_pq.top())) {
        This is wrong condition, see , -1, -2, -3, -4, -5
        */
        if(max_pq.empty() || num <= max_pq.top()) { // first element goes to max_pq
            max_pq.push(num); // can do max_pq.emplace(num) as well
            if(max_pq.size()  > min_pq.size() + 1) { // rebalance, max_pq can have atmost 1 more element than min_pq
                min_pq.push(max_pq.top());
                max_pq.pop();
            }
        }        
        else {
            min_pq.push(num);
            if(min_pq.size() > max_pq.size()) { // rebalance, min_pq size is atmost equal max_pq size
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
        }
    }
    
    double findMedian() {
        return max_pq.size() == min_pq.size() ?
            (max_pq.top() + min_pq.top()) / 2.0 : max_pq.top();
    }
};


class MedianFinder2 {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        // Balance smaller half and larger half.
        if (max_heap_.empty() || num > max_heap_.top()) {
            min_heap_.emplace(num);
            if (min_heap_.size() > max_heap_.size() + 1) {
                max_heap_.emplace(min_heap_.top());
                min_heap_.pop();
            }
        } else {
            max_heap_.emplace(num);
            if (max_heap_.size() > min_heap_.size()) {
                min_heap_.emplace(max_heap_.top());
                max_heap_.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return min_heap_.size() == max_heap_.size() ?
                   (max_heap_.top() + min_heap_.top()) / 2.0 :
                   min_heap_.top();

    }

private:
    // min_heap_ stores the larger half seen so far.
    priority_queue<int, vector<int>, greater<int>> min_heap_;
    // max_heap_ stores the smaller half seen so far.
    priority_queue<int, vector<int>, less<int>> max_heap_;
};


// balanced bst solutions
class MedianFinder3 {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

public:
    MedianFinder3(): lo_median(data.end()), hi_median(data.end()) {}

    void addNum(int num) {
        const size_t n = data.size();   // store previous size

        data.insert(num);               // insert into multiset

        if (!n) {
            // no elements before, one element now
            lo_median = hi_median = data.begin();
        }
        else if (n & 1) {
            // odd size before (i.e. lo == hi), even size now (i.e. hi = lo + 1)

            if (num < *lo_median)       // num < lo
                lo_median--;
            else                        // num >= hi
                hi_median++;            // insertion at end of equal range
        }
        else {
            // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)

            if (num > *lo_median && num < *hi_median) {
                lo_median++;                    // num in between lo and hi
                hi_median--;
            }
            else if (num >= *hi_median)         // num inserted after hi
                lo_median++;
            else                                // num <= lo < hi
                lo_median = --hi_median;        // insertion at end of equal range spoils lo
        }
    }

    double findMedian() {
        return (*lo_median + *hi_median) * 0.5;
    }
};

class MedianFinder4 {
    multiset<int> data;
    multiset<int>::iterator mid;

public:
    MedianFinder4(): mid(data.end()) {}

    void addNum(int num) {
        const int n = data.size();
        data.insert(num);

        if (!n)                                 // first element inserted
            mid = data.begin();
        else if (num < *mid)                    // median is decreased
            mid = (n & 1 ? mid : prev(mid));
        else                                    // median is increased
            mid = (n & 1 ? next(mid) : mid);
    }

    double findMedian() {
        const int n = data.size();
        return (*mid + *next(mid, n % 2 - 1)) * 0.5;
    }
};


class MedianFinder5 {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        // Balance smaller half and larger half.
        if (max_bst_.empty() || num > *max_bst_.cbegin()) {
            min_bst_.emplace(num);
            if (min_bst_.size() > max_bst_.size() + 1) {
                max_bst_.emplace(*min_bst_.cbegin());
                min_bst_.erase(min_bst_.cbegin());
            }
        } else {
            max_bst_.emplace(num);
            if (max_bst_.size() > min_bst_.size()) {
                min_bst_.emplace(*max_bst_.cbegin());
                max_bst_.erase(max_bst_.cbegin());
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return min_bst_.size() == max_bst_.size() ?
                   (*max_bst_.cbegin() + *min_bst_.cbegin()) / 2.0 :
                   *min_bst_.cbegin();

    }

private:
   // min_bst_ stores the larger half seen so far.
    multiset<int, less<int>> min_bst_;
    // max_bst_ stores the smaller half seen so far.
    multiset<int, greater<int>> max_bst_;
};

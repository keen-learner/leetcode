/*

Given a stream of integers and a window size, calculate the moving average 
of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
 

This question MovingAverage defines a class, which can be fixed digital memory, 
and each time we read the next number if this number plus the number of the total 
number is greater than limit, then remove the first to enter the number, and then 
after returning average updated, this feature is best used FIFO queue queue to do,
but we also need a double type variable sum to record the current sum of all the 
numbers, it is a new number to enter, if not exceeded limit the number, the sum 
plus this number is exceeded, then the sum to subtract the first number, 
together with that number, and then return to sum divided by the number of queue:

*/

// Time:  O(1)
// Space: O(w)

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : size_(size), sum_(0) {
    }
    
    double next(int val) {
        if (q_.size() == size_) {
            sum_ -= q_.front();
            q_.pop();
        }
        q_.emplace(val);
        sum_ += val;
        return 1.0 * sum_ / q_.size();
    }

private:
    int size_;
    int sum_;
    queue<int> q_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

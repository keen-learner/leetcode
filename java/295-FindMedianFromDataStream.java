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

*/

/*

class MedianFinder {
    
    // initialize your data structure here.
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        
    }
    
    public double findMedian() {
        
    }
}

*/


class MedianFinder {
    private PriorityQueue<Integer> maxpq; //stores lower half range; has the extra elem
    private PriorityQueue<Integer> minpq; // stores higher half range
    
    /** initialize your data structure here. */
    public MedianFinder() {
        maxpq = new PriorityQueue<Integer>(10, Collections.reverseOrder());
        minpq = new PriorityQueue<Integer>(10);
    }
    
    public void addNum(int num) {
        if(maxpq.isEmpty() || num <= maxpq.peek()) {
            maxpq.offer(num);
            if(maxpq.size() > 1+ minpq.size()) {
                Integer t = maxpq.poll();
                minpq.offer(t);
            }
        }
        else {
            minpq.offer(num);
            if(minpq.size() > maxpq.size()) {
                Integer t = minpq.poll();
                maxpq.offer(t);
            }
        }
    }
    
    public double findMedian() {
        int m = maxpq.size();
        int n = minpq.size();
        if((m+n) % 2 != 0 ) { //odd case
            return 1.0 * maxpq.peek();
        }
        return (maxpq.peek()+minpq.peek())/2.0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

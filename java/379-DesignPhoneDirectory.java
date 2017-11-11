/*

Design a Phone Directory which supports the following operations:

 

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);

*/

/*

using 2 sets used and free: not a good idea, as it doesn't reduce 
the capacity when elements are deleted, so it gets more and more 
sparse and thus takes more and more time to find anything.

*/

class PhoneDirectory {
   boolean[] numbers;
    LinkedList<Integer> available;
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    public PhoneDirectory(int maxNumbers) {
        numbers=new boolean[maxNumbers];
        available = new LinkedList<>();
        for(int i=0; i<maxNumbers; i++)
            available.add(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    public int get() {
        if(available.isEmpty())
            return -1;
        int top =available.poll();
        numbers[top]=true;
        return top;
    }
    
    /** Check if a number is available or not. */
    public boolean check(int number) {
         if(number<0 || number>=numbers.length)
             return false;
        return numbers[number]==false;
    }
    
    /** Recycle or release a number. */
    public void release(int number) {
        if(number<0 || number>=numbers.length||numbers[number]==false)
            return;
        numbers[number]=false;
        available.add(number);
    }
}

class PhoneDirectory{

    Set<Integer> used = new HashSet<Integer>();
    Queue<Integer> available = new LinkedList<Integer>();
    int max;
    public PhoneDirectory(int maxNumbers) {
        max = maxNumbers;
        for (int i = 0; i < maxNumbers; i++) {
            available.offer(i);
        }
    }
    
    public int get() {
        Integer ret = available.poll();
        if (ret == null) {
            return -1;
        }
        used.add(ret);
        return ret;
    }
    
    public boolean check(int number) {
        if (number >= max || number < 0) {
            return false;
        }
        return !used.contains(number);
    }
    
    public void release(int number) {
        if (used.remove(number)) {
            available.offer(number);
        }
    }

}

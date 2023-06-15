# Median-priority-queue
Uses two priority queues to be able to return median at O(1) complexity as new values are appended to the vector.

The heaps are classes based on the vector class and support a few different opperations:
  - insert => insert element into heap
  - extractTop => removes and returns the top element and then heapifies the remaining.
  - getTop => returns the top element
  - isEmpty => returns a boolean depending on whether the heap is empty.
  - size => returns the size of the heap.
And a few more, less relevant operations.

### 2 priority queues:

Assuming vector contains "n" elements, the first priority queue stored as a max-heap, will store the first n/2 elements --we'll call this heap "lower"--, while the second, a min-heap, will store the remaining elements -- we'll call this heap "upper." It is important for every single element in the max-heap to be less than any of the elements in the min-heap. Therefore, a set of rules are followed:

1. If both heaps are empty, the element is by default inserted into the lower queue.
      - this element would be the median

2. If the length of upper is equal to the length of lower:
      - the element is compared to the top of upper. If the element is greater than the top of upper, it is inserted into upper. Otherwise, it is inserted into lower.
      - Now, the priority queue which has the most elements contains the median, which would be the top of that priority queue.

3. If the length of upper > the length of lower:
      - The element is again compared to the top of upper and inserted accordingly.
      - using insert and extractTop, we extractTop from one heap and insert into the other, until the heaps are equal in length or one heap has at most one more element.
      - If the heaps are equal, the top of lower is returned as the median by default
      - Otherwise, the top of whichever heap is bigger becomes the median.
      
4. If the length of upper < the length of lower:
      - The element is again compared to the top of upper and inserted accordingly.
      - using insert and extractTop, we extractTop from one heap and insert into the other, until the heaps are equal in length or one heap has at most one more element.
      - If the heaps are equal, the top of lower is returned as the median by default
      - Otherwise, the top of whichever heap is bigger becomes the median.


easy :D. Also the program is created for a simulated customer service call center, which, for whatever reason, would like to know the median customer wealth each time a customer joins the waiting list.
  

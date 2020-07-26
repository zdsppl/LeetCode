//Problem: https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1337/

//solution1:
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        item_arr_ = new int[k];
        assert(nullptr != item_arr_);
        capacity_ = k;
        size_ = 0;
        head_ = 0;
        //tail_为-1
        tail_ = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        bool ret = true;
        if (isFull()) {
            ret = false;
        } else {
            //tail_指向的是当前有效的尾部
            tail_ = (tail_ + 1) % capacity_;
            item_arr_[tail_] = value;
            size_ += 1;
        }
        return ret;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
       bool ret = true;
       if (isEmpty()) {
           ret = false;
       } else {
           head_ = (head_ + 1) % capacity_;
           size_ -= 1;
       }
        return ret;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        int ret = -1;
        if (!isEmpty()) {
            ret = item_arr_[head_];
        }
        return ret;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        int ret = -1;
        if (!isEmpty()) {
            ret = item_arr_[tail_];
        }
        return ret;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return 0 == size_;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return capacity_ == size_;
    }
    
private:
    int *item_arr_;
    int capacity_;
    int size_;
    int head_;
    int tail_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

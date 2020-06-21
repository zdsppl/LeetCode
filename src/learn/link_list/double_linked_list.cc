//Problem: https://leetcode.com/explore/learn/card/linked-list/210/doubly-linked-list/1294/

//solution
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head_ = nullptr;
        tail_ = nullptr;
        node_count_ = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int val = -1;
        Node *target = nullptr;
        if (index >= 0 && index < node_count_) {
            int i = 0;
            target = head_;
            while (i < index) {
                target = target->next_;
                ++i;
            }
            val = target->val_;
        }
        return val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *new_node = new Node();
        new_node->val_ = val;
        if (nullptr == head_) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            new_node->next_ = head_;
            head_->prev_ = new_node;
            head_ = new_node;
        }
        ++node_count_;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *new_node = new Node();
        new_node->val_ = val;
        if (nullptr == head_) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->next_ = new_node;
            new_node->prev_ = tail_;
            tail_ = new_node;
        }
        ++node_count_;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index >= 0 && index <= node_count_) {
            if (0 == index) {
                addAtHead(val);
            } else if (node_count_ == index) {
                addAtTail(val);
            } else {
                int i = 0;
                Node *target_node = head_;
                Node *prev_node = nullptr;
                Node *new_node = new Node();
                new_node->val_ = val;
                while (i < index) {
                    //prev_node = target_node;
                    target_node = target_node->next_;
                    ++i;
                }
                prev_node = target_node->prev_;
                new_node->next_ = target_node;
                new_node->prev_ = prev_node;
                prev_node->next_ = new_node;
                target_node->prev_ = new_node;   
                ++node_count_;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= 0 && index < node_count_) {
            Node *target_node = head_;
            Node *prev_node = nullptr;
            if (0 == index) {
                target_node = head_;
                head_ = target_node->next_;
                if (nullptr != head_) {
                    head_->prev_ = nullptr;
                }
                delete target_node;
            } else {
                int i = 0;
                while (i < index) {
                    target_node = target_node->next_;
                    ++i;
                }
                prev_node = target_node->prev_;
                if ((node_count_ - 1) == index) {
                    prev_node->next_ = nullptr;
                    tail_ = prev_node;
                    delete target_node;
                } else {
                    prev_node->next_ = target_node->next_;
                    target_node->next_->prev_ = target_node->prev_;
                    delete target_node;
                }
            }
            --node_count_;
        }
        
    }
private:
    struct Node {
        int val_;
        Node *prev_;
        Node *next_;
        
        Node() : val_(0),
                 prev_(nullptr),
                 next_(nullptr)
        {}
    };
    
private:
    Node *head_;
    Node *tail_;
    int node_count_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

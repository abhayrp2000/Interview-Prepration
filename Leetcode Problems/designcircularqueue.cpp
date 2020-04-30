class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int size,curr_size;
    int front,rear;
    int *arr;
    MyCircularQueue(int k) {
        this->size=k;
        front=0;
        rear=k-1;
        arr=new int[k]();
        
        curr_size=0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()){
            rear=(rear+1)%size;
            arr[rear]=value;
            curr_size++;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()){
            front=(front+1)%size;
            curr_size--;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return curr_size==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return curr_size==size;
    }
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
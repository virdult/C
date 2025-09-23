/*Sliding Window Maximum. Given an array of numbers and a window size k, find the maximum of each sliding window.
Use a deque (double-ended queue) for efficiency. Your algorithm should run in O(n) time.
Input: arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Output: [3, 3, 5, 5, 6, 7]*/

/* -> O(n*k) answer. The O(n) is way below.
#include <stdio.h>

#define MAX 8

typedef struct{
    int arr[MAX];
    int front, rear;
}Queue;

void initQueue(Queue* q){
    q->front = q->rear = -1;
}

int isEmpty(Queue* q){return q->front == -1;}
int isFull(Queue* q){return q->rear == MAX -1;}

void enqueue(Queue* q, int val){
    if(isFull(q)) return;
    if(isEmpty(q)){
        q->front = 0;
    }
    q->arr[++(q->rear)] = val;
}

void dequeue(Queue* q){
    if(isEmpty(q)) return;
    printf("Dequeued: %d", q->arr[q->front]);
    if(q->front == q->rear){
        initQueue(q);
    }else{
        q->front = ((q->front)++);
    }
}

void peek(Queue* q){
    if(isEmpty(q)){
        printf("Empty queue!\n");
        return;
    }
    printf("Front element of the queue: %d\n", q->arr[q->front]);
}

int queueSize(Queue* q){
    if(isEmpty(q)) return 0;
    int i = 0;
    int temp = q->front;
    while(1){
        i++;
        if(temp == q->rear) return i;
        temp++;
    }
}

void slidingWindowMaximum(Queue* q, int k){
    int size = queueSize(q);
    if(size < k){
        printf("Queue size is lower than k. Can't check!\n");
        return;
    }
    for(int i = 0; i <= size - k; i++){
        int max = q->arr[i];
        for(int j = 1; j < k; j++){
            if(q->arr[i+j] > max){
                max = q->arr[i+j];
            }
        }
        printf("%d, ", max);
    }
    printf("\n");
}

int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    slidingWindowMaximum(arr, n, k);

    Queue q1;
    initQueue(&q1);

    enqueue(&q1, 1);
    enqueue(&q1, 3);
    enqueue(&q1, -1);
    enqueue(&q1, -3);
    enqueue(&q1, 5);
    enqueue(&q1, 3);
    enqueue(&q1, 6);
    enqueue(&q1, 7);

    slidingWindowMaximum(&q1, 3);
    

    return 0;
}
*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Deque;

void initDeque(Deque* dq){
    dq->front = dq->rear = -1;
}

int isEmpty(Deque* dq){ return dq->front == -1; }

void pushBack(Deque* dq, int val){
    if(isEmpty(dq)){
        dq->front = dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = val;
}

void popBack(Deque* dq){
    if(isEmpty(dq)) return;
    if(dq->front == dq->rear){
        initDeque(dq);
    } else {
        dq->rear--;
    }
}

void popFront(Deque* dq){
    if(isEmpty(dq)) return;
    if(dq->front == dq->rear){
        initDeque(dq);
    } else {
        dq->front++;
    }
}

int front(Deque* dq){ return dq->arr[dq->front]; }
int back(Deque* dq){ return dq->arr[dq->rear]; }

void slidingWindowMaximum(int arr[], int n, int k){
    Deque dq;//Will hold the array's index, not the values inside.
    initDeque(&dq);

    for(int i = 0; i < n; i++){
        // Remove smaller elements from back
        while(!isEmpty(&dq) && arr[back(&dq)] <= arr[i]){
            popBack(&dq);
        }
        pushBack(&dq, i);

        // Remove out-of-window elements
        if(front(&dq) <= i - k){
            popFront(&dq);
        }

        // Window has at least k elements, record max
        if(i >= k - 1){
            printf("%d, ", arr[front(&dq)]);
        }
    }
    printf("\n");
}

int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    slidingWindowMaximum(arr, n, k);

    return 0;
}
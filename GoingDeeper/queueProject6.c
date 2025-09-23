/*Sliding Window Maximum. Given an array of numbers and a window size k, find the maximum of each sliding window.
Use a deque (double-ended queue) for efficiency. Your algorithm should run in O(n) time.
Input: arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Output: [3, 3, 5, 5, 6, 7]*/

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
/* //This is not O(n) but O(n*k)
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
*/
int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    slidingWindowMaximum(arr, n, k);

    /* //O(n*k)'s main part
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
    */

    return 0;
}
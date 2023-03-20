#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct queue {
    int front;
    int rear;
    int size;
    node* items[MAX_QUEUE_SIZE];
} queue;

node* create_node(int value) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

queue* create_queue() {
    queue* new_queue = (queue*) malloc(sizeof(queue));
    new_queue->front = -1;
    new_queue->rear = -1;
    new_queue->size = 0;
    return new_queue;
}

void enqueue(queue* q, node* item) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
    q->size++;
}

node* dequeue(queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue underflow\n");
        return NULL;
    }
    node* dequeued_item = q->items[q->front];
    q->front++;
    q->size--;
    return dequeued_item;
}

int is_empty(queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void bfs(int graph[][10], int num_vertices, int start_vertex) {
    int visited[10] = {0};
    queue* q = create_queue();

    visited[start_vertex] = 1;
    printf("Visited node %d\n", start_vertex);
    enqueue(q, create_node(start_vertex));

    while (!is_empty(q)) {
        node* current_node = dequeue(q);
        int current_vertex = current_node->value;

        for (int i = 0; i < num_vertices; i++) {
            if (graph[current_vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                printf("Visited node %d\n", i);
                enqueue(q, create_node(i));
            }
        }
    }
}

int main() {
    int graph[10][10] = {{0,1,1,0,0,0,0,0,0,0},
                         {1,0,0,1,1,0,0,0,0,0},
                         {1,0,0,0,0,1,1,0,0,0},
                         {0,1,0,0,0,0,0,1,0,0},
                         {0,1,0,0,0,0,0,1,0,0},
                         {0,0,1,0,0,0,0,0,1,1},
                         {0,0,1,0,0,0,0,0,0,0},
                         {0,0,0,1,1,0,0,0,0,0},
                         {0,0,0,0,0,1,0,0,0,0},
                         {0,0,0,0,0,1,0,0,0,0}};

    bfs(graph, 10, 0);

    return 0;
}

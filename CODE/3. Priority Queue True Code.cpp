#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int priority;
  int info;
  struct Node* next;
}Node;

Node* front = NULL;
Node* curr = NULL;

void push(int item,int priority){
  Node* node = (Node*)malloc(sizeof(Node));

  node->info = item;
  node->priority = priority;
  
  if(front == NULL || priority < front->priority){
    node->next = front;
    front = node;
  }else{
    curr = front;
    while(curr->next != NULL && curr->next->priority <= priority){
      curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
  }
}

void pop(){
  curr = front;
  if(front == NULL){
    printf("Queue Underflow\n");
  }else{
    printf("Deleted item is %d\n",curr->info);
    front = front->next;
    free(curr);
  }
}

void display(){
  curr = front;
  if(front == NULL){
    printf("Queue is empty\n");
  }else{  
    printf("Queue is :\n");
    while(curr != NULL){
      printf("%d\t%d\n",curr->priority,curr->info);
      curr = curr->next;
    }
  }
}

int main(){
  push(5,1);
  push(5,2);
  push(7,4);
  push(3,1);
  
  display();
  pop();
  display();

  return 0;
}

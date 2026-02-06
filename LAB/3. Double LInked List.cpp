#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
typedef long long ll;

typedef struct Node{
  struct Node* prev;
  int value;
  struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
Node* curr = NULL;

//make a new node and set the value
Node* createNode(int value){
  Node* node = (Node*) malloc(sizeof(Node));
  
  node->value = value;
  node->next = NULL; //set pointer to NULL for temporary
  node->prev = NULL; //set pointer to NULL for temporary
  
  return node;
}

void pushHead(int value){
  Node* node = createNode(value);
  
  if(head == NULL){ //if the list is empty
    head = tail = node; //set head and tail to the new node
  }
  else{
    //head and node pointing each other
    node->next = head; //set new node pointer to head
    head->prev = node; //set head pointer to new node 
    head = node; //set new node as head
  }
}

void pushTail(int value){
  Node* node = createNode(value);
  
  if(head == NULL){ //if the list is empty
    head = tail = node; //set head and tail to the new node
  }
  else{
    tail->next = node; //set tail pointer to new node
    node->prev = tail; //set new node pointer to tail
    tail = node; //set new node as tail
  }
}

void pushMid(int value){
  if(head == NULL || value <= head->value){ //smaller than equal
    //if the list is empty or new node must be a head
    pushHead(value);
  }else if(value >= tail->value){ //grater than equal
    //if new node must be a tail
    pushTail(value);
  }else{
    curr = head;
    
    while(curr->next && value > curr->next->value){
      //find the best position for the new node
      curr = curr->next;
    }
    
    Node* node = createNode(value); //new node
    node->next = curr->next; //link new node (next) to the next node
    curr->next->prev = node; //link curr (prev) to new node
    //make them pointing each other, but this is only one site
    
    curr->next = node; //link curr (next) to new node
    node->prev = curr; //link new node (prev) to curr
    //make them pointing each other, but this is the other site
  }
}

void popHead(){
  if(head == NULL){ //if the list is empty
    puts("List kosong.");
    return;
  }
  
  Node* temp = head; //save the head for temporary
  head = head->next; //set head to the next node
  head->prev = NULL; //set head prev to NUll, because head->prev should be always NULL
  
  if(head == NULL) tail = NULL; //if the list become empty, set tail to NULL
  free(temp); //free the head to avoid memory leaking
}

void popTail(){
  if(tail == NULL){ //if the list is empty
    puts("List kosong.");
    return;
  }
  
  if(head == tail){ //if there is only 1 node
    free(head); //free the head to avoid memory leaking
    head = tail = NULL; //set head and tail to NULL
    return;
  }
  
  Node* temp = tail;
  tail = tail->prev;
  free(temp); //free the tail to avoid memory leaking
  tail->next = NULL; //update the pointer to NULL (cus this is tail AND ALWAYS POINT TO NULL);
}

void popMid(int value){
  if(head == NULL){ //if the list is empty
    puts("List kosong.");
    return;
  }
  
  if(value == head->value){ //the mid is head
    popHead();
    return;
  }
  
  if(value == tail->value){ //the mid is tail
    popTail();
    return;
  }
  
  curr = head;
  while(curr != NULL && value != curr->value){
    //find the target node
    curr = curr->next;
  }
  
  if(curr == NULL){ //if not found (already checking all nodes)
    puts("Not found!");
    return;
  }
  curr->prev->next = curr->next; //(A.next = C)
    curr->next->prev = curr->prev; //(C.prev = A)
  // make them pointing each other
  /*
  before  ->  target  ->  after
  A         B          C
  */
  
  free(curr); //free the curr to avoid memory leaking
}

void displayHead(){
  puts("Current DLL: \n\n");
  curr = head;
  
  while(curr){
    printf(" %d -> ", curr->value);
    curr = curr->next;
  }
  
  printf("NULL\n");
}

void displayTail(){
  printf ("Current DLL: \n\n");
  curr = tail;
  
  while (curr){
    printf ("%d -> ", curr->value);
    curr = curr->prev;
  }
  
  printf("NULL\n");
}

int main(){
  pushHead(10);
  pushHead(20);
  pushTail(30);
  pushTail(40);
  pushMid(50);
  popHead();
  popTail();
  popMid(30);
  displayHead();
  displayTail();
}

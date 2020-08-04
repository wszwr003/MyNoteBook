#include <stdio.h>
#include <stdlib.h> 

struct node{
  int data;
  struct node* next;
};

void appendToTail(struct node* head,int data){
  struct node* curr = head;
  struct node* nodeNew = (struct node*)malloc(sizeof(struct node));
  nodeNew->data = data;
  nodeNew->next = NULL;
  while(curr->next!=NULL){
    curr = curr->next;
  }
  curr->next = nodeNew;
}
void traverseList(struct node* head){
  struct node* p = head->next;
  while(p != NULL){
    printf("%d\n",p->data);
    p = p->next;
  }
}
void deleteNode(struct node** head,int loc){
  struct node* pre = NULL;
  struct node* curr = *head;
  if(loc == 0){
    *head = curr->next;
    free(curr);
    return;
  }
  for(int i = 0 ;i<loc;i++){
    if(curr->next!=NULL)
    {
      pre = curr;
      curr=curr->next;
    }  
  }
  pre->next=curr->next;
  free(curr);
}
int main(){
  struct node* head=(struct node*)malloc(sizeof(struct node));//FAO:为什么需要分配空间?
  head->data = 0;
  head->next = NULL;
  appendToTail(head,1);
  appendToTail(head,2);
  appendToTail(head,3);
  appendToTail(head,4);
  deleteNode(&head,2);
  traverseList(head);
}
// int main(){
//     printf("%d\n",1);
//     printf("%d\n",2);
//     printf("%d\n",3);
//     printf("%d\n",4);
//     printf("%d\n",5);
//     printf("%d\n",6);
//     printf("%d\n",7);
//     printf("%s\n","123");

// }
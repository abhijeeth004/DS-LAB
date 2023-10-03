#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void TraverseLinkedList(){
    struct Node *ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insertAtstart(int n){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = n;
    p->next = head;
    head = p;
    return;
}

void insertAtIndex(int n,int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = n;
    int i=0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return;
}

void inserAtEnd(int n){
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data = n;
        struct Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }
        ptr->next = NULL;
        p->next = ptr;
        return head;
}

void DeleteAtstart(){
    struct Node *p = head;
    head = head->next;
    free(p);
    return;

}

void DeleteAtEnd(){
    struct Node *ptr = head;
    struct Node *p = head->next;
    while(p->next != NULL){
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(p);

}

void DeleteElement(int n){
    struct Node *ptr = head;
    struct Node *p = head->next;
    while (p->data != n){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);

}

void sorting(){
    struct Node *p = head;
    struct Node *q = head->next;
    while(p->next != NULL){
        if(p->data > q->data){
            int temp = p->data;
            p->data = q->data;
            q->data = temp;
        }
        else if ((p->data < q->data) && q->next != NULL){
            q = q->next;
        }
        else{
            p = p->next;
            q = p;
            q = q->next;
        }
    }

}

int main(){

    TraverseLinkedList();
    insertAtstart(91);
    insertAtIndex(20,1);
    inserAtEnd(17);
    sorting();
    DeleteElement(20);
    TraverseLinkedList();

}


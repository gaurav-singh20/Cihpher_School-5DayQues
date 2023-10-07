#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  Node(int value){
    data=value;
    prev = NULL;
    next = NULL;
  }
};

void insert(Node* &head, int val){
  Node* n = new Node(val);
  Node* temp = head;

  if(head==NULL){
    head = n;
    return;
  }

  while(temp->next != NULL){
    temp=temp->next;
  }

  temp->next=n;
  n->prev=temp;
}

void display(Node* &head){
  Node* temp= head;
  while(temp != NULL){
    cout << temp->data << "->";
    temp=temp->next;
  }
}

  void displaySum(Node* &head){
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp2->next!=NULL){
      temp2=temp2->next;
    }

    int max=0;
    while(temp2->next!=temp1){
      int sum = temp1->data + temp2->data;
      if(sum>max){
        max=sum;
      }
      temp1=temp1->next;
      temp2=temp2->prev;
    }
    cout << max;
  }

int main(){
  Node* head = NULL;
  int n,m;
  cin >> n;
  if(n%2!=0){
    cout << "Entered size of Linked List should be even :)";
  }
  else{
    cout << "Enter numbers: " << endl ;
    for(int i=0;i<n;i++){
      cin >> m;
      insert(head,m);
    }
    
    cout << endl << "greatest sum : " ;
    displaySum(head);
  }
}
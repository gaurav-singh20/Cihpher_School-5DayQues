#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int val){
    data=val;
    next=NULL;
  }
};

void insert(Node* &head, int val){
  Node* n = new Node(val);
  Node* temp=head;
  if(head==NULL){
    head=n;
    return;
  }
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=n;
}

void indices(Node* &head){
  Node* odd = head;
  Node* even = head;
  Node* even2 = head;
  even2=even2->next;
  even=even->next;

  //tried this manually for 7 nodes to find the logic-
  
  // odd->next=even->next;
  // odd=odd->next;
  // even->next=odd->next;
  // even=even->next;  
  // odd->next=even->next;
  // odd=odd->next;
  // even->next=odd->next;
  // even=even->next;
  // odd->next=even->next;
  // odd=odd->next;
  // even->next=NULL;
  // odd->next=even2;


  while(even != NULL && even->next != NULL){
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }

  odd->next = even2;
}

void display(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
  Node* head = NULL;
  int n,m;
  cin >> n;
  cout << "Enter numbers: " << endl ;
  for(int i=0;i<n;i++){
    cin >> m;
    insert(head,m);
  }
  indices(head);
  display(head);
}
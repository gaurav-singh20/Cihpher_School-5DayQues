#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insert(Node* &head, int val){

    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void shiftRight(Node* &head,int key){
  if(head->next==NULL){
    return;
  }

  for(int i=0;i<key;i++){
    Node* tail=head;
    //Node* temp=head;
    while(tail->next->next!=NULL){
      tail=tail->next;
    }
    tail->next->next=head;
    head=head=tail->next;
    tail->next=NULL;
  }
}

int main(){
    Node *head = NULL;
    int n,m,k;
    cin >> n;
    cout << "Enter numbers: " << endl ;
    for(int i=0;i<n;i++){
      cin >> m;
      insert(head,m);
    }
    cout<< "Enter the key: ";
    cin >> k;
    shiftRight(head,k);
    display(head);
}
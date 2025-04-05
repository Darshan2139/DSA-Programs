#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node* link;
};
node* head = NULL;

void insert(int n){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = n;
    temp->link = NULL;
    node* trav = head;
    if(trav==NULL){
        head = temp;
    }else{
        while(trav->link!=NULL){
            trav = trav->link;
        }
        trav->link = temp;
    }
}

node* reverse(node* ptr){
    node* prev = NULL;
    node* curr = ptr->link;
    node* next = NULL;
    
    while(curr!=NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
       curr = next;
        
    }
    return prev;
}

bool isPallindrome(){

    if (head == NULL || head->link == NULL) {
        return true;
    }
    node* slow = head;
    node* fast = head;
    
    while(fast!=NULL && fast->link!=NULL){
        slow = slow->link;
        fast = fast->link->link;
    }
    
    node* half = reverse(slow);

    node* trav = head;
    while(half!=NULL){
        if(trav->data != half->data){
            return false;
        }else{
            trav = trav->link;
            half = half->link;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        int n2;
        cin >> n2;
        insert(n2);
    }
    bool ans = isPallindrome();
    if(ans==1){
        cout << "True";
    }else{
        cout << "False";
    }
    return 0;
}
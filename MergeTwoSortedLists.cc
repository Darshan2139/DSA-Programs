#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *link;
}*first1,*first2,*first3;
struct node* create_node(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}
void insert_front(int n)
{
    struct node *temp = create_node(n);
    if(first2==NULL)
    {
        first2 = temp;
    }
    else
    {
        temp->link = first2;
        first2 = temp;
    }    
}

void insert_last_first1(int n)
{
    if(first1==NULL)
    {
        first1 = create_node(n);
    }
    else
    {
        struct node *New = create_node(n);
        struct node *temp;
        temp = first1;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = New;
    }
}
void insert_last_first2(int n)
{
    if(first2==NULL)
    {
        first2 = create_node(n);
    }
    else
    {
        struct node *New = create_node(n);
        struct node *temp;
        temp = first2;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = New;
    }
}
void display_linkedlist_data(struct node* head)
{
    
    struct node *trav = head;
    while(trav!=NULL)
    {
        cout<<trav->data<<" ";
        trav = trav->link;
    }
}
struct node* mergeList()
{
    if(first1 == NULL)
    {
        return first2;
    }
    
    if(first2 == NULL)
    return first1;

    struct node *ptr = first1;
    if(first1->data>first2->data)
    {
        ptr = first2;
        first2 = first2->link;
    }
    else
    {
        first1 = first1->link;
    }
    struct node *cur = ptr;
    while(first1!=NULL && first2!=NULL)
    {
        if(first1->data<first2->data)
        {
            cur->link = first1;
            first1 = first1->link;
        }
        else
        {
            cur->link = first2;
            first2 = first2->link;
        }
        cur = cur->link;
    }
    if(first1!=NULL)
    {
        cur->link = first2;
    }
    else
    {
        cur->link = first1;
    }
    return ptr;
}
int main()
{
    int N1,N2,data;
    cin>>N1;
    for(int i=0;i<N1;i++)
    {
        cin>>data;
        insert_last_first1(data);
    }
    cin>>N2;
    for(int i=0;i<N2;i++)
    {
        cin>>data;
        insert_last_first2(data);
    }
    struct node *ptr = mergeList();
    first3 = ptr;
    display_linkedlist_data(first3);
    return 0;
}
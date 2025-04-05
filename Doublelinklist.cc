#include <iostream>
using namespace std;
void menu();
struct node
{
    int data;
    node *lptr;
    node *rptr;
};
struct node *head;

void insert_front(int digit)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = digit;
    temp->rptr == NULL;
    if (head == NULL)
    {
        temp->lptr = NULL;
    }
    else
    {
        temp->lptr = head;
        head->rptr = temp;
    }
    head = temp;
}
void insert_last(int digit)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = digit;
    temp->lptr = NULL;
    if (head == NULL)
    {
        temp->rptr == NULL;
        head = temp;
    }
    else
    {
        struct node *temp1;
        temp1 = head;
        while (temp1->lptr != NULL)
        {
            temp1 = temp1->lptr;
        }
        temp->rptr = temp1;
        temp1->lptr = temp;
    }
}
void delete_front()
{
    struct node *temp = head;
    head = head->lptr;
    head->rptr = NULL;
    free(temp);
}
void delete_last()
{
    struct node *temp = head;
    while (temp->lptr->lptr != NULL)
    {
        temp = temp->lptr;
    }
    temp->lptr = NULL;
    free(temp->lptr);
}
void delete_all()
{
    head = NULL;
}
void insert_data(int pdata, int digit)
{

    node *temp = new node();
    node *temp1 = new node();
    temp1 = head;
    temp->data = digit;
    while (temp1->data != pdata)
    {
        temp1 = temp1->lptr;
    }
    if (temp == NULL || temp->lptr == NULL)
    {
        cout << "Position is out of bounds" << endl;
        return;
    }
    temp->lptr = temp1->lptr;
    temp1->lptr = temp;
    temp->rptr = temp1;
    temp->lptr->rptr = temp;
}
void insert_position(int position, int digit)
{

    node *trav = new node();
    trav->data = digit;

    if (position == 1)
    {
        trav->lptr = head;
        trav->rptr = NULL;
        if (head != NULL)
        {
            (head)->rptr = trav;
        }
        head = trav;
        return;
    }

    node *temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->lptr;
    }

    if (temp == NULL || temp->lptr == NULL)
    {
        cout << "Position is out of bounds" << endl;
        return;
    }

    trav->lptr = temp->lptr;
    trav->rptr = temp;
    if (temp->lptr != nullptr)
    {
        temp->lptr->rptr = trav;
    }
    temp->lptr = trav;
}
void delet_nth_node(int position)
{
    node *temp = new node();
    temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->lptr;
    }
    temp->rptr->lptr = temp->lptr;
    temp->lptr->rptr = temp->rptr->lptr;
    free(temp);
}
void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->lptr;
    }
    cout << endl;
    cout<<"23CE051_Darshan Kachhiya";
}
void reversdisplay()
{
    struct node *temp1;
    temp1 = head;
    while (temp1->lptr != NULL)
    {
        temp1 = temp1->lptr;
    }
    struct node *temp;
    temp = temp1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->rptr;
    }
}

int main()
{
    int n;
    do
    {
        menu();

        cin >> n;
        switch (n)
        {
        case 1:
            int digit;
            cout << "Enter a digit :";
            cin >> digit;
            insert_front(digit);
            break;
        case 2:
            cout << "Enter a digit:";
            cin >> digit;
            insert_last(digit);

            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            cout << "Delete all nodes" << endl;
            delete_all();
            break;
        case 6:
            display();
            cout << endl;
            break;
        case 7:
            cout << "Rever link list :";
            reversdisplay();
            cout << endl;
            break;
        case 8:
            int d;
            int p;

            cout << "Digit :";
            cin >> d;
            cout << "Position:";
            cin >> p;
            insert_position(p, d);
            break;

        case 9:

            int di;
            int data;

            cout << "Digit :";
            cin >> di;
            cout << "Prev  data :";
            cin >> data;
            insert_data(data, di);
            break;
        case 10:
            int ps;
            cout << "Enter a ps :";
            cin >> ps;
            delet_nth_node(ps);

            break;
        case 11:
            exit(0);
        }
        
    } while (1 <= n && 11 >= n);
    return 0;
}
void menu()
{
    cout << "01. Insert at front" << endl;
    cout << "02. Insert at right" << endl;
    cout << "03. Delete from front" << endl;
    cout << "04. Delete from last" << endl;
    cout << "05. Delete all nodes" << endl;
    cout << "06. Display link list" << endl;
    cout << "07. Display  revers link list" << endl;
    cout << "08. Insert a data with position " << endl;
    cout << "09. Insert a after data  :" << endl;
    cout << "10. Delet a specific node :" << endl;
    cout << "11. Exit" << endl;
}
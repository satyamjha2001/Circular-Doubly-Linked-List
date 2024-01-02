#include <iostream>
using namespace std;
class node
{
public:
    node *prev;
    int item;
    node *next;
    node(int item)
    {
        prev = NULL;
        this->item = item;
        next = NULL;
    }
};
class CDLL
{
private:
    node *start;

public:
    CDLL();
    void insertAtStart(int);
    void insertAtLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    void print();
    ~CDLL();
};
CDLL::CDLL()
{
    start = NULL;
}
void CDLL::insertAtStart(int data)
{
    node *n = new node(data);
    if (start == NULL)
    {
        n->prev = n;
        n->next = n;
        start = n;
    }
    else
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
        start = n;
    }
}
void CDLL::insertAtLast(int data)
{
    node *n = new node(data);
    if (start == NULL)
    {
        n->prev = n;
        n->next = n;
        start = n;
    }
    else
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
    }
}
node *CDLL::search(int data)
{
    if (start)
    {
        node *temp = start;
        do
        {
            if (temp->item == data)
                return temp;
            temp = temp->next;
        } while (temp != start);
    }
    return NULL;
}
void CDLL::insertAfter(node *temp, int data)
{
    if (temp)
    {
        node *n = new node(data);
        n->prev = temp;
        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
    }
}
void CDLL::deleteFirst()
{
    if (start)
    {
        if (start == start->next)
        {
            delete start;
            start = NULL;
        }
        else
        {
            node *temp = start;
            start->prev->next = start->next;
            start->next->prev = start->prev;
            start = start->next;
            delete temp;
        }
    }
}
void CDLL::deleteLast()
{
    if (start)
    {
        if (start == start->next)
        {
            delete start;
            start = NULL;
        }
        else
        {
            node *temp = start->prev;
            temp->prev->next = start;
            start->prev = temp->prev;
            delete temp;
        }
    }
}
void CDLL::deleteNode(int data)
{
    if (start->item == data)
    {
        deleteFirst();
    }
    else
    {
        node *temp = start->next;
        while (temp != start)
        {
            if (temp->item == data)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                break;
            }
            temp = temp->next;
        }
    }
}
void CDLL::print()
{
    node *temp = start;
    if (start)
    {
        do
        {
            cout << temp->item << " ";
            temp = temp->next;
        } while (temp != start);
    }
}
CDLL::~CDLL()
{
    while (start)
        deleteFirst();
}
int main()
{
    CDLL c1;
    c1.insertAtStart(10);
    c1.insertAtStart(11);
    c1.insertAtLast(9);
    c1.insertAtLast(15);
    c1.deleteFirst();
    c1.deleteNode(10);
    c1.print();
    return 0;
}
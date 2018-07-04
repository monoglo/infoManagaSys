#include "include/declaration.h"
int Node::sum = 0;
Node::Node()
{
    cout << "Please input node name:" << endl;
    cin >> name;
    prev = NULL;
    next = NULL;
    sum++;
}
Node::Node(string n)
{
    name = n;
    prev = NULL;
    next = NULL;
    sum++;
}
Node::~Node()
{
    sum--;
}
List::List(){
    head = NULL;
    tail = NULL;
    ptr = NULL;
}
int List::CList()
{
    cout << "Now build the head,";
    head = new Node;
    ptr = head;
    tail = head;
    if (head)
        return 1;
    else
        return 0;
}
Node *List::GetHead()
{ //Get head pointer
    return head;
}
Node *List::GetTail()
{
    return tail;
}
int List::InserBefore()
{ //Insert node before ptr
    if (ptr->prev == NULL)
    {
        ptr->prev = new Node;
        ptr->prev->next = ptr;
        this->head = ptr->prev;
    }
    else
    {
        ptr->prev->next = new Node;
        ptr->prev->next->next = ptr;
        ptr->prev->next->prev = ptr->prev;
        ptr->prev = ptr->prev->next;
    }
    ptr = ptr->prev;
    return 1;
}
int List::InserAfter()
{ //Insert node after ptr
    if (ptr->next == NULL)
    {
        ptr->next = new Node;
        ptr->next->prev = ptr;
        this->tail = ptr->next;
    }
    else
    {
        ptr->next->prev = new Node;
        ptr->next->prev->prev = ptr;
        ptr->next->prev->next = ptr->next;
        ptr->next = ptr->next->prev;
    }
    ptr = ptr->next;
    return 1;
}
int List::RemoveHead()
{
    if (head == NULL)
    {
        return 0;
    }
    else if (head->next == NULL)
    {
        RemoveAll();
        return 1;
    }
    else
    {
        ptr = head;
        head = head->next;
        ptr->next = NULL;
        head->prev = NULL;
        delete ptr;
        return 1;
    }
}
int List::RemoveTail()
{
    if (tail == NULL)
    {
        return 0;
    }
    else if (tail->prev == NULL)
    {
        RemoveAll();
        return 1;
    }
    else
    {
        ptr = tail;
        tail = tail->prev;
        ptr->prev = NULL;
        tail->next = NULL;
        delete ptr;
        return 1;
    }
}
int List::AddHead()
{
    ptr = head;
    ptr->prev = new Node;
    ptr->prev->next = head;
    head = ptr->prev;
    return 1;
}
int List::AddHead(string n)
{
    ptr = head;
    ptr->prev = new Node(n);
    ptr->prev->next = head;
    head = ptr->prev;
    return 1;
}
int List::AddTail()
{
    ptr = tail;
    ptr->next = new Node;
    ptr->next->prev = tail;
    tail = ptr->next;
    return 1;
}
int List::AddTail(string n)
{
    ptr = tail;
    ptr->next = new Node(n);
    ptr->next->prev = tail;
    tail = ptr->next;
    return 1;
}
int List::RemoveAll()
{
    if (head == NULL)
    {
        return 0;
    }
    while (head != NULL)
    {
        ptr = head->next;
        delete head;
        head = ptr;
    }
    tail = NULL;
    ptr = NULL;
    return 1;
}
int List::GetCoutnt()
{
    if (head)
        return this->head->sum;
    else
    {
        return 0;
    }
}
int List::IsEmpty()
{
    if (head==NULL)
        return 1;
    else
        return 0;
}
Node *List::GetNext(int n)
{
    int i;
    ptr = head;
    for (i = 1; i < n; i++)
    {
        ptr = ptr->next;
    }
    return ptr->next;
}
Node *List::GetPrev(int n)
{
    int i;
    ptr = head;
    for (i = 1; i < n; i++)
    {
        ptr = ptr->next;
    }
    return ptr->prev;
}
string List::GetAt(int n)
{
    int i;
    ptr = head;
    for (i = 1; i < n; i++)
    {
        if (ptr->next == NULL)
            return "Not found!";
        ptr = ptr->next;
    }
    return ptr->name;
}
int List::SetAt(int n)
{
    int i;
    ptr = head;
    for (i = 1; i < n; i++)
    {
        ptr = ptr->next;
    }
    cout << "Pleae input set name:" << endl;
    cin >> ptr->name;
    return 1;
}
int List::RemoveNode(){
    if (ptr == head)
        RemoveHead();
    else if (ptr == tail)
        RemoveTail();
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    return 1;
}
int List::RemoveNode(Node *n){
    if (n == head)
        RemoveHead();
    else if (n == tail)
        RemoveTail();
    else
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
    }
    return 1;
}
int List::RemoveAt(int n)
{
    int i;
    ptr = head;
    for (i = 1; i < n; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == head)
        RemoveHead();
    else if (ptr == tail)
        RemoveTail();
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    return 1;
}
Node *List::Find(string st)
{
    ptr = head;
    while (ptr->name != st)
    {
        if (ptr->next == NULL)
        {
            return NULL;
        }
        ptr = ptr->next;
    }
    return ptr;
}
Node *List::FindIndex(int n)
{
    int i;
    ptr = head;
    for (i = 1; i < n; i++)
    {
        ptr = ptr->next;
    }
    return ptr;
}
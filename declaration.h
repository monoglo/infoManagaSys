#include <iostream>
using namespace std;
class Node
{
public:
  static int sum;
  string name;
  Node *prev;
  Node *next;
  Node();
  ~Node();
};
class List
{
public:
  Node *head;
  Node *tail;
  Node *ptr;
  List();
  int CList();
  Node *GetHead();
  Node *GetTail();
  int InserBefore();
  int InserAfter();
  int RemoveHead();
  int RemoveTail();
  int AddHead();
  int AddTail();
  int RemoveAll();
  int GetCoutnt();
  int IsEmpty();
  Node *GetNext(int n);
  Node *GetPrev(int n);
  string GetAt(int n);
  int SetAt(int n);
  int RemoveAt(int n);
  int RemoveNode();
  Node *Find(string st);
  Node *FindIndex(int n);
};
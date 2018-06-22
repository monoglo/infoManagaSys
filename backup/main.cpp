//main.cpp
#include<iostream>
using namespace std;
class Node{
public:
  static int sum;
  string name;
  Node *prev;
  Node *next;
  Node()
  {
      cout << "Please input name:" << endl;
      cin >> name;
      prev = NULL;
      next = NULL;
      sum++;
    }
    ~Node(){
        sum--;
    }
};
class List{
public:
    Node *head;
    Node *tail;
    Node *ptr;                                          //For locate the position
    void CList(){                                       //Create new empty list
        head = new Node;
        ptr = head;
        tail = head;
    }
    Node* GetHead(){                                    //Get head pointer
        return this->head;
    }
    Node* GetTail(){                                    //Get tail pointer
        return this->tail;
    }
    int InserBefore(){                                  //Insert node before ptr
        if(ptr->prev==NULL){
            ptr->prev = new Node;
            ptr->prev->next = ptr;
            this->head = ptr->prev;
        }else{
        ptr->prev->next = new Node;
        ptr->prev->next->next = ptr;
        ptr->prev->next->prev = ptr->prev;
        ptr->prev = ptr->prev->next;
        }
        
        return 1;
    }
    int InserAfter(){                                   //Insert node after ptr
        if(ptr->next==NULL){
            ptr->next = new Node;
            ptr->next->prev = ptr;
            this->tail = ptr->next;
        }else{
        ptr->next->prev = new Node;
        ptr->next->prev->prev = ptr;
        ptr->next->prev->next = ptr->next;
        ptr->next = ptr->next->prev;
        }
        return 1;
    }
};
int Node::sum = 0;
int main(){
    Node *s;
    int a;
    List ls;
    ls.CList();
    ls.InserBefore();
    ls.InserAfter();
    s=ls.GetTail();
    cout << s->name << endl;
    s=ls.GetHead();
    cout << s->name << endl;
    a = ls.head->sum;
    cout << a << endl;
    _sleep(10000);
    return 1;
}
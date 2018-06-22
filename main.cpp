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
        return head;
    }
    Node* GetTail(){                                    //Get tail pointer
        return tail;
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
    int RemoveHead(){
        if(head==NULL){
            return 0;
        }else if(head->next==NULL){
            RemoveAll();
            return 1;
        }else{
        ptr = head;
        head = head->next;
        ptr->next = NULL;
        head->prev = NULL;
        delete ptr;
        return 1;
        }
    }
    int RemoveTail(){
        if(tail==NULL){
            return 0;
        }else if(tail->prev==NULL){
            RemoveAll();
            return 1;
        }else{
        ptr = tail;
        tail = tail->prev;
        ptr->prev = NULL;
        tail->next = NULL;
        delete ptr;
        return 1;
        }
    }
    int AddHead(){
        ptr = head;
        ptr->prev = new Node;
        ptr->prev->next = head;
        head = ptr->prev;
        return 1;
    }
    int AddTail(){
        ptr = tail;
        ptr->next = new Node;
        ptr->next->prev = tail;
        tail = ptr->next;
        return 1;
    }
    int RemoveAll(){
        if(head==NULL){
            return 0;
        }
        while(head != NULL)  
        {  
            ptr=head->next;  
            delete head;  
            head=ptr;
        }
        tail = NULL;
        ptr = NULL;
        return 1;
    }
    int GetCoutnt(){
        if (head)
            return this->head->sum;
        else
        {
            return 0;
        }
        
    }
    int IsEmpty(){
        if(head)
            return 1;
            
            else
                return 0;
    }
};
int Node::sum = 0;
int main(){
    Node *s;
    List ls;
    ls.CList();
    ls.InserBefore();
    ls.InserAfter();
    ls.AddHead();
    ls.AddTail();
    s=ls.GetHead();
    cout << s->name << endl;
    s=ls.GetTail();
    cout << s->name << endl;
    cout << ls.GetCoutnt() << endl;
    cout << ls.IsEmpty() << endl;
    ls.RemoveAll();
    cout << ls.GetCoutnt() << endl;
    cout << ls.IsEmpty() << endl;
    _sleep(10000);
    return 1;
}
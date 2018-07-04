#include "include/set.h"
#include <string>
List Set::operator+(Set ls)
{
    Node *ptr1, *ptr2;
    ptr1 = this->head;
    ptr2 = ls.head;
    do
    {
        do
        {
            if (ptr1->name == ptr2->name)
                break;
            if (ptr1->next == NULL && ptr1->name != ptr2->name)
                this->AddTail(ptr2->name);
            ptr1 = ptr1->next;
        } while (ptr1 != NULL);
        ptr2 = ptr2->next;
    } while (ptr2 != NULL);
    return *this;
}
List Set::operator-(Set ls)
{
    Node *ptr1, *ptr2;
    ptr1 = this->head;
    ptr2 = ls.head;
    do
    {
        do
        {
            if (ptr1->name == ptr2->name)
                ptr1->name = "0";
            if (ptr1->next == NULL && ptr1->name != ptr2->name)
                break;
            ptr1 = ptr1->next;
        } while (ptr1 != NULL);
        ptr2 = ptr2->next;
    } while (ptr2 != NULL);
    return *this;
}
List Set::operator and(Set ls)
{
    Node *ptr1, *ptr2;
    ptr1 = this->head;
    ptr2 = ls.head;
    do
    {
        ptr2 = ls.head;
        do
        {
            if (ptr1->name == ptr2->name)
                break;
            if (ptr2->next == NULL && ptr1->name != ptr2->name)
            {
                ptr1->name = "0";
                break;
            }
            ptr2 = ptr2->next;
        } while (ptr2 != NULL);
        ptr1 = ptr1->next;
    } while (ptr1 != NULL);
    return *this;
}

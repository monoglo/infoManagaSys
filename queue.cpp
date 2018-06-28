#include "include/queue.h"
int Queue::CQueue()
{
    return CList();
}
int Queue::Qadd()
{
    return AddTail();
}
int Queue::Qde()
{
    return RemoveHead();
}
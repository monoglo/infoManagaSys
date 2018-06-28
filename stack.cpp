#include "include/stack.h"
int Stack::CStack()
{
    return CList();
}
int Stack::Spush()
{
    return AddTail();
}
int Stack::Spop()
{
    return RemoveTail();
}
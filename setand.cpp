#include "define.cpp"
#include "set.cpp"
void listallll(List &ls)
{
    int a;
    ls.ptr = ls.head;
    for (a = 1; ls.ptr != NULL; ls.ptr = ls.ptr->next)
    {
        if (ls.ptr->name != "0")
        {
            a++;
        }
    }
    cout << "There are " << a - 1 << " nodes in the list:" << endl;
    ls.ptr = ls.head;
    for (a = 1; ls.ptr != NULL; ls.ptr = ls.ptr->next)
    {

        if (ls.ptr->name != "0")
        {
            cout << "Subscript: " << a << '\t' << "Name: " << ls.ptr->name << endl;
            a++;
        }
    }
}
int main()
{
    int i;
    Set s1, s2, s3;
    s1.CList();
    s1.AddTail();
    s1.AddTail();
    s1.AddTail();
    s2.CList();
    s2.AddTail();
    s2.AddTail();
    s2.AddTail();
    s1 and s2;
    listallll(s1);
    cout << "Finished!" << endl;
    cin >> i;
    return 0;
}
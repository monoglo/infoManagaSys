#include "define.cpp"
#include "set.cpp"
void listalll(List &ls)
{
    int a;
    ls.ptr = ls.head;
    for (a = 1; ls.ptr != NULL; ls.ptr = ls.ptr->next)
    {
        a++;
    }
    cout << "There are " << a - 1 << " nodes in the list:" << endl;
    ls.ptr = ls.head;
    for (a = 1; ls.ptr != NULL; ls.ptr = ls.ptr->next)
    {
        cout << "Subscript: " << a << '\t' << "Name: " << ls.ptr->name << endl;
        a++;
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
    s1 + s2;
    listalll(s1);
    cout << "Finished!" << endl;
    cin >> i;
    return 0;
}
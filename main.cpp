#include"define.cpp"
int main()
{
    List ls;
    ls.CList();
    ls.InserAfter();
    ls.InserAfter();
    ls.InserAfter();
    ls.InserAfter();
    cout << ls.GetAt(3) << endl;
    _sleep(10000);
    return 1;
}
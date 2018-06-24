#include "define.cpp"
void find(List &ls)
{
    int cho;
    int ss;
    char yn;
    string str;
    yn = 'y';
    while (yn == 'y')
    {
        cout << "Please input the find way:" << endl;
        cout << "1. Subscript" << endl;
        cout << "2. Name" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            cout << "Please input the subscript:" << endl;
            cin >> ss;
            cout << "The result is:" << ls.GetAt(ss) << endl;
            break;
        case 2:
            cout << "Please input the name:" << endl;
            cin >> str;
            cout << "The result is:";
            if (ls.Find(str))
                cout << ls.Find(str)->name << endl;
            else
                cout << "Not Found." << endl;
            break;
        }
        cout << "Find another?(y/n)" << endl;
        cin >> yn;
    }
}
int main()
{
    int cho;
    int ss;
    char yn = 'y';
    List ls;
    string str;
    while (1)
    {
        cout << "Please input your choice:" << endl;
        cout << "1. New a List" << endl;
        cout << "2. Insert a Node" << endl;
        cout << "3. Find a Node" << endl;
        cout << "4. List all" << endl;
        cout << "0. Exit" << endl;

        cin >> cho;
        switch (cho)
        {
        case 1:
            if (ls.CList())
                cout << "Build succeed." << endl;
            break;
        case 2:
            cout << "Please input the insert way:" << endl;
            cout << "1. Before" << endl;
            cout << "2. After" << endl;
            cout << "3. Head" << endl;
            cout << "4. Tail" << endl;
            break;
        case 3:
            find(ls);
            break;
        case 0:
            break;
        default:
            cout << "Illegal,please input again." << endl;
            break;
        }
        if (cho == 0)
            break;
    }
    return 1;
}
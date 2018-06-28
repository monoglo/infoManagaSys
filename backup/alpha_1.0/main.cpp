#include "define.cpp"
int find(List &ls)
{
    int a;
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
            if (ls.GetAt(ss) == "Not found!")
                a = 0;
            else
                a = 1;
            break;
        case 2:
            cout << "Please input the name:";
            cin >> str;
            cout << "The result is:";
            if (ls.Find(str))
            {
                cout << ls.Find(str)->name;
                a = 1;
            }
            else
            {
                cout << "Not Found.";
                a = 0;
            }
            break;
        default:
            cout << "Illegal input!";
            a = 0;
            break;
        }
        cin.clear();
        cin.sync();
        cout << ",find another?(y/n)" << endl;
        cin >> yn;
    }
    return a;
}
void insert(List &ls)
{
    int cho;
    cout << "Please input the location to insert:" << endl;
    cout << "1. Find" << endl;
    cout << "2. Head" << endl;
    cout << "3. Tail" << endl;
    cin >> cho;
    switch (cho)
    {
    case 1:
        if (find(ls))
        {
            cout << "Please input the insert way:" << endl;
            cout << "1. Before" << endl;
            cout << "2. After" << endl;
            cin.clear();
            cin.sync();
            cin >> cho;
            switch (cho)
            {
            case 1:
                ls.InserBefore();
                break;
            case 2:
                ls.InserAfter();
                break;
            default:
                cout << "Illegal input!";
                break;
            }
        }
        break;
    case 2:
        ls.AddHead();
        break;
    case 3:
        ls.AddTail();
        break;
    default:
        cout << "Illegal input!";
        break;
    }
}
void deletenode(List &ls)
{
    int cho;
    cout << "Please input the location to delete:" << endl;
    cout << "1. Find" << endl;
    cout << "2. Head" << endl;
    cout << "3. Tail" << endl;
    cin >> cho;
    switch (cho)
    {
    case 1:
        if (find(ls))
        {
            ls.RemoveNode();
        }
        break;
    case 2:
        ls.RemoveHead();
        break;
    case 3:
        ls.RemoveTail();
        break;
    default:
        cout << "Illegal input!";
        break;
    }
}
void deleteall(List &ls)
{
    ls.RemoveAll();
    cout << "Delete sucessuful!" << endl;
}
void setnode(List &ls)
{
    int ss;
    cout << "Please input the subscript:";
    cin >> ss;
    ls.SetAt(ss);
}
void listall(List &ls)
{
    int a;
    cout << "There are " << ls.GetCoutnt() << " nodes in the list:" << endl;
    ls.ptr = ls.head;
    for (a = 1; ls.ptr != NULL; ls.ptr = ls.ptr->next)
    {
        cout << "Subscript: " << a << '\t' << "Name: " << ls.ptr->name << endl;
        a++;
    }
}
int main()
{
    int cho;
    //int ss;
    char yn = 'y';
    List ls;
    string str;
    while (1)
    {
        cout << "Please input your choice:" << endl;
        cout << "1. New a List" << endl;
        cout << "2. Delete List" << endl;
        cout << "3. Insert a Node" << endl;
        cout << "4. Delete a Node" << endl;
        cout << "5. Find a Node" << endl;
        cout << "6. Set a Node" << endl;
        cout << "7. List all" << endl;
        cout << "0. Exit" << endl;
        cin.clear();
        cin.sync();
        cin >> cho;
        switch (cho)
        {
        case 1:
            if (ls.IsEmpty() == 0)
            {
                system("cls");
                cout << "Had existed a List, delete first!" << endl;
            }
            else
            {
                system("cls");
                if (ls.CList())
                {
                    system("cls");
                    cout << "Build succeed." << endl;
                }
            }
            break;
        case 2:
            if (ls.IsEmpty() == 0)
            {
                system("cls");
                deleteall(ls);
            }
            break;
        case 3:
            if (ls.IsEmpty() == 0)
            {
                system("cls");
                insert(ls);
            }
            break;
        case 4:
            if (ls.IsEmpty() == 0)
            {
                system("cls");
                deletenode(ls);
            }
            break;
        case 5:
            if (ls.IsEmpty() == 0)
            {
                system("cls");
                find(ls);
            }
            break;
        case 6:
            if (ls.IsEmpty() == 0)
            {
                system("cls");
                setnode(ls);
            }
            break;
        case 7:
            if (ls.IsEmpty() == 1)
            {
                system("cls");
                cout << "Empty!" << endl;
            }
            else
            {
                system("cls");
                listall(ls);
            }
            break;
        case 0:
            break;
        default:
            cout << "Illegal,please input again." << endl;
            break;
        }
        if (cho == 0)
            break;
        cout << "Next?(y/n)" << endl;
        cin.clear();
        cin.sync();
        cin >> yn;
    }
    return 1;
}
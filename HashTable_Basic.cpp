#include<iostream>
#include<time.h>
#include<stdlib.h>

const int M=7;

using namespace std;


struct Node
{
    double Info;
    Node* pNext;
};

struct tagList
{
    Node* pHead;
    Node* pTail;
};

tagList bucket[M];

void CreateList(tagList &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}

Node* CreateNode(double x)
{
    Node *p;
    p=new Node;
    if(p==NULL)
        return p;
    p->Info=x;
    p->pNext=NULL;
    return p;
}

void AddTail(tagList &l,Node *p)
{
    if(l.pHead==NULL)
    {
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}

void Print_BK(tagList l)
{
    for(Node *p=l.pHead;p!=NULL;p=p->pNext)
    {
        cout<<p->Info<<"\t";
    }
    cout<<endl;
}

int HashFunc(double data)
{
    return (int)data%M;
}

void InitBuckets()
{
    for(int i=0;i<M;i++)
    {
        CreateList(bucket[i]);
    }
}

void InsertNode(double data)
{
    int b=HashFunc(data);
    Node *p=CreateNode(data);
    AddTail(bucket[b],p);
}

void Print_HT()
{
    for(int i=0;i<M;i++)
    {
        cout<<"[BUCKET #"<<i<<"]:\t";
        Print_BK(bucket[i]);
    }
}

bool IsEmpty_HT()
{
    for(int b=0;b<M;b++)
    {
        if(bucket[b].pHead!=NULL)
            return false;
    }
    return true;
}

void Random_HT()
{
    srand(time(0));
    int j = rand()%51 + 45;
    for(int i = 0; i < j; i++)
    {
         double x = 856 + rand()%132 + (double)(rand()%100)/100 + 0.01 ;
         InsertNode(x);
    }
}

void Input_HT()
{
    int x;
    while(1)
    {
        cout<<"Nhap -1 de ket thuc"<<endl;
        cout << "Nhap gia tri can them: ";
        cin >> x;
        if(x == -1) break;
        InsertNode(x);
    }
}

Node* Delete_Node(double data)
{
    int Index=HashFunc(data);
    tagList l=bucket[Index];
    Node *p=l.pHead;
    Node *check=p;
    while(check != NULL)
    {
        if(check->Info!=data)
        {
            cout<<"Khong tim thay de xoa"<<endl;
            break;
        }
        if(check==p && check->Info==data)
        {
            Node *temp = check;
            p=check;
            free(temp);
            return p;
        }
        else if(check->Info==data && check->pNext==NULL)
        {
            Node* temp = check;
            check = NULL;
            free(temp);
            return p;
        }
        else if(check->Info==data)
        {
            Node* temp = check;
            check = check->pNext;
            free(temp);
            return p;
        }
        check=check->pNext;
    }
}

Node* SearchData(double data)
{
    int iBucket=HashFunc(data);
    tagList l=bucket[iBucket];
    for(Node *p=l.pHead;p!=NULL;p=p->pNext)
    {
        if(data==p->Info)
        {
            return p;
        }
        else if(p->Info!=data) cout<<"Khong tim thay X"<<endl;
    }
    return NULL;
}

int main()
{
    Node *p;
    tagList l;
    InitBuckets();
    int chon;
    cout<<"19521587_Tran Tien Hung_Buoi#7_HashTable"<<endl;
    cout<<"HashTable: Chaining"<<endl;
    while(1)
    {
        cout<<"#1: Tao tu dong HashTable"<<endl;
        cout<<"#2: Nhap thu cong"<<endl;
        cout<<"#3: In bang bam"<<endl;
        cout<<"#4: Xoa gia tri X"<<endl;
        cout<<"#5: Tim X"<<endl;
        cout<<"#6: Thoat"<<endl;
        cout<<"Chon chuc nang: ";
        cin>>chon;
        switch(chon)
        {
            case 1:
            {
                Random_HT();
                cout<<"HashTable da duoc tao tu dong"<<endl;
                break;
            }
            case 2:
            {
                Input_HT();
                break;
            }
            case 3:
            {
                Print_HT();
                break;
            }
            case 4:
            {
                double x;
                cout<<"Nhap x can xoa: ";
                cin>>x;
                Delete_Node(x);
                cout<<endl;
                cout<<"Bang bam sau khi xoa X: "<<endl;
                Print_HT();
                break;
            }
            case 5:
            {
                double x;
                cout<<"Nhap x can tim: ";
                cin>>x;
                cout<<endl;
                p=SearchData(x);
                cout<<"Dia chi cua X: "<<p<<endl;
                break;
            }
            case 6:
            {
                return 0;
            }
            default: cout<<"Khong ton tai chuc nang"<<endl;
        }
    }
}

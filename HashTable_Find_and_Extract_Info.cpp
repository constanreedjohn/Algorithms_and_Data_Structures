#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

const int M=11;

struct Node
{
    double Info;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

List bucket[M];

void CreateList(List &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}

Node* CreateNode(double x)
{
    Node *p=new Node;
    if(p==NULL)
        return p;
    p->Info=x;
    p->pNext=NULL;
    return p;
}

void InsertNode(List &l,double x)
{
    Node *p=CreateNode(x);
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

void PrintList(List l)
{
    for(Node *p=l.pHead;p!=NULL;p=p->pNext)
    {
        cout<<p->Info<<"\t";
    }
}

void PrintHT(List l)
{
    for(int i=0;i<M;i++)
    {
        cout<<"Bucket["<<i<<"]: ";
        PrintList(bucket[i]);
        cout<<endl;
    }
}

int HashFunc(float x)
{
    return (int)x%M;
}

void AddHash(float x)
{
    int Index=HashFunc(x);
    InsertNode(bucket[Index],x);
}

void InitBucket(List &l)
{
    for(int i=0;i<M;i++)
    {
        CreateList(bucket[i]);
    }
}

bool IsEmpty(List l)
{
    for(int i=0;i<M;i++)
    {
        if(bucket[i].pHead==NULL) return true;
    }
    return false;
}

void InputHT(List &l)
{
    double x;
    while(1)
    {
        cout<<"Nhap -1 de ket thuc"<<endl;
        cout<<"Nhap gia tri x: ";
        cin>>x;
        if(x==-1) break;
        AddHash(x);
    }
}

void RandomHT(List &l)
{
    srand(time(NULL));
    int n=rand()%46+45;
    double x;
    for(int i=0;i<n;i++)
    {
        x=rand()%133+856+(double)(rand()%133+856)/RAND_MAX;
        AddHash(x);
    }
}

bool SearchData(double x)
{
    int Index=HashFunc(x);
    List l=bucket[Index];
    for(Node *p=l.pHead;p!=NULL;p=p->pNext)
    {
        if(x==p->Info)
            return true;
    }
    return false;
}

void DemGiaTri(List l,int &d)
{
    for(Node *p=l.pHead;p!=NULL;p=p->pNext)
    {
        if(p->Info!=0)
            d++;
    }
}

int DemNode(List l,int &dem)
{
    for(int i=0;i<M;i++)
    {
        DemGiaTri(bucket[i],dem);
    }
    return dem;
}

int TongGiaTri(List l,int &t)
{
    for(Node *p=l.pHead;p!=NULL;p=p->pNext)
    {
        if(p->Info!=0)
            t=t+p->Info;
    }
    return t;
}

int TongNode(List l,int &tong)
{
    for(int i=0;i<M;i++)
    {
        tong=TongGiaTri(bucket[i],tong);
    }
    return tong;
}

bool Check_Chan(double x)
{
    if((int)x%2==0)
        return true;
    return false;
}

int Tong_Chan_List(List l,int &t)
{
    for(Node *p=l.pHead;p!=NULL;p=p->pNext)
    {
        if(Check_Chan(p->Info)==true)
        {
            t=t+p->Info;
        }
    }
    return t;
}

int TongChan(List l,int &tong)
{
    for(int i=0;i<M;i++)
    {
        tong=Tong_Chan_List(bucket[i],tong);
    }
    return tong;
}

double Tim_First()
{
    for(int i=0;i<M;i++)
    {
        if(bucket[i].pHead!=NULL)
            return bucket[i].pHead->Info;
    }
}

void Tim_Max(List &l, double &m)
{
    for(Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if(m < p->Info)
        {
            m = p->Info;
        }
   }
}

void Tim_Min(List &l, double &m)
{
    for(Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if(m > p->Info)
        {
            m = p->Info;
        }
   }
}

void Tim_Max_Min()
{
    double Max = Tim_First();
    double Min = Max;
    for(int i=0; i<M; i++)
    {
        Tim_Max(bucket[i], Max);
    }

    for(int i=0; i<M; i++)
    {
        Tim_Min(bucket[i], Min);
    }
    cout << "Max = " << Max << endl;
    cout << "Min = " << Min;
}

int main()
{
    int tong=0,dem=0,tong_Chan=0;
    double x,Max,Min;

    InitBucket(bucket[M]);
    InputHT(bucket[M]);
    cout<<endl;
    PrintHT(bucket[M]);
    cout<<endl;
    cout<<"Nhap gia tri can tim: ";
    cin>>x;
    cout<<SearchData(x);
    cout<<endl;
    cout<<"Tong node: "<<TongNode(bucket[M],tong)<<endl;
    cout<<"So Node: "<<DemNode(bucket[M],dem)<<endl;
    cout<<"Tong Node chan: "<<TongChan(bucket[M],tong_Chan)<<endl;
    Tim_Max_Min();
    cout<<Max<<endl;
    cout<<Min;
}

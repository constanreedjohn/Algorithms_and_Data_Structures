#include<iostream>
#include<cstring>

using namespace std;

struct SV
{
    int MSSV;
    string Name;
    float GPA;
};


struct Node
{
    SV Data;
    Node* pLeft;
    Node* pRight;
};

struct Tree
{
    Node* Root;
};

void CreateTree(Tree &t)
{
    t.Root=NULL;
}

void Nhap(SV &x)
{
    cout<<"Nhap MSSV: ";
    cin>>x.MSSV;
    cout<<"Nhap Ten: ";
    cin>>x.Name;
    cout<<"Nhap diem GPA: ";
    cin>>x.GPA;
}

Node* CreateNode(SV &x)
{
    Nhap(x);
    Node *p=new Node;
    if(p==NULL)
    {
        return NULL;
    }
    p->Data.MSSV=x.MSSV;
    p->Data.Name=x.Name;
    p->Data.GPA=x.GPA;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}

Node* InsertNode(Tree &t,SV &x)
{
    Node *p=CreateNode(x);
    if(t.Root==NULL)
    {
        t.Root=p;
    }
    else
    {
        Node* pRun=t.Root;
        Node* f_Yes;
        while(pRun!=NULL)
        {
            f_Yes=pRun;
            if(x.MSSV < pRun->Data.MSSV)
            {
                pRun=pRun->pLeft;
                cout<<x.MSSV<<" da add vao ben trai"<<endl;
            }
            else if(x.MSSV > pRun->Data.MSSV)
            {
                pRun=pRun->pRight;
                cout<<x.MSSV<<" da add vao ben phai"<<endl;
            }
        }
        if(x.MSSV < f_Yes->Data.MSSV)
        {
            f_Yes->pLeft=p;
        }
        else if(x.MSSV > f_Yes->Data.MSSV)
        {
            f_Yes->pRight=p;
        }
    }
    return p;
}

Node* SearchNode(Tree t,SV x)
{
    cout<<"Nhap MSSV can tim: ";
    cin>>x.MSSV;
    Node* i=t.Root;
    while(i!=NULL)
    {
        if(x.MSSV < i->Data.MSSV)
        {
            i=i->pLeft;
        }
        else if(x.MSSV > i->Data.MSSV)
        {
            i=i->pRight;
        }
        else if(i->Data.MSSV==x.MSSV)
        {
            cout<<x.MSSV<<" co trong cay"<<endl;
            cout<<"Dia chi cua "<<x.MSSV<<": "<<i;
            return i;
        }
    }
    if(i==NULL) cout<<"Khong tim thay "<<x.MSSV<<endl;
}

void LNR(Node* root)
{
    if(root!=NULL)
    {
        LNR(root->pLeft);
        cout<<root->Data.MSSV<<"\t"<<root<<"\tLeft: "<<root->pLeft<<"\tRight: "<<root->pRight<<endl;
        LNR(root->pRight);
    }
}

int main()
{
    Tree A;
    CreateTree(A);
    SV E[100],x;
    int n;
    cout<<"Nhap so luong SV: ";
    cin>>n;
    A.Root=CreateNode(E[0]);
    Node *p;
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        cout<<"Nhap thong in SV "<<i+1<<endl;
        p=InsertNode(A,E[i]);
    }
    cout<<endl;
    LNR(A.Root);
    cout<<endl;
    p=SearchNode(A,x);
}

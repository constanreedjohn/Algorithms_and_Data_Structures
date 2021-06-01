#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;

struct Node
{
    int Data;
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

Node* CreateNode(int x)
{
    Node *p=new Node;
    if(p==NULL)
    {
        return NULL;
    }
    p->Data=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}

Node* InsertNode(Tree &t,int x)
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
            if(x < pRun->Data)
            {
                pRun=pRun->pLeft;
                cout<<x<<" da add vao ben trai"<<endl;
            }
            else if(x > pRun->Data)
            {
                pRun=pRun->pRight;
                cout<<x<<" da add vao ben phai"<<endl;
            }
        }
        if(x < f_Yes->Data)
        {
            f_Yes->pLeft=p;
//            cout<<"Dia chi da add vao ben trai: "<< &p->pLeft<<endl;
        }
        else if(x > f_Yes->Data)
        {
            f_Yes->pRight=p;
//            cout<<"Dia chi da add vao ben phai: "<<&p->pRight<<endl;
        }
    }
    return p;
}

Node* SearchNode(Tree t,int x)
{
    Node* i=t.Root;
    while(i!=NULL)
    {
        if(x < i->Data)
        {
            i=i->pLeft;
        }
        else if(x > i->Data)
        {
            i=i->pRight;
        }
        else if(i->Data==x)
        {
            cout<<x<<" co trong cay"<<endl;
            cout<<"Dia chi cua "<<x<<": "<<i;
            return i;
        }
    }
    if(i==NULL) cout<<"Khong tim thay "<<x<<endl;
}

void NLR(Node* root)
{
    if(root!=NULL)
    {
        cout<<root->Data<<"\t"<<root<<"\tLeft: "<<root->pLeft<<"\tRight: "<<root->pRight<<endl;
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}

void LNR(Node* root)
{
    if(root!=NULL)
    {
        LNR(root->pLeft);
        cout<<root->Data<<"\t"<<root<<"\tLeft: "<<root->pLeft<<"\tRight: "<<root->pRight<<endl;
        LNR(root->pRight);
    }
}

void LRN(Node* root)
{
    if(root!=NULL)
    {
        LRN(root->pLeft);
        LRN(root->pRight);
        cout<<root->Data<<"\t"<<root<<"\tLeft: "<<root->pLeft<<"\tRight: "<<root->pRight<<endl;
    }
}





void Random_Tree(Tree &t,int &n);
int Dem_Node(Node* root,int &dem);
int Dem_La(Node *root,int &demLa);
int Dem_Node_x(Node *root,int x,int &dem_x);
int Dem_Node_X(Node *root,int x,int &dem_X);
int Dem_Node_Khoang(Node *root,int x,int y,int &dem_Khoang);
int Dem_Node_Chan(Node *root,int &dem_Chan);
void PrintBranch(Tree t,int x);
Node* Delete_Tree(Node *root);
Node* SearchMin(Tree t);
Node* SearchMax(Tree t);
Node* DeleteNode(Tree &t,Node *root,int x);
void SoSanh(int dem_x,int dem_X);
void SoSanh_ChanLe(int dem_Chan,int dem_Le);
void SoSanh_Gtri_ChanLe(int tong_Chan,int tong_Le);
int TinhTong_Node(Node *root,int &tong);
int TinhTong_Node_Chan(Node *root,int &tong_Chan);
int TinhTong_Node_Le(Node *root,int &tong_Le);
int Dem_Node_Le(Node *root,int &dem_Le);




int main()
{
    srand(time(NULL));
    Tree A;
    CreateTree(A);

    bool flag=0, cau10=0, cau11=0, cau17=0, cau18=0;
    int x,n,Goc,X,Delete,Nhanh;
    int m,M,c,C;
    Node *p;
    int chon;

    int dem=0;
    int demLa=0;
    int dem_x=0;
    int dem_X=0;
    int dem_Khoang=0;
    int dem_Chan=0;
    int dem_Le=0;

    int tong=0;
    int tong_Chan=0;
    int tong_Le=0;


    cout<<endl;
    cout<<"19521587_TRAN TIEN HUNG_Buoi#6_BST"<<endl;
    while(1)
    {
        cout<<endl;
        cout<<"                 Binary Search Tree                         "<<endl;
        cout<<"Cau #1: Nhap thu cong Cay Nhi Phan"<<endl;
        cout<<"Cau #2: Nhap tu dong Cay Nhi Phan"<<endl;
        cout<<"Cau #3: Duyet Cay Nhi Phan"<<endl;
        cout<<"Cau #4: Tim kiem gia tri X"<<endl;
        cout<<"Cau #5: Xoa mot gia tri X tren cay"<<endl;
        cout<<"Cau #6: Xoa toan bo Node tren cay"<<endl;
        cout<<"Cau #7: Dem toan bo so Node tren cay"<<endl;
        cout<<"Cau #8: Dem so la tren cay"<<endl;
        cout<<"Cau #9: In ra nhanh (NLR) tu mot Node"<<endl;
        cout<<"Cau #10: Dem Node co gia tri nho hon X"<<endl;
        cout<<"Cau #11: Dem Node co gia tri lon hon X"<<endl;
        cout<<"Cau #12: Dem Node co gia tri trong khoang (X,Y)"<<endl;
        cout<<"Cau #13: So sanh 2 cau 10 va 11"<<endl;
        cout<<"Cau #14: Dem Node co gia tri chan, le"<<endl;
        cout<<"Cau #15: So Sanh cau #14"<<endl;
        cout<<"Cau #16: Tinh Tong cac Node trong cay"<<endl;
        cout<<"Cau #17: Tinh Tong chan cac Node trong cay"<<endl;
        cout<<"Cau #18: Tinh Tong le cac Node trong cay"<<endl;
        cout<<"Cau #19: So sanh 2 cau 17 va 18"<<endl;
        cout<<"Cau #20: Tim Node co gia tri Max, Min trong cay"<<endl;
        cout<<"Cau #0: Thoat"<<endl;
        cout<<"----Chon Chuc Nang----"<<endl;
        cin>>chon;
        switch(chon)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                if(flag)
                {
                    cout<<"Cay da duoc nhap"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nhap goc cua cay: ";
                    cin>>Goc;
                    A.Root=CreateNode(Goc);
                    while(1)
                    {
                        cout<<endl;
                        cout<<"Nhap -1 de ket thuc: "<<endl;
                        cout<<"Nhap gia tri x: ";
                        cin>>x;
                        if(x==-1) break;
                        p=InsertNode(A,x);
                    }
                    flag=1;
                }
                break;
            }
            case 2:
            {
                if(flag)
                {
                    cout<<"Cay da duoc nhap"<<endl;
                    break;
                }
                else
                {
                    Random_Tree(A,n);
                    cout<<"Cay da duoc nhap tu dong"<<endl;
                    flag=1;
                }
                break;
            }
            case 3:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 vao truoc"<<endl;
                    break;
                }
                else
                {
                    int way;
                    cout<<"Chon cach de duyet cay: "<<endl;
                    cout<<"#1: NLR"<<endl;
                    cout<<"#2: LNR"<<endl;
                    cout<<"#3: LRN"<<endl;
                    cin>>way;
                    switch(way)
                    {
                        case 1:
                        {
                            cout<<"Cach duyet cay theo NLR:"<<endl;
                            NLR(A.Root);
                            break;
                        }
                        case 2:
                        {
                            cout<<"Cach duyet cay theo LNR:"<<endl;
                            LNR(A.Root);
                            break;
                        }
                        case 3:
                        {
                            cout<<"Cach duyet cay theo LRN:"<<endl;
                            LRN(A.Root);
                            break;
                        }
                        default: cout<<"Khong ton tai chuc nang"<<endl;
                    }
                }
                break;
            }
            case 4:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nhap gia tri X can tim: ";
                    cin>>X;
                    p=SearchNode(A,X);
                    cout<<endl;
                }
                break;
            }
            case 5:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nhap gia tri can xoa: ";
                    cin>>Delete;
                    DeleteNode(A,A.Root,Delete);
                    cout<<"Cay sau khi da xoa "<<Delete<<": "<<endl;
                    LNR(A.Root);
                    cout<<endl;
                    break;
                }
            }
            case 6:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    Delete_Tree(A.Root);
                    cout<<endl;
                }
                break;
            }
            case 7:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    cout<<"Tong so Node co trong cay: "<<Dem_Node(A.Root,dem)<<endl;
                }
                break;
            }
            case 8:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    cout<<"Tong so La co trong cay: "<<Dem_La(A.Root,demLa)<<endl;
                }
                break;
            }
            case 9:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    cout<<"Chon nhanh can in: ";
                    cin>>Nhanh;
                    PrintBranch(A,Nhanh);
                    cout<<endl;
                }
                break;
            }
            case 10:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nhap gia tri X: ";
                    cin>>m;
                    cout<<"So Node co gia tri nho hon X la: "<<Dem_Node_x(A.Root,m,dem_x)<<endl;
                    cau10=1;
                }
                break;
            }
            case 11:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nhap gia tri X: ";
                    cin>>M;
                    cout<<"So Node co gia tri lon hon X la: "<<Dem_Node_X(A.Root,M,dem_X)<<endl;
                    cau11=1;
                }
                break;
            }
            case 12:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    cout<<"Nhap gia tri trong khoang: "<<endl;
                    cout<<"X: ";
                    cin>>c;
                    cout<<"Y: ";
                    cin>>C;
                    cout<<"So Node co gia tri trong khoang ["<<c<<","<<C<<"] la :"<<Dem_Node_Khoang(A.Root,c,C,dem_Khoang)<<endl;
                }
                break;
            }
            case 13:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    if(cau10==1 && cau11==1)
                    {
                        SoSanh(dem_x,dem_X);
                        cout<<endl;
                    }
                    else cout<<"Nhap cau 10 hoac 11 vao truoc de so sanh"<<endl;
                }
                break;
            }
            case 14:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    int cau;
                    cout<<"Chon chuc nang"<<endl;
                    cout<<"#1:Dem Node chan"<<endl;
                    cout<<"#2:Dem Node Le"<<endl;
                    cin>>cau;
                    switch(cau)
                    {
                        case 1:
                        {
                            cout<<"So Node co gia tri chan: "<<Dem_Node_Chan(A.Root,dem_Chan)<<endl;
                            break;
                        }
                        case 2:
                        {
                            cout<<"So Node co gia tri le: "<<Dem_Node_Le(A.Root,dem_Le)<<endl;
                            break;
                        }
                        default: cout<<"Chuc nang khong ton tai"<<endl;
                    }
                }
                break;
            }
            case 15:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                    SoSanh_ChanLe(dem_Chan,dem_Le);
                break;
            }
            case 16:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                    cout<<"Tong cac gia tri Node trong cay: "<<TinhTong_Node(A.Root,tong)<<endl;
                break;
            }
            case 17:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                    cout<<"Tong cac gia tri chan Node trong cay: "<<TinhTong_Node_Chan(A.Root,tong_Chan)<<endl;
                    cau17=1;
                break;
            }
            case 18:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                    cout<<"Tong cac gia tri le Node trong cay: "<<TinhTong_Node_Le(A.Root,tong_Le)<<endl;
                    cau18=1;
                break;
            }
            case 19:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                    if(cau18==1 && cau17==1)
                        SoSanh_Gtri_ChanLe(tong_Chan,tong_Le);
                    else cout<<"Nhap cau 17 hoac 18 truoc de so sanh"<<endl;
                break;
            }
            case 20:
            {
                if(!flag)
                {
                    cout<<"Nhap cau 1 hoac 2 truoc"<<endl;
                    break;
                }
                else
                {
                    int choose;
                    cout<<"Chon chuc nang:"<<endl;
                    cout<<"#1: Tim Node Max"<<endl;
                    cout<<"#2: Tim Node Min"<<endl;
                    cin>>choose;
                    switch(choose)
                    {
                        case 1:
                        {
                            p=SearchMax(A);
                            cout<<endl;
                            break;
                        }
                        case 2:
                        {
                            p=SearchMin(A);
                            cout<<endl;
                            break;
                        }
                        default: cout<<"Chuc nang khong ton tai"<<endl;
                    }
                    break;
                }
            }
            default: cout<<"Chuc nang khong ton tai"<<endl;
        }
    }
}



int Dem_Node(Node* root,int &dem)
{
    if(root!=NULL)
    {
        dem++;
        Dem_Node(root->pLeft,dem);
        Dem_Node(root->pRight,dem);
    }
    return dem;
}

int Dem_La(Node *root,int &demLa)
{
    if(root!=NULL)
    {
        if(root->pLeft==NULL && root->pRight==NULL)
        {
            demLa++;
        }
        Dem_La(root->pLeft,demLa);
        Dem_La(root->pRight,demLa);
    }
    return demLa;
}

int Dem_Node_x(Node *root,int x,int &dem_x)
{
    if(root!=NULL)
    {
        if(root->Data < x)
            dem_x++;
        Dem_Node_x(root->pLeft,x,dem_x);
        Dem_Node_x(root->pRight,x,dem_x);
    }
    return dem_x;
}

int Dem_Node_X(Node *root,int x,int &dem_X)
{
    if(root!=NULL)
    {
        if(root->Data > x)
            dem_X++;
        Dem_Node_X(root->pLeft,x,dem_X);
        Dem_Node_X(root->pRight,x,dem_X);
    }
    return dem_X;
}

int Dem_Node_Khoang(Node *root,int x,int y,int &dem_Khoang)
{
    if(root!=NULL)
    {
        if(root->Data > x && root->Data < y)
            dem_Khoang++;
        Dem_Node_Khoang(root->pLeft,x,y,dem_Khoang);
        Dem_Node_Khoang(root->pLeft,x,y,dem_Khoang);
    }
    return dem_Khoang;
}

int Dem_Node_Chan(Node *root,int &dem_Chan)
{
    if(root!=NULL)
    {
        if(root->Data%2==0)
            dem_Chan++;
        Dem_Node_Chan(root->pLeft,dem_Chan);
        Dem_Node_Chan(root->pRight,dem_Chan);
    }
    return dem_Chan;
}

int Dem_Node_Le(Node *root,int &dem_Le)
{
    if(root!=NULL)
    {
        if(root->Data%2!=0)
            dem_Le++;
        Dem_Node_Le(root->pLeft,dem_Le);
        Dem_Node_Le(root->pRight,dem_Le);
    }
    return dem_Le;
}

void PrintBranch(Tree t,int x)
{
    Node *p=SearchNode(t,x);
    cout<<endl;
    if(p->pLeft==NULL && p->pRight==NULL)
    {
        cout<<"Xuat thong bao"<<endl;
    }
    else
    {
        NLR(p);
    }
}

Node* SearchMin(Tree t)
{
    Node* i=t.Root;
    while(i->pLeft!=NULL)
    {
        i=i->pLeft;
    }
    cout<<"Min: "<<i->Data<<endl;
    return i;
}

Node* SearchMax(Tree t)
{
    Node* i=t.Root;
    while(i->pRight!=NULL)
    {
        i=i->pRight;
    }
    cout<<"Max: "<<i->Data<<endl;
    return i;
}

Node* DeleteNode(Tree &t,Node *root,int x)
{
    if(root==NULL) return root;
    if(x < root->Data)
        root->pLeft=DeleteNode(t,root->pLeft,x);
    else if(x > root->Data)
        root->pRight=DeleteNode(t,root->pRight,x);
    else
    {
        if(root->pLeft==NULL)
        {
            Node *temp=root->pRight;
            free(root);
            return temp;
        }
        else if(root->pRight==NULL)
        {
            Node *temp=root->pLeft;
            free(root);
            return temp;
        }
        Node *temp=SearchMin(t);
        root->Data=temp->Data;
        root->pRight=DeleteNode(t,root->pRight,temp->Data);
    }
    return root;
}

void SoSanh(int dem_x,int dem_X)
{
    if(dem_x>dem_X) cout<<"So node nho hon X lon hon"<<endl;
    else if(dem_x<dem_X) cout<<"So node lon hon X lon hon"<<endl;
    else cout<<"Ca hai bang nhau"<<endl;
}

void SoSanh_ChanLe(int dem_Chan,int dem_Le)
{
    if(dem_Chan>dem_Le) cout<<"So node Chan lon hon"<<endl;
    else if(dem_Chan<dem_Le) cout<<"So node Le lon hon"<<endl;
    else cout<<"Ca hai bang nhau"<<endl;
}

int TinhTong_Node(Node *root,int &tong)
{
    if(root!=NULL)
    {
        tong=tong+root->Data;
        TinhTong_Node(root->pLeft,tong);
        TinhTong_Node(root->pRight,tong);
    }
    return tong;
}

int TinhTong_Node_Chan(Node *root,int &tong_Chan)
{
    if(root!=NULL)
    {
        if(root->Data%2==0)
            tong_Chan=tong_Chan+root->Data;
        TinhTong_Node_Chan(root->pLeft,tong_Chan);
        TinhTong_Node_Chan(root->pRight,tong_Chan);
    }
    return tong_Chan;
}

int TinhTong_Node_Le(Node *root,int &tong_Le)
{
    if(root!=NULL)
    {
        if(root->Data%2!=0)
            tong_Le=tong_Le+root->Data;
        TinhTong_Node_Le(root->pLeft,tong_Le);
        TinhTong_Node_Le(root->pRight,tong_Le);
    }
    return tong_Le;
}

void SoSanh_Gtri_ChanLe(int tong_Chan,int tong_Le)
{
    if(tong_Chan>tong_Le) cout<<"Tong gia tri node chan lon hon"<<endl;
    else if(tong_Chan>tong_Le) cout<<"Tong gia tri node le lon hon"<<endl;
    else cout<<"Ca hai bang nhau"<<endl;
}

void Random_Tree(Tree &t,int &n)
{
    Node *p;
    t.Root=CreateNode(1000+rand()%358);
    n=10+rand()%10;
    for(int i=0;i<n;i++)
    {
        p=InsertNode(t,1000+rand()%358);
    }
}

Node* Delete_Tree(Node *root)
{
    while(root!=NULL)
    {
        if (root == NULL) return root;
        if (root->pLeft!=NULL)
        {
                Node *temp=root->pRight;
                free(root);
                return temp;
        }
        else if(root->pRight!=NULL)
        {
            Node *temp=root->pLeft;
            free(root);
            return temp;
        }
    }
    return root;
}

#include<iostream>
#include<cmath>
#include<time.h>
#include<algorithm>

using namespace std;

void Random(int a[],int &n);
void Random_Tang(int a[],int &n);
int TuyenTinh(int a[],int n,int x);
int NhiPhan(int a[],int n,int x);
int NoiSuy(int a[],int n,int x);
void SoSanh(int a[],int n,int x);
void Xuat(int a[],int n);
void BinarySearch(int a[],int n,int x);
void SapXep(int a[],int n);

int main()
{
    int A[100],n;
    int B[100],m;
    int C[100];
    int x;
    srand(time(0));
    int flag=0,check=0,cau;
    int select,out,TT,NP,NS;
    while(1)
    {
    cout<<endl<<endl;
    cout<<" 19521587_TRAN TIEN HUNG_Buoi#3_BAI_THUC_HANH "<<endl;
    cout<<" -----------  MENU  ----------- "<<endl;
    cout<<"Cau (1): Tao mang "<<endl;
    cout<<"Cau (2): Xuat "<<endl;
    cout<<"Cau (3): Tim kiem Tuyen Tinh"<<endl;
    cout<<"Cau (4): Tim kiem Nhi Phan"<<endl;
    cout<<"Cau (5): Tim kiem Noi Suy"<<endl;
    cout<<"Cau (6): So sanh so lan thuc hien cua 3 phuong phap"<<endl;
    cout<<"Cau (7): Ham tim kiem them trong thu vien <algorithm>"<<endl;
    cout<<"Cau (8): Thoat"<<endl;
    cout<<" -----------  END  ----------- "<<endl;
    cout<<"Chon tinh nang: ";
    cin>>cau;
    switch(cau)
    {
    case 1:
        {
            cout<<"1. Tao mang X ngau nhien"<<endl;
            cout<<"2. Tao mang Y tang dan"<<endl;
            cout<<"Chon (0) de chon ca hai"<<endl;
            cin>>select;
            switch(select)
            {
                case 1:
                    {

                        Random(A,n);

                        flag=1;
                        cout<<"Mang X da duoc tao"<<endl;
                        break;
                    }
                case 2:
                    {

                        Random_Tang(B,m);

                        check=1;
                        cout<<"Mang Y da duoc tao"<<endl;
                        break;
                    }
                case 0:
                    {

                        Random(A,n);
                        Random_Tang(B,m);

                        flag=1;
                        check=1;
                        break;
                    }
                default:
                    cout<<"Tinh nang khong ton tai"<<endl;
                    break;
            }
        break;
        }
    case 2:
        {
            cout<<"1. Xuat mang X"<<endl;
            cout<<"2. Xuat mang Y"<<endl;
            cout<<"Chon (0) de chon ca hai"<<endl;
            cin>>out;
            switch(out)
            {
                case 1:
                    {
                        if(flag)
                        {

                            Xuat(A,n);

                        }
                        else cout<<"Nhap mang X truoc";
                        break;
                    }
                case 2:
                    {
                        if(check)
                        {

                            Xuat(B,m);

                        }
                        else cout<<"Nhap mang Y truoc";
                        break;
                    }
                case 0:
                    {
                        if(flag==1 && check==1)
                        {

                            Xuat(A,n);

                            cout<<endl;

                            Xuat(B,m);

                        }
                        else cout<<"Nhap 2 mang truoc";
                        break;
                    }
                default:
                    cout<<"Tinh nang khong ton tai";
                    break;
            }
        break;
        }
    case 3:
        {
            cout<<"1. Tim kiem tuyen tinh Mang X"<<endl;
            cout<<"2. Tim kiem tuyen tinh Mang Y"<<endl;
            cout<<"Chon (0) de chon ca hai"<<endl;
            cin>>TT;
            switch(TT)
            {
                case 1:
                    {
                        if(flag)
                        {
                            cout<<"Mang X sau khi da sap xep:"<<endl;
                            SapXep(A,n);
                            cout<<endl;


                            cout<<"Nhap x= ";
                            cin>>x;


                            if(TuyenTinh(A,n,x)!=-1)
                                cout<<"X co trong mang"<<endl;
                            else cout<<"X khong co trong mang"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap mang X vao truoc"<<endl;
                        break;
                    }
                case 2:
                    {
                        if(check)
                        {
                            cout<<"Mang Y sau khi da sap xep: "<<endl;
                            SapXep(B,m);


                            cout<<"Nhap x= ";
                            cin>>x;


                            if(TuyenTinh(B,m,x)!=-1)
                                cout<<"X co trong mang"<<endl;
                            else cout<<"X khong co trong mang"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap mang Y vao truoc"<<endl;
                        break;
                    }
                case 0:
                    {
                        if(flag==1 && check==1)
                        {
                            cout<<"Mang X:"<<endl;
                            SapXep(A,n);
                            cout<<endl<<endl;
                            cout<<"Mang Y: "<<endl;
                            SapXep(B,m);
                            cout<<endl;


                            cout<<"Nhap x= ";
                            cin>>x;


                            cout<<"Tuyen Tinh cho mang X: "<<endl;
                            if(TuyenTinh(A,n,x)!=-1)
                                cout<<"X co trong mang X"<<endl;
                            else cout<<"X khong co trong mang X"<<endl;


                            cout<<endl;


                            cout<<"Tuyen Tinh cho mang Y: "<<endl;
                            if(TuyenTinh(B,m,x)!=-1)
                                cout<<"X co trong mang Y"<<endl;
                            else cout<<"X khong co trong mang Y"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap 1 trong 2 mang vao truoc"<<endl;
                        break;
                    }
                default:
                    cout<<"Tinh nang khong ton tai"<<endl;
                    break;
            }
        break;
        }
    case 4:
        {
            cout<<"1. Tim kiem nhi phan Mang X"<<endl;
            cout<<"2. Tim kiem nhi phan Mang Y"<<endl;
            cout<<"Chon (0) de chon ca hai"<<endl;
            cin>>NP;
            switch(NP)
            {
                case 1:
                    {
                        if(flag)
                        {
                            cout<<"Mang X sau khi da sap xep:"<<endl;
                            SapXep(A,n);
                            cout<<endl;


                            cout<<"Nhap x= ";
                            cin>>x;


                            if(NhiPhan(A,n,x)!=-1)
                                cout<<"X co trong mang"<<endl;
                            else cout<<"X khong co trong mang"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap mang X vao truoc"<<endl;
                        break;
                    }
                case 2:
                    {
                        if(check)
                        {
                            cout<<"Mang Y sau khi da sap xep:"<<endl;
                            SapXep(B,m);
                            cout<<endl;


                            cout<<"Nhap x= ";
                            cin>>x;


                            if(NhiPhan(B,m,x)!=-1)
                                cout<<"X co trong mang"<<endl;
                            else cout<<"X khong co trong mang"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap mang Y vao truoc"<<endl;
                        break;
                    }
                case 0:
                    {
                        if(flag==1 && check==1)
                        {
                            cout<<"Mang X:"<<endl;
                            SapXep(A,n);
                            cout<<endl<<endl;
                            cout<<"Mang Y: "<<endl;
                            SapXep(B,m);
                            cout<<endl;


                            cout<<"Nhap x= ";
                            cin>>x;


                            cout<<"Nhi Phan cho mang X: "<<endl;
                            if(NhiPhan(A,n,x)!=-1)
                                cout<<"X co trong mang X"<<endl;
                            else cout<<"X khong co trong mang X"<<endl;


                            cout<<endl;


                            cout<<"Nhi Phan cho mang Y: "<<endl;
                            if(NhiPhan(B,m,x)!=-1)
                                cout<<"X co trong mang Y"<<endl;
                            else cout<<"X khong co trong mang Y"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap 1 trong 2 mang vao truoc"<<endl;
                        break;
                    }
                default:
                    cout<<"Tinh nang khong ton tai"<<endl;
                    break;
            }
        break;
        }
    case 5:
        {
            cout<<"1. Tim kiem noi suy Mang X"<<endl;
            cout<<"2. Tim kiem noi suy Mang Y"<<endl;
            cout<<"Chon (0) de chon ca hai"<<endl;
            cin>>NS;
            switch(NS)
            {
                case 1:
                    {
                        if(flag)
                        {
                            cout<<"Mang X sau khi da sap xep:"<<endl;
                            SapXep(A,n);
                            cout<<endl;


                            cout<<"Nhap x= ";
                            cin>>x;


                            if(NoiSuy(A,n,x)!=-1)
                                cout<<"X co trong mang"<<endl;
                            else cout<<"X khong co trong mang"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap mang X vao truoc"<<endl;
                        break;
                    }
                case 2:
                    {
                        if(check)
                        {
                            cout<<"Mang Y sau khi da sap xep:"<<endl;
                            SapXep(B,m);
                            cout<<endl;


                            cout<<"Nhap x= ";
                            cin>>x;


                            if(NoiSuy(B,m,x)!=-1)
                                cout<<"X co trong mang"<<endl;
                            else cout<<"X khong co trong mang"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap mang Y vao truoc"<<endl;
                        break;
                    }
                case 0:
                    {
                        if(flag==1 && check==1)
                        {
                            cout<<"Mang X:"<<endl;
                            SapXep(A,n);
                            cout<<endl<<endl;
                            cout<<"Mang Y: "<<endl;
                            SapXep(B,m);
                            cout<<endl;


                            cout<<"Nhap x= ";
                            cin>>x;


                            cout<<"Noi Suy cho mang X: "<<endl;
                            if(NoiSuy(A,n,x)!=-1)
                                cout<<"X co trong mang X"<<endl;
                            else cout<<"X khong co trong mang X"<<endl;


                            cout<<endl;


                            cout<<"Noi Suy cho mang Y: "<<endl;
                            if(NoiSuy(B,m,x)!=-1)
                                cout<<"X co trong mang Y"<<endl;
                            else cout<<"X khong co trong mang Y"<<endl;


                            cout<<endl;
                        }
                        else cout<<"Nhap 1 trong 2 mang vao truoc"<<endl;
                        break;
                    }
                default:
                    cout<<"Tinh nang khong ton tai"<<endl;
                    break;
            }
        break;
        }
    case 6:
        {
            SoSanh(A,n,x);
            cout<<endl;
            break;
        }
    case 7:
        {
            if(flag)
            {
                Xuat(A,n);

                cout<<"Ham tim kiem nhi phan trong thu vien <algorithm> cho mang X"<<endl;

                BinarySearch(A,n,x);

                cout<<endl;
            }
            else cout<<"Nhap mang X truoc"<<endl;
            break;
        }
    case 8:
        return 0;
        break;
    default:
        {
            cout<<"Tinh nang khong ton tai"<<endl;
            break;
        }
    }
    }
}

void Random(int a[],int &n)
{
    n=30+rand()%21;
    for(int i=0;i<n;i++)
    {
        a[i]=100+rand()%900;
    }
}

void Random_Tang(int a[],int &n)
{
    int i=1;
    a[0]=130+rand()%870;
    n=30+rand()%21;
    for(int j=1;j<n;j++)
    {
        a[j]=a[i-1]+rand()%16;
    }
}

void SapXep(int a[],int n)
{
    std::sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

void Xuat(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";

    }
    cout<<endl;
}

int TuyenTinh(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(x==a[i])
        {
            return i;
        }
    }
    return -1;
}

int NhiPhan(int a[],int n,int x)
{
    int left=0,right=n-1;
    int mid=left+(right-left)/2;
    for(int i=0;i<n;i++)
    {
        while(left<=right)
        {
            if(x==a[mid])
                return mid;
            if(x<a[mid])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
    }
    return -1;
}

int NoiSuy(int a[],int n,int x)
{
    int left=0,right=n-1;
    int mid = left + ((right - left) / (a[right] - a[left])) * (x - a[left]);
    for(int i=0;i<n;i++)
    {
        while(left<=right && x>a[left] && x<a[right])
        {
            if(x==a[mid])
                return mid;
            if(x<a[mid])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
    }
    return -1;
}

void BinarySearch(int a[],int n,int x)
{
    std::sort(a,a+n);
    cout<<"Nhap x can tim= ";
    cin>>x;
    if(std::binary_search(a,a+n-1,x))
        cout<<"X co trong mang"<<endl;
    else cout<<"X ko co trong mang"<<endl;
}

void SoSanh(int a[],int n,int x)
{
    int a1=TuyenTinh(a,n,x);
    int a2=NhiPhan(a,n,x);
    int a3=NoiSuy(a,n,x);
    int m=min(a1,min(a2,a3));
    int M=max(a1,max(a2,a3));
    if(m==a1)
        cout<<"Tuyen Tinh duoc so sanh nho nhat";
    else if(m==a2)
        cout<<"Nhi Phan duoc so sanh nho nhat";
    else if(m==a3)
        cout<<"Noi Suy duoc so sanh nho nhat";
    else if(M==a1)
        cout<<"Tuyen Tinh duoc so sanh lon nhat";
    else if(M==a2)
        cout<<"Nhi Phan duoc so sanh lon nhat";
    else if(M==a3)
        cout<<"Noi Suy duoc so sanh lon nhat";
}

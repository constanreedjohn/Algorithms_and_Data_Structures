#include<iostream>
#include<cmath>
#include<time.h>
#include<stdlib.h>

using namespace std;

int fib(int n);
void Fib_Nhap(int a[],int &n);
void Fib_Xuat(int a[],int n);

int main()
{
    int A[100],n,x;
    srand(time(0));
    bool flag=0;
    int cau;
    while(1)
    {
    cout<<endl<<endl;
    cout<<" 19521587_TRAN TIEN HUNG_Buoi#1_BAI05 "<<endl;
    cout<<" -----------  MENU  ----------- "<<endl;
    cout<<"Cau (1): Nhap tu dong cho day financi."<<endl;
    cout<<"Cau (2): Xuat day financi."<<endl;
    cout<<"Cau (3): Xuat vi tri trong day financi."<<endl;
    cout<<"Cau (4): Thoat"<<endl;
    cout<<" -----------  END  ----------- "<<endl;
    cout<<"Chon tinh nang: ";
    cin>>cau;
    switch(cau)
        {
            case 1:
                {
                    Fib_Nhap(A,n);
                    flag=1;
                    break;
                }
            case 2:
                {
                    if(flag)
                    {
                        cout<<"Day financi la: ";
                        Fib_Xuat(A,n);
                        cout<<endl;
                    }
                    else cout<<"Nhap cau (1) truoc"<<endl;
                    break;
                }
            case 3:
                {
                    if(flag)
                    {
                        cout<<"Day financi la: ";
                        Fib_Xuat(A,n);
                        cout<<endl;
                        cout<<"Nhap vi tri cua Fibonaci= ";
                        cin>>x;
                        cout<<"Gia tri tai fib("<<x<<"): "<<fib(x)<<endl;
                    }
                    else cout<<"Nhap cau (1) truoc"<<endl;
                    break;
                }
            case 4:
                {
                    return 0;
                    break;
                }
            default:
                cout<<"Tinh nang khong ton tai";
        }
    }
}
int fib(int n)
{
    if(n<=1)
        return n;
    else
        return fib(n-1)+fib(n-2);
}
void Fib_Xuat(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void Fib_Nhap(int a[],int &n)
{
    n=10+rand()%41;
    for(int i=0;i<n;i++)
    {
        a[i]=fib(i);
    }
}

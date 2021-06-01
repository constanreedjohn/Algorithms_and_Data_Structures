#include<iostream>
#include<cmath>

using namespace std;

struct PHANSO
{
    int tu;
    int mau;
};

void Nhap(PHANSO &X);
void Xuat(PHANSO X);
void RutGon(PHANSO &X);
int UCLN(int a, int b);
void SoSanh(PHANSO X,PHANSO Y);
PHANSO Tong(PHANSO X,PHANSO Y);
PHANSO Hieu(PHANSO X,PHANSO Y);
PHANSO Tich(PHANSO X,PHANSO Y);
PHANSO Thuong(PHANSO X,PHANSO Y);
int main()
{
    PHANSO A,B;
    Nhap(A);
    Xuat(A);
    RutGon(A);
    cout<<endl;
    Nhap(B);
    Xuat(B);
    RutGon(B);
    cout<<endl;
    SoSanh(A,B);
    cout<<endl;
    cout<<"Tong 2 PS la: "<<endl;
    Tong(A,B);
    cout<<endl;
    cout<<"Hieu 2 PS la: "<<endl;
    Hieu(A,B);
    cout<<endl;
    cout<<"Tich 2 PS la: "<<endl;
    Tich(A,B);
    cout<<endl;
    cout<<"Thuong 2 PS la: "<<endl;
    Thuong(A,B);
    cout<<endl;
}
void Nhap(PHANSO &X)
{
    cout<<"Nhap tu= ";
    cin>>X.tu;
    do
    {
        cout<<"Nhap mau= ";
        cin>>X.mau;
    }
    while(X.mau==0);
}
void Xuat(PHANSO X)
{
    cout<<"Phan so da nhap la: ";
}
void RutGon(PHANSO &A)
{
    int d=UCLN(A.tu,A.mau);
    A.tu/=d;
    A.mau/=d;
    cout<<A.tu<<"/"<<A.mau;
}
int UCLN(int a, int b)
{
    if(a<0) a=-a;
    if(b<0) b=-b;
    while(a!=b)
    {
        if(a>=b) a=a-b;
        else b=b-a;
    }
    return a;
}
void SoSanh(PHANSO X,PHANSO Y)
{
    PHANSO Q=Hieu(X,Y);
    if(X.mau=Y.mau)
    {
        if(X.tu>Y.tu) cout<<"PS dau lon hon PS sau";
        else cout<<"PS dau nho hon PS sau";
    }
    else if(X.tu=Y.tu)
    {
        if(X.mau>Y.mau) cout<<"PS dau nho hon PS sau";
        else cout<<"PS dau lon hon PS sau";
    }
    else if(Q.tu>0)
    {
        cout<<"PS dau lon hon PS sau";
    }
    else if(Q.tu<0) cout<<"PS dau nho hon PS sau";
    else if(Q.tu==0) cout<<"Hai PS bang nhau";
}
PHANSO Tong(PHANSO X,PHANSO Y)
{
    PHANSO Z;
    Z.mau=X.mau*Y.mau;
    Z.tu=X.mau*Y.tu + X.tu*Y.mau;
    RutGon(Z);
    return Z;
}
PHANSO Hieu(PHANSO X,PHANSO Y)
{
    PHANSO Z;
    Z.mau=X.mau*Y.mau;
    Z.tu=X.mau*Y.tu - X.tu*Y.mau;
    RutGon(Z);
    return Z;
}
PHANSO Tich(PHANSO X,PHANSO Y)
{
    PHANSO Z;
    Z.mau=X.mau*Y.mau;
    Z.tu=X.tu * Y.tu;
    RutGon(Z);
    return Z;
}
PHANSO Thuong(PHANSO X,PHANSO Y)
{
    PHANSO Z;
    Z.mau=X.mau*Y.tu;
    Z.tu=X.tu*Y.mau;
    RutGon(Z);
    return Z;
}

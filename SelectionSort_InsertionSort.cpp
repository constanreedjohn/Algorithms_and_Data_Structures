#include<iostream>
#include<cmath>
#include<time.h>

using namespace std;

#define MAX1 10e5
#define MAX2 100000

double A[(int)MAX1];
double B[(int)MAX1];

void Random_Thuc(double A[],int &n);
void OutPut(double A[],int n);
void SelectionSort(double A[],int n);
void InsertionSort(double A[],int n);
float Time_Process_SS(double A[],int n);
float Time_Process_IS(double A[],int n);

int main()
{
    srand(time(NULL));
    int n,m;
    int cau,flag,check;
    bool fin=false,comp=false;
    while(1)
    {
    cout<<endl<<endl;
    cout<<" 19521587_TRAN TIEN HUNG_Buoi#4_BTSapXep "<<endl;
    cout<<" -----------  MENU  ----------- "<<endl;
    cout<<"Cau (1): Nhap tu dong da thuc de sap xep."<<endl;
    cout<<"Cau (2): Sap xep truc tiep."<<endl;
    cout<<"Cau (3): Sap xep chen"<<endl;
    cout<<"Cau (4): Xuat mang"<<endl;
    cout<<"Cau (5): Thoat"<<endl;
    cout<<" -----------  END  ----------- "<<endl;
    cout<<"Chon tinh nang: ";
    cin>>cau;
    switch(cau)
        {
            case 1:
                {
                    int nhap;
                        cout<<"Chon cau de nhap: "<<endl;
                        cout<<"Cau (1): Mang A"<<endl;
                        cout<<"Cau (2): Mang B"<<endl;
                        cout<<"Chon (0) de xuat ca hai: ";
                        cin>>nhap;
                    switch(nhap)
                    {
                        case 1:
                            {
                                Random_Thuc(A,n);
                                flag=1;
                                cout<<"Da nhap tu dong mang A vao may"<<endl;
                                break;
                            }
                        case 2:
                            {
                                Random_Thuc(B,m);
                                check=1;
                                cout<<"Da nhap tu dong mang B vao may"<<endl;
                                break;
                            }
                        case 0:
                            {
                                Random_Thuc(A,n);
                                flag=1;


                                Random_Thuc(B,m);
                                check=1;

                                cout<<"Da nhap tu dong 2 mang vao may"<<endl;
                                break;
                            }
                        default:
                            {
                                cout<<"Tinh nang khong ton tai"<<endl;
                                break;
                            }
                    }
                    break;
                }
            case 4:
                {
                    int xuat;
                        cout<<"Chon cau de xuat: "<<endl;
                        cout<<"Cau (1): Mang A"<<endl;
                        cout<<"Cau (2): Mang B"<<endl;
                        cout<<"Chon (0) de xuat ca hai: ";
                        cin>>xuat;
                    switch(xuat)
                    {
                        case 1:
                        {
                            if(flag)
                            {
                                OutPut(A,n);
                                cout<<endl;
                            }
                            else
                            {
                                cout<<"Nhap cau (1) truoc."<<endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(check)
                            {
                                OutPut(B,m);
                                cout<<endl;
                            }
                            else
                            {
                                cout<<"Nhap cau (2) truoc."<<endl;
                            }
                            break;
                        }
                        case 0:
                        {
                            if(flag==1 && check==1)
                            {
                                OutPut(A,n);
                                cout<<endl;
                                OutPut(B,m);
                                cout<<endl;
                            }
                            else
                            {
                                cout<<"Nhap cau (1) va (2) truoc."<<endl;
                            }
                            break;
                        }
                        default:
                            cout<<"Cau khong ton tai:"<<endl;
                    }
                    break;
                }
            case 2:
                {
                    int SS;
                        cout<<"Chon cau de sap xep truc tiep: "<<endl;
                        cout<<"Cau (1): Mang A"<<endl;
                        cout<<"Cau (2): Mang B"<<endl;
                        cin>>SS;
                    switch(SS)
                    {
                        case 1:
                        {
                            if(!fin)
                            {
                                if(flag)
                                {
                                    cout<<"Sap xep truc tiep cho mang A:"<<endl;
                                    SelectionSort(A,n);
                                    OutPut(A,n);


                                    cout<<endl<<endl;


                                    cout<<"SelectionSort::Time Process: "<<Time_Process_SS(A,n);
                                    fin=true;
                                }
                                else
                                {
                                    cout<<"Nhap cau (1) truoc."<<endl;
                                }
                            }
                            else cout<<"Mang A da duoc sap xep truoc do"<<endl;
                            break;
                        }
                        case 2:
                        {
                            if(!comp)
                            {
                                if(check)
                                {
                                    cout<<"Sap xep truc tiep cho mang B:"<<endl;
                                    SelectionSort(B,m);
                                    OutPut(B,m);

                                    cout<<endl<<endl;

                                    cout<<"SelectionSort::Time Process: "<<Time_Process_SS(B,m);
                                    comp=true;
                                }
                                else
                                {
                                    cout<<"Nhap cau (2) truoc."<<endl;
                                }
                            }
                            else cout<<"Mang B da duoc sap xep truoc do"<<endl;
                            break;
                        }
                        default:
                            cout<<"Cau khong ton tai:"<<endl;
                    }
                    break;
                }
            case 3:
                {
                    int IS;
                        cout<<"Chon cau de sap xep chen: "<<endl;
                        cout<<"Cau (1): Mang A"<<endl;
                        cout<<"Cau (2): Mang B"<<endl;
                        cin>>IS;
                    switch(IS)
                    {
                        case 1:
                        {
                            if(!fin)
                            {
                                if(flag)
                                {
                                    cout<<"Sap xep chen cho mang A:"<<endl;
                                    InsertionSort(A,n);
                                    OutPut(A,n);

                                    cout<<endl<<endl;

                                    cout<<"InsertionSort::Time Process: "<<Time_Process_IS(A,n);
                                    fin=true;
                                }
                                else
                                {
                                    cout<<"Nhap cau (1) truoc."<<endl;
                                }
                            }
                            else cout<<"Mang A da duoc sap xep truoc do."<<endl;
                            break;
                        }
                        case 2:
                        {
                            if(!comp)
                            {
                                if(check)
                                {
                                    cout<<"Sap xep chen cho mang B:"<<endl;
                                    InsertionSort(B,m);
                                    OutPut(B,m);

                                    cout<<endl<<endl;

                                    cout<<"InsertionSort::Time Process: "<<Time_Process_IS(B,m);
                                    comp=true;
                                }
                                else
                                {
                                    cout<<"Nhap cau (2) truoc."<<endl;
                                }
                            }
                            else cout<<"Mang B da duoc sap xep truoc do."<<endl;
                            break;
                        }
                        default:
                            {
                                cout<<"Cau khong ton tai:"<<endl;
                                break;
                            }
                    }
                    break;
                }
            case 5:
                {
                return 0;
                break;
                }
        default:
            cout<<"Tinh nang khong ton tai";
        }
    }
    return 0;
}

void Random_Thuc(double A[],int &n)
{
    int Max_Rand=rand()%MAX2;
    n=100000;
    for(int i=0;i<n;i++)
    {
        A[i]=rand()+(rand()/(double)Max_Rand);
    }
}

void OutPut(double A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}

void SelectionSort(double A[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        int m = i;
        for (int j=i+1;j<n;j++)
        {
            if (A[j] < A[m])
            {
                m = j;
            }
        }
        swap(A[i],A[m]);
    }
}

void InsertionSort(double A[],int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i-1;

        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
    }
}

float Time_Process_IS(double A[],int n)
{
    clock_t Start,End;
    double cpu_time_used;

    Start=clock();
        InsertionSort(A,n);
    End=clock();

    cpu_time_used=((double) (End - Start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

float Time_Process_SS(double A[],int n)
{
    clock_t Start,End;
    double cpu_time_used;

    Start=clock();
        SelectionSort(A,n);
    End=clock();

    cpu_time_used=((double) (End - Start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

#include<iostream>
#include<time.h>
#include<algorithm>

using namespace std;

#define MAX1 10e6
#define MAX2 100000

double A[(int)MAX1];
double B[(int)MAX1];
double C[(int)MAX1];
double D[(int)MAX1];

void Random_Thuc(double a[],int &n)
{
    int Max_Rand=rand()%MAX2;
    for(int i=0;i<n;i++)
    {
        a[i]=rand()+(rand()/(double)Max_Rand);
    }
}

void OutPut(double a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

void Convert(double a[],double b[],int &n)
{
    double temp;
    for(int i=0;i<n;i++)
    {
        temp=a[i];
        b[i]=temp;
    }
}

int Partition(double x[],int low,int high)
{
    int pivot=x[high];
    int left=low;
    int right=high-1;
    while(true){
        while(left<=right && x[left]<pivot)
            left++;
        while(right>=left && x[right]>pivot)
            right--;
        if(left>=right)
            break;
        swap(x[left],x[right]);
        left++;
        right--;
    }
    swap(x[left],x[high]);
    return left;
}

void QuickSort(double x[], int low, int high)
{
    if(low<high)
    {
        int pi=Partition(x,low,high);

        QuickSort(x,low,pi-1);
        QuickSort(x,pi+1,high);
    }
}

void Merge(double a[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

// Create 2 halves arrays
    int L[n1],R[n2];

// Copy data into 2 arrays L[] and R[]

    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[m+1+j];

// Merge both arrays into 1 array

    i=0; // First Subarray S1[i]
    j=0; // Second Subarray S2[j]
    k=l; // Merge Subarray a[k]
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void MergeSort(double a[],int l,int r)
{
    if(l<r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m=l+(r-l)/2;

        // Sort first and second halves
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);

        Merge(a, l, m, r);
    }
}

void Heapify(double a[],int n,int i)
{
    int largest=i; // Initialize largest as root
    int l=2*i+1; // left = 2*i + 1
    int r=2*i+2; // right = 2*i + 2

    // If left child is larger than root
    if(l<n && a[l]>a[largest])
        largest=l;

    // If right child is larger than largest so far
    if(r<n && a[r]>a[largest])
        largest=r;

    // If largest is not root
    if(largest!=i)
    {
        swap(a[i],a[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(a,n,largest);
    }
}

// main function to do heap sort
void HeapSort(double a[],int n)
{
    // Build heap (rearrange array)
    for(int i=n/2-1;i>=0;i--)
        Heapify(a,n,i);

    // One by one extract an element from heap
    for(int i=n-1;i>0;i--)
    {
        // Move current root to end
        swap(a[0],a[i]);

        // call max heapify on the reduced heap
        Heapify(a,i,0);
    }
}

float Time_Process_HS(double a[],int n)
{
    clock_t Start,End;
    double cpu_time_used;

    Start=clock();
        HeapSort(a,n);
    End=clock();

    cpu_time_used=((double) (End - Start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

float Time_Process_MS(double a[],int n)
{
    clock_t Start,End;
    double cpu_time_used;

    Start=clock();
        MergeSort(a,0,n-1);
    End=clock();

    cpu_time_used=((double) (End - Start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

float Time_Process_QS(double a[],int n)
{
    clock_t Start,End;
    double cpu_time_used;

    Start=clock();
        QuickSort(a,0,n-1);
    End=clock();

    cpu_time_used=((double) (End - Start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

float Time_Process_CSort(double a[],int n)
{
    clock_t Start,End;
    double cpu_time_used;

    Start=clock();
        std::sort(a,a+n);
    End=clock();

    cpu_time_used=((double) (End - Start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}


int main()
{
    int n=100000;

    cout<<"19521587_Tran Tien Hung_ BTLon"<<endl;
    cout<<"Khao sat thoi gian cua tung giai thuat Sort"<<endl<<endl;

    cout<<"|=============================================================================================|"<<endl;
    cout<<"|     Database     |     QuickSort     |     HeapSort     |     MergeSort     |     CSort     |"<<endl;
    cout<<"|=============================================================================================|"<<endl;
    for(int i=0;i<15;i++)
    {
        Random_Thuc(A,n);
        Random_Thuc(B,n);
        Random_Thuc(C,n);
        Random_Thuc(D,n);
        QuickSort(A,0,n-1);
        HeapSort(B,n);
        MergeSort(C,0,n-1);
        std::sort(D,D+n);
        cout<<"|     Database "<<i+1<<"     |     "<<Time_Process_QS(A,n)<<"     |     "<<Time_Process_HS(B,n)<<"      |      "<<Time_Process_MS(C,n)<<"     |     |"<<Time_Process_CSort(D,n)<<"      |"<<endl;
    }
    cout<<"|=============================================================================================|"<<endl;
}

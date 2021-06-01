#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAX1 100

struct Stack
{
    char Name;
    int A[MAX1];
    int top;
};

void Create_Stack(Stack &s)
{
    cout<<"Nhap ten Stack: ";
    cin>>s.Name;
    s.top=-1;
}

bool IsEmpty_Stack(Stack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}

bool IsFull_Stack(Stack s)
{
    if(s.top>=MAX1)
        return 1;
    return 0;
}

int Top_Stack(Stack &s)
{
    return s.A[s.top];
}

void Push_Stack(Stack &s,int n)
{
	if(IsFull_Stack(s)==0)
	{
        for(int i=0;i<n;i++)
        {
            s.A[++s.top]=n-i;
        }
//		cout<<x<<" pushed into stack"<<endl;
	}
	else cout<<"Stack is full"<<endl;
}

void PushX_Stack(Stack &s,int x)
{
	if(IsFull_Stack(s)==0)
	{
        s.A[++s.top]=x;
//		cout<<x<<" pushed into stack"<<endl;
	}
	else cout<<"Stack is full"<<endl;
}

void Pop_Stack(Stack &s,int &x)
{
	if(IsEmpty_Stack(s)==0)
	{
        x=s.A[s.top--];
	}
	else cout<<"Stack is empty"<<endl;
}

void OutPut_Stack(Stack s)
{
    cout<<"Stack "<<s.Name<<": <";
    for(int i=0;i<s.top+1;i++)
        cout<<"\t"<<s.A[i]<<"\t";
    cout<<">Top"<<endl;
}

bool IsDes(Stack s,int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(s.A[i]<s.A[i+1]) return false;
    }
    return true;
}

int main()
{
    int n,tang;
    int chon;
    int check=0;
    int dem=0;


    Stack A,B,C;

    cout<<"19521587_TRAN TIEN HUNG_Buoi#5_BT_TowerOfHanoi"<<endl<<endl;

    Create_Stack(A);
    Create_Stack(B);
    Create_Stack(C);

    while(true)
    {
    cout<<endl;
    cout<<"             DEMO TOWER OF HANOI             "<<endl;
    cout<<"#1: Create Tower"<<endl;
    cout<<"#2: "<<A.Name<<" -> "<<B.Name<<endl;        // 1 -> 2
    cout<<"#3: "<<A.Name<<" -> "<<C.Name<<endl;        // 1 -> 3
    cout<<"#4: "<<B.Name<<" -> "<<A.Name<<endl;        // 2 -> 1
    cout<<"#5: "<<B.Name<<" -> "<<C.Name<<endl;        // 2 -> 3
    cout<<"#6: "<<C.Name<<" -> "<<A.Name<<endl;        // 3 -> 1
    cout<<"#7: "<<C.Name<<" -> "<<B.Name<<endl;        // 3 -> 2
    cout<<"#8: Check Win"<<endl;
    cout<<"#9: Thoat"<<endl;
    cout<<"Choose Option: ";
    cin>>chon;
    cout<<endl;
    switch(chon)
    {
    case 1:
        {
            if(A.A[A.top]!=1)
            {
                cout<<"Input Stack Level: ";
                cin>>tang;
                check=1;
                cout<<endl;


                Push_Stack(A,tang);


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
            else
            {
                cout<<"Stack "<<A.Name<<" has been created"<<endl;

                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
            break;
        }
    case 2:                     //A -> B
        {
        if(check)
        {
            if(A.A[A.top]>B.A[B.top])
            {
                cout<<"Pham vi luat cua tro choi"<<endl<<endl;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
            else
            {
                PushX_Stack(B,A.A[A.top]);
                Pop_Stack(A,n);


                dem++;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
        }
        else cout<<"Nhap cau 1 truoc"<<endl;
            break;
        }
    case 3:                     //A -> C
        {
        if(check)
        {
            if(A.A[A.top]>C.A[C.top])
            {
                cout<<"Pham vi luat cua tro choi"<<endl<<endl;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
            else
            {
                PushX_Stack(C,A.A[A.top]);
                Pop_Stack(A,n);


                dem++;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
        }
        else cout<<"Nhap cau 1 truoc"<<endl;
        break;
        }
    case 4:                    //B -> A
        {
        if(check)
        {
            if(B.A[B.top]>A.A[A.top])
            {
                cout<<"Pham vi luat cua tro choi"<<endl<<endl;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
            else
            {
                PushX_Stack(A,B.A[B.top]);
                Pop_Stack(B,n);


                dem++;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
        }
        else cout<<"Nhap cau 1 truoc"<<endl;
        break;
        }
    case 5:                     //B -> C
        {
        if(check)
        {
            if(B.A[B.top]>C.A[C.top])
            {
                cout<<"Pham vi luat cua tro choi"<<endl<<endl;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
            else
            {
                PushX_Stack(C,B.A[B.top]);
                Pop_Stack(B,n);


                dem++;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
        }
        else cout<<"Nhap cau 1 truoc"<<endl;
        break;
        }
    case 6:                     //C -> A
        {
        if(check)
        {
            if(C.A[C.top]>A.A[A.top])
            {
                cout<<"Pham vi luat cua tro choi"<<endl<<endl;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
            else
            {
                PushX_Stack(A,C.A[C.top]);
                Pop_Stack(C,n);


                dem++;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
        }
        else cout<<"Nhap cau 1 truoc"<<endl;
        break;
        }
    case 7:                     //C -> B
        {
        if(check)
        {
            if(C.A[C.top]>B.A[B.top])
            {
                cout<<"Pham vi luat cua tro choi"<<endl<<endl;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
            else
            {
                PushX_Stack(B,C.A[C.top]);
                Pop_Stack(C,n);


                dem++;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
        }
        else cout<<"Nhap cau 1 truoc"<<endl;
        break;
        }
    case 8:
        {
        if(check)
        {
            if(IsDes(C,tang))
            {
                cout<<"YOU WON"<<endl;
                cout<<"Your moves: "<<dem<<endl;
                return 0;
            }
            else
            {
                cout<<"TRY AGAIN"<<endl;


                OutPut_Stack(A);
                cout<<endl;
                OutPut_Stack(B);
                cout<<endl;
                OutPut_Stack(C);
                cout<<endl;
            }
        }
        else cout<<"Nhap cau 1 truoc"<<endl;
        break;
        }
    case 9:
        {
            return 0;
        }
    default:
        {
            cout<<"Tinh nang khong ton tai";
            break;
        }
    }
    }
}

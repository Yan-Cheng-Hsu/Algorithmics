#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

void PrintTriangle(int height)
{

    for(int i=height;i>0;i--)
    {
        for(int j=i;j>0;j--)cout<<" ";
        for(int j=height-i+1;j>=2;j--)cout<<j;
        cout<<"1";
        for(int j=2;j<=height-i+1;j++)cout<<j;
        for(int j=i+1;j>0;j--)cout<<" ";
        cout<<endl;
    }
    
    return;
}

void PrintBigTriangle(int height)
{
    for(int k=height;k>0;k--)
    {
        
        for(int i=height;i>0;i--)
        {
            for(int j=height*(k-1);j>0;j--)cout<<" ";
            for(int j=height-k+1;j>0;j--)
            {
                for(int j=i-1;j>0;j--)cout<<" ";
                for(int j=height-i+1;j>=2;j--)cout<<j;
                cout<<"1";
                for(int j=2;j<=height-i+1;j++)cout<<j;
                for(int j=i;j>0;j--)cout<<" ";
                
            }
            cout<<endl;
        }
    }
    return;
}


int main(void)
{
    cout<<"input the height:"<<endl;
    int h;
    cin>>h;
    PrintBigTriangle(h);
    system("pause");
    return 0;
}

/*




*/
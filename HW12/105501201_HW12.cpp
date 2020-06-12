#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

typedef signed long long int sll_int;

class Solution
{
    public:
        void GCD_HW12();
        void OS_HW12();
        void P_HW12();
        void PD_HW12();
};



void Solution::GCD_HW12()
{
    vector<int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int in1;
        cin>>in1;
        int in2;
        cin>>in2;
        
        while( ( in1 != 0 ) && ( in2 != 0 ) )
        {
            if( in1 >= in2 )
                in1 = in1 % in2;
            else
                in2 = in2 % in1;
        }   

        if( in1 != 0 )
            O.push_back( in1 );
        else
            O.push_back( in2 );

    }

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;

    return;
}


void Solution::OS_HW12()
{
    vector<int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int start;
        cin>>start;
        int end;
        cin>>end;

        if( ( start%2 != 0 ) && ( end%2 != 0 ) )
            O.push_back( ( start + end )*( (end - start)/2 +1 )/2 );
        else if( ( start%2 == 0 ) && ( end%2 != 0 ) )
        {
            start++;
            O.push_back( ( start + end )*( (end - start)/2 +1 )/2 );
        }
        else
        {
            start++;
            end--;
            O.push_back( ( start + end )*( (end - start)/2 +1 )/2 );
        }
        
    }

    for(int i=0;i<O.size();i++)
        cout<<"Case "<<i+1<<": "<<O[i]<<endl;

    return;
}

void Solution::P_HW12()
{
    vector<int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int in1;
        cin>>in1;
        int in2;
        cin>>in2;
        
        int sum = in1; 

        while( in1 >= in2 )
        {
            sum = sum + (in1 / in2);
            in1 = (in1/in2) + (in1%in2);
        }
        

        O.push_back( sum );

    }
    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;


    return;
}

void Solution::PD_HW12()
{
    vector<sll_int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;

        vector<int> d;
        int j = 9;
        while( j > 1 )
        {
            if( num%j == 0 )
            {
                num = num / j;
                d.push_back( j );
            }
            else
                j--;
            
        }

        if( num == 1 )
        {
            sll_int sum = 0;
            sll_int pow = 1;
            for(int k=0;k<d.size();k++)
            {
                sum = sum + pow*d[k]; 
                pow = pow * 10;
            }
            O.push_back( sum );
        }
        else
            O.push_back( -1 );
        
    }

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;

    return;
}


void test()
{
    Solution S;
    S.PD_HW12();
    return;
}


int main(void)
{
    test();
    return 0;
}
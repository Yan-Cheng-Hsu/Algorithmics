#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;



class Solution
{
    public:
        void GCD_HW12();
        void OS_HW12();
        void P_HW12();
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

        O.push_back( ( start + end )*( (end - start)/2 +1 )/2 );
    }

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;

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




void test()
{
    Solution S;
    S.P_HW12();
    return;
}


int main(void)
{
    test();
    return 0;
}
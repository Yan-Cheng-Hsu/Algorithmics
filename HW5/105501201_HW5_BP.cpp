#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


class Solution
{
    public:
        void BP_HW5();
};

void Solution::BP_HW5()
{
    int n;
    cin>>n;

    double capacity = 1;
    vector<double> trash;

    for(int i=0;i<n;i++)
    {
        double in;
        cin>>in;
        trash.push_back( in );
    }

    sort( trash.begin() , trash.end() );

    int BinNum = 1;
    double state = trash[0];

    for(int i=1;i<trash.size();i++)
    {
        if( (state + trash[i]) <= capacity )
            state = state + trash[i];
        else
        {
            BinNum++;
            state = 0;
            state = state + trash[i];
        }
    }

    cout<<BinNum;


    return;
}

void test()
{
    Solution S;
    S.BP_HW5();
    return;
}


int main(void)
{
    test();
    return 0;
}
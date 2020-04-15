#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


class Solution
{
    public:
        void Kth_smallest_HW4();
        void Max_subarray_HW4();
};


void Solution::Kth_smallest_HW4()
{

    vector<int> Output;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {   
        vector<int> gradeList;
        for(int j=0;j<20;j++)
        {
            int grade;
            cin>>grade;
            gradeList.push_back( grade );
        }

        int K;
        cin>>K;

        sort( gradeList.begin() , gradeList.end() );

        Output.push_back( gradeList[K-1] );

    }    

    for(int i=0;i<Output.size();i++)
        cout<<Output[i]<<endl;




    return;
}


void Solution::Max_subarray_HW4()
{
    vector<int> Output;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        vector<int> Arr;
        int size;
        cin>>size;

        for(int j=0;j<size;j++)
        {
            int num;
            cin>>num;
            Arr.push_back( num );
        }


        int max = -2147483648;

        for(int x=0;x<size;x++)
        {
            int sum = 0;
            for(int y=x;y<size;y++)
            {
                sum = sum + Arr[y];
                if( sum > max )
                    max = sum;
            }
        }

        Output.push_back( max );

    }

    for(int i=0;i<Output.size();i++)
        cout<<Output[i]<<endl;


    return;
}

void test()
{
    Solution S;
    S.Max_subarray_HW4();
    return;
}

int main(void)
{
    test();
    return 0;
}
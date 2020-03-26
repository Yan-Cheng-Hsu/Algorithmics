#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//Class Declaration
class Solution;

//Function Calls Declaration
void test_Fib();


class Solution
{
    public:
        void HW3_Fib();
        void HW3_Sequence();
    private:
        bool isEqual( vector<int> NumList , int sum , int startIndex );
};

void Solution::HW3_Fib()
{
    vector<int> TermList;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int term;
        cin>>term;
        if( term == 0 )
            TermList.push_back( 0 );
        else if( (term == 1) || (term == 2) )
            TermList.push_back( 1 );
        else
        {
            int j = 3;
            int termN_1 = 1;
            int termN_2 = 1;
            int termN = 0;
            while( j <= term )
            {
                termN = termN_1 + termN_2;
                termN_2 = termN_1;
                termN_1 = termN;
                j++;
            }
            TermList.push_back( termN );
        }
        
    }

    for(int k=0;k<TermList.size();k++)
        cout<<TermList[k]<<endl;

    return;
}

void Solution::HW3_Sequence()
{
    vector<string> Output;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int NumofTerm;
        cin>>NumofTerm;
        vector<int> NumList;
        for(int j=0;j<NumofTerm;j++)
        {
            int Num;
            cin>>Num;
            NumList.push_back(Num);
        }

        int counter = 0;

        for(int x=0;x<NumofTerm;x++)
        {
            for(int y=x+1;y<NumofTerm;y++)
            {
                int sum = NumList[x] + NumList[y];
                if( isEqual( NumList , sum , y ) )
                    counter++;
            }
        }

        if( counter != 0 )
            Output.push_back( "false" );
        else
            Output.push_back( "true" );
        


    }
    
    for(int w=0;w<n;w++)
        cout<<Output[w]<<endl;


    return;
}


bool Solution::isEqual( vector<int> NumList , int sum , int startIndex )
{
    for(int z=startIndex;z<NumList.size();z++)
    {
        if( sum == NumList[z] )
            return true;
    }
    return false;
}




void test_Fib()
{
    Solution S;
    S.HW3_Fib();
    return;
}
void test_Sequence()
{   
    Solution S;
    S.HW3_Sequence();
    return;
}


int main(void)
{
    test_Sequence();
    return 0;
}


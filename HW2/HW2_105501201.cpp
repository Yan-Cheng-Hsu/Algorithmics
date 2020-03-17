#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<vector>
using namespace std;


typedef unsigned long long int ull_int;

int Euler(int n);

class Solution
{
    public:
        void Age_Sort();
        void EulerFunction();
        void JandOddNum();
};



void Solution::Age_Sort()
{
    int numofPeople;
    cin>>numofPeople;
    

    while( numofPeople != 0 )
    {
        vector<int> AgeList;
        for(int i=0;i<numofPeople;i++)
        {
            int age;
            cin>>age;
            AgeList.push_back(age);
        }
        
        sort( AgeList.begin() , AgeList.end() );

        for(int j=0;j<AgeList.size();j++)
        {
            if( j != ( AgeList.size() - 1 ) )
                cout<<AgeList[j]<<" ";
            else 
                cout<<AgeList[j];
        }
        cout<<endl;
        cin>>numofPeople;
    }

    return;
}








void Solution::EulerFunction()
{
    vector<int> EulerReturn;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int TargetNum;
        cin>>TargetNum;
        EulerReturn.push_back( Euler( TargetNum ) );
    }
    for(int k=0;k<EulerReturn.size();k++)
    {
        if( k != ( EulerReturn.size() - 1 ) )
            cout<<EulerReturn[k]<<endl;
        else
            cout<<EulerReturn[k];
    }

    return;
}


void Solution::JandOddNum()
{
    ull_int input;
    while( cin>>input )
    {
        ull_int StartNumofIndex = 1;
        for(int i=1;i<input;i=i+2)
            StartNumofIndex = StartNumofIndex + i;
        ull_int StartNumofCol = 1 + 2*( StartNumofIndex - 1 );
        ull_int EndNumofCol = StartNumofCol + 2*( input - 1 );

        ull_int sum = 0;
        for(int i=0;i<5;i=i+2)
            sum = sum + EndNumofCol - i;
        cout<<sum<<endl;
    }

    return;
}



int Euler(int n)   
{
    int rea = n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            rea = rea- ( rea / i );
           while(n%i==0)
           {
                n = n / i;
           }
        }
    }
    if(n>1)
        rea = rea - rea / n ;
    return rea;

}



void test1()
{
    Solution S;
    S.Age_Sort();
    return;
}

void test2()
{
    Solution S;
    S.EulerFunction();
    
    return;
}
void test3()
{
    Solution S;
    S.JandOddNum();

    return;
}


int main(void)
{
    test3();

    return 0;
}
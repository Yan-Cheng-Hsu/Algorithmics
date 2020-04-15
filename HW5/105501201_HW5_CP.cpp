#include<iostream>
#include<stdio.h>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;




class Solution
{
    public:
        void CP_HW5();

};

class Term
{
    public:
        Term( double x = 0 , double y = 0 )
        {
            this -> x = x;
            this -> y = y;
        }
    public:
        double x;
        double y;
};



void Solution::CP_HW5()
{
    vector<double> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int numofPair;
        cin>>numofPair;
        vector<Term> TermList;
        for(int j=0;j<numofPair;j++)
        {
            double x;
            cin>>x;
            double y;
            cin>>y;
            Term term( x , y );
            TermList.push_back( term );
        }


        double min=  sqrt( abs( TermList[0].x - TermList[1].x )*abs( TermList[0].x - TermList[1].x ) + abs( TermList[0].y - TermList[1].y )*abs( TermList[0].y - TermList[1].y ) );
        for(int j=0;j<numofPair;j++)
        {
            for(int k=j+1;k<numofPair;k++)
            {
                double d =  sqrt( abs( TermList[j].x - TermList[k].x )*abs( TermList[j].x - TermList[k].x ) + abs( TermList[j].y - TermList[k].y )*abs( TermList[j].y -TermList[k].y ) );
                if( d < min )
                    min = d;
                
            }
        }

        O.push_back( min );

    }

   for(int x=0;x<O.size();x++)
        cout << fixed << setprecision(3) << O[x] <<endl;




    return;
}




void test()
{
    Solution S;
    S.CP_HW5();
    return;
}

int main(void)
{
    test();
    return 0;
}
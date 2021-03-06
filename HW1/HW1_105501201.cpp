#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
//=================Functions Declaration============================================================//
bool isPrime( int n );//Prime Detection
void test1();//test for HW1: Above Average
void test2();//test for HW1: Odd Sum without Prime
void test3();//test for HW1: Prime Factorization
void test3_V2();//test for HW1: Prime Factorization Version.2

//================the Declaration of Solution================================//
class Solution
{
    public:
        void HW1_AboveAverage();
        void HW1_OddSumwithoutPrime();
        void HW1_PrimeFactorization();
        void HW1_PrimeFactorization_V2();
};

//================function Calls of Solution================================//

void Solution::HW1_AboveAverage()
{
    
    int maxLoop;
    cin>>maxLoop;
    double *PercentageList = new double[maxLoop];
    for(int i=0;i<maxLoop;i++)
    {
        double NumofStu;
        cin>>NumofStu;
        double *ScoreList = new double[int(NumofStu)];
        double sum = 0.0;
        for(int j=0;j<int(NumofStu);j++)
        {
            double score;
            cin>>score;
            ScoreList[j] = score;
            sum = sum + score;
        }
        
        
        double AvgScore = sum / NumofStu;
        double AboveAvg = 0.0;
    
        for(int k=0;k<int(NumofStu);k++)
        {
            if( ScoreList[k] >  AvgScore )
                AboveAvg = AboveAvg + 1.0;
        }

        PercentageList[i] =  AboveAvg * 100 / NumofStu;
    }

    for(int x=0;x<maxLoop;x++)
        cout << fixed << setprecision(3) << PercentageList[x] << "%" <<endl;


    return;
}

void Solution::HW1_OddSumwithoutPrime()
{  
    vector<int> sumList;
    int maxLoop;
    cin>>maxLoop;

    for(int i=0;i<maxLoop;i++)
    {
        int Floor;
        cin>>Floor;
        int Ceil;
        cin>>Ceil;
        
        if( ( Floor%2 ) == 0 )
            Floor = Floor + 1;
        
        int sum = 0;

        for(int i=Floor;i<=Ceil;i=i+2)
        {
            if( !( isPrime(i) ) )
                sum = sum + i;
        }

        sumList.push_back( sum );

    }

    for(int i=0;i<sumList.size();i++)
        cout<<sumList[i]<<endl;



    return;
}

void Solution::HW1_PrimeFactorization()
{
    int n;
    cin>>n;    


        vector<int> PrimeFactorList;
        int num = n;
        
        int i = 2;
        while( num > 1 )
        {
            while( (num%i) == 0 )
            {
                //cout<<i<<endl;
                PrimeFactorList.push_back(i);
                num = num / i;
            }
            i++;
        }


        ////print out the results
        cout<<n<<"=";
        /*for(int i=0;i<PrimeFactorList.size();i++)
        {   
            if( i != ( PrimeFactorList.size() - 1 )  )
                cout<<PrimeFactorList[i]<<" ";
            else
                cout<<PrimeFactorList[i];
            
        }*/
        
        int counter = 1;

        if( PrimeFactorList.size() == 1 )
            cout<<PrimeFactorList[0]<<endl;
        else
        {

            for(int i=1;i<PrimeFactorList.size();i++)
            {
                if( (PrimeFactorList[i] == PrimeFactorList[i-1]) && (i == PrimeFactorList.size() - 1) )
                {
                    counter++;
                    cout<<PrimeFactorList[i-1]<<"^"<<counter;
                }
                else if( PrimeFactorList[i] == PrimeFactorList[i-1] )
                {
                    counter++;
                }
                else if( (PrimeFactorList[i] != PrimeFactorList[i-1]) && (i == PrimeFactorList.size() - 1) )
                {
                    if( counter > 1 )
                        cout<<PrimeFactorList[i-1]<<"^"<<counter<<"*";
                    else 
                        cout<<PrimeFactorList[i-1]<<"*";
                    counter = 1;
                    cout<<PrimeFactorList[i];
                }
                else
                {
                    if ( counter > 1 )
                        cout<<PrimeFactorList[i-1]<<"^"<<counter<<"*";
                    else 
                        cout<<PrimeFactorList[i-1]<<"*";
                    counter = 1;
                }
            }

        }
        //cout<<endl;
    
    

        

    return;
}


void Solution::HW1_PrimeFactorization_V2()
{
    int n;
    cin>>n;    

    cout<<n<<"=";

    int num = n;
    int i = 2;
    while( num > 1 )
    {
        int counter = 0;
        while(1)
        {   
            if( (num%i) != 0 )
            {   
                if( counter == 0 )
                    break;
                else
                {
                    if( num == 1 )
                    {
                        if( counter = 1 )
                        {
                            cout<<i;
                            break;
                        }
                        else
                        {
                            cout<<i<<"^"<<counter;
                            break;
                        }
                    }
                    else
                    {
                        if( counter == 1)
                        {
                            cout<<i<<"*";
                            break;
                        }
                        else
                        {
                            cout<<i<<"^"<<counter<<"*";
                            break;
                        }
                    }                    
                }
            }
            else
            {
                num = num / i;
                counter++;
                continue;
            }
            
        }
        i++;
    }
    
    return;
}



//=================Function Call====================================================================//
bool isPrime( int n )
{
    if( n<2 ) return false;

    //int Length = int( floor( sqrt( float(n) ) )+1);
    for(int i=2;i<n;i++ )
    {
        if( ( n%i ) == 0  )
            return false; 
    }

    return true;
}


void test1()
{
    Solution S;
    S.HW1_AboveAverage();
    return;
}

void test2()
{
    Solution S;
    S.HW1_OddSumwithoutPrime();
    return;
}

void test3()
{
    Solution S;
    S.HW1_PrimeFactorization();
    return;
}

void test3_V2()
{
    Solution S;
    S.HW1_PrimeFactorization_V2();
    return;
}



int main(void)
{

    
    test3_V2();

    system( "pause" );
    return 0;
}
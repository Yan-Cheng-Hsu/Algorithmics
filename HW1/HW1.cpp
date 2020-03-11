#include<iostream>
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

//================the Declaration of Term and PrimeFactor================================//
class PrimeFactor;
class Term
{
	friend class PrimeFactor;
	public:
		Term( int coef = 0, int exp = 0, Term *link = 0 )
		{
			this -> coef = coef;
			this -> exp = exp;
			this -> link = link; 
		}
	public:
		int coef;
		int exp;
		Term *link;	
};

class PrimeFactor
{
	friend ostream &operator<<(ostream &output, const PrimeFactor &new_one);
	public:
		PrimeFactor( Term *Head = NULL , Term *Rear = NULL )
		{
			this-> Head = Head;
			this-> Rear = Rear;
		}
		void Addnode(int coef, int exp);
    public:
        Term *Head;
        Term *Rear;
};

//================the Declaration of Solution================================//
class Solution
{
    public:
        void HW1_AboveAverage();
        vector<int> HW1_OddSumwithoutPrime();
        vector<int> HW1_PrimeFactorization();
};




//================function Calls of Term and PrimeFactor================================//
void PrimeFactor::Addnode(int coef, int exp)
{
	
	if( coef == 0 )
		return;
	else
	{
		if( Head )
		{
			Term *new_term=new Term( coef , exp );
			Rear -> link = new_term;
			new_term -> link = NULL;
			Rear = new_term;
		}
		else
		{
			Term *new_term = new Term( coef , exp );
			new_term -> link = NULL;
			Head = Rear = new_term;
		}
	}
    return;
}


ostream &operator<<( ostream &output, PrimeFactor &new_one )
{
    Term *current = new_one.Head;
    while( current != 0)
    {
        if( ( current->link ) != 0 )
            output<< ( current-> coef ) << "^" << ( current -> exp ) << "*";
        else 
            output<< ( current-> coef ) << "^" << ( current -> exp );
        current = current -> link;
    }
    return output;
}


//================function Calls of Solution================================//

void Solution::HW1_AboveAverage()
{
    return;
}

vector<int> Solution::HW1_OddSumwithoutPrime()
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

    return sumList;

}

vector<int> Solution::HW1_PrimeFactorization()
{
    vector<int> PrimeFactorList;

    int n;
    cin>>n;
    int num = n;
    
    int i = 2;
    while( num > 1 )
    {
        while( (num%i) == 0 )
        {
            if( isPrime(i) )
            {
                PrimeFactorList.push_back(i);
                num = num / i;
            }
        }
        i++;
    }

    /*PrimeFactor Output;
    int counter = 1;
    for(int i=1; i<PrimeFactorList.size();i++)
    {
        if( (PrimeFactorList[i] == PrimeFactorList[i-1]) && (i == PrimeFactorList.size() - 1) )
        {
            counter++;
            Output.Addnode( PrimeFactorList[i-1] , counter );
        }
        else if( PrimeFactorList[i] == PrimeFactorList[i-1] )
            counter++;
        else
        {
            Output.Addnode( PrimeFactorList[i-1] , counter );
            counter = 1;
        }
    }*/



    return PrimeFactorList;
}




//=================Function Call====================================================================//
bool isPrime( int n )
{
    if( n<2 ) return false;

    int Length = int( floor( sqrt( float(n) ) )+1);
    for(int i=2;i<Length;i++ )
    {
        if( ( n%i ) == 0  )
            return false; 
    }

    return true;
}

void test2()
{

    Solution S;
    vector<int> sumList;
    sumList = S.HW1_OddSumwithoutPrime();
    
    for(int i=0;i<sumList.size();i++)
        cout<<sumList[i]<<endl;


    return;
}

void test3()
{
    Solution S;
    vector<int> PrimeFactorList;
    PrimeFactorList = S.HW1_PrimeFactorization();
    int counter = 1;
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
            cout<<PrimeFactorList[i-1]<<"^"<<counter;
            counter = 1;
        }
        else
        {
            cout<<PrimeFactorList[i-1]<<"^"<<counter<<"*";
            counter = 1;
        }
        
        

    }
    /*for(int i=0;i<PrimeFactorList.size();i++)
        cout<< PrimeFactorList[i]<<" ";
    cout<<endl;*/

    return;
}





int main(void)
{

    test3();
    system( "pause" );
    return 0;
}
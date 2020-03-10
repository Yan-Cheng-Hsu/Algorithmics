#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

//PROBLEM:
/*
Write a program to determine whether an integer n (n > 2) is a prime.

if (n is a prime)
    return true;
else 
    return false;

*/



/*

Pseudo code for Solution to Prime Detection

Input: an arbitrary integer n (n > 2) 
Output: true or false





*/


class SolutionforHW1
{
    public:
        SolutionforHW1( int n = 0 )
        {
            this -> n = n;
            this -> LengthofnumList = int( ceil( sqrt( float(n) ) )+1);
            this -> primeList = new bool[LengthofnumList];
        }
        bool A_PrimeDetection();
        int B_ReturnLargestFactor();
        int C_SumofFactor();
        vector<int> D_HW1(int m);
        bool E_isPerfectNumber();
        bool F_isHappyNumber();
    private:
        int n;
        int LengthofnumList;
        bool *primeList;//to record which numbers (less than n) are factors of n 
        vector<int> factorList;//the factor list counts n itself as a factor of n
};

bool SolutionforHW1::A_PrimeDetection()
{
    
    for(int i=0;i<( this -> LengthofnumList );i++)
    {
        if( i == 0 ) 
            this -> primeList[i] = false;
        else 
            this -> primeList[i] = true;
    }
    
    for(int j=2;j<( this -> LengthofnumList );j++)
    {
        if( this -> primeList[j] )
        {
            if( (n%j) != 0 )
            {
                for(int k=j;k<( this -> LengthofnumList );k=k+j)
                    this -> primeList[k] = false;
            }
        }
    }
    

    int counter = 0;
    for(int i=0;i<( this -> LengthofnumList );i++)
    {
        if(primeList[i])
            counter++;
    }

    if( counter == 1)
        return true;
    else
        return false;

}

int SolutionforHW1::B_ReturnLargestFactor()
{
    int iterator = 0;
    int SecondLargestfactor = 1;

    for(int i=0;i<( this -> LengthofnumList );i++)
    {
        if( this -> primeList[i] )
        {
            
            //n included
            if( i != ( (this -> n)/i) )
            {
                this -> factorList.push_back( i );
                this -> factorList.push_back( (this -> n) / i );
            }
            else //make sure if i is a squre number, we won't push back it twice.
            {
                this -> factorList.push_back( i );
            }

            if( iterator == 1 )
                SecondLargestfactor = (this -> n) / i;

            iterator++;
        }
    }

    sort( this -> factorList.begin() , this -> factorList.end() ); 



    for(int i=0;i<( this -> factorList.size() );i++)
    {  
        if( factorList[i] == factorList[i-1] )
            factorList.erase( factorList.begin() + i );
    }




    return SecondLargestfactor;
}


int SolutionforHW1::C_SumofFactor()
{   
    int sum = 0;

    for(int i=0;i<( this -> factorList.size()-1 );i++)
    {
        cout<<this -> factorList[i]<<"  ";
        sum = sum + factorList[i];
    }    
    return sum;
}



vector<int> SolutionforHW1::D_HW1(int m)
{
    vector<int> temp;
    for(int i=0;i<( this -> factorList.size() );i++ )
    {
        if( (this -> factorList[i] < n) && (this -> factorList[i] > m) )
            temp.push_back( this -> factorList[i] );
    }

    if( temp.empty() )
        temp.push_back(0);
    
    return temp;

}


bool SolutionforHW1::E_isPerfectNumber()
{
    if( (this -> n ) == (this -> C_SumofFactor()) )
        return true;
    else 
        return false;
}


bool SolutionforHW1::F_isHappyNumber()
{
	if (n <= 0)
        return false;
    int temp1 = this -> n;

	while (1)
	{
		int temp = 0;
		while (temp1 > 0)
		{
			temp = temp + int( pow( double(temp1 % 10) , 2.0) );
			temp1 = temp1 / 10;
		}
		if (temp == 1)return true;
		if (temp == 4)return false;
		if (temp == 16)return false;
		if (temp == 37)return false;
		if (temp == 58)return false;
		if (temp == 89)return false;
		if (temp == 145)return false;
		if (temp == 42)return false;
		if (temp == 20)return false;
		temp1 = temp;
	}
	

}



void test()
{
    cout<< "plz input a number: ";
    int n;
    cin>>n;
    SolutionforHW1 S(n);
    if( S.A_PrimeDetection() )
        cout<<"n is a prime."<<endl;
    else
        cout<<"n is not a prime. "<<endl;
    cout<<"the 2end largest factor of "<<n<<" is "<<S.B_ReturnLargestFactor()<<endl;
    cout<<"the sum of the factors ( other than n itself ) is " <<S.C_SumofFactor()<<endl;

    cout<<"plz input the lower bound m: ";
    int m;
    cin>>m;
    vector<int> temp;
    temp = S.D_HW1(m);
    cout<<"the factors of n, which are larger than "<<m<<" but smaller than "<<n<<" are:";
    for( int i=0;i<temp.size();i++ )
        cout<<temp[i]<<" ";
    cout<<endl;


    if( S.E_isPerfectNumber() )
        cout<<"n is a perfect number."<<endl;
    else 
        cout<<"n is not a perfect number."<<endl;
    
    if( S.F_isHappyNumber() )
        cout<<"n is a Happy Number."<<endl;
    else
        cout<<"n is not a Hpper NUmber."<<endl;


}



int main(void)
{

    test(); 
    system( "pause" );
    return 0;
}



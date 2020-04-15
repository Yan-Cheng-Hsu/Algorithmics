#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;



typedef unsigned long long int ull_int;

class Solution
{
    public:
        void RA_HW6();
        ull_int reverse( ull_int x );
};

ull_int Solution::reverse( ull_int x )
{
	ull_int ans = 0;
	while (x)
	{
		ull_int temp = ans * 10 + x % 10;
		if ( temp / 10 != ans )
			return 0;
		ans = temp;
		x /= 10;
	}
	return ans;
}


void Solution::RA_HW6()
{
    vector<ull_int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ull_int num;
        cin>>num;

        num = num + this -> reverse( num );

        ull_int counter = 1;

        while( ( counter < 1000 ) && ( num <= 4294967295 ) )
        {

            ull_int rnum = this -> reverse( num );
            if( rnum == num )
            {
                O.push_back( counter );
                O.push_back( num );
                break;
            }
            else
            {
                num = rnum + num;
                counter++;
            }
            
        }

    }

    for(int i=1;i<O.size();i=i+2)
        cout<<O[i-1]<<" "<<O[i]<<endl;

    return;
}

void test()
{
    Solution S;
    S.RA_HW6();
    return;
}




int main(void)
{
    test();
    return 0;
}

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

void test1();
void test2();
void MergeSort( int TA[] , int SizeofOgArray );
void Merge( int TA[] , int *IndexTable , int i , int j , int SizeofOgArray , int SizeofIndexTable );




void MergeSort( int TA[] , int SizeofOgArray )
{
    
    for(int i=1;i<SizeofOgArray;i=i*2)
    {
        int SizeofIndexTable = int(ceil( double(double(SizeofOgArray)/double(i)) ));
        cout<<"i = "<<i<<"Size of Index Table:"<< SizeofIndexTable <<endl;
        int *IndexTable = new int[SizeofIndexTable];

        for(int x=0;x<SizeofIndexTable;x++)
            IndexTable[x] = x * i;
        for(int x=0;x<SizeofIndexTable;x++)
            cout<<IndexTable[x]<<" ";
        cout<<endl;




        
        for(int j=1;j<SizeofIndexTable;j=j+2)
    
            Merge( TA , IndexTable , i , j , SizeofOgArray , SizeofIndexTable );
        cout<<endl;
    }



    return;
}

void Merge( int TA[] , int *IndexTable , int i , int j , int SizeofOgArray , int SizeofIndexTable )
{
    if( j== (SizeofIndexTable-1) ) // the last round of merge when j is even
    {
        int *tempArray = new int[SizeofOgArray];
        int Index1 = IndexTable[j-1];
        int Index2 = IndexTable[j];

        int IndexforTemp = 0;
        while( ( Index1<IndexTable[j] ) && ( Index2<SizeofOgArray ) )
        {
            
            if( TA[Index1] > TA[Index2] )
            {
                tempArray[IndexforTemp] = TA[Index1];
                Index1++;
            }
            else
            {
                tempArray[IndexforTemp] = TA[Index2];
                cout<<"TA[Index2] = "<<TA[Index2]<<endl;
                Index2++;
                
            }
            IndexforTemp++;
        }
        cout<<"IndexforTemp = "<<IndexforTemp<<endl;
        while( Index1 < IndexTable[j] )
        {
            tempArray[IndexforTemp] = TA[Index1];
            cout<<"TA[Index1] = "<<TA[Index1]<<endl;
            cout<<"tempArray[IndexforTemp] ="<<tempArray[IndexforTemp]<<endl;
            Index1++;
            IndexforTemp++;
            cout<<"============"<<endl; 
        } 
        while( Index2 < SizeofOgArray )
        {
            tempArray[IndexforTemp] = TA[Index2];
            Index2++;
            IndexforTemp++; 
            cout<<"@@@@@@@@@"<<endl;
        }


                
        




        for(int a=0;a<SizeofOgArray;a++)
            TA[a+IndexTable[j-1]] = tempArray[a];
        


        cout<<"tempArray = ";
         for(int b=0;b<SizeofOgArray;b++)
            cout<<tempArray[b]<<" ";
        cout<<endl;

        cout<<"TA = ";
         for(int b=0;b<SizeofOgArray;b++)
            cout<<TA[b]<<" ";
        cout<<endl;

        
        delete[] tempArray;
    }
    else
    {
        int *tempArray = new int[i*2];
        int Index1 = IndexTable[j-1];
        int Index2 = IndexTable[j];
        cout<<"Index1 = "<<Index1<<" "<<"Index2 = "<<Index2<<endl;
        cout<<"TA[Index1] = "<<TA[Index1]<<" "<<"TA[Index2] = "<<TA[Index2]<<endl;

        int IndexforTemp = 0;
        while( (Index1<IndexTable[j]) && (Index2<IndexTable[j+1]) )
        {
            
            if( TA[Index1] > TA[Index2] )
            {
                tempArray[IndexforTemp] = TA[Index1];
                Index1++;
            }
            else
            {
                tempArray[IndexforTemp] = TA[Index2];
                Index2++;
            }
            IndexforTemp++;
        }
        while( Index1<IndexTable[j] )
        {
            tempArray[IndexforTemp] = TA[Index1];
            Index1++;
            IndexforTemp++; 
        } 
        while( Index2<IndexTable[j+1] )
        {
            tempArray[IndexforTemp] = TA[Index2];
            Index2++;
            IndexforTemp++; 
        } 


        cout<<"tempArray = ";
         for(int b=0;b<2*i;b++)
            cout<<tempArray[b]<<" ";
        cout<<endl;

        for(int a=0;a<2*i;a++)
            TA[a+IndexTable[j-1]] = tempArray[a]; 
        
        cout<<"TA = ";
         for(int b=0;b<SizeofOgArray;b++)
            cout<<TA[b]<<" ";
        cout<<endl;

        delete[] tempArray;
    }

    return;
}



void test()
{
    int a[10];

    for(int i=0;i<25;i++)
        a[i] = i;
    
    MergeSort( a , 25 );
    
   for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


int main(void)
{

    test();
    system("pause");
    return 0;
}
      #include <iostream>      using namespace std;

      //This function displays an integer number as 32 bits.      void bitprint(int v)      {            int mask = 1;                          //mask = 00000000000000000000000000000001       mask <<= 31;  //shift left 31 positions: mask = 10000000000000000000000000000000       for (int i=1; i<=32; i++)         { if ((v & mask)==0)   //check the leftmost bit only              cout<<"0";           else              cout<<"1";                     v <<= 1;  //shift left 1 bit
         }       cout<<endl;      }      int main()      {
       //sample testing       int n = 7;
       bitprint(n);             return 0;       }
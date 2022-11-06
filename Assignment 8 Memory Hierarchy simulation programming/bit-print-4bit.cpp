      #include <iostream>      using namespace std;

      //This function displays an integer number as right-most 4 bits.      void bitprint_4bit(int v)      {            int mask = 1;                          //mask = 00000000000000000000000000000001       mask <<= 3;  //shift left 3 positions:   mask = 00000000000000000000000000001000       for (int i=1; i<=4; i++)         { if ((v & mask)==0)   //check the leftmost bit only              cout<<"0";           else              cout<<"1";                     v <<= 1;  //shift left 1 bit
         }       cout<<endl;      }      int main()      {
       //sample testing       int n = 7;
       bitprint_4bit(n);             return 0;       }
#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>
using namespace std;

//Template to address driver function and booth algo function

//1 bit ALU function
//For add/sub
int oneBitALU(int a, int b, int Binv, int car_in) { // 
    int sum = 0, car_out = 0, result = 0;
    if (car_in == 0) { //Carry-in = 0
        if (a == 0 && b == 0) {
            sum = a + b + car_in;
            car_out = 0;
        }
        else if (a == 0 && b == 1) { 
            sum = a + b + car_in;
            car_out = 0;
        }
        else if (a == 1 && b == 0) {
            sum = a + b + car_in;
            car_out = 0;
        }
        else {
            sum = a + b + car_in;
            car_out = 1;
        }
    }

    else { //Carry-in = 1
        if (a == 0 && b == 0) {
            sum = a + b + car_in;
            car_out = 0;
        }
        else if (a == 0 && b == 1) {
            sum = a + b + car_in;
            car_out = 1;
        }
        else if (a == 1 && b == 0) {
            sum = a + b + car_in;
            car_out = 1;
        }
        else {
            sum = a + b + car_in;
            car_out = 1;
        }
    }
    //Binv 
    result = sum + ~Binv;
    return result;
}

//16 bit ALU function
//Needs 1 bit ALU as a subcomponent
int sixteenBitALU(int a, int b) {
    //16 iterations
    int car_in = 0,  Binv = 0;
    for (int i = 0; i < 16; i++) {
        return oneBitALU(a, b, Binv, car_in);
    }
}

//Booth multiplier
//Needs 16 bit ALU as a subcomponent
template <typename T>
T booth(T a, T b) { //a = MD, b = MQ, c = MQ-1
    int prod = 0, cycle_counter = 1111, c = 0; //cy_coun = 4 bits
    long ac = 0000000000000000;
    cin >> cycle_counter; //Read in a 4 digit binary number
    while (cycle_counter >= 0) {
        //Conditionals for MQ
        if ((a == 0 && b == 0) || (a == 1 && b == 1)) sixteenBitALU(a,b);
        else if (a == 0 && b == 1) sixteenBitALU(a, b); //
        //else 
        cout << cycle_counter << endl;
        cycle_counter--;
    }

    ac = ac >> 1; //Bit shifting AC 
    b = b >> 1; //Bit shifting MQ
    c = c >> 1; //Bit shifting MQ-1
    return cycle_counter + " " + a + " " + ac + " " + b + " " + c;
}

//Main implementation
int main() {
    cout << "Simulation programming for Booth’s Multiplier\n";
    int MD = 0, MQ = 0, result = 0;
    cout << "16 bit value for MD:";
    cin >> MD;
    cout << "16 bit value for MQ:";
    cin >> MQ;
    result = booth(MD, MQ);
    cout << result << endl;
}

#include <iostream>
#include <fstream> //For file i/o
//#include <bitset> //For outputting binary numbers (OUTPUT 32 BITS)
#include <string>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

/*
How to use bitset: 
char a = -58;
std::bitset<8> x(a);
std::cout << x << '\n';
*/

class block {
    public:
        bool valid = false;
        int tag;
        int data;
};

//Function to convert from BINARY to DECIMAL
int bin_dec(int n) {
    int num = n, dec = 0, base = 1;
    while (num) {
        int last_dig = num % 10;
        num /= 10;
        dec += last_dig * base;
        base *= 2;
    }
    return dec;
}

//Function to convert from DECIMAL to BINARY (from lecture 4-28)
void dec_bin(int a) {
    int mask = 1;
    mask << 31;
    for (int i = 0; i <= 31; i++) {
        if ((a & mask) == 0) cout << "0";
        else cout << "1";
        a <<= 1;
    }
    cout << endl;
}

/*
Computing offset
offset = A % page_size
*/

//Computing offset
/*
int off(int n) {
    for (int i = 31; i > 15; i--) {
        int offst = 0;
        if (n[i] == 1) offst += pow(2, 31 - i);
        cout << offst << endl;
    }
}
*/

//Initializing memory contents
void mem_init(vector<int>& mem) {
    for (int x : mem) {
        mem.at(x) += 5;
        cout << mem.at(x) << endl;
    }
}

int main() {
    vector<int> reg(8); //vector for register-file
    int cache[8][2]; //2d array for cache
    //vector<vector<int>>
    vector<int> mem(127); //vector for main memory modules
    vector<int> bit(6); //For storing the first 6 bits and computing opcode

    //Starting process of reading the file
    ifstream input;
    input.open("input_file.txt"); //Opening input file
    string line; //Need to read each line in the input file

    //Refer to global-Logic.pdf
    while (getline(input, line)) { //Repeating steps 1-5 for the program logic
        int a = stoi(line); //Convert each line (32 bit value) in the file interpreted as a string to the actual int
        //bitset<32> x(a); //Attempt to convert from decimal to binary
        reg.push_back(a);
        cout << a << endl;
        string opcode = line.substr(0,5); //Try to read first 6 bits in 32 bit value
        int b = stoi(opcode);
        if (bin_dec(b) == 35) cout << "lw\n"; //If opcode is 35, then lw
        else if (bin_dec(b) == 43) cout << "sw\n"; //If opcode is 43, then sw

        string rs = line.substr(6,10); //Reading the next 5 bits after the opcode to get the rs register value
        string rt = line.substr(11,15); //Reading the next 5 bits after rs to get rt
        string offset = line.substr(16, 31); //Reading remaining 16 bits to obtain offset

        //Converting rs, rt, and offset as strings to int form and then to dec form
        int c = stoi(rs);
        int d = stoi(rt);
        int e = stoi(offset);
        //off(e); //Computing the offset
        bin_dec(c);
        bin_dec(d);
        bin_dec(e);

        int byte_addr = c + e; //Computing byte address
        int word_addr = byte_addr / 4; //Computing word address
        int set = word_addr % 8; //Getting cache set #
        int tag = word_addr / 8; //Getting cache tag

        if (input.eof()) break;
        else continue;
    }

    //mem_init(mem); //Initializing vector elements to increment by 5

    cout << endl;
    //Displaying result of register file
    cout << "Registers" << endl;
    for (int x : reg) {
        cout << "$s" << x << ":  " << x << endl;
    }
    cout << endl;
    cout << "Cache Block 0\n";
    cout << endl;
    cout << "Cache Block 1\n";
    cout << endl;
    cout << "Addr\n";
    cout << endl;

    input.close(); //Closing input file
}

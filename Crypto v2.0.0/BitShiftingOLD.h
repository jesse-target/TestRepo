#include <cstdlib>

using namespace std;

// I want to have some cool words...
#define ZERO false
#define ONE true

// I want to have an alphabet
const string    ALPHABET        ="abcdefghijklmnopqrstuvwxyz .,!?\n";
const int       ALPHABET_SIZE   =32;
const int       BYTE_LENGTH     =5;

// I want to have bit 
typedef bool bit;

// I want to have a 5-bit byte

class byte {
    private:
        bit contents [BYTE_LENGTH];
        
    public:
        byte(){}
        
        byte( int a, int b, int c, int d, int e ) {
            contents[0]=a;
            contents[1]=b;
            contents[2]=c;
            contents[3]=d;
            contents[4]=e;
        }
        
        bit operator[] ( int i ) {
            return contents[i];
        }
};

// I want to have a function which converts a character into a byte

byte C2B ( char c ) {
    
    int num=0;
    bool contents[BYTE_LENGTH];
    
    for (num; num<ALPHABET_SIZE; num++) {
        if (ALPHABET[num]==c) {
            break;
        }
    }
    for (int i=BYTE_LENGTH-1; i>=0; i--) { 
        if (num>=pow(2,i)) {
            num-=(int)pow(2,i);
            contents[i]=ONE;
        }
        else
            contents[i]=ZERO;
    }
    
    return byte( contents[0], contents[1], contents[2], contents[3], contents[4] );
}

// I want to have a function which takes a byte and makes a char

char B2C ( byte b ) {
    
    int num=0;
    
    for (int i=0; i<BYTE_LENGTH; i++) {
        if (b[i]==ONE) {
            num+=(int)pow(2,i);
        }
    }
    
    return ALPHABET[num];
}

// I want to have a function which takes an ArrayList of bytes and converts it
// to an ArrayList of bits, with a multiple of 8 bits in it

ArrayList<bit> Bytes2Bits ( ArrayList<byte> l ) {
    
    ArrayList<bit> b;
    
    for (int i=0; i<l.size(); i++) {
        for (int j=0; j<5; j++) {
            b.push( l[i][j] );
        }
    }
    
    do {
        bit r;
        if (rand()%2==0) 
            r=ZERO;
        else
            r=ONE;
        b.push( r );
    } while ( b.size()%8 );
    
    return b;
}

// I want to have a function which takes an ArrayList of bits and converts it
// to an ArrayList of bytes

ArrayList<byte> Bits2Bytes ( ArrayList<bit> l ) {
    
    ArrayList<byte> b;
    
    for (int i=0; i<l.size()-5; i+=5) {
        b.push( *(new byte( l[i], l[i+1], l[i+2], l[i+3], l[i+4] )) );
    }
    
    return b;
}

// I want to have a function which takes an ArrayList of bits and converts it 
// into a string of 8-bit characters
// PRECONDITION: @l is a multiple of 8 long

string B2S ( ArrayList<bit> l ) {
    
    string s;
    
    for (int i=0; i<l.size(); i+=8) {

        unsigned char c=0;
        bit b[8] = { l[i], l[i+1], l[i+2], l[i+3], l[i+4], l[i+5], l[i+6], l[i+7] };
        
        for (int j=0; j<8; j++) {
            if (b[j]==ONE) {
                c+=(char)pow(2,j);
            }
        }
        s+=c;
    }
    
    return s;
}

// I want to have a function which takes a string of 8-bit characters and 
// converts it to an ArrayList of bits

ArrayList<bit> S2B ( string s ) {
    
    ArrayList<bit> b;
    unsigned char c;
    
    for (int i=0; i<s.length(); i++) {
        c=s[i];
        bit a[8];
        for (int j=7; j>=0; j--) { 
            if (c>=pow(2,j)) {
                c-=(int)pow(2,j);
                a[j]=ONE;
            }
            else
                a[j]=ZERO;
        }
        for (int j=0; j<8; j++) {
            b.push( a[j] );
        }                                                                       
    }
    
    return b;
}



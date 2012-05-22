#ifndef _BITSHIFTING_
#define _BITSHIFTING_

#include <cstdlib>

using namespace std;

// I want to have some cool words...
#define ZERO false
#define ONE true       

// I want to have an alphabet
static const int            BYTE_LENGTH     =11;
static const int            ALPHABET_SIZE   =2^BYTE_LENGTH;
static const vector<int>    ALPHABET;

// I want to create an alphabeta
void init_alphabeta( string key ) {
    
    // Generate hash=unique integer via key
    vector<unsigned long> primes=get_primes(ALPHABET_SIZE);
    unsigned long hash=1;
    for (int i=0; i<key.length(); i++) {
        hash*=primes[key-97];
    }
    cout<< "DEBUG+ |HASH| -> " << hash << endl;
    
    // Generate plain alphabet
    for (int i=0; i<2^BYTE_LENGTH; i++) {
        ALPHABET+=i;
    }
    
    // Start Random Number Sequence with Unique Integer...
    srand( hash );
    
    int numSwaps=rand()%3000+1000;
    for( int i=0; i<numSwaps; i++ ){
        
        int index1=rand()%size();
        int index2=rand()%size();
        int temp=ALPHABET[index1];
        ALPHABET[index1]=ALPHABET[index2];
        ALPHABET[index2]=temp;
    }    
}     

// I want to have bit 
typedef bool bit;

// I want to have a 11-bit byte

class byte {
    private:
        bit * contents;
        
    public:
        byte(){}
        
        byte( bit a[BYTE_LENGTH] ) {
            *contents=a;    
        }
        
        bit operator[] ( int i ) {
            return *(contents+i);
        }
};

// I want to have a function which converts a character into a byte

byte C2B ( char c ) {
    
    int num=0;
    bit contents[BYTE_LENGTH];
    
    for (num; num<ALPHABET_SIZE; num++) {
        if (ALPHABET[num]==(int)c) {
            break;
        }
    }
    for (int i=BYTE_LENGTH; i>=0; i--) { 
        if (num>=pow(2,i)) {
            num-=(int)pow(2,i);
            contents[i]=ONE;
        }
        else
            contents[i]=ZERO;
    }
    
    
    return byte( contents );
}

// I want to have a function which takes a byte and makes a char

int B2C ( byte b ) {
    
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
        for (int j=0; j<BYTE_LENGTH; j++) {
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
    
    for (int i=0; i<l.size()-BYTE_LENGTH; i+=BYTE_LENGTH) {
        bit a [BYTE_LENGTH];
		for (int j=0; j<BYTE_LENGTH; j++) { 
			a[j] = l[i+j];
		}
        b.push( a );
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


#endif


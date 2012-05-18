#include <cstdlib>
#include <iostream>
#include <fstream>
#include "math.h"
#include "ArrayList.h"
#include "BitShifting.h"
#include "Blocking.h"
#include "FileHandling.h"
#include "primes.h"

/** Project Description
    
    Author: Cortez the Quazz
    Date:   August 31, 2011
    
    Encryption software is extremely important to protect our ideas and 
    information. With the availability of RSA Encryption our data is extremely
    well protected. At least, for now. If an algorithm can be created to predict
    prime numbers, it will lose its desireability. Thus, new encryption
    software, written creatively and cunningly, will be needed to keep our data 
    safe. Thus, it is my goal to write the software and break primes, which will
    create demand in my product and perhaps lead to a lot of money.
    
*/

                                                                                // MESSAGES
using namespace std;

// I want to have a function which takes my plaintext file and converts it into
// encryptedtext

void encrypt ( string fileName, string destinationFileName, string key ) {
    
    string plainText=F2S( fileName );                                           cout << "Plain text characters inputed........" << plainText.length() << endl;
    ArrayList<byte> byteList;
    
    plainText=reletter( key, plainText );
    
    for (int i=0; i<plainText.length(); i++) {
        byteList.push( C2B( plainText[i] ) );
    }
    
    ArrayList<bit> bitList=Bytes2Bits( byteList );                              
    string encryptedText=B2S(bitList);                                          cout << "Encrypted text characters outputed..." << encryptedText.length() << endl;
    S2F( destinationFileName, encryptedText );
}

// I want to have a function which takes my encryptedtext file and converts it
// into plaintext

void decrypt ( string fileName, string destinationFileName, string key ) {
    
    string encryptedText=F2S( fileName );                                       cout << "Encrypted text characters inputed...." << encryptedText.length() << endl;
    string plainText="";
    
    ArrayList<bit> bitList=S2B( encryptedText );                                
    ArrayList<byte> byteList=Bits2Bytes( bitList );                             
    
    for (int i=0; i<byteList.size(); i++) {
        plainText+=B2C( byteList[i] );
    }
    
    plainText=unreletter( key, plainText );
    
    S2F( destinationFileName, plainText );                                      cout << "Plain text characters outputed......." << plainText.length() << endl;
}
// MAIN FUNCTION ---------------------------------------------------------------

int main(int argc, char *argv[]) {
    
    srand( (unsigned)time(NULL) ); // As per usual when using randoms...
    
    string fileName;
    string destinationFileName;
    string key;
    string operation;
    
                                                                                cout << "Welcome to Crypto...\n";
                                                                                cout << "\n";
                                                                                cout << "Enter file name: ";
                                                                                getline( cin, fileName, '\n' );
                                                                                cout << "Enter destination file name: ";
                                                                                getline( cin, destinationFileName, '\n' );
                                                                                cout << "Enter key: ";
                                                                                getline( cin, key, '\n' );
                                                                                cout << "Enter operation ENCRYPT/DECRYPT: ";
                                                                                cin >> operation;
                                                                                cout << endl;
    
    if (operation=="ENCRYPT")
        encrypt( fileName, destinationFileName, key );
    if (operation=="DECRYPT")
        decrypt( fileName, destinationFileName, key );
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

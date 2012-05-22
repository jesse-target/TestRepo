#ifndef _FILEHANDLING_
#define _FILEHANDLING_

// I want to have a function which opens a text file and converts it to a string

string F2S ( string fileName ) {
    
    fstream f( fileName.c_str(), ios::in );
    string s;
    
    getline( f, s, '\0' );
    f.close();
    
    return s;
}

// I want to have a function which converts a string to a text file

void S2F ( string fileName, string s ) {
    
    fstream f( fileName.c_str(), ios::out );
    f << s;
    f.close();
}

#endif
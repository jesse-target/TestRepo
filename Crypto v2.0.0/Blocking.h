
// Query method encrypt returns a encrypted version of the string passed
string reletter ( string key, string value )
{    string returnVal="";
     int keyLength = key.length();
     
     // Build cypherBlock
     char cypherBlock[keyLength][27];
     
     for (int i=0; i<keyLength; i++)
     {   cypherBlock[i][26] = '\0';
         for (char j=0; j<26; j++)
         {   cypherBlock[i][j] = (char)(( j + ( key[i]-97 ) ) % 26 + 97);
         }
     }
     
     // Encrypt
     for ( int i=0; i<value.length(); i++ )
     {   char letter = value[i];
         if ( letter >= 'A' && letter <= 'Z'  )
             letter+=32;
         if ( letter >= 'a' && letter <= 'z' )
         {  returnVal += cypherBlock[i%keyLength][letter-97];
         }
         else
            returnVal += letter;
     }
     
     return returnVal;
}//=============================================================================

// Query method decrypt returns a decrypted version of the string passed
string unreletter ( string key, string value )
{    string returnVal="";
     int keyLength = key.length();
     
     // Build cypherBlock
     char cypherBlock[keyLength][27];
     
      for (int i=0; i<keyLength; i++)
     {   cypherBlock[i][26] = '\0';
         for (char j=0; j<26; j++)
         {   cypherBlock[i][j] = (char)(( j + ( key[i]-97 ) ) % 26 + 97);
         }
     }
     
     // Decrypt
     for (int i=0; i<value.length(); i++)
     {   char letter = value[i];
         if (letter >= 'a' && letter <= 'z' ) {
             for ( char j='a'; j<='z'; j++)
                 if ( letter == cypherBlock[ i % keyLength ][ (int)j -97 ] )
                 {  returnVal += j;
                 }
         }
         else
             returnVal += letter;
             
     }
     
     return returnVal;
}//=============================================================================

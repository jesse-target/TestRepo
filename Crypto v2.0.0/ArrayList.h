#ifndef _ARRAYLIST_
#define _ARRAYLIST_


#include <cstdlib>

#define MAX_SIZE 5000

template < class T >
class ArrayList {
    
    private:
        int             itsIndex;
        T               s [MAX_SIZE];
        
    public:
        
        ArrayList () {
            itsIndex=-1;
        }
        
        void push ( T p ) {
        	itsIndex++;
        	s[itsIndex]=p;
        }
        
        T top () {
            return s[itsIndex];
        }
        
        T get ( int i ) {
            if ( i>=0 && i<=itsIndex ) {
                return s[i];
            }
            return s[0];
        }
        
        T operator[] ( int i ) {
            if ( i>=0 && i<=itsIndex ) {
                return s[i];
            }
            return s[0];
        }
             
        int size () {
            return itsIndex + 1;
        }
        
        void empty () {
            itsIndex=-1;
        }
        
        bool isEmpty () {
            return (itsIndex==-1);
        }
        
        int count ( T what ) {
        	int c=0;
        	for ( int i=0; i<=itsIndex; i++ ) {
        			if ( s[i]==what )
        				c++;
            }
            return c;
        } 
        
        bool has ( T what ) {
            for ( int i=0; i<=itsIndex; i++ ) {
                    if ( what==s[i] )
                        return true;
            }
            return false;
        }
        
        int get ( T what ) {
            for ( int i=0; i<=itsIndex; i++ ) {
                    if ( what==s[i] )
                        return i;
            }
            return -1;
        }
        
        void remove ( int index ) {
            itsIndex--;
            for ( int i=index; i<=itsIndex; i++ )
                    s[i]=s[i+1];
        }
        
        void removeAll ( T what ) {
            for ( int i=0; i<=itsIndex; ) {
                if ( what==s[i] )
                    remove( i );
                else
                    i++;
            }
        }
        
        void replace ( T what, T with ) {
            for (int i=0; i<itsIndex; i++)
                if (what==s[i])
                    s[i]=with;
        }
        
        void swap ( int one, int two ) {
            T temp=s[one];
            s[one]=s[two];
            s[two]=temp;
        }
        
        void reverse() {
            T temp[MAX_SIZE];
            int j=0;
            for (int i=itsIndex-1; i>=0; i--) {
                temp[j]=s[i];
                j++;
            }
            for (int i=0; i<itsIndex; i++)
                s[i]=temp[i];
        }
};




#endif

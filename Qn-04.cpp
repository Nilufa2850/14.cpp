/*
4.
class Array
{
    int *p ;
    int size ;
    public :
        // methods
} ;
Define operator = to perform deep copy of array objects*/

#include<iostream>
using namespace std ;

class Array
{
    private : 
        int *p ;
        int size ;
    public : 
        Array (int s=1)
        {
            size = s ;
            p = (int*) calloc (size , sizeof(int)) ;
        }
        ~Array()
        {
            free(p) ;
        }
        void setData(int range)
        {
            size = range ;
            free(p) ;
            p = (int*) calloc (size , sizeof(int)) ;

            cout<<"Enter "<<size<<" values\n" ;
            for (int i=0 ; i<size ; i++)
                cin>>p[i] ;
        }
        void showData ()
        {
            for (int i=0 ; i<size ; i++)
                cout<<p[i]<<" " ;
            cout<<endl ;
        }

        void operator = (Array obj)
        {
            size = obj.size ;
            p = (int*) calloc(size , sizeof(int)) ;
            for (int i=0 ; i<size ; i++)
                p[i] = obj.p[i] ;
        }
        
        
};


int main ()
{
    Array obj1 , obj2 ;
    obj1.setData(5) ;
    obj1.showData() ;

    obj2 = obj1 ;
    obj2.showData() ;

    return 0 ;
}

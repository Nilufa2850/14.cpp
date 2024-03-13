/*5. In qn 4 , define a friend operator + to concatenate two array
objects
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
        /*Array operator = (Array obj)
        {
            Array temp ;
            size = obj.size ;
            temp.p = (int*) calloc(temp.size , sizeof(int)) ;
            for (int i=0 ; i<temp.size ; i++)
                temp.p[i] = obj.p[i] ;

            return temp ;
        }*/
        friend Array* operator + (Array , Array) ;
        
        
};
Array* operator + (Array obj1 , Array obj2)
{
    Array *temp = (Array*) malloc (sizeof(Array)) ;
    int i , k , j ;

    temp->size = obj1.size + obj2.size ;

    temp->p = (int*) calloc(temp->size , sizeof(int)) ;

    for (i=0,k=0 ; i<obj1.size ; i++,k++)
    {
        temp->p[k] = obj1.p[i] ;
        
    }
    for (j=0 ; j<obj2.size ; j++,k++)
    {
        temp->p[k] = obj2.p[j] ;
    }
    return temp ;
}


int main ()
{
    Array obj1 , obj2 , *X;

    obj1.setData(3) ;
    cout<<"\n1st array data\n" ;
    obj1.showData() ;

    obj2.setData(3) ;
    cout<<"\n2nd array data\n" ;
    obj2.showData() ;

    X = (obj1 + obj2) ;
    cout<<"\nFinal array data\n" ;
    X->showData() ;

    return 0 ;
}

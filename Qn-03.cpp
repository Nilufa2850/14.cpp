/*3, In qn 2 , overload operator= to perform copy of Time objects
2.Define a class Time and overload following operaters 
i)  << insertion operators
ii) >> extraction operators
*/
#include<iostream>
using namespace std ;

class Time
{
    private : 
        int hr,min,sec ;
    public : 
        Time (int x=0 , int y=0 , int z=0) { };
        
        void operator = (Time t)
        {
            hr = t.hr ;
            min = t.min ;
            sec = t.sec ;
        }
        // overload << (insertion)
        friend ostream& operator << (ostream& , Time) ;
        // overload >> (extraction)
        friend istream& operator >> (istream& , Time&) ;
};

// Define << (insertion) as a friend function
ostream& operator << (ostream& dout, Time t)
{
    dout<<"\n"<<t.hr<<":"<<t.min<<":"<<t.sec<<endl  ;
    return dout ;
}
// Define >> (extraction) as a friend function
istream& operator >> (istream &din, Time &t)
{
    din>>t.hr>>t.min>>t.sec ;
    return din ;
}
int main ()
{
    Time t1, t2 , t3 ;

    cout<<"Enter time \n" ;
    cin>>t1 ;

    cout<<"Time is \n" ;
    cout<<t1 ;

    t2=t1 ; //t2.operator(t1) ;
    cout<<t2 ;
    return 0 ;
    
    
    return 0 ;
}


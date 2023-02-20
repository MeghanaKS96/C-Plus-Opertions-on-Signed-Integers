#include <stdexcept>
#include<iostream>
#include<string>

class SafeInt {
    private:
        int value;
    public:
        //constructor 1.1
        SafeInt(int value): value(value)
        {     
        }
        //copy constructor 1.2
        SafeInt(const SafeInt &SI)
        { 
            value = SI.value;    
        }
       
       //Overload operators definition 1.3
        friend SafeInt operator+(const SafeInt &c1, const SafeInt &c2);
        friend SafeInt operator-(const SafeInt &c1, const SafeInt &c2);        
        friend SafeInt operator*(const SafeInt &c1, const SafeInt &c2);
        friend SafeInt operator++(const SafeInt &c1) ;       
        
         //Getvalue of object 1.5
         int GetValue() 
         { 
             return value;
              }
};
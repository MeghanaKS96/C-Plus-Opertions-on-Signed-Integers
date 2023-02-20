#include "safeint.h"
#include <iostream>
#include <string>
using namespace std;

 //Operators overload functions 1.3
 SafeInt operator+(const SafeInt &c1, const SafeInt &c2)        
        {
            if(c1.value > 0 && c2.value > 0)
            {
            if (c1.value > INT_MAX - c2.value || c2.value > INT_MAX - c1.value )
            {
                throw std::overflow_error("Addition not possible due to Overflow");
                
            }
            return 0;
            }
            else
            if(c1.value < 0 && c2.value < 0)
            {
            if (c1.value < INT_MIN - c2.value || c2.value < INT_MIN - c1.value )
            {
                throw std::underflow_error("Addition not possible due to Underflow");
                
            }
            return 0;
            }
            else
            {
                return SafeInt(c1.value + c2.value);
            }           
        }

 SafeInt operator-(const SafeInt &c1, const SafeInt &c2)        
        {
        
            if (c1.value > 0 && c2.value < 0)
            {
                if(c1.value > INT_MAX + c2.value)
            {
                throw std::underflow_error("Subtraction not possible due to Overflow");
                
            }
            return 0;
            }
            else
            if (c1.value < 0 && c2.value > 0)
            {
                if(c1.value < INT_MIN + c2.value)
            {
                throw std::underflow_error("Subtraction not possible due to Underflow");
                
            }
            return 0;
            }
            else
            {
                return SafeInt(c1.value - c2.value);
            } 
        }

 SafeInt operator*(const SafeInt &c1, const SafeInt &c2)        
        {
            if((c1.value > 0 && c2.value > 0) || (c1.value < 0 && c2.value < 0))
            {
                if(c1.value > INT_MAX / c2.value || c2.value > INT_MAX / c1.value )
                {
                    throw std::underflow_error("Multiplication not possible due to Overflow");
                }
                return 0;
            }
            else
            if(c1.value < INT_MIN / c2.value || c2.value < INT_MIN / c1.value )
            {
                throw std::underflow_error("Multiplication not possible due to Underflow");
            }

        return SafeInt(c1.value * c2.value);
        }

 SafeInt operator++(const SafeInt &c1)        
        {
         if(c1.value>=INT_MAX)
         {
             throw std::overflow_error("Increment not possible due to Overflow");
         }
         return SafeInt(c1.value+1);
        }

int main() {
    
    SafeInt s1(5);
    SafeInt s2(10);
    try
    {
        SafeInt s3 = s1 + s2 ;
        //print safeint via cout 1.4
        cout<<"s1 + s2 = " << s3.GetValue()<<endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        SafeInt s3 = s1 - s2;
        std::cout << "s1 - s2 = " << s3.GetValue() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        SafeInt s3 = s1 * s2;
        std::cout << "s1 * s2 = " << s3.GetValue() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    try
    {

        SafeInt s3 = ++s1;
        std::cout << "++s3 " << s3.GetValue() << std::endl;
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    return 0;


     
}

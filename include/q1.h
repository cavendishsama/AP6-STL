#ifndef Q1_H
#define Q1_H

#include<iostream>
#include<cmath>
#include<functional>

namespace q1{

template <typename T, typename Func>
// using T = double;
T gradient_descent(T initial_val, T step_size, Func fun){

    size_t i{};
   
    T current_point { initial_val  };
    T next_point { current_point + step_size };
    
    if(fun(current_point) > fun(next_point) ){
        while(true){        
            if( fun(current_point) < fun(next_point))
                // break;
                return current_point;

            current_point = next_point;
            next_point = current_point + step_size;
            i++;
            // std::cout<<current_point<<std::endl;
        }
    }
        
    if(fun(current_point) < fun(next_point)){
        while(true){
            if( fun(current_point) > fun(next_point) )
                // break;
                return next_point;
            next_point = current_point;
            current_point = current_point - step_size;
        }
    }
    return true;

}

}

#endif //Q1_H
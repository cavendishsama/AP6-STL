#ifndef Q1_H
#define Q1_H

#include<iostream>
#include<cmath>
#include<functional>

namespace q1{

template <typename T, typename Func>
T gradient_descent(T initial_val, T step_size, Func fun = Func()){
   
    T current_point { initial_val  };
    T next_point { current_point + step_size };
    
    if(fun(current_point) >= fun(next_point) ){
        while(true){        
            if( fun(current_point) < fun(next_point))
                return current_point;

            current_point = next_point;
            next_point = current_point + step_size;
        }
    }
        
    if(fun(current_point) <= fun(next_point)){
        while(true){
            if( fun(current_point) > fun(next_point) )
                return next_point;
            next_point = current_point;
            current_point = next_point - step_size;
        }
    }
    return true;

}

}

#endif //Q1_H
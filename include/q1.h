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
   
        
    while(true){        
        T current_point { initial_val + i * step_size };
        T next_point { current_point + step_size };
        
        if( fun(current_point) < fun(next_point))
            return current_point;
        
        i++;
        // current_point = next_point;
        // next_point = fun(initial_val + i * step_size);
        std::cout<<current_point<<std::endl;
        
       
    }
}

}

#endif //Q1_H
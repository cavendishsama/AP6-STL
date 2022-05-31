#ifndef Q1_H
#define Q1_H

#include<iostream>
#include<cmath>
#include<functional>

namespace q1{

// template <typename T, typename Func>
// using T = double;
inline double gradient_descent(double initial_val, double step_size, std::function<double(double)> fun){

    size_t i{};
   
    double current_point { initial_val  };
    double next_point { current_point + step_size };
    
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

}

}

#endif //Q1_H
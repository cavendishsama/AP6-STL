#ifndef Q4_H
#define Q4_H

#include<iostream>
#include<vector>
#include <numeric>


namespace q4{

    struct Vector2D
    {   
        Vector2D() = default;
        Vector2D(double _x, double _y): x{_x}, y{_y} { }
    
        double x{};
        double y{}; 
    };


    struct Sensor
    {
        Sensor(q4::Vector2D _pos, double _accuracy): pos{_pos}, accuracy{_accuracy} {}
        
        Vector2D pos;
        double accuracy;    
    };


    // struct X{
    //     bool operator()(double finalx1, Sensor& sensor){
    //         return finalx1 + sensor.pos.x ;
    //     }
            
    // };
    // struct Y{
    //     bool operator()(Sensor& sensor){
    //         return sensor.pos.y ;
    //     }
            
    // };


    inline Vector2D kalman_filter(std::vector<Sensor> sensors){
        double finalx {}, finaly{};
        double DEN { std::accumulate(sensors.begin(), sensors.end(), 0.0, [](double a, Sensor& b){ return a + b.accuracy; }) };
        double kalman_resultx { std::accumulate(sensors.begin(), sensors.end(), finalx, [](double finalx, Sensor& X){ return finalx + X.pos.x * X.accuracy; } ) / DEN };
        double kalman_resulty { std::accumulate(sensors.begin(), sensors.end(), finaly, [](double finaly, Sensor& Y){ return finaly + Y.pos.y * Y.accuracy; } ) / DEN };
        
        Vector2D position(kalman_resultx, kalman_resulty);

        return position;
    }

}

#endif //Q4_H
#ifndef Q3_H
#define Q3_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
#include<vector>
#include<queue>

// \d-\s(\w+):(\w+)\s-\s\w+:(\d+)h(\d+)*m?\s-\s(\w+):(\d)\s-\s(\w+):(\d+)h(\d+)*m?,*(\d+)*h*(\d+)*m*,?(\d)*h*(\d+)*m*\s-\s(\w+):(\d+)
namespace q3{
    struct Flight
    {
        Flight (std::string _flight_number, size_t _duration, size_t _connections, size_t _connection_times, size_t _price):
            flight_number {_flight_number}, duration {_duration}, connections {_connections},
            connection_times {_connection_times}, price{_price} {}

        std::string flight_number;
        size_t duration;
        size_t connections;
        size_t connection_times;
        size_t price;
    };
    //duration + connection_times + 3*price

    // inline auto func = [](Flight first, Flight second){
    //     size_t a { first.duration + first.connection_times + 3 * first.price };
    //     size_t b { second.duration + second.connection_times + 3 * second.price };
    //     return a > b;
    // };
    
    struct func
    {
        bool operator()(const Flight first, const Flight second){
            return (first.duration + first.connection_times + 3*first.price) > (second.duration + second.connection_times + 3*second.price);
        }
    };
    
    inline std::priority_queue<Flight, std::vector<Flight>, func> gather_flights(std::string filename){
        
        std::priority_queue<Flight, std::vector<Flight>, func> _flight {};
        std::ifstream file(filename);
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string txt = buffer.str();
    
        std::regex pattern(R"(\d-\s(\w+):(\w+)\s-\s\w+:(\d+)h(\d+)*m?\s-\s(\w+):(\d)\s-\s(\w+):(\d+)h(\d+)*m?,*(\d+)*h*(\d+)*m*,?(\d)*h*(\d+)*m*\s-\s(\w+):(\d+))");
        std::smatch match;


        std::cout << "match[0]" << std::endl;

        while(std::regex_search(txt, match, pattern)){
            // /*
            std::string FlightNum { match[2].str() };
            size_t durationHour {};      std::stringstream _durationHour {match[3].str()};       _durationHour >> durationHour;
            size_t durationMin {};       std::stringstream _durationMin {match[4].str()};        _durationMin >> durationMin;
            size_t connectionsNum {};    std::stringstream _connectionsNum {match[6].str()};     _connectionsNum >> connectionsNum;  
            size_t ConTimeHour1 {};      std::stringstream _ConTimeHour1 {match[8].str()};       _ConTimeHour1 >> ConTimeHour1;            
            size_t ConTimeMin1 {};       std::stringstream _ConTimeMin1 {match[9].str()};        _ConTimeHour1 >> ConTimeMin1;
            size_t ConTimeHour2 {};      std::stringstream _ConTimeHour2 {match[10].str()};      _ConTimeHour2 >> ConTimeHour2;            
            size_t ConTimeMin2 {};       std::stringstream _ConTimeMin2 {match[11].str()};       _ConTimeHour2 >> ConTimeMin2;
            size_t ConTimeHour3 {};      std::stringstream _ConTimeHour3 {match[12].str()};      _ConTimeHour3 >> ConTimeHour3;            
            size_t ConTimeMin3 {};       std::stringstream _ConTimeMin3 {match[13].str()};       _ConTimeHour3 >> ConTimeMin3;
            size_t _price {};            std::stringstream __price {match[15].str()};            __price >> _price;
            // */
            /*
            std::string FlightNum { match[2].str() };

            int durationHour { std::stoi(match[3].str()) };
            int durationMin { std::stoi(match[4].str()) };
            int connectionsNum { std::stoi(match[6].str()) };

            int ConTimeHour1 { std::stoi(match[8].str()) };
            int ConTimeMin1 { std::stoi(match[9].str()) };
            
            int ConTimeHour2 { std::stoi(match[10].str()) };
            int ConTimeMin2 { std::stoi(match[11].str()) };

            int ConTimeHour3 { std::stoi(match[12].str()) };
            int ConTimeMin3 { std::stoi(match[13].str()) };

            int _price { std::stoi(match[15].str()) };
            */
            _flight.push(Flight(FlightNum, (durationHour*60) + durationMin, connectionsNum, (ConTimeHour1 + ConTimeHour2 + ConTimeHour3) * 60 + ConTimeMin1 + ConTimeMin2 + ConTimeMin3, _price));

            txt = match.suffix().str();
        }


        return _flight;
    }

    
}

#endif //Q3_H
#ifndef Q2_H
#define Q2_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
#include<vector>

namespace q2{
    struct Patient
    {
        Patient(std::string _name, size_t _age, size_t _smokes, size_t _area_q, size_t _alkhol) :
        name {_name}, age{_age}, smokes{_smokes},
        area_q{_area_q}, alkhol{_alkhol} 
        {
        }

        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };

    inline std::vector<Patient> read_file(std::string filename){
        std::vector<Patient> _patient;
        std::ifstream file("lung_cancer.csv");
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string txt = buffer.str();

        std::regex pattern(R"((\w+)\s?,(\w+)\s?,(\d+),(\d+),(\d+),(\d+))");

        std::cout << "checkpoint0" << std::endl;////////////////////////////////////////////////////////////////
        
        std::smatch match;

        while(std::regex_search(txt, match, pattern)){
            std::string FirstName { match[1].str() };
            std::string LastName { match[2].str() };
            
            size_t _age{};      std::stringstream __age(match[3].str());        __age >> _age;
            size_t _smokes{};   std::stringstream __smokes(match[4].str());     __smokes >> _smokes;
            size_t _areaq{};    std::stringstream __areaq(match[5].str());      __areaq >> _areaq;
            size_t _alkhol{};   std::stringstream __alkhol(match[6].str());     __alkhol >> _alkhol;
            _patient.push_back(Patient(FirstName + " " + LastName, _age, _smokes, _areaq, _alkhol));

            txt = match.suffix().str();
        }

        return _patient;
    }

    inline void sort(std::vector<Patient>& patient1){

        std::sort(patient1.begin(), patient1.end(), [](Patient first, Patient second){ 
            size_t a { 3 * first.age + 5 * first.smokes + 2 * first.area_q + 4 * first.alkhol };
            size_t b { 3 * second.age + 5 * second.smokes + 2 * second.area_q + 4 * second.alkhol };
            return a > b ;
        });
    }

}


#endif //Q2_H
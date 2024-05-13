#pragma once
#include <iostream>
#include <string>

class City {
private:
    std::string country;
    std::string name;
    int population;

public:
    City(std::string country, std::string name, int population);

    std::string getCountry() const;
    std::string getName() const;
    int getPopulation() const;

    bool comparePopulation(const City& other) const;

    void write(std::ostream& out) const;

    void read(std::istream& in);
};

std::ostream& operator<<(std::ostream& out, const City& city);

std::istream& operator>>(std::istream& in, City& city);
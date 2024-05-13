#include "city.h"

City::City(std::string country, std::string name, int population) : country(country), name(name), population(population) {}

std::string City::getCountry() const {
    return country;
}

std::string City::getName() const {
    return name;
}

int City::getPopulation() const {
    return population;
}

bool City::comparePopulation(const City& other) const {
    return population < other.population;
}

void City::write(std::ostream& out) const {
    out << "Country: " << country << ", City: " << name << ", Population: " << population;
}

void City::read(std::istream& in) {
    in >> country >> name >> population;
}

std::ostream& operator<<(std::ostream& out, const City& city) {
    city.write(out);
    return out;
}

std::istream& operator>>(std::istream& in, City& city) {
    city.read(in);
    return in;
}


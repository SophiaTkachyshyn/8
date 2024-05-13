#include <iostream>
#include <vector>
#include "city.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

vector<City> readCitiesFromFile(const string& filename)
{
    vector<City> cities;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return cities;
    }

    string country, name;
    int population;
    while (file >> country >> name >> population) {
        cities.push_back(City(country, name, population));
    }

    file.close();
    return cities;
}

void processCitiesByCountry(const vector<City>& cities) {
    map<string, vector<City>> citiesByCountry;
    map<string, int> totalPopulationByCountry;

    for (const auto& city : cities) {
        citiesByCountry[city.getCountry()].push_back(city);
        totalPopulationByCountry[city.getCountry()] += city.getPopulation();
    }

    for (auto it = citiesByCountry.begin(); it != citiesByCountry.end(); ++it) {
        const string& country = it->first;
        const vector<City>& cityVec = it->second;

        cout << "Cities in " << country << ":" << endl;
        for (const auto& city : cityVec) {
            cout << city.getName() << " (Population: " << city.getPopulation() << ")" << endl;
        }
        cout << "Total population in " << country << ": " << totalPopulationByCountry[country] << endl;
        cout << endl;
    }

    int totalPopulation = 0;
    for (auto it = totalPopulationByCountry.begin(); it != totalPopulationByCountry.end(); ++it) {
        totalPopulation += it->second;
    }
    cout << "Total population of all countries: " << totalPopulation << endl;
}

int scalarProduct(vector<int> v1, vector<int> v2) {
    int result = 0;
    for (int i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

vector<int> multiplyVectorMatrix(vector<vector<int>> matrix, vector<int> vec) {
    int vectorSize = vec.size();
    int matrixColumns = matrix[0].size();

    if (matrixColumns != vectorSize) {
        cout << "Помилка: Кількість стовпців матриці не дорівнює кількості елементів вектора!" << endl;
        return {};
    }

    vector<int> result(matrix.size());

    for (int i = 0; i < matrix.size(); i++) {
        result[i] = 0;
        for (int j = 0; j < matrixColumns; j++) {
            result[i] += matrix[i][j] * vec[j];
        }
    }

    return result;
}

int main() {
    vector<City> cities1 = readCitiesFromFile("Text1.txt");
    vector<City> cities2 = readCitiesFromFile("Text2.txt");
    vector<City> cities3 = readCitiesFromFile("Text3.txt");

    vector<City> allCities;
    allCities.insert(allCities.end(), cities1.begin(), cities1.end());
    allCities.insert(allCities.end(), cities2.begin(), cities2.end());
    allCities.insert(allCities.end(), cities3.begin(), cities3.end());

    sort(allCities.begin(), allCities.end(), [](const City& a, const City& b) {
        return a.comparePopulation(b);
    });

    cout << "All cities:" << endl;
    for (const auto& city : allCities) {
        cout << city.getName() << " (Population: " << city.getPopulation() << ")" << endl;
    }
    cout << endl;

    processCitiesByCountry(allCities);

    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2 = { 2, 2, 2 };

    int result = scalarProduct(v1, v2);

    cout << "Scalar Product: " << result << endl;

    vector<int> v3 = { 2, 2, 2 };
    vector<vector<int>> m = { {1, 2, 3}, {4, 5, 6} };

    vector<int> resultVec = multiplyVectorMatrix(m, v3);

    cout << "Matrix-Vector Multiplication Result:\n";
    for (int i = 0; i < m.size(); i++) {
        cout << resultVec[i] << " ";
    }

    return 0;
}

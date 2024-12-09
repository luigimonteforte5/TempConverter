#include <algorithm>
#include <functional>
#include <iostream>
#include <map>

using std::string;
using std::map;

class ConversionException final : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Custom exception occurred!";
    }
};

double celsiusToFahrenheit(const double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(const double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double celsiusToKelvin(const double celsius) {
    return celsius + 273.15;
}

double fahrenheitToKelvin(const double fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit) + 273.15);
}

double kelvinToCelsius(const double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(const double kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

enum Units {
    CELSIUS,
    FAHRENHEIT,
    KELVIN,
    INVALID
};

Units stringToUnit(const string &unitString) {
    static const map<string, Units> unitMap = {
        {"C", CELSIUS},
        {"F", FAHRENHEIT},
        {"K", KELVIN}
    };

    if (const auto found = unitMap.find(unitString);
        found != unitMap.end()) {
        return found->second;
    }
    return INVALID;
}

string unitToString(const Units unit) {
    switch (unit) {
        case CELSIUS: return "C";
        case FAHRENHEIT: return "F";
        case KELVIN: return "K";
        default: return "Invalid";
    }
}

string toUpperCase(const string &input) {
    std::string result = input;
    std::ranges::transform(result, result.begin(), ::toupper);
    return result;
}

double chooseOp(Units unit, Units target, double temp) {
    const static map<std::pair<Units, Units>, std::function<double(double)> > conversionMap = {
        {{CELSIUS, FAHRENHEIT}, celsiusToFahrenheit},
        {{CELSIUS, KELVIN}, celsiusToKelvin},
        {{FAHRENHEIT, CELSIUS}, fahrenheitToCelsius},
        {{FAHRENHEIT, KELVIN}, fahrenheitToKelvin},
        {{KELVIN, CELSIUS}, kelvinToCelsius},
        {{KELVIN, FAHRENHEIT}, kelvinToFahrenheit}
    };

    auto it = conversionMap.find({unit, target});
    if (it != conversionMap.end()) {
        return it->second(temp);
    }
    throw ConversionException();
}

int main() {
    double temp;
    string inputUnit;
    string target;

    std::cout << "Insert temperature: ";
    std::cin >> temp;

    std::cout << "Insert the starting unit (C,F,K): ";
    std::cin >> inputUnit;
    Units tempUnit = stringToUnit(toUpperCase(inputUnit));

    std::cout << "Insert target unit (C,F,K): ";
    std::cin >> target;
    Units targetUnit = stringToUnit(toUpperCase(target));

    double converted = chooseOp(tempUnit, targetUnit, temp);

    std::cout << "Converted value: " << converted << " " << target;

    return 0;
}

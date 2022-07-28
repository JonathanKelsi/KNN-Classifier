#include "Classified.h"
#include <cmath>

Classified::Classified() {
    //Katzav
}

Classified::Classified(std::string handle, std::vector<double> data) {
    //Katzav
}

Classified::Classified(const Classified& classified) {
    //Katzav
}

const std::string& Classified::handle() const {
    //Katzav
}

void Classified::handle(std::string) {
    //Katzav
}

double Classified::dataLen() const {
    //Katzav
}

const std::vector<double> operator-(const std::vector<double>& v) {

}

const std::vector<double> operator+(const std::vector<double>& v, const std::vector<double>& u) {

}

const std::vector<double> operator-(const std::vector<double>& u, const std::vector<double>& v) {
    return v + (-u);
}

const std::vector<double> operator*(double t, std::vector<double> v) {
}

const std::vector<double> operator*(const std::vector<double>& v, double t) {
    return t * v;
}

const std::vector<double> operator/(std::vector<double> v, double t) {
    return v * (1 / t);
}

double len(const std::vector<double>& v) {

}



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

std::string Classified::handle() {
    //Katzav
}

void Classified::handle(std::string) {
    //Katzav
}

Classified Classified::operator-() const {
}

const Classified Classified::operator+(const Classified& u) const {
}

const Classified Classified::operator-(const Classified& u) const {
    return *this + (-u);
}

Classified &Classified::operator+=(const Classified& v) {
}

Classified &Classified::operator*=(const double t) {
    //Katzav
}

Classified &Classified::operator/=(const double t) {
    *this *= 1 / t;
    return *this;
}

double Classified::len() const {
    //Katzav
}

double Classified::operator[](double i) const {
    return m_data[i];
}

const Classified Classified::operator*(double t) const {

}

const Classified Classified::operator/(double t) const {
    return *this * (1 / t);
}


const Classified operator*(double t, const Classified& u) {
    return u * t;
}

double dot(const Classified& u, const Classified& v) {
    //Katzav
}

Classified unitVector(Classified v) {
    return v / v.len();
}


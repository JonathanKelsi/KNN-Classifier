#include "Classified.h"
#include <cmath>
#include <utility>

Classified::Classified() {
    m_handle = "";
}

Classified::Classified(std::string handle, std::vector<double>& data) {
    m_handle = std::move(handle);
    m_data = data;
}

Classified::Classified(const Classified& classified) {
    //TODO: Katzav
}

const std::string& Classified::handle() const {
    //TODO: Katzav
}

const std::vector<double>& Classified::data() const {
    //TODO: Katzav
}


void Classified::handle(std::string) {
    //TODO: Katzav
}

const std::vector<double> operator-(const std::vector<double>& v) {
    std::vector<double> res = v;
    auto size = res.size();

    for (int i = 0; i < size; ++i) {
        res[i] *= -1;
    }

    return res;
}

const std::vector<double> operator+(const std::vector<double>& v, const std::vector<double>& u) {
    auto size = v.size();

    if (size != u.size()) {
        throw std::invalid_argument("The vectors don't have the same size");
    }

    std::vector<double> res = v;

    for (int i = 0; i < size; ++i) {
        res[i] += u[i];
    }

    return res;
}

const std::vector<double> operator-(const std::vector<double>& u, const std::vector<double>& v) {
    return v + (-u);
}

const std::vector<double> operator*(double t, const std::vector<double>& v) {
    std::vector<double> res = v;
    int size = res.size();

    for (int i = 0; i < size; ++i) {
        res[i] *= t;
    }

    return res;
}

const std::vector<double> operator*(const std::vector<double>& v, double t) {
    return t * v;
}

const std::vector<double> operator/(const std::vector<double>& v, double t) {
    return v * (1 / t);
}

double len(const std::vector<double>& v) {
    double lenSqrd = 0;
    double size = v.size();

    for (int i = 0; i < size; ++i) {
        lenSqrd += v[i] * v[i];
    }

    return sqrt(lenSqrd);
}



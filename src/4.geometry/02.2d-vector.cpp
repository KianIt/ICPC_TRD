template <typename T>
struct vec {
    T x, y;
    vec() : x(0), y(0) { }
    vec(T _x, T _y) : x(_x), y(_y) { }
    
    vec operator+(const vec &b) {
        return vec<T>(x + b.x, y + b.y);
    }
    vec operator-(const vec &b) {
        return vec<T>(x - b.x, y - b.y);
    }
    vec operator*(T c) {
        return vec(x * c, y * c);
    }
    T operator*(const vec &b) {
        return x * b.x + y * b.y;
    }
    T operator^(const vec &b) {
        return x * b.y - y * b.x;
    }
    bool operator<(const vec &other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
    bool operator==(const vec &other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const vec &other) const {
        return !(*this == other);
    }
    friend ostream &operator<<(ostream &out, const vec &v) {
        return out << "(" << v.x << ", " << v.y << ")";
    }
    friend istream &operator>>(istream &in, vec<T> &v) {
        return in >> v.x >> v.y;
    }
    T norm() { // squared length
        return (*this) * (*this);
    }
    ld len() {
        return sqrt(norm());
    }
    ld angle(const vec &other) { // angle between this and other vector
        return acosl((*this) * other / len() / other.len());
    }
    vec perp() {
        return vec(-y, x);
    }
};
template<typename T>
struct Point2D {
  T x, y;

  Point2D() {
    this->x = 0;
    this->y = 0;
  }
  Point2D(T x, T y) {
    this->x = x;
    this->y = y;
  }
  Point2D(const Point2D &p) {
    this->x = p.x;
    this->y = p.y;
  }

  Point2D operator+(const Point2D &p) const {
    return Point2D(this->x + p.x, this->y + p.y);
  }
  Point2D operator-(const Point2D &p) const {
    return Point2D(this->x - p.x, this->y - p.y);
  }
  Point2D operator*(T k) const {
    return Point2D(this->x * k, this->y * k);
  }
  Point2D operator/(T k) const {
    assert(k != 0);
    return Point2D(this->x / k, this->y / k);
  }

  Point2D& operator+=(const Point2D &p) {
    this->x += p.x;
    this->y += p.y;
    return *this;
  }
  Point2D& operator-=(const Point2D &p) {
    this->x -= p.x;
    this->y -= p.y;
    return *this;
  }
  Point2D& operator*=(T k) {
    this->x *= k;
    this->y *= k;
    return *this;
  }
  Point2D& operator/=(T k) {
    assert(k != 0);
    this->x /= k;
    this->y /= k;
    return *this;
  }
};

template<typename T>
Point2D<T> operator*(T k, const Point2D<T> &p) {
  return p * k;
}

template<typename T> 
T dot(const Point2D<T> &p, const Point2D<T> &q) {
  return p.x * q.x + p.y * q.y;
}

template<typename T>
T norm2(const Point2D<T> &p) {
  return dot(p, p);
}

template<typename T>
double norm(const Point2D<T> &p) {
  return sqrt(norm2(p));
}

template<typename T>
double proj(const Point2D<T> &p, const Point2D<T> &q) {
  double n = norm(q);
  assert(n != 0);
  return dot(p, q) / n;
}

template<typename T>
T cross(const Point2D<T> &p, const Point2D<T> &q) {
  return p.x * q.y - q.x * p.y;
}

template<typename T>
struct Point3D {
  T x, y, z;

  Point3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }
  Point3D(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
  Point3D(const Point3D &p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
  }

  Point3D operator+(const Point3D &p) const {
    return Point3D(this->x + p.x, this->y + p.y, this->z + p.z);
  }
  Point3D operator-(const Point3D &p) const {
    return Point3D(this->x - p.x, this->y - p.y, this->z - p.z);
  }
  Point3D operator*(T k) const {
    return Point3D(this->x * k, this->y * k, this->z * k);
  }
  Point3D operator/(T k) const {
    assert(k != 0);
    return Point3D(this->x / k, this->y / k, this->z / k);
  }

  Point3D& operator+=(const Point3D &p) {
    this->x += p.x;
    this->y += p.y;
    this->z += p.z;
    return *this;
  }
  Point3D& operator-=(const Point3D &p) {
    this->x -= p.x;
    this->y -= p.y;
    this->z -= p.z;
    return *this;
  }
  Point3D& operator*=(T k) {
    this->x *= k;
    this->y *= k;
    this->z *= k;
    return *this;
  }
  Point3D& operator/=(T k) {
    assert(k != 0);
    this->x /= k;
    this->y /= k;
    this->z /= k;
    return *this;
  }
};

template<typename T>
Point3D<T> operator*(T k, const Point3D<T> &p) {
  return p * k;
}

template<typename T> 
T dot(const Point3D<T> &p, const Point3D<T> &q) {
  return p.x * q.x + p.y * q.y + p.z * q.z;
}

template<typename T>
T norm2(const Point3D<T> &p) {
  return dot(p, p);
}

template<typename T>
double norm(const Point3D<T> &p) {
  return sqrt(norm2(p));
}

template<typename T>
double proj(const Point3D<T> &p, const Point3D<T> &q) {
  double n = norm(q);
  assert(n != 0);
  return dot(p, q) / n;
}

template<typename T>
Point3D<T> cross(const Point3D<T> &p, const Point3D<T> &q) {
  return Point3D(p.y * q.z - q.y * p.z, q.x * p.z - p.x * q.z, p.x * q.y - q.x * p.y);
}

template<typename T>
T triple(const Point3D<T> &p, const Point3D<T> &q, const Point3D<T> &r) {
  return dot(p, cross(q, r));
}

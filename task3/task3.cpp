#include <iostream>

template <typename T, class Op>
concept IsSupported = requires(T first, T second, Op operation) {
  {operation(first, second)}->std::convertible_to<T>;
  {T::identity()}->std::convertible_to<T>;
};

template <class BinaryOp, class ValueType>
requires IsSupported<ValueType, BinaryOp> ValueType
calculate(int n, ValueType value, const BinaryOp& f) {
  if (n <= 0)
    return ValueType::identity();

  if (n == 1)
    return value;

  ValueType result = value;
  for (int i = 1; i < n; ++i)
    result = f(result, value);

  return result;
}

class Number {
 private:
  int val;

 public:
  Number(int v = 0) : val(v) {}

  int get_value() const { return val; }

  static Number identity() { return Number(1); }

  friend std::ostream& operator<<(std::ostream& os, const Number& n) {
    os << n.val;
    return os;
  }
};

struct Multiply {
  Number operator()(const Number& a, const Number& b) const {
    return Number(a.get_value() * b.get_value());
  }
};

int main() {
  Number x(2);
  Multiply mult;
  Number result = calculate(5, x, mult);

  std::cout << "Rezultat calculate(5, 2, multiply): " << result << std::endl;
  Number manual = mult(mult(mult(mult(x, x), x), x), x);
  std::cout << "Recznie obliczone mult(mult(mult(mult(x, x), x), x), x): "
            << manual << std::endl;
}

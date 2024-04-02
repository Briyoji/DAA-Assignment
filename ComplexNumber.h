class ComplexNumber {
    public:
        float a;
        float b;
        void print();
        void println();
        double l1Norm();

        ComplexNumber () {
            this->a = 0;
            this->b = 0;
        };

        ComplexNumber (float a, float b) {
            this->a = a;
            this->b = b;
        };

        ComplexNumber (ComplexNumber& other) {
            this->a = other.a;
            this->b = other.b;
        };

        ComplexNumber operator+(ComplexNumber other) {
            return ComplexNumber(this->a + other.a, this->b + other.b);
        }

        ComplexNumber operator-(ComplexNumber other) {
            return ComplexNumber(this->a - other.a, this->b - other.b);
        }

        ComplexNumber operator*(ComplexNumber other) {
            return ComplexNumber(this->a * other.a - this->b * other.b, this->a * other.b + this->b * other.a);
        }

        ComplexNumber operator/(ComplexNumber other) {
            return ComplexNumber((this->a * other.a + this->b * other.b) / (other.a * other.a + other.b * other.b), (this->b * other.a - this->a * other.b) / (other.a * other.a + other.b * other.b));
        }

        ComplexNumber operator=(ComplexNumber other) {
            this->a = other.a;
            this->b = other.b;
            return *this;
        }

        bool operator==(ComplexNumber other) {
            return this->a == other.a && this->b == other.b;
        }

        bool operator!=(ComplexNumber other) {
            return this->a != other.a || this->b != other.b;
        }

        bool operator>(ComplexNumber other) {
            return this->l1Norm() > other.l1Norm();
            // return this->a > other.a && this->b > other.b;
        }

        bool operator<(ComplexNumber other) {
            return this->l1Norm() < other.l1Norm();
            // return this->a < other.a && this->b < other.b;
        }

        bool operator>=(ComplexNumber other) {
            return this->l1Norm() >= other.l1Norm();
            // return this->a >= other.a && this->b >= other.b;
        }

        bool operator<=(ComplexNumber other) {
            return this->l1Norm() <= other.l1Norm();
            // return this->a <= other.a && this->b <= other.b;
        }

        ComplexNumber operator-() {
            return ComplexNumber(-this->a, -this->b);
        }

        ComplexNumber operator+() {
            return ComplexNumber(this->a, this->b);
        }
};

void ComplexNumber::print() {
    cout << this->a << ((this->b > 0) ? "+" : "") << this->b << "i ";
};

void ComplexNumber::println() {
    cout << this->a << ((this->b > 0) ? "+" : "") << this->b << "i\n";
};

double ComplexNumber::l1Norm() {
    return abs(this->a) + abs(this->b);
};
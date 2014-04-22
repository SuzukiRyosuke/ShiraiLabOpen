#include <iostream>
using namespace std;


class Triangle {
    double a, b, c;
public:
    void set_a(double x);
    void set_b(double x);
    void set_c(double x);
    double get_a();
    double get_b();
    double get_c();
};

void Triangle::set_a(double x) {
    a = x;
}

void Triangle::set_b(double x) {
    b = x;
}

void Triangle::set_c(double x) {
    c = x;
}

double Triangle::get_a() {
    return a;
}

double Triangle::get_b() {
    return b;
}

double Triangle::get_c() {
    return c;
}

int main() {
    Triangle obj;
    double a, b, c;

    cout << "�O�p�`�̕ӂ̒�������͂��Ă�������:";
    cin >> a >> b >> c;

    obj.set_a(a);
    obj.set_b(b);
    obj.set_c(c);

    cout << "��a = " << obj.get_a() << "\n";
    cout << "��b = " << obj.get_b() << "\n";
    cout << "��c = " << obj.get_c() << "\n";

    return 0;
}

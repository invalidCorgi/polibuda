#include <iostream>

class A {
public:
void a();
};

void A::a() {
std::cout << "Lotrem Ipsym\n";
}

template <class T>
class SmartPointer {
public:
SmartPointer(T* ws) : pointer(ws)
{}
T& operator->() {
return *pointer;
}
T& operator*() {
return *pointer;
}
private:
T* pointer;
};

int main() {
SmartPointer<A> sp(new A);
sp->a();
(*sp).a();

return 0;
}

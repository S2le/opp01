#include <iostream>
template <typename T, int num = 5>
T add_num(T t) {
	return t + num;
}
int main() {
	int x = 3;
	std::cout << "x : " << add_num(x - 3) << std::endl;
}
//매개변수를 수정한다
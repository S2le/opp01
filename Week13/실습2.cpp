#include <iostream>
#include <string>
template <typename T>
auto sum(T x) {
	return x;
}
template<typename T, typename...Args>
auto sum(T x, Args... args) {
	return x + sum(args...);
}
int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;
	getchar();
}
//마지막 하나남았을때 해당되는 함수가 없으므로 만들어준다
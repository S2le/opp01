#include <iostream>
#include <stdexcept>
class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* (실습 1-1) 분석결과 :
결과 :
Executed in B
Destructor execution: B
Executed in A
Destructor execution: A
설명 : 함수A가 시작되고 id값이 A인 객체 생성 후 함수B를 실행한다.
id값이 B인 객체 생성 후 Executed in B를 출력한다.
B함수가 종료되면서 id값이 B인 객체 소멸자가 실행되어 Destructor execution: B를 출력한다.
Executed in A를 출력하고 A함수가 종료되면서 id값이 A인 객체 소멸자가 실행되어 Destructor execution: A를 출력한다.
*/
/* (실습 1-2) 분석결과 :
결과 :
Destructor execution: B
Destructor execution: A
Exception : Exception from funcB!
설명 : 함수A -> B순으로 실행되고 B에서 throw문이 실행된다.
함수B가 종료되면서 id값이 B인 객체 소멸자가 실행되어 Destructor execution: B를 출력한다
함수A가 종료되면서 id값이 A인 객체 소멸자가 실행되어 Destructor execution: A를 출력한다
main에 있는 catch문을 실행한다.
*/
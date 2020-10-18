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
/* (�ǽ� 1-1) �м���� :
��� :
Executed in B
Destructor execution: B
Executed in A
Destructor execution: A
���� : �Լ�A�� ���۵ǰ� id���� A�� ��ü ���� �� �Լ�B�� �����Ѵ�.
id���� B�� ��ü ���� �� Executed in B�� ����Ѵ�.
B�Լ��� ����Ǹ鼭 id���� B�� ��ü �Ҹ��ڰ� ����Ǿ� Destructor execution: B�� ����Ѵ�.
Executed in A�� ����ϰ� A�Լ��� ����Ǹ鼭 id���� A�� ��ü �Ҹ��ڰ� ����Ǿ� Destructor execution: A�� ����Ѵ�.
*/
/* (�ǽ� 1-2) �м���� :
��� :
Destructor execution: B
Destructor execution: A
Exception : Exception from funcB!
���� : �Լ�A -> B������ ����ǰ� B���� throw���� ����ȴ�.
�Լ�B�� ����Ǹ鼭 id���� B�� ��ü �Ҹ��ڰ� ����Ǿ� Destructor execution: B�� ����Ѵ�
�Լ�A�� ����Ǹ鼭 id���� A�� ��ü �Ҹ��ڰ� ����Ǿ� Destructor execution: A�� ����Ѵ�
main�� �ִ� catch���� �����Ѵ�.
*/
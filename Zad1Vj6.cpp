#include <iostream>

class IntStack {
private:
	int cap;
	int* a = new int[cap];
	int koliko;
public:
	IntStack(int j) {
		cap = j;
		a = new int[cap];
		koliko = 0;
	}
	IntStack() {
		cap = 2;
		a = new int[cap];
		koliko = 0;
	}
	~IntStack() {
		delete[] a;
	}
	IntStack(const IntStack& other) {
		cap = other.cap;
		a = other.a;
		koliko = other.koliko;
	}
	void push(int x) {
		if (koliko+1 > cap) {
			int* b = new int[cap];
			for (int i = 0; i < koliko; i++) {
				b[i] = a[i];
				std::cout << "Clan" << i << "je" << b[i] << std::endl;
			}
			std::cout << b[koliko-1] << std::endl;
			cap = cap * 2;
			a = new int[cap];
			for (int i = 0; i < koliko; i++) {
				a[i] = b[i];
			}
			a[koliko++] = x;
		} else {
			a[koliko++] = x;
		}
	}
	void pop() {
		int *c = new int[cap];
		for (int i = 0; i < koliko - 1; i++) {
			c[i] = a[i];
		}
		a = c;
		delete[] c;
		koliko--;
	}
	int top() {
		return a[koliko];
	}
	int size() {
		return koliko;
	}
	int capacity() {
		return cap;
	}
	bool empty() {
		if (koliko == 0) {
			return 0;
		}
		else return 1;
	}
};

int main()
{
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
	c.pop();
	c.push(99);
	std::cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
	std::cout << '\n';
	return 0;
}


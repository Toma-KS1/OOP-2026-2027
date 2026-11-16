#include <iostream>
#include <fstream>
#include <string>

class Money {
	int euros;
	int cents;
public:
	Money(int euros = 0, int cents = 0);
	Money& operator+=(const Money& other) {
		euros += other.euros;
		cents += other.cents;
		return *this;
	}
	Money operator+(const Money& other) {
		Money a = *this;
		a += other;
		return a;
	}
	bool operator<(const Money& other) {
		Money a = *this;
		if (a.euros != other.euros) {
			return bool(a.euros < other.euros);
		}
		else if (a.euros == other.euros) {
			return bool(a.cents < other.cents);
		}
	}
	friend std::ostream& operator<<(std::ostream& os, const Money& a) {
		os << a.euros << '.';
		if (a.cents < 10)
			os << '0';
		os << a.cents;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Money& a) {
		int m, s;
		char colon;
		if (is >> m >> colon >> s && colon == '.' && s >= 0 && m >= 0)
			a = Money(m, s);
		else
			is.setstate(std::ios::failbit);
		return is;
	}
};

int main()
{
	Money a(1, 5);
	Money b(0, 95);
	std::cout << a << " + " << b << " = " << a + b << '\n';

	std::ifstream in("racun.txt");
	if (!in) {
		std::cout << "Datoteka racun.txt ne postoji\n";
		return 1;
	}

	std::string item;
	Money price;
	Money total;
	Money max_price;
	std::string max_item;
	int count = 0;
	while (in >> item >> price) {
		total += price;
		if (max_price < price) {
			max_price = price;
			max_item = item;
		}
		++count;
	}
	if (!in.eof())
		std::cout << "Neispravan zapis: " << item << '\n';

	std::cout << "Stavki: " << count << '\n';
	std::cout << "Ukupno: " << total << '\n';
	std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
	return 0;
}



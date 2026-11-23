#include <iostream>
#include <string>
#include <vector>

class Enemy {
protected:
	std::string ime;
	int zdravlje;
public:
	Enemy(const std::string& n, int h) : ime(n), zdravlje(h) {};
	virtual void take_damage(int d) {
		zdravlje = zdravlje - d;
	}
	virtual ~Enemy() { 
		std::cout << ime << " nestaje" << '\n'; 
	}
	void print() {
		std::cout << ime << " " << zdravlje << '\n';
	}
	int czdravlje() {
		return zdravlje;
	}

};

class Goblin : public Enemy {
public:
	Goblin() : Enemy("Goblin", 20) {}
};

class Bat : public Enemy {
protected:
	int brojac = 0;
public:
	Bat() : Enemy("Bat", 15) {}
	virtual void take_damage(int d) {
		if (brojac == 0) {
			zdravlje = zdravlje - d;
			brojac=brojac+1;
		}
		else {
			std::cout << ime << " izbjegne udarac" << '\n';
			brojac = 0;
		}
	}
};

class Ghost : public Enemy {
public:
	Ghost() : Enemy("Ghost", 30) {}
	virtual void take_damage(int d) {
		zdravlje = zdravlje - (d / 2);
	}
};

class Level {
	std::vector<Enemy*> e;
public:
	~Level(){
		for (Enemy* a : e) {
			delete a;
			}
	}
	void add(Enemy *a) {
		e.push_back(a);
	}
	int size() {
		return e.size();
	}
	void explode(int d) {
		for (Enemy* a : e) {
			a->take_damage(d);
		}
	}
	void remove_dead() {
		for (Enemy* a : e) {
			if (a->czdravlje() <= 0) {
				e.erase(a);
				//delete a;
			}
		}
	}
	void print() {
		for (Enemy* a : e) {
			(*a).print();
		}
	}
};



int main()
{
	Level cave;
	cave.add(new Goblin);
	cave.add(new Bat);
	cave.add(new Ghost);
	cave.add(new Goblin);
	std::cout << cave.size() << '\n';

	cave.explode(10);                // bomba pogodi sve neprijatelje
	cave.print();
	std::cout << "---\n";
	cave.explode(10);
	cave.print();
	std::cout << "---\n";
	cave.remove_dead();
	std::cout << cave.size() << '\n';
	std::cout << "--- kraj ---\n";
	return 0;
}


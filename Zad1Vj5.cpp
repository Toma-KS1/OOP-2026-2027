#include <iostream>
#include <cassert>

class Volume {
	int g;
	int save = g;
	private:
		bool valid() const { return (g <= 100 || g >= 0); };
	public:
		Volume(int l) {
			if (l > 100 || l < 0) {
				g = normalno(l);
			}
			else {
				g = l;
			}
		}
		static int normalno(int l) {
			if (l > 100) {
				return 100;
			}
			else { return 0; }
		}
		Volume() : Volume(50) {};
		
		void up(int step = 10) {
			g += step;
			if (g > 100) {
				g = normalno(g);
			}
			assert(valid());
		}
		void down(int step = 10) {
			g -= step;
			if (g < 0) {
				g = normalno(g);
			}
			assert(valid());
		}
		void mute() {
			save = g;
			g = 0;
			assert(valid());
		}
		void unmute() {
			g = save;
			assert(valid());
		}
		int get() {
			return g;
		}

};

int main()
{
	Volume v;
	std::cout << v.get() << '\n';
	v.up();
	v.up(60);
	std::cout << v.get() << '\n';
	v.mute();
	std::cout << v.get() << '\n';
	v.unmute();
	std::cout << v.get() << '\n';
	Volume w(-20);
	w.down();
	std::cout << w.get() << '\n';
	return 0;
}

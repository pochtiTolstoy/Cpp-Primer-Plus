#include <iostream>

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_box(const box& b);
void set_volume(box& b);

int main() {
	box b1 = { "Docker", 0.32, 1.2, 2.2, 0 };
	show_box(b1);
	set_volume(b1);
	show_box(b1);

	return 0;
}

void show_box(const box& b) {
	std::cout << "Maker: "  << b.maker  << std::endl
						<< "Height: " << b.height << std::endl
						<< "Width: "  << b.width  << std::endl
						<< "Length: " << b.length << std::endl
						<< "Volume: " << b.volume << "\n\n";
}

void set_volume(box& b) {
	b.volume = b.height * b.width * b.length;
}

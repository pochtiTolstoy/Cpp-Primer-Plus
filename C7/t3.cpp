#include <iostream>

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_box(const box b);
void change_value_box(box* pb);

int main() {
	box b1 = { "Docker", 1.3f, 2.3f, 3.5f, 0.0f };
	show_box(b1);
	change_value_box(&b1);
	show_box(b1);
	return 0;
}

void show_box(const box b) {
	std::cout << "Maker: "  << b.maker  << std::endl
						<< "Height: " << b.height << std::endl
						<< "Width: "  << b.width  << std::endl
						<< "Length: " << b.length << std::endl
						<< "Volume: " << b.volume << std::endl;
}

void change_value_box(box* pb) {
	pb->volume = pb->width * pb->height * pb->length;
}

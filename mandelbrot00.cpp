#include <iostream> //for 'cout'
#include <fstream> //for writing to file
#include <math.h>

const int image_width = 480; //width
const int image_height = 360; //height

struct color {
    uint8_t r;
    uint8_t g;
    uint8_t b;

    void from_floats(float _r, float _g, float _b) {
        // return { static_cast<int>(_r), static_cast<int>(_g), static_cast<int>(_b) };
        r = static_cast<int>(_r);
        g = static_cast<int>(_g);
        b = static_cast<int>(_b);
    }
};

int main () 
{

    color c;

    c.r = 0, c.g = 255, c.b = 0;

	std::cout << "DIMENSIONS: " << image_width << " X " << image_height << "\n\n";

	std::ofstream fout("mandelbrot00.ppm");
	if (fout.fail()) return -1;

	fout << "P3\n" << image_width << " " << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j)
	{

		std::cerr << "\rRemaining: " << j << " " << std::flush;

		for (int i = 0; i < image_width; ++i)
		{

			fout << c.r << " " << c.g << " " << c.b << "\n";

		}
	}

	std::cerr << "\n\nDONE.\n";

	fout.close();

	return 0;
}

#include <iostream>
#include <vector>

void prog(float r, std::vector<float>& vx, std::vector<float>& vy)
{
	std::cout << "R: " << r << std::endl;

	float p_count = 0;
	for (size_t i = 0; i < 10; i++)
	{
		float x = vx[i];
		float y = vy[i];

		std::cout << "x: " << x << ' ';
		std::cout << "y: " << y << ' ';

		bool o1 = pow(x - r, 2) + pow(y + r, 2) <= pow(r, 2); // окружность с центорм в т. (r;-r)
		bool o2 = pow(x + r, 2) + pow(y - r, 2) <= pow(r, 2); // окружность с центорм в т. (-r;r)
		bool f = !o1 && !o2 && abs(x) < r && abs(y) < r && !(x < 0 && y < 0) && !(x > 0 && y > 0);

		if (f) p_count++;
		std::cout << (f ? "Попалб" : "Непопалб") << std::endl;
	}

	std::cout << "Вероятность попадания в цель = " << p_count / 10;
}

int main()
{
	setlocale(LC_ALL, "");
	std::vector<float> vx = { 1, 0, 1, 0, 0.01, -0.01, 0.01, -0.01, 0.5, -0.5 };
	std::vector<float> vy = { 1, 0, 0, 1, -0.01, 0.01, 0.01, -0.01, -0.5, 0,5};
	prog(1, vx, vy);
}
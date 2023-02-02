#include <iostream>
#include <climits>
#include <string>

// задание 4

std::string get_line_f(const char* filename);

int main()
{
	setlocale(LC_ALL, "");

	unsigned long min = 1024;
	std::string s = get_line_f("input.txt");

	if (s.length() == 0)
	{
		std::cout << "File is empty or not exist";
		return -1;
	}

	size_t pos = 0;
	std::string currnet_word;

	// разделяем строку по пробелу
	while ((pos = s.find(" ")) != std::string::npos) {
		currnet_word = s.substr(0, pos);

		if (currnet_word.length() < min)
			min = currnet_word.length();

		s.erase(0, pos + 1);
	}

	std::cout << "Minimun word length: " << min;
}

std::string get_line_f(const char* filename) {
	FILE* f;
	char line[1024];

	fopen_s(&f, filename, "r");
	if (f == 0) return std::string();
	fgets(line, 1024, f);
	fclose(f);

	return std::string(line);
}

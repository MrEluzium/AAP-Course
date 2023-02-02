#include <string>
#include <iostream>

struct subj
{
	std::string subject    ;
	unsigned    score   :7 ;
};

struct student
{
	std::string fullname  ;
	std::string faculty   ;
	std::string group     ;
	subj        scores[5] ;
};

void write_array_f(student* arr, int n);
void print_array(student* arr, int n);

int main()
{
	setlocale(LC_ALL, "Russian");

	student a_Students[5] = {
		{"Воронов Артём Сергеевич", "ИКНТ", "ФИТ-3", {
			{"Матанализ", 100},
			{"Ангем", 100},
			{"АИП", 100},
			{"ТОИ", 100},
			{"Физра", 100}
		}},
		{"Фукалов Евгений Денисович", "Мехмат", "МММ-1", {
			{"Матанализ", 10},
			{"Ангем", 5},
			{"АИП", 9},
			{"ТОИ", 6},
			{"Физра", 11}
		}},
		{"Жданов Андрей Сергеевич", "ИКНТ", "ФИТ-3", {
			{"Матанализ", 41},
			{"Ангем", 40},
			{"АИП", 41},
			{"ТОИ", 40},
			{"Физра", 41}
		}},
		{"Макодрай Михаил Александрович", "ИКНТ", "ИТХ-2", {
			{"Матанализ", 40},
			{"Ангем", 41},
			{"АИП", 40},
			{"ТОИ", 41},
			{"Физра", 40}
		}},
		{"Поттер Гарри Джеймсович", "Гриффиндор", "ПМИ-8", {
			{"Матанализ", 41},
			{"Ангем", 41},
			{"АИП", 41},
			{"ТОИ", 41},
			{"Физра", 42}
		}}
	};

	write_array_f(a_Students, 5);
	print_array(a_Students, 5);

	std::cin.get();
}

void write_array_f(student* arr, int n)
{
	FILE* f;
	fopen_s(&f, "output.txt", "w+");

	for (int i = 0; i < n; i++) {
		fprintf(f, "%s\n%s\n%s\n",
			arr[i].fullname.c_str(),
			arr[i].faculty.c_str(),
			arr[i].group.c_str());

		for (int j = 0; j < n; j++) {
			fprintf(f, "%s:%d\n",
				arr[i].scores[j].subject.c_str(),
				arr[i].scores[j].score);
		}
		fprintf(f, "\n");
	}

	fclose(f);
}

void print_array(student* arr, int n)
{
	for (int i = 0; i < 5; i++) {
		float sum = 0;
		for (int j = 0; j < 5; j++)
			sum += arr[i].scores[j].score;
		if (sum / 5 <= 41) continue;

		printf("%s\n%s\n%s\n",
			arr[i].fullname.c_str(),
			arr[i].faculty.c_str(),
			arr[i].group.c_str());

		for (int j = 0; j < 5; j++) {
			printf("%s:%d\n",
				arr[i].scores[j].subject.c_str(),
				arr[i].scores[j].score);
		}
		printf("Средний балл: %.1f\n\n", sum / 5);
	}
}

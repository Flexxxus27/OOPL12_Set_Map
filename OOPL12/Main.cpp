#include <iostream>
#include <vector>
#include <string>
#include <random>

#include <set>
#include <map>
#include <unordered_set>


void DemoBase() {
	std::vector<int> initialData;
	initialData.reserve(10);
	//=======================================================
	std::random_device rd; // Источник истинно случайных чисел
	std::mt19937 provider(rd()); // источник псевдослучайных чисел , начальное значение задачно случайно
	std::uniform_int_distribution<int> distributor(10, 999); //класс доставщик чисел. причесывает числа до нужного нам диапазона
	//=======================================================
	for (int i = initialData.size(); i < initialData.capacity(); i++) {
		initialData.push_back(distributor(provider));
	}
	//=======================================================
	std::set<int> uniqueData;
	for (auto& element : initialData) {
		/*
		bool flag{ true };
		for (auto& uElement : uniqueData) {
			if (element == uElement) {
				flag = false;
				break;
			}
		}
		if (flag) {
			uniqueData.push_back(element);
		}
		*/
		uniqueData.insert(element);
	}
	//=======================
	std::cout << "Atall elements: " << initialData.size() << '\n';
	for (auto &i : initialData){
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	std::cout << "Unique elements: " << uniqueData.size() << '\n';
	for (auto& i : uniqueData) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	
}

class A {
public:
	/*bool operator<(const A& other)const {
		return bool();
	}*/
};

namespace std {

	template <>
	struct less<A> {
		bool operator()(const A& a, const A& b)const {
			return bool();
		}
	};
	// перегрузка свойств типа по признаку сравниваемости, таким образом мы можем научить работать с нашим типом стандартную библиотеку языка
	// не нагружая функционал класса наследуемыми элементами 
}


struct M {
	std::string id;
	std::string name;
	std::string patrinomyc;
	std::string surename;
};


int main() {
	setlocale(0, "");


	//DemoBase();
	std::set<A> obj;
	obj.insert(A());
	A z, x;
	obj.contains(z);
	
	std::map<std::string, M> dictionary;
	std::vector<M> data{
		{"q123r15", "jack", "vitalievich", "london"},
		{"q124r15", "jhon", "", "eddison"},
		{"q123d15", "Mark", "ivanovich", "frolov"},
		{"q223r15", "Anna", "vitalievich", "enshtein"},
		{"q123r15", "ivan", "vitalievich", "frolov"},
		{"q123r55", "patrick", "vitalievich", "pitt"},
	};
	for (int i = 0; i < data.size(); i++) {
		if (!dictionary.contains(data[i].id)) {
			dictionary.insert({ data[i].id, data[i] });
		}
		else {
			std::cout << "didnt insert data:\n" << data[i].id << '\n' <<
				data[i].name << '\n' <<
				data[i].patrinomyc << '\n' <<
				data[i].surename << '\n' <<
				"this data alredy has:\n" <<
				dictionary[data[i].id].id << '\n' <<
				dictionary[data[i].id].name << '\n' <<
				dictionary[data[i].id].patrinomyc << '\n' <<
				dictionary[data[i].id].surename << '\n';

		}
	}


	return 0;
}
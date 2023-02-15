#include<iostream>
#include<fstream>
// SOLID
// single Responsibility - принцип единственной ответственности
// принцип открытости/закрытости - Open closed principle(програмные сущности открыты для расширения, но закрыты для модификации)
// принцип постановки Лисков - Liskov Substitution
// принцип разделения интерфейса
// принцип инверсии зависимостей


int main(int argc, char** argv) {
	if (argc > 1) {
		for (size_t i = 0; i < argc; i++) {
			std::string filename = std::string(argv[i]);
			std::cout << filename << '\n';
		}
		/*std::string filename(argv[1]);
		std::cout << filename << '\n';
		std::ifstream fin(filename);*/
	}
	else
		std::cout << "Onle one argument was provided\n";

	// SOLID


	return 0;
}
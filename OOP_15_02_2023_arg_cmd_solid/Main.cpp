#include<iostream>
#include<fstream>
#include<memory>
// SOLID
// принцип единственной ответственности - single Responsibility
// принцип открытости/закрытости - Open closed principle(програмные сущности открыты для расширения, но закрыты для модификации)
// принцип постановки Лисков - Liskov Substitution(функции, которые используют базовый тип, должны иметь возможность использовать 
// подтипы базового типа, не зная об этом)
// принцип разделения интерфейса - Interface segrigation(много интерфейсов, специально предназначеных для клиентов, лучше, чем один интерфейс общего назначения)
// принцип инверсии зависимостей - Dependency inversion

// паттерн проектирования: фабричный метод

// Base class(fabric method)
// class Dialog
// void render()
// abstract Buttjn createButton() <- fabric meethod
//WindowDialog : public Dialog
// Button createButton() returns windowButton
//
//
class Button {
public:
	virtual void render() = 0;
	virtual ~Button(){}
};

class Dialog {
public:
	void render() {
		std::shared_ptr<Button> button = createButton();
		button->render();
	}
	virtual std::shared_ptr<Button> createButton()=0;
	virtual ~Dialog(){}
};
class WindowsButton : public Button{
public:
	void render()override {
		std::cout << " Win\n";
	}

};
class HTMLButton : public Button {
public:
	void render()override {
		std::cout << " HTML\n";
	}

};

class WindowDialog : public Dialog {
public:
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<WindowsButton>();
	}
};
class WebDialog : public Dialog {
public:
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<HTMLButton>();
	}
};

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

	/*std::shared_ptr<Dialog> dialog;
	std::string config;
	std::cout << "Enter config (Win or Web): ";
	std::cin >> config;

	if (config == "Win") {
		dialog = std::make_shared<WindowDialog>();
	}
	else if (config == "Web") {
		dialog = std::make_shared<WebDialog>();
	}
	else
		throw "Error: unknow config";*/



	return 0;
}
#include <iostream>
#include <string>

class Coffe {
	private:
		//Свойства
		bool powerOn;      //Состояние: включен\нет
		bool energized;      //Состояние: запитан\нет
		bool boiling; // Состояние: вскипел\нет

	public:
		// Конструктор по умолчанию
		Coffe() : powerOn(false), energized(false), boiling(false) {}

		// Конструктор с параметрами
		Coffe(bool power, bool energe, bool boil)
			: powerOn(power), energized(energe), boiling(boil) {}

		// Методы
		void turnOn() {
			powerOn = true;
			std::cout << "кофеварка включена";
		}

		void turnOff() {
			powerOn = false;
			std::cout << "кофеварка выключена";
		}

		void energe() {
			energized = true;
			std::cout << "кофеварка включена в сеть";
		}

		void discharge() {
			energized = false;
			std::cout << "кофеварка не включена в сеть";
		}

		void connectToWifi() {
			boiling = true;
			std::cout << "жидкость вскипела";
		}

		void disconnectFromWifi() {
			boiling = false;
			std::cout << "жидкость не вскипела";
		}

		// Отображения текущего состояния
		void displayState() const {
			std::cout << "Состояния Электрической кофеварки";
			std::cout << "Включена: " << (powerOn ? "1" : "0") << "\n";
			std::cout << "Запитана: " << (energized ? "Да" : "Нет") << "\n";
			std::cout << "Вскипело: " << (boiling ? "Да" : "Нет") << "\n";
		}

		// Метод установки свойств
		void setProperties(bool power, bool energe, bool boil) {
			powerOn = power;
			energized = energe;
			boiling = boil;
		}
};

int main() {
	// Создание объекта ноутбука
	Coffe elCoffe;

	// Меню взаимодействия
	int choice;
	setlocale(LC_ALL, "Russian");
	
		std::cout << "1. Создать элетрическую кофеварку\n";
		std::cout << "2. Состояния\n";
		std::cout << "3. Включен\n";
		std::cout << "4. Выключен\n";
		std::cout << "5. Запитана\n";
		std::cout << "6. Не запитана\n";
		std::cout << "7. Вскипело\n";
		std::cout << "8. Не вскипело\n";
		std::cout << "9. Выход\n";
		std::cout << "Введите циферку: ";
		std::cin >> choice;

		switch (choice) {
			case 1: {
				bool power, energe, boil;
				std::cout << "Введите состояние (включен/выключен): ";
				std::string powerInput;
				std::cin >> powerInput;
				power = (powerInput == "включен");

				std::cout << "Введите состояние питания (да/нет): ";
				std::string chargeInput;
				std::cin >> chargeInput;
				energe = (chargeInput == "да");

				std::cout << "Введите состояние кипячения (вскипело/не вскипело): ";
				std::string wifiInput;
				std::cin >> wifiInput;
				boil = (wifiInput == "вскипело");

				elCoffe.setProperties(power, energe, boil);
				break;
			}
			case 2:
				elCoffe.displayState();
				break;
			case 3:
				elCoffe.turnOn();
				break;
			case 4:
				elCoffe.turnOff();
				break;
			case 5:
				elCoffe.energe();
				break;
			case 6:
				elCoffe.discharge();
				break;
			case 7:
				elCoffe.connectToWifi();
				break;
			case 8:
				elCoffe.disconnectFromWifi();
				break;
			case 9:
				std::cout << "Выйти";
				break;
			default:
				std::cout << "Что-то пошло не так, попробуйте снова"; 		
			while (choice != 9);}
return 0;}

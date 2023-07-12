#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>


class MechanismPart
{
private:
	std::string _name;

public:
	MechanismPart() = default;
	MechanismPart(const std::string& name) : _name(name) {}
	void SetName(const std::string& name)
	{
		_name = name;
	}
	std::string GetNameOfMechPart()
	{
		return _name;
	}
};

class Door : virtual public MechanismPart
{
private:
	bool _isOpen = false;

public:
	Door() = default;
	Door(const std::string& name, bool isOpen) : MechanismPart(name), _isOpen(isOpen) {}
	bool GetIsOpen()
	{
		return _isOpen;
	}
	void OpenDoor()
	{
		_isOpen = true;
	}
	void CloseDoor()
	{
		_isOpen = false;
	}
};

class Wheel : virtual public MechanismPart
{
private:
	std::string _rotate;

public:
	Wheel() = default;
	Wheel(const std::string& name, const std::string& rotate)
		: MechanismPart(name), _rotate(rotate) {}
	std::string GetStatOfWheel()
	{
		return _rotate;
	}
	void SetStatOfWheel(const std::string& rotate)
	{
		_rotate = rotate;
	}
};

class Engine : virtual public MechanismPart
{
private:
	std::string _work;

public:
	Engine() = default;
	Engine(const std::string& name, const std::string& work)
		: MechanismPart(name), _work(work) {}
	std::string GetStatOfEngine()
	{
		return _work;
	}
	void SetStatOfEngine(const std::string& work)
	{
		_work = work;
	}
};


class Automobil : public Wheel, public Door, public Engine 
{
public:
	Automobil(const std::string& door, bool isOpen,
		const std::string& wheel, const std::string& rotate,
		const std::string& engine, const std::string& work)
		: Door(door, isOpen), Wheel(wheel, rotate), Engine(engine, work) {}
};




int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));

	Automobil a("дверь", false, "")

	return 0;
}

#pragma once
/*
Dokoñczyæ (niczego nie zmieniaj¹c, jedynie dopisuj¹c) deklaracjê klas CEngine i CCar tak, ¿eby poprawnie dzia³a³y w podanej funkcji main.
*/

class CEngine
{
private:
	int* Power;

public:
	CEngine(int pPower) : Power(new int(pPower)) {}
	~CEngine() {
		delete Power;
	}
	int getPowerOfEngine() {
		return *this->Power;
	}
	void increasePowerOfEngine(int pow) {
		*this->Power += pow;
	}

};

class CCar
{
private:
	CEngine* pEngine;

public:
	CCar(int Power) : pEngine(new CEngine(Power)) {}

	~CCar() {
		delete pEngine;
	}
	int getPowerOfEngine() {
		return pEngine->getPowerOfEngine();
	}
	void increasePowerOfEngine(int num) {
		pEngine->increasePowerOfEngine(num);
		return;
	}
};

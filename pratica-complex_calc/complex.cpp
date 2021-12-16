#include "complex.h"

void Complexos::com_read(){
		cout << "Valor Real: ";
		cin >> _real;
		cout << "Valor Imaginário: ";
		cin >> _img;
}
double Complexos::get_real(){
		// Retornar Valor Real
		return ((*this)._real);
	}
double Complexos::get_img(){
		// Retornar Valor Imaginário
		return ((*this)._img);
	}

// Mostrar Valor do Número Entrado
void Complexos::display(){
	if (_img >= 0)
		cout << _real << '+' << _img << "i" << endl;
	else
		cout << _real << '-' << _img << "i" << endl;
}

Complexos Complexos::operator+(Complexos o2){
	Complexos temp;

	temp._real = _real + o2._real;

	temp._img = _img + o2._img;

	return temp;
}

Complexos Complexos::operator-(Complexos o2){
	Complexos temp;

	temp._real = _real - o2._real;

	temp._img = _img - o2._img;

	return temp;
}

Complexos Complexos::operator*(Complexos o2){
	Complexos temp;

	temp._real = (_real * o2._real) + (-1 * (_img * o2._img));

	temp._img = (_img * o2._real) + (_real * o2._img);

	return temp;
}
// Retorna Conjugado
Complexos Complexos::operator~(void){
Complexos temp;

temp._real = _real;

temp._img = -1 * _img;

return temp;
}

Complexos Complexos::operator/(Complexos o2){
	Complexos o, num, den, temp;

	// Receber Conjufgado
	o = ~o2;

	// Calcular Numerador e Denominador
	num = (*this) * (o);
	den = o2 * o;

	// Dividir Real
	temp._real = num._real / den._real;

	// Dividir Imaginário
	temp._img = num._img / den._real;

	return temp;
}



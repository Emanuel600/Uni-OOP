/*
 * Definição de Métodos
 */
#include "poli_p2.h"

using namespace std;
Funcao::Funcao(){ return; }

Funcao::Funcao(Funcao *f){ return; }
// Função Virtual
double Funcao::operator()(double x){ return 0; }
// Função Estática
double Funcao::integrar(Funcao *f, double x0, double x1, double step){
	if((f==NULL) | (x0==x1) | (step<=0)){ // Para evitar problemas
		cerr << "Parâmetros inválidos" << endl;
		return -1; // CÃ³digo de erro
	}
	double i=0, area=0, op;

	for (i=x0; i<x1; i+=step){
		op=(*f)(i);
		#ifdef NDEBUG
		if(step==0.01) // Não quero 5e5 linhas de saída toda vez que testar algo
			cout << "f(" << i << ")=" << op << endl;
		#endif
		area += op*step;
	}
	return area;
}

// Função Constante
Constante::Constante(double val){ _value=val; }
double Constante::operator()(double x){ return _value; }

// Função Escalar
Escalar::Escalar(){
	_value=1;
	comp=NULL;
}
Escalar::Escalar(double val, Funcao *f){
	_value=val;
	comp=f;
}
Escalar::Escalar(double val){
	_value=val;
	comp=NULL;
}
Escalar::Escalar(Funcao *f){
	_value=1;
	comp=f;
}

double Escalar::operator()(double x){
	if(comp)
		return _value*(*comp)(x);

	return _value*x;
}

// Função Potencial
Potencial::Potencial(){
	_value=1;
	comp=NULL;
}
Potencial::Potencial(double val, Funcao *f){
	_value=val;
	comp=f;
}
Potencial::Potencial(double val){
	_value=val;
	comp=NULL;
}
Potencial::Potencial(Funcao *f){
	_value=1;
	comp=f;
}

double Potencial::operator()(double x){
	if(comp)
		return pow((*comp)(x), _value);

	return pow(x, _value);
}

// Função Exponencial
Exponencial::Exponencial(double val, Funcao *f){
	_value=val;
	comp=f;
}
Exponencial::Exponencial(double val){
	_value=val;
	comp=NULL;
}
Exponencial::Exponencial(Funcao *f){
	_value=1;
	comp=f;
}
Exponencial::Exponencial(){
	_value=1;
	comp=NULL;
}

double Exponencial::operator()(double x){
	if(comp)
		return pow(_value, (*comp)(x));
	
	return pow(_value, x);
}

// Função Seno
Seno::Seno(double val, Funcao *f){ comp=f; }
Seno::Seno(double val){ comp=NULL; }
Seno::Seno(Funcao *f){ comp=f; }
Seno::Seno(){ comp=NULL; }

double Seno::operator()(double x){
	if (comp)
		return sin((*comp)(x));

	return sin(x);
}

// Função Coseno
Coseno::Coseno(double val, Funcao *f){ comp=f; }
Coseno::Coseno(double val){ comp=NULL; }
Coseno::Coseno(Funcao *f){ comp=f; }
Coseno::Coseno(){ comp=NULL; }

double Coseno::operator()(double x){
	if (comp)
		return cos((*comp)(x));

	return cos(x);
}

// Agregar Funções
void FuncaoAgregada::agrega(Funcao *f){
	funcoes.push_back(f);
}

double FuncaoAgregada::operator()(double x){
	double soma=0.0;
	vector<Funcao*>::iterator it;

	for(it=funcoes.begin(); it != funcoes.end(); ++it)
		soma+=(**it)(x);
	return soma;
}

void testar(Funcao *f, double a, double b, double step, double real){
	double area=Funcao::integrar(f, a, b, step);
	double erro=100*abs(real-area)/double(real);
	#ifdef DEBUG // Para ver se está calculando normalmente
	cout << "f(" << a << ")= " << (*f)(a) << endl;
	cout << "f(" << b << ")= " << (*f)(b) << endl;
	#endif
	cout << "Valor estimado da integral de f(x) no intervalo ["<< a << "," << b << "]: " << area << endl;
	cout << "Valor real: " << real << endl;
	cout << "Erro real: " << erro << "%" << endl;
	cout << endl;
}

void teste(){
	Constante f(5); // 5
	cout << "=== Teste 1: f(x)=5 ===" << endl;
	testar(&f, 3, 5, 1e-5, 10);

	Escalar g(2); // 2x
	cout << "=== Teste 2: f(x)=2x ===" << endl;
	testar(&g, 1, 6, 1e-5, 35);

	Potencial h(2); // x^2
	cout << "=== Teste 3: f(x)=x^2 ===" << endl;
	testar(&h, -2, 4, 1e-5, 24);

	Constante parte(-1);
	FuncaoAgregada i;

	i.agrega(&parte) ; i.agrega(&g); // 2x-1
	cout << "=== Teste 4: f(x)=2x-1 ===" << endl;
	testar(&i, -3, 10, 1e-5, 78);

	Seno j(&i); // sen(2x-1)
	cout << "=== Teste 5: f(x)=sen(2x-1) ===" << endl;
	testar(&j, 4, 8, 1e-5, (cos(7)-cos(15))/2);

	Escalar k(5, &j); // 5sen(2x-1)
	cout << "===Teste 6: f(x)=5sen(2x-1) ===" << endl;
	testar(&k, (M_PI+1)/2, M_PI+1, 1e-5, -(5+5*cos(1))/double(2));

	FuncaoAgregada l;
	l.agrega(&k) ; l.agrega(&f) ; l.agrega(&h); // x^2+5sen(2x-1)+5
	cout << "===Teste 7: f(x)=x^2+5sen(2x-1)+5===" << endl;
	testar(&l, 0, 5, 0.01, -(15*cos(9)-15*cos(1)-400)/double(6));

	cout << "=== Final da Rotina de Testes ===" << endl;
}

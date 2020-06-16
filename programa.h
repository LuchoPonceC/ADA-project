#include "secuencia.h"
#include <time.h>

#define VORAZ 1
#define RECURSIVO 1
#define MEMOIZADO 1
#define DINAMICO 0

class Programa{
private:
	int casos;
	Secuencias *sec;
	clock_t t;
public:
	void IniciarPrograma();
	void RellenarDatos();
	void Ejecutar();
};


void Programa::IniciarPrograma(){
	string temporal;
	getline(cin,temporal);
	casos = stoi(temporal);
	for(int i=0; i<casos;i++){
		sec = new Secuencias;
		RellenarDatos();
		Ejecutar();
		delete sec;
	}	
}


void Programa::Ejecutar(){
	if(VORAZ){
		t = clock();
		sec->set_resultado(sec->Voraz_func());
		cout<<"VORAZ: El resultado es : "<<sec->get_resultado()<<" y se demora "<<(float)(clock()-t)*1000/CLOCKS_PER_SEC<<endl;
	}
	
	if(MEMOIZADO){
		t = clock();
		sec->set_resultado(sec->Memoizado_func());
		cout<<"MEMOIZADO: El resultado es : "<<sec->get_resultado()<<" y se demora "<<(float)(clock()-t)*1000/CLOCKS_PER_SEC<<endl;
	}
	if(RECURSIVO){
		t = clock();
		sec->set_resultado(sec->Recursivo_func());
		cout<<"RECURSIVO: El resultado es : "<<sec->get_resultado()<<" y se demora "<<(float)(clock()-t)*1000/CLOCKS_PER_SEC<<endl;
	}
	if(DINAMICO){
		t = clock();
		sec->set_resultado(sec->Dinamico_func());
		cout<<"DINAMICO: El resultado es : "<<sec->get_resultado()<<" y se demora "<<(float)(clock()-t)/CLOCKS_PER_SEC<<endl;
	}

}

void Programa::RellenarDatos(){
	string temporal;
	getline(cin,temporal);
	sec->LlenarVectores(temporal,TIPO_A);
	getline(cin,temporal);
	sec->LlenarVectores(temporal,TIPO_B);	
	if(TESTING){

		sec->MostrarPesos(TIPO_A);
		//sec->MostrarWeightsAcumulado(TIPO_A);
		sec->MostrarPesos(TIPO_B);
		//sec->MostrarWeightsAcumulado(TIPO_B);
		
	}
}






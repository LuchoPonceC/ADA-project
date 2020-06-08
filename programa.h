#include "secuencia.h"

#define VORAZ 0
#define RECURSIVO 1
#define MEMOIZADO 0
#define DINAMICO 0

class Programa{
private:
	int casos;
	Secuencias *sec;
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
		sec->set_resultado(sec->Voraz_func());
		cout<<"VORAZ"<<endl;
		cout<<"El resultado es : "<<sec->get_resultado()<<endl;
	}
	if(RECURSIVO){
		sec->set_resultado(sec->Recursivo_func());
		cout<<"RECURSIVO"<<endl;
		cout<<"El resultado es : "<<sec->get_resultado()<<endl;
	}
	if(MEMOIZADO){
		cout<<"MEMOIZADO"<<endl;
		sec->set_resultado(sec->Memoizado_func());
		cout<<"El resultado es : "<<sec->get_resultado()<<endl;
	}
	if(DINAMICO){
		cout<<"DINAMICO"<<endl;
		sec->set_resultado(sec->Dinamico_func());
		cout<<"El resultado es : "<<sec->get_resultado()<<endl;
	}

}

void Programa::RellenarDatos(){
	string temporal;
	getline(cin,temporal);
	sec->LlenarVectores(temporal,TIPO_A);
	getline(cin,temporal);
	sec->LlenarVectores(temporal,TIPO_B);	
	if(TESTING){
		sec->MostrarWeights(TIPO_A);
		sec->MostrarWeights(TIPO_B);
	}
}






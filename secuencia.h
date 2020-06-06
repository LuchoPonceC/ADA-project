#include <vector>
#include <string>

#define TIPO_A 0
#define TIPO_B 1
#define TESTING 1


typedef int dataType;

using namespace std;

class Secuencias{

private:
		
	vector<int> A_vector;
	vector<int> B_vector;
	vector<dataType> A_weights;
	vector<dataType> B_weights;
	dataType resultado;

public:

	void set_resultado(dataType resultado);
	void LlenarVectores(string dato, int tipo);
	void MostrarVector(int tipo);
	void LlenarWeights(int tipo);
	void MostrarWeights(int tipo);
	dataType get_resultado();


	//FUNCIONES VORAZ :
	dataType Voraz_func();		




	//FUNCIONES RECURSIVO:
	dataType Recursivo_func();		




	//FUNCIONES MEMOIZADO:
	dataType Memoizado_func();		




	//FUNCIONES FINAMICO:
	dataType Dinamico_func();		
	

};



dataType Secuencias::Voraz_func(){
	return 0;
}	
dataType Secuencias::Recursivo_func(){

	return 0;




}		
dataType Secuencias::Memoizado_func(){
	return 0;
}		
dataType Secuencias::Dinamico_func(){
	return 0;
}		







void Secuencias::set_resultado(dataType resultado){
	this->resultado = resultado;
}

dataType Secuencias::get_resultado(){
	return this->resultado;
}

void Secuencias::LlenarVectores(string dato, int tipo){
	
	vector<int> *current = (tipo == TIPO_A) ? &A_vector : &B_vector;

	for(int i=0; i<dato.length(); i++){
		current->push_back(dato[i]-48);
	}
	LlenarWeights(tipo);
			
}

void Secuencias::MostrarVector(int tipo){


	vector<int> *current = (tipo == TIPO_A) ? &A_vector : &B_vector;

	for(int i=0;i<current->size();i++){
		cout<<(*current)[i]<<" - ";
	}

	cout<<endl;
}

void Secuencias::MostrarWeights(int tipo){

	vector<int> *current = (tipo == TIPO_A) ? &A_weights : &B_weights;

	for(int i=0;i<current->size();i++){
		cout<<(*current)[i]<<" - ";
	}

	cout<<endl;
}

void Secuencias::LlenarWeights(int tipo){

	bool esta_sumando = false;
	int suma = 0;	
	vector<dataType> *current, *current_vector;
	if(tipo == TIPO_A){
		current = &A_weights;
		current_vector = &A_vector;
	}
	else{
		current = &B_weights;
		current_vector = &B_vector;
	}

	for(int i=0; i<current_vector->size(); i++){

		if((*current_vector)[i] == 1){
			esta_sumando = true;
			suma++;
			if(i==current_vector->size()-1){
				current->push_back(suma);	
			}
		}
		else{
			if(esta_sumando){
				current->push_back(suma);
				esta_sumando = false;
				suma = 0;
			}
		}
	}

}




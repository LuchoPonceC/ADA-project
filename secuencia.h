#include <vector>
#include <string>
#include <algorithm>

#define	DIVISION 1
#define AGRUPACION 2


#define TIPO_A 0
#define TIPO_B 1
#define TESTING 1


typedef double dataType;

using namespace std;

class Secuencias{

private:
		
	vector<int> A_vector;
	vector<int> B_vector;
	vector<dataType> A_weights;
	vector<dataType> A_acumulado;
	vector<dataType> B_weights;
	vector<dataType> B_acumulado;
	dataType resultado;
	

public:
	
	void MostrarWeightsAcumulado(int tipo);
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
	dataType OPT(int i, int j);



	//FUNCIONES MEMOIZADO:
	dataType Memoizado_func();		




	//FUNCIONES FINAMICO:
	dataType Dinamico_func();		
	

};



dataType Secuencias::Voraz_func(){
	return 0;
}	


dataType Secuencias::Recursivo_func(){

	return OPT(A_weights.size()-1,B_weights.size()-1);		

}		

dataType Secuencias::OPT(int i, int j){

	if(i==0 and j!=0){
		return A_weights[i]/B_acumulado[j];
	}
	if(i!=0 and j==0){
		return A_acumulado[i]/B_weights[j];
	}
	
	if(i==0 and j==0){
		return A_weights[i]/B_weights[j];
	}	

	vector<dataType> valores;
	valores.push_back(A_weights[i]/B_weights[j] + OPT(i-1,j-1));

	for(int k=j-1;k>=1;k--){
		valores.push_back(A_weights[i]/(B_acumulado[j]-B_acumulado[k-1])+OPT(i-1,k-1));
	}
	for(int k=i-1;k>=1;k--){
		valores.push_back((A_acumulado[i]-A_acumulado[k-1])/B_weights[j]+OPT(k-1,j-1));
	}
	
	return *std::min_element(valores.begin(), valores.end());
		

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

	vector<dataType> *current = (tipo == TIPO_A) ? &A_weights : &B_weights;

	for(int i=0;i<current->size();i++){
		cout<<(*current)[i]<<" - ";
	}

	cout<<endl;
}

void Secuencias::MostrarWeightsAcumulado(int tipo){
	vector<dataType> *current = (tipo == TIPO_A) ? &A_acumulado : &B_acumulado;

	for(int i=0;i<current->size();i++){
		cout<<(*current)[i]<<" - ";
	}

	cout<<endl;

}

void Secuencias::LlenarWeights(int tipo){

	bool esta_sumando = false;
	int suma = 0;	
	vector<dataType> *current; 
	vector<int> *current_vector;
	vector<dataType> *current_weights_acumulado;
	if(tipo == TIPO_A){
		current = &A_weights;
		current_vector = &A_vector;
		current_weights_acumulado = &A_acumulado;
	}
	else{
		current = &B_weights;
		current_vector = &B_vector;
		current_weights_acumulado = &B_acumulado;
	}

	for(int i=0; i<current_vector->size(); i++){

		if((*current_vector)[i] == 1){
			esta_sumando = true;
			suma++;
			if(i==current_vector->size()-1){
				current->push_back(suma);	
				if(current_weights_acumulado->size()==0){
					current_weights_acumulado->push_back(suma);
				}
				else{
					current_weights_acumulado->push_back(suma+((*current_weights_acumulado)[current_weights_acumulado->size()-1]));
				}
			}
		}
		else{
			if(esta_sumando){
				current->push_back(suma);
				if(current_weights_acumulado->size()==0){
					current_weights_acumulado->push_back(suma);
				}
				else{
					current_weights_acumulado->push_back(suma+((*current_weights_acumulado)[current_weights_acumulado->size()-1]));
				}
				esta_sumando = false;
				suma = 0;
			}
		}
	}

}




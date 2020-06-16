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
	dataType** Matriz;
	

public:
	
	Secuencias();
	void MostrarPesosAcumulado(int tipo);
	void set_resultado(dataType resultado);
	void LlenarVectores(string dato, int tipo);
	void MostrarVector(int tipo);
	void LlenarPesos(int tipo);
	void MostrarPesos(int tipo);
	dataType get_resultado();



	//FUNCIONES VORAZ :
	dataType Voraz_func();		
	dataType Voraz(int i, int j);




	//FUNCIONES RECURSIVO:
	dataType Recursivo_func();		
	dataType OPT(int i, int j);



	//FUNCIONES MEMOIZADO:
	dataType Memoizado_func();	
	dataType Memoizado(int i, int j);	
	void iniciarMatriz();
	void casoBase();
	void freeMatriz();



	//FUNCIONES FINAMICO:
	dataType Dinamico_func();		
	

};

Secuencias::Secuencias() {
	this->Matriz=nullptr;
}



dataType Secuencias::Voraz_func(){
		
	return Voraz(0,0);
}	

dataType Secuencias::Voraz(int i, int j){

	if(i==(A_weights.size()-1) && (j==B_weights.size()-1)){
		return A_weights[i]/B_weights[j];
	}

	if(i==(A_weights.size()-1) && (j!=B_weights.size()-1)){
		dataType auxiliar = 0;
		do{
			auxiliar+=B_weights[j];
			j++;

		}while(j!=B_weights.size());
		
		return A_weights[i]/auxiliar;
			
	}

	if(i!=(A_weights.size()-1) && (j==B_weights.size()-1)){
		dataType auxiliar = 0;
		do{
			auxiliar+=A_weights[i];
			i++;
		}while(i!=A_weights.size());

		return auxiliar/B_weights[j];
	}

	dataType auxiliar = B_weights[j];

	if(A_weights[i]/B_weights[j]>1){

		while(A_weights[i]/auxiliar>1){
			j++;
			if(j == B_weights.size()-1){
				j--;
				break;
			}
			auxiliar+=B_weights[j];
		}
	}
		
	return A_weights[i]/auxiliar + Voraz(i+1,j+1);
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

dataType Secuencias::Memoizado_func() {
	this->iniciarMatriz();
	this->casoBase();
	dataType result =  this->Memoizado(this->A_weights.size()-1, this->B_weights.size()-1);
	this->freeMatriz();
	this->Matriz = nullptr;
	return result;
}

void Secuencias::freeMatriz() {
	for(int i = 0; i < this->A_weights.size(); i++) {
		delete [] this->Matriz[i];
	}
	delete [] this->Matriz;
}

dataType Secuencias::Memoizado(int i, int j) {
	if(this->Matriz[i][j] != 0) {
		return this->Matriz[i][j];
	}
	vector<double> temp;
	temp.push_back(A_weights[i]/B_weights[j]+Memoizado(i-1, j-1));
	for(int k = j-1; k >= 1; k--) {
		temp.push_back((A_weights[i]/(B_acumulado[j]-B_acumulado[k-1]))+Memoizado(i-1, k-1));
	}
	for(int k = i-1; k >= 1; k--) {
		temp.push_back(((A_acumulado[i]-A_acumulado[k-1])/B_weights[j])+Memoizado(k-1, j-1));
	}
	this->Matriz[i][j] = (*min_element(temp.begin(), temp.end()));
	return this->Matriz[i][j];
}

void Secuencias::iniciarMatriz() {
	this->Matriz = new dataType*[this->A_weights.size()];
	for(int i = 0; i < this->A_weights.size(); i++) {
		this->Matriz[i] = new dataType[this->B_weights.size()]{0};
	}
}

void Secuencias::casoBase() {
	for(int i = 0; i < this->A_weights.size(); i++) {
		this->Matriz[i][0] = this->A_acumulado[i]/this->B_weights[0];
	}
	for(int i = 1; i < this->B_weights.size(); i++) {
		this->Matriz[0][i] = this->A_weights[0]/this->B_acumulado[i];
	}
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
	LlenarPesos(tipo);
			
}

void Secuencias::MostrarVector(int tipo){


	vector<int> *current = (tipo == TIPO_A) ? &A_vector : &B_vector;

	for(int i=0;i<current->size();i++){
		cout<<(*current)[i]<<" - ";
	}

	cout<<endl;
}

void Secuencias::MostrarPesos(int tipo){

	vector<dataType> *current = (tipo == TIPO_A) ? &A_weights : &B_weights;

	for(int i=0;i<current->size();i++){
		cout<<(*current)[i]<<" - ";
	}

	cout<<endl;
}

void Secuencias::MostrarPesosAcumulado(int tipo){
	vector<dataType> *current = (tipo == TIPO_A) ? &A_acumulado : &B_acumulado;

	for(int i=0;i<current->size();i++){
		cout<<(*current)[i]<<" - ";
	}

	cout<<endl;

}

void Secuencias::LlenarPesos(int tipo){

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

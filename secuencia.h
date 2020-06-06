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
	dataType minimo(dataType a, dataType b, dataType c);
	dataType OPT(int i, int j, int tipo, dataType A1, dataType B1);



	//FUNCIONES MEMOIZADO:
	dataType Memoizado_func();		




	//FUNCIONES FINAMICO:
	dataType Dinamico_func();		
	

};



dataType Secuencias::Voraz_func(){
	return 0;
}	


dataType Secuencias::Recursivo_func(){
			
	return min(OPT(0,0,DIVISION,A_weights[0],0),OPT(0,0,AGRUPACION,0,B_weights[0]));

}		

dataType Secuencias::OPT(int i, int j, int tipo, dataType A1, dataType B1){

	/*if((i>=A_weights.size() || j>=B_weights.size()) && (posicion == -1 || posicion == 1)){
		
		return 0;
	}*/	
	if(i+1 == A_weights.size() && j+1 == B_weights.size() ){
		return A_weights[i]/B_weights[j];	
	}	
	if(tipo == DIVISION){
		if(i+1 == A_weights.size()){
			dataType sum_temp = 0;
			for (int auxiliar = j; auxiliar<B_weights.size(); auxiliar++){
				sum_temp += B_weights[auxiliar];
			}		
			return A1/(B1+sum_temp);
		}
		if(j+1 == B_weights.size()){
			return 10000;	
		}
	}
	else{
		if(j+1 == B_weights.size()){
			dataType sum_temp = 0;
			for (int auxiliar = i; auxiliar<A_weights.size(); auxiliar++){
				sum_temp += A_weights[auxiliar];
			}		
			return (A1+sum_temp)/B1;
		}
		if(i+1 == A_weights.size()){
			return 10000;
		}
	}
/*	
	if(j>=B_weights.size() && (posicion == 1)){
		if((A_weights.size()-i)!=0) return 100000;	
		return 0;
	}
	if(i>=A_weights.size() && (posicion == -1)){
		if((B_weights.size()-j)!=0) return 100000;	
		return 0;
	}	
	if(i>=A_weights.size() || j>=B_weights.size()){return 100000;}
	*/
	if(tipo == DIVISION){
		return minimo(((A1/(B_weights[j]+B1))+OPT(i+1,j+1,DIVISION,A_weights[i+1],0)),
					OPT(i,j+1,DIVISION,A1,B_weights[j]+B1),
					((A1/(B_weights[j]+B1))+OPT(i+1,j+1,AGRUPACION,0,B_weights[j+1])));
	}
	else{
		return minimo((((A_weights[i]+A1)/B1) + OPT(i+1,j+1,AGRUPACION, 0, B_weights[j+1])),
			   		OPT(i+1,j,AGRUPACION,A1+A_weights[i],B1),
					(((A_weights[i]+A1)/B1)+OPT(i+1,j+1,DIVISION,A_weights[i+1],0)));	
	}
}



dataType Secuencias::Memoizado_func(){
	return 0;
}		



dataType Secuencias::Dinamico_func(){
	return 0;
}		





dataType Secuencias::minimo(dataType a, dataType b, dataType c){
	return min(a,min(b,c));
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

void Secuencias::LlenarWeights(int tipo){

	bool esta_sumando = false;
	int suma = 0;	
	vector<dataType> *current; 
	vector<int> *current_vector;
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




#include<iostream>
#include<cstdlib>
#include<fstream>


using namespace std;



char *leer_arreglo(istream& is,char *s, int n){
	is.getline(s,n);
	return s;
};

double leer(istream& is){
	double a;
	is>>a;
	return a;

}


double *leer_arreglo_double(istream& is, double *x, int n){
	
	for(int i=0; i<n; i++){
		x[i]=leer(is);
	}
	return x;
};


ostream& escribir_cadena(ostream& os,char *letra){
	os<<letra;
	return os;
}

ostream& escribir_double(ostream& os,double s){
	os<<s;
	return os;
}




ostream& escribir_char(ostream& os,char s){
	os<<s;
	return os;
}

int longitud_parcial(char* x, int i){
if(x[i] == '\0'){
return 0;
};
return 1 + longitud_parcial(x, i + 1);
};


int longitud_cadena(char* x){
return longitud_parcial(x, 0);
};


int longitud_parcial(double* x, int i){
if(x[i] == '\0'){
return 0;
};
return 1 + longitud_parcial(x, i + 1);
};


int longitud_cadena(double* x){
return longitud_parcial(x, 0);
};



ostream& escribir_arreglo(ostream& os, double *x,int colum){
	escribir_char(os,'&');
	
	for(int i=0; i<longitud_cadena(x); i++){
		escribir_double(os,x[i]);
			if((i+1)%colum==0)
			{

				escribir_char(os,'\n');
					
			} 
			escribir_char(os,' ');
	   escribir_char(os,'&');
	   		escribir_char(os,' ');
       }
     escribir_char(os,'&');  
return os;
};

int main(){

	ofstream ofs("salidaNumeros.txt");
	ifstream ifs("entradaNumeros.txt");
	
		
		
		int n=255;
		int n2;
		int colum;
		double * numero2= new double [n];
		double * numero= new double [n];
	
		
		
	cout<<"ingrese la cantidad de numeros"<<endl;
	cin>>n2;
	cout<<"ingrese la cantidad de Columnas"<<endl;
	cin>>colum;
	
	numero=leer_arreglo_double(ifs,numero2,n2);
	
for(int i=0; i<longitud_cadena(numero); i++){
		cout<<numero[i];
			if((i+1)%colum==0)
			{

				cout<<'\n';
					
			} 
			cout<<' ';
	   cout<<'&';
	   		cout<<' ';
       }
     cout<<'&';  
	



	ofs.close();
	ifs.close();
	
	delete []numero;
	delete []numero2;
	
		system ("pause");
	return EXIT_SUCCESS;
}

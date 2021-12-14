#include <iostream>
#include <fstream>
using namespace std;




int clientes(){
	int x;
	
	cout<<"-------MENU - CLIENTES -------"<<endl;
	cout<<"1. Agregar Cliente"<<endl;
	cout<<"2. Listar Cliente"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"Opcion:";
	cin>>x;
	return x;
}
	
	void agregar(ofstream &es){
		system("cls");
		string nombre;
		string cedula;
		string telefono;
		string direccion;
		int codigoempresa;
		es.open("Clientes.txt", ios::out | ios::app);
		cout<<"Nombre:";
		cin>>nombre;
		cout<<"Cedula:";
		cin>>cedula;
		cout<<"Telefono:";
		cin>>telefono;
		cout<<"Direccion:";
		cin>>direccion;
		cout<<"Codigo Empresa:";
		cin>>codigoempresa;
		es<<nombre<<" "<<cedula<<" "<<telefono<<" "<<direccion<<" "<<codigoempresa<<"\n";
		es.close();
	}
		
	void VerCliente(ifstream &Lec){
		string nombre;
		string cedula;
		string telefono;
		string direccion;
		int codigoempresa;
		Lec.open("Clientes.txt", ios::in);
		Lec>>nombre;
		while(!Lec.eof()){
			Lec>>cedula;
			Lec>>telefono;
			Lec>>direccion;
			Lec>>codigoempresa;
			
			cout<<"Nombre---:"<<nombre<<endl;
			cout<<"Cedula---:"<<cedula<<endl;
			cout<<"Telefono---:"<<telefono<<endl;
			cout<<"Direccion---:"<<direccion<<endl;
			cout<<"Codigo Empresa---:"<<codigoempresa<<endl;
			cout<<"--------------------------"<<endl;
			Lec>>nombre;
		}
		Lec.close();
		system("pause");
	}

int main(int argc, char *argv[]) {
	int opc;
	ofstream Esc;
	ifstream Lec;
	cout<<"BIENVENIDO FILM MAGIC"<<endl;
	cout<<"-------MENU-------"<<endl;
	cout<<"1. Clientes"<<endl;
	cout<<"2. Alquiler Video"<<endl;
	cout<<"3. Reportes"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"Opcion:";
	cin>>opc;
	
	
	switch(opc){
	case 1:
		int op;
		do{
			system("cls");
			op = clientes();
			switch(op){
				case 1: 
					agregar(Esc);
			case 2:
				VerCliente(Lec);
				break;
			}
		} while(op !=3);
		break;
	}
	return 0;
}


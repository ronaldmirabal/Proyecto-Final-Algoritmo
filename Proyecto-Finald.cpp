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
	
	int Alquiler(){
		int x;
		cout<<"-------MENU - ALQUILER -------"<<endl;
		cout<<"1. Agregar Alquiler"<<endl;
		cout<<"2. Listar Alquileres"<<endl;
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
		
	void RegistrarAlquiler(ofstream &es, int codigo){
		system("cls");
		string pelicula;
		string fecha;
		double precio;
		es.open("Alquiler.txt", ios::out | ios::app);
		cout<<"Nombre de la pelicula:";
		cin>>pelicula;
		cout<<"Precio de la pelicula:";
		cin>>precio;
		cout<<"Fecha Entrega:";
		cin>>fecha;
		es<<pelicula<<" "<<precio<<" "<<fecha<<" "<<codigo<<"\n";
		es.close();
	}
		
	void AgregarAlquiler(ifstream &Lec){
		system("cls");
		ofstream Esc;
		Lec.open("Clientes.txt", ios::in);
		int codigoempresaaux;
		string nombre;
		string cedula;
		string telefono;
		string direccion;
		int codigoempresa;
		bool encontrado = false;
		cout<<"Digite el numero de cliente: "<<endl;
		cin>>codigoempresaaux;
		Lec>>nombre;
		while(!Lec.eof() && !encontrado){
			Lec>>cedula;
			Lec>>telefono;
			Lec>>direccion;
			Lec>>codigoempresa;
			if(codigoempresa == codigoempresaaux){
				cout<<"Nombre---:"<<nombre<<endl;
				cout<<"Cedula---:"<<cedula<<endl;
				cout<<"Telefono---:"<<telefono<<endl;
				cout<<"Direccion---:"<<direccion<<endl;
				cout<<"Codigo Empresa---:"<<codigoempresa<<endl;
				cout<<"--------------------------"<<endl;
				encontrado = true;
			}
			Lec>>nombre;
		}
		Lec.close();
		if(!encontrado){
			cout<<"Cliente no encontado"<<endl;
			system("pause");
		}else{
			system("pause");
			RegistrarAlquiler(Esc, codigoempresaaux);
		}
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
		
	void ListarAlquiler(ifstream &Lec){
		system("cls");
		string pelicula;
		string fecha;
		double precio;
		int codigo;
		Lec.open("Alquiler.txt", ios::in);
		Lec>>pelicula;
		while(!Lec.eof()){
			Lec>>precio;
			Lec>>fecha;
			Lec>>codigo;
			
			cout<<"Pelicula---:"<<pelicula<<endl;
			cout<<"Precio---:"<<precio<<endl;
			cout<<"Fecha Entrega---:"<<fecha<<endl;
			cout<<"Codigo Cliente---:"<<codigo<<endl;
			cout<<"--------------------------"<<endl;
			Lec>>pelicula;
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
	cout<<"3. Salir"<<endl;
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
	case 2:
		int op2;
		do{
			system("cls");
			op2 = Alquiler();
			switch(op2){
			case 1:
				AgregarAlquiler(Lec);
				break;
			case 2:
				ListarAlquiler(Lec);
				break;
			}
		} while(op2 !=3);
		break;
	}
	
	return 0;
}


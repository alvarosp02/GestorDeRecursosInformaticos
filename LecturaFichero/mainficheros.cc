#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include <ctime>
#include <fstream>
#include "maquina.h"
#include "reserva.h"
#include "usuario.h"
using namespace std;

void leeUsuarios(list<Usuario> &usuarios){
	usuarios.clear();
	ifstream fichero("usuarios.txt");
	string aux;
	Usuario temp("111", "correo", 1, 1, 1, 1);
	while(getline(fichero,aux,',')){
		temp.setIdUsu(aux);
		getline(fichero,aux,',');
		temp.setCorreo(aux);
		getline(fichero,aux,',');
		temp.setLim_tiempo(stoi(aux));
		getline(fichero,aux,',');
		temp.setLim_nucleo(stoi(aux));
		getline(fichero,aux,',');
		temp.setTiempoDisp(stoi(aux));
		getline(fichero,aux,'\n');
		temp.setNucleoDisp(stoi(aux));
		usuarios.push_back(temp);
	}
	fichero.close();
}

void leeMaquinas(list<Maquina> &maquinas){
	maquinas.clear();
	ifstream fichero("maquinas.txt");
	string aux;
	Maquina temp("111", 1);
	while(getline(fichero,aux,',')){
		temp.setId_Maq(aux);
		getline(fichero,aux,',');
		if(aux=="true")
			temp.setEstado(1);
		else
			temp.setEstado(0);
		getline(fichero,aux,',');
		temp.setNuc_Tot(stoi(aux));
		getline(fichero,aux,'\n');
		temp.setNuc_Disp(stoi(aux));
		maquinas.push_back(temp);
	}
	fichero.close();
}

void leeReservas(list<Reserva> &reservas){
	reservas.clear();
	ifstream fichero("reservas.txt");
	string aux;
	Reserva temp("111","aaa", 1, 1,"maq");
	while(getline(fichero,aux,',')){
		temp.setId_reser(aux);
		getline(fichero,aux,',');
		temp.setCreador_reserva(aux);
		getline(fichero,aux,',');
		temp.setTiempo(stoi(aux)); //en time_t de fecha
		getline(fichero,aux,',');
		temp.setNuc_reser(stoi(aux));
		getline(fichero,aux,'\n');
		temp.setMaq_reser(aux);

		reservas.push_back(temp);
	}
	fichero.close();
}

void escribeUsuarios(list<Usuario> &usuarios){
	ofstream fichero("usuarios.txt");
	list<Usuario>::iterator i;
	for( i=usuarios.begin();i!=usuarios.end();i++){
		fichero<<i->getIdUsu()<<","<<
		i->getCorreo()<<","<<
		i->getLim_tiempo()<<","<< // tiempo 
		i->getLim_nucleo()<<","<< 
		i->getTiempoDisp()<<","<<
		i->getNucleoDisp()<<endl;
	}
	fichero.close();
}

void escribeReservas(list<Reserva> &reservas){
	ofstream fichero("reservas.txt");
	list<Reserva>::iterator i;
	for( i=reservas.begin();i!=reservas.end();i++){
		fichero<<i->getId_reser()<<","<<
		i->getCreador_reserva()<<","<<
		i->getTiempo()<<","<< //tiempo
		i->getNuc_reser()<<","<<
		i->getMaq_reser()<<endl;
	}
	fichero.close();
}

void escribeMaquinas(list<Maquina> &maquinas){
	ofstream fichero("maquinas.txt");
	list<Maquina>::iterator i;
	for( i=maquinas.begin();i!=maquinas.end();i++){
		fichero<<i->getIdMaq()<<","<<
		i->getEstado()<<","<<
		i->getNucleoTotal()<<","<<
		i->getNucleosDisp()<<","<<endl;
	}
	fichero.close();
}

menu1(){
	cout<<"1.- Crear reserva"<<endl;
	cout<<"2.- Modificar reserva"<<endl;
	cout<<"3.- Eliminar reserva"<<endl;
	cout<<"4.- Salir del sistema"<<endl;
}

menu2(){
	cout<<"1.- Alta usuario"<<endl;
	cout<<"2.- Baja usuario"<<endl;
	cout<<"3.- Limitar tiempo de reserva"<<endl;
	cout<<"4.- Limitar nucleos de reserva"<<endl;
	cout<<"5.- Salir del sistema"<<endl;
}

menu3(){
	cout<<"1.- Alta maquina"<<endl;
	cout<<"2.- Baja maquina"<<endl;
	cout<<"3.- Limitar tiempo de reserva"<<endl;
	cout<<"4.- Limitar nucleos de reserva"<<endl;
	cout<<"5.- Salir del sistema"<<endl;
}
int main(){
	//lectura de ficheros
	list<Maquina> maquinas;
	list<Usuario> usuarios;
	list<Reserva> reservas;
	leeUsuarios(usuarios);
	leeReservas(reservas);
	leeMaquinas(maquinas);

	string id;
	cout<<"Bienvenido al sistema de reserva de maquinas. Por favor, introduzca su ID para iniciar sesion"<<endl;
	cout<<"(usuario --> usuario, adminU --> Administrador1, adminM --> Administrador2)"<<endl;
	cin>>id;

	if(id == "usuario"){
		menu1();
		int opcion;
		while(opcion != 4){
			cin>>opcion;
			switch(opcion){
				menu1();
				case 1:
				{
					cout<<"Opcion 1"<<endl;
				}
				break;
				case 2:
				{
					cout<<"Opcion 2"<<endl;
				}
				break;
				case 3:
				{
					cout<<"Opcion 3"<<endl;
				}
				break;
				case 4:
				{
					cout<<"Saliendo del programa..."<<endl;
				}
				break;

				default: cout<<"Se ha ingresado una opcion incorrecta"<<endl;
				break;
			}
		}
	}
	if(id == "adminU"){
		menu2();
		int opcion;
		while(opcion != 5){
			cin>>opcion;
			switch(opcion){
				menu1();
				case 1:
				{
					cout<<"Opcion 1"<<endl;
				}
				break;
				case 2:
				{
					cout<<"Opcion 2"<<endl;
				}
				break;
				case 3:
				{
					cout<<"Opcion 3"<<endl;
				}
				break;
				case 4:
				{
					cout<<"Opcion 4"<<endl;
				}
				break;
				case 5:
				{
					cout<<"Saliendo del programa..."<<endl;
				}
				break;

				default: cout<<"Se ha ingresado una opcion incorrecta"<<endl;
				break;
			}
		}
	}

	if(id == "adminM"){
		menu3();
		int opcion;
		while(opcion != 5){
			cin>>opcion;
			switch(opcion){
				menu1();
				case 1:
				{
					cout<<"Opcion 1"<<endl;
				}
				break;
				case 2:
				{
					cout<<"Opcion 2"<<endl;
				}
				break;
				case 3:
				{
					cout<<"Opcion 3"<<endl;
				}
				break;
				case 4:
				{
					cout<<"Opcion 4"<<endl;
				}
				break;
				case 5:
				{
					cout<<"Saliendo del programa..."<<endl;
				}
				break;

				default: cout<<"Se ha ingresado una opcion incorrecta"<<endl;
				break;
			}
		}
	}


	//escritura de ficheros
	escribeUsuarios(usuarios);
	escribeReservas(reservas);
	escribeMaquinas(maquinas);
}

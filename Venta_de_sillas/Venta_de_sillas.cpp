// Venta_de_sillas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sillas_clas.h" 
#include <iostream>
#include <array> //for std::array
#define  D_SCL_SECURE_NO_WARNINGS
using namespace std;

int silla(char s);
int descuento_A(int des);
int descuento_B(int des);
int descuento_C(int des);
int _tmain(int argc, _TCHAR* argv[])
{
	sillas_clas s = sillas_clas();
	sillas_clas v = sillas_clas();
	int VACIO = -858993460;
	std::array<sillas_clas,1000>listSilla;
	std::array<sillas_clas, 1000>lisDia;
	bool bandera = false;
	char seleccion;
	int  cantidad;
	int cont = 0;


	int cantidad_A = 0;
	int cantidad_B = 0;
	int cantidad_C = 0;
	
	char menu;
	while (true)
	{
		
		bandera = false;
		system("cls");
		cout << "***************************************** \n";
		cout << "*               MENU                    * \n";
		cout << "***************************************** \n";
		cout << "*                                       * \n";
		cout << "*  COMPRAR--1                           * \n";
		cout << "*                                       * \n";
		cout << "*  VENTAS_DEL_DIA--2                    * \n";
		cout << "***************************************** \n\n";
		cout << "Ingrese la accion a realizar: ";
		cin >> menu;
		
		//comprar
		if (menu == '1'){
			s.~sillas_clas();
			while (bandera != true){
				sillas_clas s = sillas_clas();
				system("cls");
				cout << "***Seleccione el tipo de mueble y la cantidad**** \n";
				cout << "***MUEBLE A**** \n";
				cout << "***MUEBLE B**** \n";
				cout << "***MUEBLE C**** \n";

				cout << "Ingrese un tipo de mueble: \n";
				cin >> seleccion;
				s.silla = seleccion;


				system("cls");

				if (seleccion == 'A' || seleccion == 'B' || seleccion == 'C')
				{
					char d;
					cout << "Ingrese cantidad: \n";
					cin >> cantidad;
					s.cantidad = cantidad;
					cout << "¿Desea segir comprando? s/n: \n";
					cin >> d;
					listSilla[cont] = s;
					lisDia[cont] = s;
					if (d == 'n' || d == 'N')
					{


						for (size_t i = 0; i < 1000; i++)
						{


							if (lisDia[i].cantidad != VACIO)
							{
								//cout << listSilla[i].cantidad << listSilla[i].silla << "\n";

								if (lisDia[i].silla == 'A')
								{
									cantidad_A += lisDia[i].cantidad;

								}
								if (lisDia[i].silla == 'B')
								{
									cantidad_B += lisDia[i].cantidad;

								}
								if (lisDia[i].silla == 'C')
								{
									cantidad_C += lisDia[i].cantidad;

								}

							}

						}


						/*impresion de el tiked de compra
						*/

						system("cls");
						int precio_A = cantidad_A*silla('A');
						int descuento_N_A = descuento_A(cantidad_A);
						int descuento_A_final = precio_A - descuento_N_A;

						cout << "Usted compro silla de tipo A : " << cantidad_A << "\n"
							<< "Por un precio unitario " << precio_A << "\n"
							<< "Descuento aplicable  " << descuento_N_A << "\n"
							<< "Precio total: " << descuento_A_final << "\n\n";

						int precio_B = cantidad_B*silla('B');
						int descuento_N_B = descuento_B(cantidad_B);
						int descuento_B_final = precio_B - descuento_N_B;

						cout << "Usted compro silla de tipo A : " << cantidad_B << "\n"
							<< "Por un precio unitario " << precio_B << "\n"
							<< "Descuento aplicable  " << descuento_N_B << "\n"
							<< "Precio total: " << descuento_B_final << "\n\n";


						int precio_C = cantidad_C*silla('C');
						int descuento_N_C = descuento_C(cantidad_C);
						int descuento_C_final = precio_C - descuento_N_C;

						cout << "Usted compro silla de tipo A : " << cantidad_C << "\n"
							<< "Por un precio unitario " << precio_C << "\n"
							<< "Descuento aplicable  " << descuento_N_C << "\n"
							<< "Precio total: " << descuento_C_final << "\n\n";

						int total = descuento_A_final + descuento_B_final + descuento_C_final;

						cout << "Precio total: $ " << total << "\n\n";

						
						
						char m;
						cout << "Presione cualquier tecla para ir al menu inicio";
						cin >> m;
						//vaciar tiked del dia 
						
						cantidad_A = 0;
						cantidad_B = 0;
						cantidad_C = 0;
						bandera = true;

						
					}
					system("cls");
				}
				cont++;
			}
		} // fin de comprar

		// imprimir ventas del dia 

		if (menu == '2')
		{
			for (size_t i = 0; i < 1000; i++)
			{


				if (listSilla[i].cantidad != VACIO)
				{
					//cout << listSilla[i].cantidad << listSilla[i].silla << "\n";

					if (listSilla[i].silla == 'A')
					{
						cantidad_A += listSilla[i].cantidad;

					}
					if (listSilla[i].silla == 'B')
					{
						cantidad_B += listSilla[i].cantidad;

					}
					if (listSilla[i].silla == 'C')
					{
						cantidad_C += listSilla[i].cantidad;

					}

				}

			}


			

			system("cls");
			int precio_A = cantidad_A*silla('A');
			int descuento_N_A = descuento_A(cantidad_A);
			int descuento_A_final = precio_A - descuento_N_A;
			cout << "Ticket";
			cout << "Usted compro silla de tipo A : " << cantidad_A << "\n"
				<< "Por un precio unitario " << precio_A << "\n"
				<< "Descuento aplicable  " << descuento_N_A << "\n"
				<< "Precio total: " << descuento_A_final << "\n\n";

			int precio_B = cantidad_B*silla('B');
			int descuento_N_B = descuento_B(cantidad_B);
			int descuento_B_final = precio_B - descuento_N_B;

			cout << "Usted compro silla de tipo A : " << cantidad_B << "\n"
				<< "Por un precio unitario " << precio_B << "\n"
				<< "Descuento aplicable  " << descuento_N_B << "\n"
				<< "Precio total: " << descuento_B_final << "\n\n";


			int precio_C = cantidad_C*silla('C');
			int descuento_N_C = descuento_C(cantidad_C);
			int descuento_C_final = precio_C - descuento_N_C;

			cout << "Usted compro silla de tipo A : " << cantidad_C << "\n"
				<< "Por un precio unitario " << precio_C << "\n"
				<< "Descuento aplicable  " << descuento_N_C << "\n"
				<< "Precio total: " << descuento_C_final << "\n\n";

			int total = descuento_A_final + descuento_B_final + descuento_C_final;

			cout << "Precio total: $ " << total << "\n\n";
			

			char m;
			cout << "Presione cualquier tecla para ir al menu inicio";
			cantidad_A = 0;
			cantidad_B = 0;
			cantidad_C = 0;
			cin >> m;
			
		}


	}
	


	system("PAUSE");
	return 0;
}

 int silla(char s)
{
	 if (s == 'A'){
		 return 500;
	 }
	 else if(s=='B'){
		 return 700;
	 }
	 else if (s == 'C')
	 {
		 return 1000;
	 }
	return 0;
}

 int descuento_A(int des)
 {
	 if (des / 5 > 0)
	 {
		 return (int)(des / 5)*75;
	 }

	 return 0;
 }

 int descuento_B(int des)
 {
	 if (des / 5 > 0)
	 {
		 return (int)(des / 5) * 175;
	 }

	 return 0;
 }

 int descuento_C(int des)
 {
	 if (des / 5 > 0)
	 {
		 return (int)(des / 5) * 350;
	 }

	 return 0;
 }
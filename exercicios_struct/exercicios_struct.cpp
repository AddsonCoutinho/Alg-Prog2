// exercicios_struct.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

struct horario
{
	int hora = 0, minuto = 0, segundo = 0;
};
struct datas{
	int dia, mes, ano;
};
struct pessoa
{
	datas nasc;
	string nome;
};

void CriaData(datas D) { 
	D.mes = 1 + (rand() % 12); 
	D.ano = 1940 + (rand() % 74); 
	D.dia = 1 + (rand() % 30); 
}
void soma_horario(horario first, horario second) {
	horario total, acumulador;

	total.segundo = first.segundo + second.segundo;
	if (total.segundo >= 60) {
		total.segundo -= 60;
		total.minuto = 1;
	}
	total.minuto += first.minuto + second.minuto;
	if (total.minuto >= 60) {
		total.minuto -= 60;
		total.hora = 1;
	}
	total.hora += first.hora + second.hora;

	cout << total.hora << " : "<< total.minuto << " : " << total.segundo;
}

void exercicio1() {
	horario primeiro, segundo;
	cout << "Digite o primeiro horario : " << endl;
	cout << "hora" << " : ";
	cin >> primeiro.hora;
	cout << "minutos" << " : ";
	cin >> primeiro.minuto;
	cout << "segundos" << " : ";
	cin >> primeiro.segundo;
	cout << "Digite o segundo horario : " << endl;
	cout << "hora" << " : ";
	cin >> segundo.hora;
	cout << "minutos" << " : ";
	cin >> segundo.minuto;
	cout << "segundos" << " : ";
	cin >> segundo.segundo;

	soma_horario(primeiro, segundo);
}
void exercicio2() {
	entrada_data();
}
void exercicio3() {
	
}

int ano() {
	int year;
	cout << "ano : ";
	cin >> year;
	if (year < 1) {
		ano();
	}
	else
		if (year > 2018) {
			ano();
		}	else {
			return year;
		}
}
int mes() {
	int month;
	cout << "mes : ";
	cin >> month;
	if (month < 1) {
		mes();
	}
	else
		if (month > 12) {
			mes();
		}	else {
			return month;
		}
}
int dia(bool bissexto, int mes) {
	int day;
	cout << "Dia : ";
	cin >> day;
	if (day < 1) {
		dia(bissexto, mes);
	}
	else {
		if ((mes % 2) == 1) {
			if (day > 31) {
				dia(bissexto, mes);
			}
			else {
				return day;
			}
		}
		else {
			if (mes == 2) {
				if (bissexto == true) {
					if (day > 29) {
						dia(bissexto, mes);
					}
					else {
						return day;
					}
				}
				else
				{
					if (day > 28) {
						dia(bissexto, mes);
					}
					else {
						return day;
					}
				}
			}
			else {
				if (day > 30) {
					dia(bissexto, mes);
				}
				else {
					return day;
				}
			}
		}
	}
}
bool bissexto(int ano) {
	bool bissexto = false;

	if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
		bissexto = true;
	}
	return bissexto;
	cout << "não esta pronto" << endl;
}

void entrada_data() {			// NAO ESTA PRONTO
	bool bis;
	datas vali;

	cout << "digite uma data : " << endl;	
	vali.ano = ano();

	bis = bissexto(vali.ano);
	vali.mes = mes();

	vali.dia = dia(bis, vali.mes);
	cout << vali.dia << "/" << vali.mes << "/" << vali.ano ;

}

int main()
{
	srand(time(NULL));
    return 0;
}
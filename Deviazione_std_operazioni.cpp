#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

double a1, a2, x1, x2, ds1, ds2, dev_std_res;
double ex1, ex2, eds1, eds2;
char sign1, sign2, signds1, signds2;

char operazione;

double exp_sci(char segno, double esponente){
	
	if(segno == '-'){
		int exp = int(esponente);
		esponente = 1;
		for(int i = 0; i < exp; i++){
			esponente *= 0.1;
		}
	}
		
	if(segno == '+'){
		int exp = int(esponente);
		esponente = 1;
		for(int i = 0; i < exp; i++){
			esponente *= 10;
		}
	}
	
	return esponente;
}

void stampa_sci(double a){
	int counter = 0;
	
	if(a >= 1 && a <=10){
		cout << a << '\t';
	}
	
	if(a <= -1 && a >= -10){
		cout << a << '\t';
	}
	
	if(a >= 0 && a < 1){
		for(; a < 1;){
			counter++;
			a *= 10;
		}
		
		cout << a << "*10^-"<< counter << '\t';
	}
		
	if(a > 10){
		for(; a > 10;){
			counter++;
			a /= 10;
		}
		
		cout << a << "*10^"<< counter << '\t';
	}
	
	if(a > -1 && a < 0){
		for(; a > -1;){
			counter++;
			a *= 10;
		}
		
		cout << a << "*10^-"<< counter << '\t';
	}
	
	if(a < -10){
		for(; a < -10;){
			counter++;
			a /= 10;
		}
		
		cout << a << "*10^"<< counter << '\t';
	}

}


int main(){
	
	cout << "Benvenuto in Dev_Std_OP by rimaturus, dove OP sta per OverPow... Operation\n\n";
	
	cout << "Scegliere l'operazione da eseguire inserendo:\n";
	cout << "[+] somma\n" << "[-] sottrazione\n" << "[*] prodotto\n" << "[/] divisione\n";
	cin >> operazione;
	
	cout << "ACHTUNG! Specificare sempre il segno dell'esponente	es. 10^+2 o 10^-2 \n" << "Se l'esponente e' zero, assegnare un segno arbitrario	es. 10^+0 = 10^-0\n\n";
		
	if(operazione == '/'){
		cout << "Divisione\n";
		cout << "Inserire la formula nel formato:	a1*x1*10^N/a2*x2*10^N\n";
		scanf("%lf*%lf*10^%c%lf/%lf*%lf*10^%c%lf", &a1, &x1, &sign1, &ex1, &a2, &x2, &sign2, &ex2);
	
		ex1 = exp_sci(sign1, ex1);
		ex2 = exp_sci(sign2, ex2);
			
		cout << "Inserire la deviazione std di x1:	ds1*10^N\t";
		scanf("%lf*10^%c%lf", &ds1, &signds1, &eds1);
		eds1 = exp_sci(signds1, eds1);;
		
		cout << "Inserire la deviazione std di x2:	ds2*10^N\t";
		scanf("%lf*10^%c%lf", &ds2, &signds2, &eds2);
		eds2 = exp_sci(signds2, eds2);
		
		double r1 = (a1/(a2*x2*ex2));
		r1 = r1*r1;
		double d1 = ds1*ds1*eds1*eds1;
		r1 = r1*d1;
		
		double r2 = (a1*x1*ex1)/(a2*(x2*ex2*x2*ex2));
		r2 = r2*r2;
		double d2 = ds2*ds2*eds2*eds2;
		r2 = r2*d2;
		
		dev_std_res = sqrt(r1+r2);
		
		double div = (a1*x1*ex1)/(a2*x2*ex2);
		
		cout << "Risultato operazione\t";
		stampa_sci(div);
		cout << "Deviazione standard della divisione\t";
		stampa_sci(dev_std_res);
	}
		
	if(operazione == '*'){
		cout << "Moltiplicazione\n";
		cout << "Inserire la formula nel formato:	a1*x1*10^N*a2*x2*10^N\n";
		scanf("%lf*%lf*10^%c%lf*%lf*%lf*10^%c%lf", &a1, &x1, &sign1, &ex1, &a2, &x2, &sign2, &ex2);
		
		ex1 = exp_sci(sign1, ex1);
		ex2 = exp_sci(sign2, ex2);
			
		cout << "Inserire la deviazione std di x1:	ds1*10^N\t";
		scanf("%lf*10^%c%lf", &ds1, &signds1, &eds1);
		eds1 = exp_sci(signds1, eds1);;
		
		cout << "Inserire la deviazione std di x2:	ds1*10^N\t";
		scanf("%lf*10^%c%lf", &ds2, &signds2, &eds2);
		eds2 = exp_sci(signds2, eds2);
		
		double r1 = a1*a2*x2*ex2*ds1*eds1;
		r1 = r1*r1;
		double r2 = a1*a2*x1*ex1*ds2*eds2;
		r2 = r2*r2;

		dev_std_res = sqrt(r1+r2);
		double prod = a1*a2*x1*ex1*x2*ex2;
		
		cout << "Risultato operazione\t";
		stampa_sci(prod);
		cout << "Deviazione standard della moltiplicazione\t";
		stampa_sci(dev_std_res);
	}
	
	if(operazione == '+'){
		cout << "Addizione\n";
		cout << "Inserire la formula nel formato:	x1*10^N+x2*10^N\n";
		scanf("%lf*10^%c%lf+%lf*10^%c%lf", &x1, &sign1, &ex1, &x2, &sign2, &ex2);
		
		ex1 = exp_sci(sign1, ex1);
		ex2 = exp_sci(sign2, ex2);
			
		cout << "Inserire la deviazione std di x1:	ds1*10^N\t";
		scanf("%lf*10^%c%lf", &ds1, &signds1, &eds1);
		eds1 = exp_sci(signds1, eds1);;
		
		cout << "Inserire la deviazione std di x2:	ds1*10^N\t";
		scanf("%lf*10^%c%lf", &ds2, &signds2, &eds2);
		eds2 = exp_sci(signds2, eds2);
		
		double r1 = ds1*eds1;
		r1 = r1*r1;
		double r2 = ds2*eds2;
		r2 = r2*r2;

		dev_std_res = sqrt((r1+r2)/2);
		double sum = (x1*ex1+x2*ex2);
		
		cout << "Risultato operazione\t";
		stampa_sci(sum);
		cout << "Deviazione standard della somma\t";
		stampa_sci(dev_std_res);
	}
	
	if(operazione == '-'){
		cout << "Sottrazione\n";
		cout << "Inserire la formula nel formato:	x1*10^N-x2*10^N\n";
		scanf("%lf*10^%c%lf-%lf*10^%c%lf", &x1, &sign1, &ex1, &x2, &sign2, &ex2);
		
		ex1 = exp_sci(sign1, ex1);
		ex2 = exp_sci(sign2, ex2);
			
		cout << "Inserire la deviazione std di x1:	ds1*10^N\t";
		scanf("%lf*10^%c%lf", &ds1, &signds1, &eds1);
		eds1 = exp_sci(signds1, eds1);;
		
		cout << "Inserire la deviazione std di x2:	ds1*10^N\t";
		scanf("%lf*10^%c%lf", &ds2, &signds2, &eds2);
		eds2 = exp_sci(signds2, eds2);
		
		double r1 = ds1*eds1;
		r1 = r1*r1;
		double r2 = ds2*eds2;
		r2 = r2*r2;

		dev_std_res = sqrt((r1+r2)/2);
		double sub = (x1*ex1-x2*ex2);
		
		cout << "Risultato operazione\t";
		stampa_sci(sub);
		cout << "Deviazione standard della sottrazione\t";
		stampa_sci(dev_std_res);
	}
	
	
	return 0;
}
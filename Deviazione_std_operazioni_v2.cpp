#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

double a1, a2, x1, x2, ds1, ds2, dev_std_res;
double ex1, ex2, eds1, eds2;

char operazione;

double exp_sci(double esponente){
	
	if(esponente < 0){
		int exp = int(esponente);
		esponente = 1;
		for(int i = 0; i < exp; i++){
			esponente *= 0.1;
		}
	}
		
	if(esponente > 0){
		int exp = int(esponente);
		esponente = 1;
		for(int i = 0; i < exp; i++){
			esponente *= 10;
		}
	}
	
	if(esponente == 0){
		esponente = 1;
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
	
	//inizio area debug
	//fine area debug
		
	cout << "Benvenuto in Dev_Std_OP by rimaturus, dove OP sta per OverPow... Operation\n\n";
	
	cout << "Scegliere l'operazione da eseguire inserendo:\n";
	cout << "[+] somma\n" << "[-] sottrazione\n" << "[*] prodotto\n" << "[/] divisione\n" << "[e] esponenziale\n";
	cin >> operazione;
		
	if(operazione == '/'){
		cout << "Divisione\n";
		cout << "Inserire la formula nel formato:	a1*x1*10^N/a2*x2*10^N\n";
		scanf("%lf*%lf*10^%lf/%lf*%lf*10^%lf", &a1, &x1, &ex1, &a2, &x2, &ex2);
	
		ex1 = exp_sci(ex1);
		ex2 = exp_sci(ex2);
			
		cout << "Inserire la deviazione std di x1:	ds1*10^N\t";
		scanf("%lf*10^%lf", &ds1, &eds1);
		eds1 = exp_sci(eds1);;
		
		cout << "Inserire la deviazione std di x2:	ds2*10^N\t";
		scanf("%lf*10^%lf", &ds2, &eds2);
		eds2 = exp_sci(eds2);
		
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
		scanf("%lf*%lf*10^%lf*%lf*%lf*10^%lf", &a1, &x1, &ex1, &a2, &x2, &ex2);
		
		ex1 = exp_sci(ex1);
		ex2 = exp_sci(ex2);
			
		cout << "Inserire la deviazione std di x1:	ds1*10^N\t";
		scanf("%lf*10^%lf", &ds1, &eds1);
		eds1 = exp_sci(eds1);;
		
		cout << "Inserire la deviazione std di x2:	ds1*10^N\t";
		scanf("%lf*10^%lf", &ds2, &eds2);
		eds2 = exp_sci(eds2);
		
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
		scanf("%lf*10^%lf+%lf*10^%lf", &x1, &ex1, &x2, &ex2);
		
		ex1 = exp_sci(ex1);
		ex2 = exp_sci(ex2);
			
		cout << "Inserire la deviazione std di x1:	ds1*10^N\t";
		scanf("%lf*10^%lf", &ds1, &eds1);
		eds1 = exp_sci(eds1);;
		
		cout << "Inserire la deviazione std di x2:	ds1*10^N\t";
		scanf("%lf*10^%lf", &ds2, &eds2);
		eds2 = exp_sci(eds2);
		
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
		scanf("%lf*10^%lf-%lf*10^%lf", &x1, &ex1, &x2, &ex2);
		
		ex1 = exp_sci(ex1);
		ex2 = exp_sci(ex2);
			
		cout << "Inserire la deviazione std di x1:	ds1*10^N\t";
		scanf("%lf*10^%lf", &ds1, &eds1);
		eds1 = exp_sci(eds1);;
		
		cout << "Inserire la deviazione std di x2:	ds1*10^N\t";
		scanf("%lf*10^%lf", &ds2, &eds2);
		eds2 = exp_sci(eds2);
		
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
	
	if(operazione == 'e'){
		cout << "Esponenziale\n";
		cout << "Inserire la formula nel formato:	a*e^(x*10^N)\n";
		scanf("%lf*e^(%lf*10^%lf)", &a2, &x2, &ex2);
		
		ex2 = exp_sci(ex2);
			
		cout << "Inserire la deviazione std di x:	dsx*10^N\t";
		scanf("%lf*10^%lf", &ds2, &eds2);
		eds2 = exp_sci(eds2);
		
		//formula ==> dev_std(e^x) = y = sqrt{[(x*e^x)^2]*(dev_std(x))^2}
		
		//x^2
		double r1 = a2*x2*ex2;
		r1 = r1*r1;
		
		//(e^x)^2
		double r2 = exp(x2*ex2);
		r2 = r2*r2;
		
		//(dev_std(x))^2
		double r3 = ds2*eds2;
		r3 = r3*r3;
		
		//{[(x*e^x)^2]*(dev_std(x))^2}
		r3 = r1*r2*r3;
		
		//y
		dev_std_res = sqrt(r3);
		//risultato dell'esponenziale
		double esp = (a2*exp(x2*ex2));
		
		cout << "Risultato operazione\t";
		stampa_sci(esp);
		cout << "Deviazione standard dell'esponenziale\t";
		stampa_sci(dev_std_res);
	}
	
	
	return 0;
}
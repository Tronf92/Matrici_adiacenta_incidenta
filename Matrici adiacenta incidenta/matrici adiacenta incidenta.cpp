/*Nicorici Adrian
05.10.2014
Agraf-Matrici incidenta adiacenta.
*/

#include <iostream>
using namespace std;

int m_adiacenta[10][10], m_incidenta[10][10],N=3;//matricile de incidenta adiacenta

void adiacenta_in();
void adiacenta_out(int linii,int coloane);
void incidenta_in();
void incidenta_out();
void meniu();
void actiune();
void init_incidenta();
void adiacenta_init();

int main(){
	meniu();
	actiune();
	system("pause");
	return 0;
}

void meniu(){//afisam optiunile posibile in acest program
	cout << "1.Din matrice de adiacenta in matrice de incidenta " << endl;
	cout << "2.Din matrice de incidenta in matrice de adiacenta " << endl;
	cout << "0.Iesire" << endl;

}

void actiune(){//core of program
	int choice = -1;//setam choice ca -1 sa nu avem o posibila alegere facuta dinainte.
	
	while(choice!=0){//loop sa ceara optiunea
		cout << "Introduceti optiunea dvs. " << endl;
		cin >> choice;
		switch (choice)
		{
			case 1://optiunea 1 de la adiacenta la incidenta
				adiacenta_in();
				incidenta_out();
				break;
			case 2://optiunea 2 de la incidenta la adiacenta.
				incidenta_in();
				break;
			case 0://optiunea 3 exit
				system("EXIT");
				break;
			default://optiune gresita
				cout << "Optiune gresita" << endl;
			break;
		}
	}

}

void adiacenta_in(){//scriem matricea de adiacenta.
	cout << "Introduceti matricea de adiacenta a grafului: " << endl;
	int i,j;
	for(i=0;i<N;i++){
		for(j=0; j < N;j++){
			cout << "Adiacenta[" << i << "][" << j << "]=";
			cin >> m_adiacenta[i][j];
			cout << endl;
		}
	}
}

void init_incidenta(){//initializam matricea de incidenta cu 0
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			m_incidenta[i][j]=0;
		}
	}
}

void incidenta_out(){//cream matricea de incidenta pornind de la matricea de adiacenta
	init_incidenta();
	int i,j,l,m,k=0,col_incidenta=0;
	for(i=0;i<N;i++){//parcurgem matricea de adiacenta linie cu linie.
		for(j=0;j<N;j++){
			if(m_adiacenta[i][j] == 1){//unde gasim unu, punem pe poz [i][k] 1 si [j][k] -1
				col_incidenta++;
				m_incidenta[i][k] = 1;
				m_incidenta[j][k] = -1;
				k++;//marim k
			}
		}
	}
	
	cout << "Matricea de incidenta:" << endl; //afisam matricea de incidenta.
	for (i=0;i<N;i++){
		for(j=0;j<col_incidenta;j++){
			cout << m_incidenta[i][j] << " ";
		}
		cout << endl;
	}
	
}

void incidenta_in(){//introducem matricea de incidenta.
	int linii,coloane,i,j;
	cout << "Introduceti nr. de arce din graf: ";
	cin >> coloane;//cerem arcele
	cout << endl <<"Introduceti nr. de noduri din graf: ";
	cin >> linii;//cerem nodurile

	for(i=0;i<linii;i++){
		for(j=0;j<coloane;j++){
			cout << "Incidenta[" << i << "][" << j << "]=";
			cin >> m_incidenta[i][j];
		}
	}
	adiacenta_out(linii,coloane);//apelam functia care creaza matricea de adiacenta
}

void adiacenta_init(){//initial matricea de adiacenta este 0
int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			m_adiacenta[i][j]=0;
		}
	}
}

void adiacenta_out(int linii,int coloane){//crearea matricei de adiacenta.
	int i,j;
	int linie,coloana;
	void adiacenta_init();
	for(j=0;j<coloane;j++){//parcurgem matricea de incidenta coloana cu coloana
		for(i=0;i<linii;i++){
			if(m_incidenta[i][j] == 1){//element cu 1 salvam linia intr-o variabila				
				linie = i;
			}
			else if(m_incidenta[i][j] == -1){//element cu -1 salvam linia intr-o variabila
				coloana = i;
			}
		}
		m_adiacenta[linie][coloana] = 1;//in matricea de adiacenta punem 1 in elementul cu indicele coloanei cu 1 si -1.
	}
	
	cout << "Matricea de adiacenta: " << endl;//afisam matricea.
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cout << m_adiacenta[i][j];
		}
		cout << endl;
	}
}
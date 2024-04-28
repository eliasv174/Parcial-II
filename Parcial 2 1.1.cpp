#include<iostream>
using namespace std;
main(){
	int N, id, nota1, nota2, nota3, nota4, promedio;
	string nombres, apellidos;
	
	cout<<"Cuantos estudiantes tiene su clase: ";
	cin>>N;
	system("cls");
	
	string estudiantes[N][9]={};
	
	for(int i=0;i<N;i++){
		cout<<"Escriba el ID: ";
		cin>>id;
		estudiantes[i][0]=to_string(id);
		cout<<"Escriba el Nombre: ";
		cin>>nombres;
		estudiantes[i][1]=nombres;
		cout<<"Escriba el Apellido: ";
		cin>>apellidos;
		estudiantes[i][2]=apellidos;
		cout<<"Escriba el Nota 1: ";
		cin>>nota1;
		estudiantes[i][3]=to_string(nota1);
		cout<<"Escriba el Nota 2: ";
		cin>>nota2;
		estudiantes[i][4]=to_string(nota2);
		cout<<"Escriba el Nota 3: ";
		cin>>nota3;
		estudiantes[i][5]=to_string(nota3);
		cout<<"Escriba el Nota 4: ";
		cin>>nota4;
		estudiantes[i][6]=to_string(nota4);
		promedio=(nota1+nota2+nota3+nota4)/4;
		estudiantes[i][7]=to_string(promedio);
		if(promedio>60){
			estudiantes[i][8]="Aprobo";
		} else{
			estudiantes[i][8]="Reprobo";
		}
		system("cls");
	}
	cout<<"ID       Name   LsNm    n1      n2      n3      n4   promedio"<<endl;
	for(int i = 0; i < N; i++) {
        for(int j = 0; j < 9; j++) {
        	
            cout << estudiantes[i][j] << "\t";
        }
        cout << endl;
    }

	
}
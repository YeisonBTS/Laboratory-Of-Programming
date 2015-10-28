#include <bits/stdc++.h>

using namespace std;

main(){
    vector < int > dura;
    vector < int > sexo;
    
    FILE *p;    int n, i, temp, mes, dure, Ho=0, Mu=0, sumfid = 0;
    long int fi = 0, Fia = 0, sumfi = 0; //inicializamos fi desde 0
    char sexoc[20],  nom[20];
    float sumhid100 = 0;

    printf("Ingrese nombre del archivo \n");
    gets(nom);
    printf("\n tamaño del vector \n");
    scanf("%d",&n);
    p=fopen(nom,"r");
    printf("\n recuperando datos: %d \n", n);
    for(i = 1; i <= n; i++){
        fscanf(p, "%s %d %d", &sexoc ,&temp, &dure);
        dura.push_back(dure);
        if(strcmp(sexoc,"Hombre")){
            sexo.push_back(1); Ho++;
        }else{
            sexo.push_back(0); Mu++;
        }
    }
    printf("\n recuperado \n");
    fclose(p);
    float hiHo = (float)Ho/(float)n*100;
    float hiMu = (float)Mu/(float)n*100;//int Ho = count_if(sexo.begin(), sexo.end(), 1);
    //int Mu = count_if(sexo.begin(), sexo.end(), 0);
    cout << "\t ______.......///----*BTS INFINITE BEAST*----\\\.........______"  << endl;
    cout << "\t _________________________"  << endl;
    cout << "\t| Sexo |  (fi) |(hi x 100)|" << endl;
    cout << "\t|------+-------+----------|" << endl;
    printf( "\t|Hombre| %d   |  %2.2f   |\n", Ho, hiHo );
    printf( "\t|Mujer | %d   |  %2.2f   |\n", Mu, hiMu );
    cout << "\t|------+------+-----------|\n" << endl;
    printf( "\t|      |%5i   | %3.2f  |\n", Ho+Mu, hiHo+hiMu);
	cout << "\t _________________________\n\n" << endl;
    int ndura = 6;

    cout << "\t ______.......///----*BTS INFINITE BEAST*----\\\.........______"  << endl;
        cout << "\t ___________________________"  << endl;
        cout << "\t|Duracion|  (fi) |(hi x 100)|" << endl;
        cout << "\t|--------+-------+----------|" << endl;
    mes = 37;

    while(ndura--){

    	int fid = count(dura.begin(), dura.end(), mes);
        sumfid += fid;
    	float hid100 = (float)fid/(float)n*100;
    	sumhid100 += hid100;
		printf("\t|   %i   | %4i  | %6.2f   | \n", mes, fid, hid100);
		//cout << (long long int)(Xi*(float)fi) <<" -++- "<< ((float)fi*(pow(Xi, 2))) << endl;
		mes++;
	}
	cout << "\t|--------+-------+----------| \n" << endl;
		printf("\t|        |%5.1d |  %6.1f   |\n", sumfid, sumhid100);
	cout << "\t ___________________________\n\n" << endl;
    return 0;
}

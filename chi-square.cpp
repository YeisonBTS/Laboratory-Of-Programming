#include <bits/stdc++.h>

using namespace std;

vector < int > dura;
vector < int > sexo;

int contar_si(int sx, int ms){
	int cs = 0;
	for(int i = 0; i <= 792; i++){
		if(sexo.at(i) == sx && dura.at(i) == ms) cs++;
	}
	return cs;
}

int main(){
    

    FILE *p;    int n, i, temp, dure;
    long int fi = 0, Fia = 0, sumfi = 0; //inicializamos fi desde 0
    char sexoc[20],  nom[20];
    float sumhid100 = 0;

    printf("Ingrese nombre del archivo \n");
    gets(nom);
    printf("\n tamaño del vector \n");
    scanf("%d",&n);
    p=fopen(nom,"r");
    printf("\n recuperando datos: %d \n", n);
    for(i = 1; i <= n+1; i++){
        fscanf(p, "%s %d %d", &sexoc ,&temp, &dure);
        dura.push_back(dure);
        if(strcmp(sexoc,"Mujer")){
            sexo.push_back(1); 
        }else{
            sexo.push_back(0);
        }
    }
    printf("\n recuperado \n");
    fclose(p);
   
    int  sexH = 1, sexM = 0;;
	int nsx = 2;

    	int mes = 37;
    	int ndura = 6;
    	
		cout << "\t ____________________________ " << endl; 
		cout << "\t|          |      sexo       |" << endl; 
		cout << "\t| Duracion | Hombre | Mujer  |" << endl; 
		cout << "\t| Embarazo |-----------------| total" << endl; 
		int ttm = 0, tth = 0;
	    while(ndura--){
			
	    	int NH = contar_si(sexH, 40);
	    	int NM = contar_si(sexM, mes);
	    	int tm = NH + NM;
	    printf("\t|   %i     |  %5i | %5i  |  %5i  | \n", mes, NH, NM, tm);
			mes++;		ttm += NM; tth += NH;
		} 
		cout << "\t ____________________________ " << endl;
	 	printf("\t  total   |  %5i | %5i  |  %5i  | ", tth, ttm, ttm+tth);
    return 0;
}

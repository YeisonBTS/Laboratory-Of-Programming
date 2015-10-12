/* Load File Sexo Peso Duracion de Embarazo
*   BTS Yeison Eduardo
*/

#include<bits/stdc++.h>

using namespace std;
main(){
    FILE *p;
    int n,i;
    char sexo[20];
    float peso, dure;
    char nom[20];
    printf("Ingrese nombre del archivo \n");
    gets(nom);
    printf("\n tamaño del vector \n");
    scanf("%d",&n);
    p=fopen(nom,"r");
    printf("\n recuperando datos: %d \n", n);
    for(i = 1; i <= n; i++){
        fscanf(p, "%s %f %f", &sexo ,&peso, &dure);
        printf("  %s %3.2f %3.2f \n", sexo, peso, dure);
    }
    printf("\n recuperado");
    fclose(p);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long int LI, LS;//varialbes gloabales
bool Is(int i) { return (i <= LS);}

main(){
    vector< int > peso;
    FILE *p;
    int n, i, temp, mini, maxi, range, number_range, size_range, sum, average;
    long int fi = 0, Fia = 0, sumfi = 0; //inicializamos fi desde 0
    float sumhi100 = 0, sumXifi = 0, sumXifi2 = 0, dure;
    char sexo[20],  nom[20];

    printf("Ingrese nombre del archivo \n");
    gets(nom);
    printf("\n tamaño del vector \n");
    scanf("%d",&n);
    p=fopen(nom,"r");
    printf("\n recuperando datos: %d \n", n);
    for(i = 1; i <= n; i++){
        fscanf(p, "%s %d %d", &sexo ,&temp, &dure);
        peso.push_back(temp);
    }
    printf("\n recuperado \n");
    fclose(p);
    for(int i = 0; i < 20; i++)
        cout << peso.at(i) << " " << endl;

    //cout << peso.size() << endl;

    maxi = *std::max_element(peso.begin(),peso.end());
    mini = *std::min_element(peso.begin(),peso.end());
    range = maxi - mini;
    cout << "cantidad de intervalos: ";  cin >>number_range;
    size_range = round((float)range/(float)number_range); // casteamos para poder redondear
	sum = accumulate(peso.begin(),peso.end(),NULL);
	average  = sum / n;

    cout << "large: \t" << maxi << endl;
    cout << "small: \t" << mini << endl;
    cout << "range: \t" << range << endl;
    cout << "number range: \t" << number_range << endl;
    cout << "size range: \t" << size_range << endl;
    cout << "average: \t" << average << endl;

    LS = mini + size_range;
    LI = mini;
    cout << "\t ______.......///----*BTS INFINITE BEAST*----\\\.........______"  << endl;
    cout << "\t ______________________________________________________________"  << endl;
    cout << "\t| Li  -  Ls |  (Xi)  |  (fi)  |  (Fi)  |(hi x 100)| (Hi x 100) |" << endl;
    cout << "\t|-----------+--------+--------+--------+----------+------------|" << endl;

    while(number_range--){

    	int Fi = count_if(peso.begin(), peso.end(), Is);
    	fi = Fi-Fia;  sumfi += fi;
		Fia = Fi;
    	float Xi =((float)LI+(float)LS)/2;// casteamos para poder apreciar los decimales
    	float hi100 = (float)fi/n*100;  sumhi100 += hi100;
    	float Hi100 = (float)Fi/n*100;
    	sumXifi += (Xi*(float)fi);
    	sumXifi2 += ((float)fi*(pow(Xi, 2)));
  		cout << "\t|" << LI << " - " << LS <<"|";
		printf(" %6.1f |%6.1d  | %6.1d |  %5.2f   |   %6.2f   |\n", Xi, fi, Fi, hi100, Hi100);
		//cout << (long long int)(Xi*(float)fi) <<" -++- "<< ((float)fi*(pow(Xi, 2))) << endl;

  		LI = LS + 1;
  		LS += 1 + size_range;

	}

	cout << "\t|-----------+--------+--------+--------+----------+------------|" << endl;
		printf("\t| \t    |        |%6.1d  |        |  %6.1f  |            | \n", sumfi, sumhi100);
	cout << "\t ______________________________________________________________\n\n" << endl;

    //cout << "sumXifi " << (long long int)sumXifi << "   sumXifi2 " << (long long int)sumXifi2 << endl;
    double pro = sumXifi/n, var = round((sumXifi2-(pow(sumXifi,2)/n))/(n-1));
	double desv =pow(var,0.5), cv =desv/pro*100;
    cout << "promedio: " << pro << "\t\t varianza: " << var << endl;
    cout << "desviacion estandar: " << desv << "\t Coeficiente de variacion: " << cv << endl;
    return 0;
}

// C++ 
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
 
const int MAX = 1000;
 
// Memoreaza in store nodurile
int store[MAX], k, N, M, gata;
 
// Graful
int graph[MAX][MAX];
 
// Nr. de muchii ale nodurilor
int d[MAX];
 
// Functia verifica daca un set de noduri
// din array-ul  store formeaza un clique subgraf complet sau nu
bool is_clique(int b) {
    // b este nr. de noduri din array-ul store

    for (int i = 1; i < b; i++) {
        for (int j = i + 1; j < b; j++)

            // Daca exsta in matricea graph o valoare 0 atunci nu e clique
            if (graph[store[i]][store[j]] == 0)
                return false;
    }
    return true;
}

void print_sat1(int n) {
	int i, j;
    for (i = 1; i < n - 2; i++)
    	for (j = i + 1; j < n; j++) {
	    	cout << "(x" << store[i] <<"V";
        	cout << "x"<<store[j] <<")"<< "^";
    	}
    cout << "(~x" << store[1] << "V" << "~x" << store[i + 1] << ")";
    cout << "\n";
}


// Functia cauta primul clique de dimensiune s si daca gaseste gata = 1
void findCliques(int i, int l, int s) {
    for (int j = i + 1; j <= N - (s - l); j++) 

        // Daca nr de muchii este mai mare decit s-1
        if (d[j] >= s - 1) {

            // Adauga un nod in vectorul  store
            store[l] = j;

            // Verifica daca nodurile din store formeaza un clique
            if (is_clique(l + 1))  
 
                // Daca s-a ajuns la dimensiunea clicii din graf atunci e gata
                if (l < s)
 
                    // Recursiv adaug un nod daca nu s-a atins dimensiunea clicii
                    findCliques(j, l + 1, s);
 
                // s-a ajuns la dimensiunea clicii
                else {
					gata = 1;
					print_sat1(l + 1);
				}
        }
}
 
// Programul principal

int main(int argc, char *argv[]) {

	string fileName;
	fileName = argv[1];

	std::ifstream myfile (fileName);

	//citesc din fisierul de intrare linie cu linie
	if (myfile.is_open()){
		myfile >> k;
		myfile >> N;
		myfile >> M;
		int edges[M][2];

    	for (int i = 0; i < M; i++) {
    		myfile >> edges[i][0] >> edges[i][1];
		}	
	
		myfile.close();

		if(k != 0) {
			int size = sizeof(edges) / sizeof(edges[0]);
			for (int i = 0; i < size; i++) {
				graph[edges[i][0]][edges[i][1]] = 1;
				graph[edges[i][1]][edges[i][0]] = 1;
				d[edges[i][0]]++;
				d[edges[i][1]]++;
			}		

			gata = 0;
			findCliques(0, 1, k);
			if (gata == 0)
				cout << "(x1 V x2 )^(x3 V x4 )^(~x4 V ~x3)^(~x4 V ~x3)^(~x4 V ~x2)^(~x4 V ~x1)^(~x3 V ~x4)^(~x3 V ~x4)^(~x3 V ~x2)^(~x3 V ~x1)^(~x2 V ~x4)^(~x2 V ~x3)^(~x2 V ~x1)^(~x2 V ~x1)^(~x1 V ~x4)^(~x1 V ~x3)^(~x1 V ~x2)^(~x1 V ~x2)";
		}

		return 0;
	}
}

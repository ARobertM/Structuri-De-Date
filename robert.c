
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable:4996)

////HashTable-ListaSimpla
//typedef struct Proiect Proiect;
//typedef struct Nod Nod;
//typedef struct HashTable HashTable;
//
//struct Proiect {
//	unsigned int cod_proiect;
//	char* titlu_proiect;
//	char* beneficiar;
//	unsigned char nr_exec;
//	float buget;
//};
//
//struct Nod {
//	Proiect info;
//	Nod* next;
//};
//
//struct HashTable {
//	Nod** vector;
//	int dim;
//};
//// AfisareProiect
//void afisareProiect(Proiect p) {
//	printf("Cod: %u, Titlu: %s, Beneficiar: %s, Executanti: %hhu, Buget: %.2f\n",
//		p.cod_proiect, p.titlu_proiect, p.beneficiar, p.nr_exec, p.buget);
//}
//void afisareProiect2(Proiect p) {
//	printf("Cod: %u, Beneficiar: %s\n",
//		p.cod_proiect,  p.beneficiar);
//}
//// Inserare in ListaSimpla
//void inserareSfarsit(Proiect p, Nod** cap) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = p;
//	nou->next = NULL;
//
//	if (*cap == NULL) {
//		*cap = nou;
//	}
//	else {
//		Nod* current = *cap;
//		while (current->next != NULL) {
//			current = current->next;
//		}
//		current->next = nou;
//	}
//}
//// InitializareaTabelei
//HashTable initializareHashTable(int dim) {
//	HashTable tabela;
//	tabela.dim = dim;
//	tabela.vector = (Nod**)malloc(sizeof(Nod*) * dim);
//	for (int i = 0; i < dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//	return tabela;
//}
//// Functia Hash
//int hash(int dim, char* beneficiar) {
//	return strlen(beneficiar) % dim;
//}
//// InserareaInHashTable - lant
//void inserareHashTable(HashTable* tabela, Proiect p) {
//	if (tabela->dim > 0) {
//		int poz = hash(tabela->dim, p.beneficiar);
//		if (poz >= 0 && poz < tabela->dim) {
//			inserareSfarsit(p, &(tabela->vector[poz]));
//		}
//	}
//}
//// Afisarea HashTable
////void afisareHashTable(HashTable tabela) {
////	for (int i = 0; i < tabela.dim; i++) {
////		if (tabela.vector[i] != NULL) {
////			printf("Pozitia din tabel %d\n", i);
////			while (tabela.vector[i]) {
////				afisareProiect(tabela.vector[i]->info);
////				tabela.vector[i] = tabela.vector[i]->next;
////			}
////		}
////		else {
////			printf("Pozitia %d este goala!\n", i);
////		}
////	}
////} - asta nu e bine, aici era problema
//
//void afisareHashTable(HashTable tabela) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			printf("Pozitia din tabel %d\n", i);
//			Nod* temp = tabela.vector[i]; 
//			while (temp != NULL) {
//				afisareProiect(temp->info);
//				temp = temp->next;
//			}
//		}
//		else {
//			printf("Pozitia %d este goala!\n", i); 
//		}
//	}
//}
//
//void afisareHashTable2(HashTable tabela) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			printf("Pozitia din tabel %d\n", i);
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				afisareProiect2(temp->info);
//				temp = temp->next;
//			}
//		}
//		else {
//			printf("Pozitia %d este goala!\n", i);
//		}
//	}
//}
//
//// Ex3 - bugetTotal pe cap
//
//float bugetTotalBeneficiar(HashTable tabela, const char* beneficiar) {
//	float suma = 0.0f;
//	if (tabela.vector != NULL) {
//		for (int i = 0; i < tabela.dim; i++) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				if (strcmp(temp->info.beneficiar, beneficiar) == 0) {
//					suma += temp->info.buget;
//				}
//				temp = temp->next;
//			}
//		}
//	}
//	else {
//		printf("Tabelul Hash este gol!");
//	}
//	return suma;
//}
//
//// Ex4 - Modifica denumirea unui beneficiar dat ca parametru
//
//void modificaNumeBeneficiar(HashTable tabela, const char* beneficiarVechi, const char* beneficiarNou) {
//	if (tabela.vector != NULL) {
//		for (int i = 0; i < tabela.dim; i++) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				if (strcmp(temp->info.beneficiar, beneficiarVechi) == 0) {
//					// Eliberam beneficiarul vechi si alocam mem pentru urmatorul
//					free(temp->info.beneficiar);
//					temp->info.beneficiar = (char*)malloc(sizeof(char) * (strlen(beneficiarNou) + 1));
//					strcpy(temp->info.beneficiar, beneficiarNou);
//					printf("Modificarea a fost realizata cu succes!\n");
//				}
//				temp = temp->next;
//			}
//		}
//	}
//}
//
//// Ex5 - ListaSimpla cu elem peste un anumit buget
//
//Nod* adaugareInListaSimpla(HashTable tabela, float nivelBuget) {
//	Nod* cap = NULL;
//	for (int i = 0; i < tabela.dim; i++) {
//		Nod* temp = tabela.vector[i];
//		while (temp != NULL) {
//			if (temp->info.buget > nivelBuget) {
//				inserareSfarsit(temp->info, &cap);
//			}
//			temp = temp->next;
//		}
//	}
//	return cap;
//}
//// afisare listaSIMPLA
//
//void afisareLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareProiect(cap->info);
//		cap = cap->next;
//	}
//}
//
////void amin
//int main() {
//	printf("void amin\n");
//	int nrProiecte;
//	char buffer[30];
//
//	Proiect p;
//	HashTable tabela = initializareHashTable(8);
//
//	FILE* f = fopen("proiecte.txt", "r");
//	fscanf(f, "%d", &nrProiecte);
//	for (int i = 0; i < nrProiecte; i++) {
//		fscanf(f, "%u", &p.cod_proiect);
//		fscanf(f, " %s", buffer);
//		p.titlu_proiect = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//		strcpy(p.titlu_proiect, buffer);
//		fscanf(f, "%s", buffer);
//		p.beneficiar = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//		strcpy(p.beneficiar, buffer);
//		fscanf(f, "%hhu", &p.nr_exec);
//		fscanf(f, "%f", &p.buget);
//
//		inserareHashTable(&tabela, p);
//		
//
//	}
//
//	fclose(f);
//	
//	afisareHashTable(tabela);
//	printf("\n\n\nEx 3: \n");
//
//	float sumaTotala = bugetTotalBeneficiar(tabela, "Robert");
//	printf("Bugetul total pentru Robert : %.2f\n", sumaTotala);
//
//	printf("\n\n\nEx 4: \n");
//	modificaNumeBeneficiar(tabela, "Gabriel", "King");
//	afisareHashTable2(tabela);
//
//	printf("\n\n\nEx 5: \n");
//	printf("\nListaSimpla: \n");
//	Nod* cap = NULL;
//	cap = adaugareInListaSimpla(tabela, 300.00f);
//	afisareLista(cap);
//
//
//	return 0;
//}

////// ListaDubla-Heap
//typedef struct Proiect Proiect;
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
//typedef struct Heap Heap;
//
//struct Proiect {
//	unsigned int cod_proiect;
//	char* titlu;
//	char* beneficiar;
//	unsigned char nr_executanti;
//	float buget;
//};
//struct Nod {
//	Proiect info;
//	Nod* next;
//	Nod* prev;
//};
//struct ListaDubla {
//	Nod* primulNod;
//	Nod* ultimulNod;
//};
//struct Heap {
//	Proiect* vector;
//	int dim;
//};
//
//void afisareProiect(Proiect p) {
//	printf("Cod %u, Titlu: %s, Beneficiar: %s, NR_EXEC: %hhu, Buget: %.2f\n",
//		p.cod_proiect, p.titlu, p.beneficiar, p.nr_executanti, p.buget);
//}
//
//ListaDubla inserareInceput(ListaDubla lista, Proiect p) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = p;
//	nou->next = lista.primulNod;
//	nou->prev = NULL;
//
//	if (lista.primulNod != NULL) {
//		lista.primulNod->prev = nou;
//	}
//	else {
//		lista.ultimulNod = nou;
//	}
//	lista.primulNod = nou;
//	return lista;
//}
//
//void afisareListaDubla(ListaDubla lista) {
//	while (lista.primulNod != NULL) {
//		afisareProiect(lista.primulNod->info);
//		lista.primulNod = lista.primulNod->next;
//	}
//}
//
////EX 2 - Nr proiecte cu executantii peste un prag
//// unsigned char este un int
//
//int NrProiectePestePrag(ListaDubla lista, int prag_cautat) {
//	int nr_proiecte = 0;
//	while (lista.primulNod != NULL) {
//		if (lista.primulNod->info.nr_executanti > prag_cautat) {
//			nr_proiecte += 1;
//		}
//		lista.primulNod = lista.primulNod->next;
//	}
//	return nr_proiecte;
//}
//
////EX 3 - Actualizeaza bugetul proiectelor avand un beneficiar specificat ca parametru
//
////void ModificaBugetDupaBeneficiar(ListaDubla lista, const char* beneficiar_cautat, float buget_nou) {
////	Nod* temp = lista.primulNod;
////	while (temp != NULL) {
////		if (strcmp(temp->info.beneficiar, beneficiar_cautat) == 0) {
////			//free(temp->info.beneficiar);
////			//temp->info.beneficiar = (char*)malloc(sizeof(char) * (strlen(beneficiar_cautat) + 1));
////			//strcpy(temp->info.beneficiar, beneficiar_cautat);
////			temp->info.buget = buget_nou;
////		}
////		temp = temp->next;
////	}
////}
//
//void ModificaBugetDupaBeneficiar(ListaDubla lista, const char* beneficiar_cautat, float procent) {
//	Nod* temp = lista.primulNod;
//	while (temp != NULL) {
//		if (strcmp(temp->info.beneficiar, beneficiar_cautat) == 0) {
//			temp->info.buget  += (procent / 100) * temp->info.buget;
//		}
//		temp = temp->next;
//	}
//}
//
////ListaDubla actualizareBuget(ListaDubla lista, const char* beneficiar, float procent)
////{
////	ListaDubla temp = lista;
////
////	while (temp.primulNod != NULL)
////	{
////		if (strcmp(temp.primulNod->info.beneficiar, beneficiar) == 0)
////		{
////			temp.primulNod->info.buget += (procent / 100) * temp.primulNod->info.buget;
////		}
////		temp.primulNod = temp.primulNod->next;
////	}
////	return lista;
////}
//
//// EX 4 - BubbleSort pe buget
//
////void sortarePeBuget(ListaDubla lista) {
////	Nod* aux = lista.primulNod;
////	Nod* aux_tranversare = NULL;
////	while (aux != NULL) {
////		if (aux->info.buget > aux->next->info.buget) {
////			aux = aux_tranversare;
////			aux->next = aux;
////			aux_tranversare = aux;
////		}
////		aux = aux->next;
////	}
////}
//
//void sortarePeBuget(ListaDubla lista) {
//	int sorted = 0;
//	while (sorted == 0) {
//		sorted = 1;
//		Nod* current = lista.primulNod;
//		while (current->next != NULL) {
//			if (current->info.buget > current->next->info.buget) {
//				Proiect temp = current->info;
//				current->info = current->next->info;
//				current->next->info = temp;
//				sorted = 0;
//			}
//			current = current->next;
//		}
//		current = NULL;
//	}
//}
//
//// EX 5: Datele Proiectelor pentru acelasi beneficiar - salvate in Heap
//
//void inserareHeapDinListaDubla(ListaDubla lista, Heap* h) {
//	int index = 0;
//	h->dim = 0; 
//	Nod* temp = lista.primulNod;
//
//	while (temp != NULL) {
//		h->dim++;
//		temp = temp->next;
//	}
//	h->vector = (Proiect*)malloc(sizeof(Proiect) * h->dim);
//	index = 0;
//	temp = lista.primulNod;
//	while (temp != NULL) {
//		h->vector[index] = temp->info;
//		index++;
//		temp = temp->next;
//	}
//}
//
//void afisareHeap(Heap h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareProiect(h.vector[i]);
//	}
//}
//
//void filtrareHeap(Heap heap, int index) {
//	if (heap.dim > 0) {
//		int pozS = 2 * index + 1;
//		int posD = 2 * index + 2;
//		int pozMax = index;
//		if (heap.dim > pozS && heap.vector[pozMax].cod_proiect < heap.vector[pozS].cod_proiect) {
//			pozMax = pozS;
//		}
//		if (heap.dim > posD && heap.vector[pozMax].cod_proiect < heap.vector[posD].cod_proiect) {
//			pozMax = posD;
//		}
//		if (pozMax != index) {
//			Proiect aux = heap.vector[pozMax];
//			heap.vector[pozMax] = heap.vector[index];
//			heap.vector[index] = aux;
//			filtrareHeap(heap, pozMax);
//		}
//	}
//}
//
//
//void main() {
//	int nrProiecte;
//	char buffer[30];
//
//	Proiect p;
//	ListaDubla lista;
//	lista.primulNod = NULL;
//	lista.ultimulNod = NULL;
//
//
//	FILE* f = fopen("proiecte2.txt", "r");
//	fscanf(f, "%d", &nrProiecte);
//	for (int i = 0; i < nrProiecte; i++) {
//		fscanf(f, "%u", &p.cod_proiect);
//		fscanf(f, "%s", buffer);
//		p.titlu = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(p.titlu, buffer);
//		fscanf(f, "%s", buffer);
//		p.beneficiar = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(p.beneficiar, buffer);
//		fscanf(f, "%hhu", &p.nr_executanti);
//		fscanf(f, "%f", &p.buget);
//
//		lista = inserareInceput(lista, p);
//
//
//	}
//	fclose(f);
//	afisareListaDubla(lista);
//
//	printf("EX 2: \n");
//	int proiecte_cautate = NrProiectePestePrag(lista, 3);
//	printf("Numarul de proiecte cautate din lista cu numarul de executanti peste 3 este: %d\n", proiecte_cautate);
//
//	printf("EX 3: \n");
//	ModificaBugetDupaBeneficiar(lista, "Robert", 30);
//	afisareListaDubla(lista);
//
//	printf("EX 4: \n");
//	sortarePeBuget(lista);
//	afisareListaDubla(lista);
//
//	Heap heap;
//	heap.dim = 5;
//
//	printf("EX 5: \n");
//	inserareHeapDinListaDubla(lista, &heap);
//	
//
//	for (int i = heap.dim / 2 - 1; i >= 0; i--) {
//		filtrareHeap(heap, i);
//	}
//	afisareHeap(heap);
//
//}

//// Arbore Binar de Cautare
// 
//typedef struct Rezervare Rezervare;
//typedef struct Nod Nod;
//
//struct Rezervare {
//	unsigned int id_rezervare;
//	char* denumire_hotel;
//	unsigned char nr_camere;
//	char* nume_client;
//	float suma;
//};
//struct Nod {
//	Rezervare info;
//	Nod* stanga;
//	Nod* dreapta;
//};
//
//void afisareRezerare(Rezervare r) {
//	printf("ID: %u, Denumire Hotel: %s, Nr Camere: %hhu, NumeClient: %s, Suma: %.2f\n",
//		r.id_rezervare, r.denumire_hotel, r.nr_camere, r.nume_client, r.suma);
//}
//void afisareRezerare2(Rezervare r) {
//	printf("ID: %u, NumeClient: %s\n",
//		r.id_rezervare, r.nume_client);
//}
//
//void inserareABC(Nod** radacina, Rezervare r) {
//	if (*radacina == NULL) {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = r;
//		nou->stanga = NULL;
//		nou->dreapta = NULL;
//		*radacina = nou;
//	}
//	else {
//		if (r.id_rezervare > (*radacina)->info.id_rezervare) {
//			inserareABC(&(*radacina)->dreapta, r);
//		}
//		else {
//			inserareABC(&(*radacina)->stanga, r);
//		}
//	}
//
//}
//
//void afisarePreOrdine(Nod* radacina) {
//	if (radacina != NULL) {
//		afisareRezerare(radacina->info);
//		afisarePreOrdine(radacina->stanga);
//		afisarePreOrdine(radacina->dreapta);
//	}
//}
//
////EX 3 - suma rez efectuate de un client
//
//float sumaRezClient(Nod** radacina, const char* beneficiar_cautat) {
//	float suma_rezervare = 0.0f;
//	if (*radacina != NULL) {
//		if (strcmp((*radacina)->info.nume_client, beneficiar_cautat) == 0) {
//			suma_rezervare += (*radacina)->info.suma;
//		}
//		suma_rezervare += sumaRezClient(&(*radacina)->stanga, beneficiar_cautat);
//		suma_rezervare += sumaRezClient(&(*radacina)->dreapta, beneficiar_cautat);
//	}
//	return suma_rezervare;
//}
//
////EX 4 - sterge nodul cu id-ul minim
////NodArbore* eleminareNod(NodArbore* radacina) {
////	if (radacina != NULL) {
////		if (radacina->stanga == NULL) {
////			NodArbore* nodMinim = radacina;
////			radacina = radacina->dreapta;
////			free(nodMinim->info.denumire_hotel);
////			free(nodMinim->info.nume_client);
////			free(nodMinim);
////			return radacina;
////		}
////		else {
////			radacina->stanga = eleminareNod(radacina->stanga);
////			return radacina;
////		}
////	}
////	else {
////		return NULL; //uneori vrea si 0 in loc de null, nush dc
////	}
////}
//
//Nod* eliminareNodMin(Nod* radacina) {
//	if (radacina != NULL) {
//		if (radacina->stanga == NULL) {
//			Nod* nod_minim = radacina;
//			radacina = radacina->dreapta;
//			free(nod_minim->info.denumire_hotel);
//			free(nod_minim->info.nume_client);
//			free(nod_minim);
//		}
//		else {
//			radacina->stanga = eliminareNodMin(radacina->stanga);
//			return radacina;
//		}
//	}
//	else {
//		return NULL;
//	}
//}
//
////EX 5 - TRASNF VECTOR
//void salvareVector(Nod* radacina, Rezervare* vector, int* nr) {
//	if (radacina != NULL) {
//		vector[*nr] = radacina->info;
//		(*nr)++;
//		salvareVector(radacina->stanga, vector, nr);
//		salvareVector(radacina->dreapta, vector, nr);
//	}
//	
//}
//
//
//
//void main() {
//	int nrRezervari;
//	char buffer[30];
//
//	Rezervare r;
//
//	Nod* radacina = NULL;
//
//	FILE* f = fopen("rezervari.txt", "r");
//	fscanf(f, "%d", &nrRezervari);
//	for (int i = 0; i < nrRezervari; i++) {
//		fscanf(f, "%u", &r.id_rezervare);
//		fscanf(f, "%s", buffer);
//		r.denumire_hotel = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(r.denumire_hotel, buffer);
//		fscanf(f, "%hhu", &r.nr_camere);
//		fscanf(f, "%s", buffer);
//		r.nume_client = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(r.nume_client, buffer);
//		fscanf(f, "%f", &r.suma);
//
//		inserareABC(&radacina, r);
//
//	}
//	fclose(f);
//	afisarePreOrdine(radacina);
//
//	printf("\nEX 3:\n");
//	printf("Suma rezervarilor lui Sabin este egala cu:  %.2f ", sumaRezClient(&radacina, "Sabin"));
//
//	printf("\nEX 4:\n");
//	radacina = eliminareNodMin(radacina);
//	afisarePreOrdine(radacina);
//
//	printf("\nEX 5 (VECTOR):\n");
//	int nr = 0;
//	Rezervare* vector = (Rezervare*)malloc(sizeof(Rezervare) * nrRezervari);
//	salvareVector(radacina, vector, &nr);
//	for (int i = 0; i < nr; i++) {
//		printf("ID-ul %hhu , Nume Client: %s\n",
//			vector[i].id_rezervare, vector[i].nume_client);
//	}
//	free(vector);
//}

//// Arbore Binar + Heap
//typedef struct Album Album;
//typedef struct Nod Nod;
//typedef struct Heap Heap;
//
//struct Album {
//	char* email_utilizator;
//	char* denumire_album;
//	int nr_fotografii;
//	float spatiu_ocupat;
//};
//struct Nod {
//	Album info;
//	Nod* stanga;
//	Nod* dreapta;
//};
//struct Heap {
//	Album* vector;
//	int dim;
//};
//
//void afisareAlbum(Album a) {
//	printf("Email: %s, Denumire: %s, Nr_Fotografii : %d, Spatiu_Ocupat: %.2f\n",
//		a.email_utilizator, a.denumire_album, a.nr_fotografii, a.spatiu_ocupat);
//}
//
//void inserareArboreBinar(Nod** radacina, Album a) {
//	if (*radacina == NULL) {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = a;
//		nou->stanga = NULL;
//		nou->dreapta = NULL;
//		*radacina = nou;
//	}
//	else {
//		if (a.nr_fotografii > (*radacina)->info.nr_fotografii) {
//			inserareArboreBinar(&(*radacina)->dreapta, a);
//		}
//		else {
//			inserareArboreBinar(&(*radacina)->stanga, a);
//		}
//	}
//}
//// EX 2- Stergere Nod cu nr de fotografii minime
//Nod* stergereNod(Nod* radacina) {
//	if (radacina != NULL) {
//		if (radacina->stanga == NULL) {
//			Nod* minim = radacina;
//			radacina = radacina->dreapta;
//			free(minim->info.email_utilizator);
//			free(minim->info.denumire_album);
//			free(minim);
//			return radacina;
//		}
//		else {
//			radacina->stanga = stergereNod(radacina->stanga);
//			return radacina;
//		}
//	}
//	else {
//		return NULL;
//	}
//}
//
//
//void afisarePreOrdine(Nod *radacina) {
//	if (radacina != NULL) {
//		afisareAlbum(radacina->info);
//		afisarePreOrdine(radacina->stanga);
//		afisarePreOrdine(radacina->dreapta);
//	}
//}
//
//// EX 3 - Heap bazat pe aceeasi denumire
//
////void inserareHeap(Nod* radacina, Heap* h, const char* denumire_cautata ) {
////	Nod* temp = radacina;
////	h->vector = (Album*)malloc(sizeof(Album) * 6);
////	int index = 0;
////	if (temp != NULL) {
////		if (strcmp(radacina->info.denumire_album, denumire_cautata) == 0) {
////			h->vector[index] = radacina->info;
////			index++;
////		}
////		inserareHeap(radacina->stanga, &h, denumire_cautata);
////		inserareHeap(radacina->dreapta, &h, denumire_cautata);
////	}
////}
//
//
//
//void afisareHeap(Heap h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareAlbum(h.vector[i]);
//	}
//}
//
//void filtrare() {
//
//}
//
////void inserareHeapDinListaDubla(ListaDubla lista, Heap* h) {
//	//	int index = 0;
//	//	h->dim = 0; 
//	//	Nod* temp = lista.primulNod;
//	//
//	//	while (temp != NULL) {
//	//		h->dim++;
//	//		temp = temp->next;
//	//	}
//	//	h->vector = (Proiect*)malloc(sizeof(Proiect) * h->dim);
//	//	index = 0;
//	//	temp = lista.primulNod;
//	//	while (temp != NULL) {
//	//		h->vector[index] = temp->info;
//	//		index++;
//	//		temp = temp->next;
//	//	}
//	//}
//
//void main() {
//	int nrAlbume;
//	char buffer[30];
//
//	Album a;
//	Nod* radacina = NULL;
//
//	FILE* f = fopen("albume.txt", "r");
//	fscanf(f, "%d", &nrAlbume);
//	for (int i = 0; i < nrAlbume; i++) {
//		fscanf(f, "%s", buffer);
//		a.email_utilizator = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(a.email_utilizator, buffer);
//		fscanf(f, "%s", buffer);
//		a.denumire_album = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(a.denumire_album, buffer);
//		fscanf(f, "%d", &a.nr_fotografii);
//		fscanf(f, "%f", &a.spatiu_ocupat);
//
//		inserareArboreBinar(&radacina, a);
//	}
//	fclose(f);
//	afisarePreOrdine(radacina);
//	printf("EX3 : Stergere nod cu nr de fotografii minime: \n\n");
//	radacina = stergereNod(radacina);
//	afisarePreOrdine(radacina);
//	printf("EX4 : Heap: \n\n");
//	Heap h;
//	h.dim = 0; // Inițializare dimensiune heap
//	inserareHeap(radacina, &h, "PozeFamilie");
//	//afisareHeap(h);
//}
//
//// ListaDubla cu Heap
//typedef struct Vagon Vagon;
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
//typedef struct Heap Heap;
//
//struct Vagon {
//	int nr_vagon;
//	char* firma_transport;
//	int nr_bilete_vandute;
//	int capacitate_vagon;
//};
//struct Nod {
//	Vagon info;
//	Nod* next;
//	Nod* prev;
//};
//struct ListaDubla {
//	Nod* prim;
//	Nod* ultim;
//};
//struct Heap {
//	int dim;
//	Vagon* vector;
//};
//
//void afisareVagon(Vagon v) {
//	printf("NR VAG: %d, Firma: %s, Nr bilete: %d, Capacitate: %d\n",
//		v.nr_vagon, v.firma_transport, v.nr_bilete_vandute, v.capacitate_vagon);
//}
//// Inserare Heap
//
//void inserareHeap2(Heap* h, Vagon v) {
//	
//	for (int i = 0; i < 4; i++) {
//		h->vector[i] = v;
//	}
//}
//
//ListaDubla inserareInceput(ListaDubla lista, Vagon v) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = v;
//	nou->next = lista.prim;
//	nou->prev = NULL;
//
//	if (lista.prim != NULL) {
//		lista.prim->prev = nou;
//	}
//	else {
//		lista.ultim = nou;
//	}
//	lista.prim = nou;
//	return lista;
//}
//
//void afisareLista(ListaDubla lista) {
//	while (lista.prim != NULL) {
//		afisareVagon(lista.prim->info);
//		lista.prim = lista.prim->next;
//	}
//}
//// EX 3 - Stergere ListaDubla cu nr bilete minime
//
//void stergereNodMinim(ListaDubla* lista) {
//	Nod* temp = lista->prim;
//	Nod* minim = lista->prim;
//	while (temp != NULL) {
//		if (temp->info.nr_bilete_vandute < minim->info.nr_bilete_vandute) {
//			minim = temp;
//		}
//		temp = temp->next;
//	}
//		if (minim->prev != NULL) {
//			minim->prev->next = minim->next;
//		}
//		if (minim->next != NULL) {
//			minim->next->prev = minim->prev;
//		}
//		//trb sa legi nodurile
//	free(minim->info.firma_transport);
//	free(minim);
//}
//
//// EX 4 - Salvare pe Heap
//
//void inserareHeap(ListaDubla lista, Heap* h) {
//	
//	h->dim = 0;
//	Nod* aux = lista.prim;
//	Nod* aux2 = lista.prim;
//	while (aux != NULL) {
//		h->dim++;
//		aux = aux->next;
//	}
//	h->vector = (Vagon*)malloc(sizeof(Vagon) * h->dim);
//	h->dim = 0;
//	while (aux2 != NULL) {
//		h->vector[h->dim] = aux2->info;
//		h->dim++;
//		aux2 = aux2->next;
//	}
//}
//
//void afisareHeap(Heap h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareVagon(h.vector[i]);
//	}
//}
//
//void filtrareHeap(Heap h, int index) {
//	if (h.dim > 0) {
//		int pozS = 2 * index + 1;
//		int pozD = 2 * index + 2;
//		int pozMax = index;
//
//		if (h.dim > pozS && h.vector[pozMax].capacitate_vagon < h.vector[pozS].capacitate_vagon) {
//			pozMax = pozS; 
//		}
//		if (h.dim > pozD && h.vector[pozMax].capacitate_vagon < h.vector[pozD].capacitate_vagon) {
//			pozMax = pozD; 
//		}
//		if (pozMax != index) {
//			// Interschimbare
//			Vagon aux = h.vector[pozMax];
//			h.vector[pozMax] = h.vector[index];
//			h.vector[index] = aux;
//
//			filtrareHeap(h, pozMax);
//		}
//	}
//}
//
//// EX 5 - Modificare Heap
//
//void modificareNrBilete(Heap* h, int nr_vagon_cautat, int numar_bilete) {
//	for (int i = 0; i < h->dim; i++) {
//		if (h->vector[i].nr_vagon == nr_vagon_cautat) {
//			h->vector[i].nr_bilete_vandute = numar_bilete;
//		}
//	}
//}
//
//
//void main() {
//	int nrVagoane;
//		char buffer[30];
//
//		
//		Vagon v;
//		Nod* radacina = NULL;
//		Heap h;
//		
//		ListaDubla lista;
//		lista.prim = NULL;
//		lista.ultim = NULL;
//	
//		FILE* f = fopen("vagoane.txt", "r");
//		fscanf(f, "%d", &nrVagoane);
//		for (int i = 0; i < nrVagoane; i++) {
//			fscanf(f, "%d", &v.nr_vagon);
//			fscanf(f, "%s", buffer);
//			v.firma_transport = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//			strcpy(v.firma_transport, buffer);
//			fscanf(f, "%d", &v.nr_bilete_vandute);
//			fscanf(f, "%d", &v.capacitate_vagon);
//
//			//lista = inserareInceput(lista, v);
//			inserareHeap2(&h, v);
//
//		}
//		fclose(f);
//		//printf("Afisare ListaDubla: \n");
//		//afisareLista(lista);
//		//printf("\nVagon sters: \n");
//		///*stergereNodMinim(&lista);*/
//		//afisareLista(lista);
//
//		//printf("EX 4 - Inserare Heap: \n");
//		//
//		//h.dim = 4;
//		//inserareHeap(lista, &h);
//		////afisareHeap(h);
//		//for (int i = h.dim / 2 - 1; i >= 0; i--) {
//		//	filtrareHeap(h, i);
//		//}
//		//afisareHeap(h);
//		//printf("EX 5 - Modificare Heap: \n");
//		//modificareNrBilete(&h, 3, 26);
//		//afisareHeap(h);
//		printf("EX 6 - Inserare functie de Heap: \n");
//		afisareHeap(h);
//
//}
//
//typedef struct Examen Examen;
//typedef struct Nod Nod;
//typedef struct HashTable HashTable;
//
//struct Examen {
//	int id_examen;
//	char* disciplina;
//	float nota;
//	char* profesor;
//};
//struct Nod {
//	Examen info;
//	Nod* next;
//};
//struct HashTable {
//	int dim;
//	Nod** vector;
//};
//
//void afisareExmaen(Examen e) {
//	printf("Id: %d, Disciplina: %s, Nota: %.2f, Profesor: %s\n",
//		e.id_examen, e.disciplina, e.nota, e.profesor);
//}
//
//HashTable initializareHash(int dim) {
//	HashTable tabela;
//	tabela.dim = dim;
//	tabela.vector = (Nod**)malloc(sizeof(Nod*) * dim);
//	for (int i = 0; i < dim; i++) {
//		tabela.vector[i] = NULL; //facem poz pe 0
//	}
//	return tabela;
//}
//
//int functieHash(int dim, const char* disciplina) {
//	return strlen(disciplina) % dim;
//}
//
//void inserareListaFinal(Nod** cap, Examen e) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = e;
//	nou->next = NULL;
//	if (*cap != NULL) {
//		Nod* aux = *cap;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//}
//
//void inserareHashTable(HashTable* tabel, Examen e) {
//	if (tabel->dim > 0) {
//		int poz = functieHash(tabel->dim, e.disciplina);
//		if (poz >= 0 && poz < tabel->dim) {
//			inserareListaFinal(&(tabel->vector[poz]), e);
//		}
//	}
//}
//
//void afisareHashTable(HashTable tabela) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			printf("Pozitia din tabel %d\n", i);
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				afisareExmaen(temp->info);
//				temp = temp->next;
//			}
//		}
//		else {
//			printf("Pozitia %d este goala!\n", i);
//		}
//	}
//}
//// EX2 - Adaugare note (suma)
//
//float sumaNote(HashTable tabela, const char* disciplina_cautata) {
//	float nota_finala = 0.0f;
//
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				if (strcmp(temp->info.disciplina, disciplina_cautata) == 0) {
//					nota_finala += temp->info.nota;
//				}
//				temp = temp->next;
//			}
//		}
//		else {
//			printf("Pozitia %d este goala!\n", i);
//		}
//	}
//	return nota_finala;
//}
//
//// EX3 - Modificare Hash
//
//void modificareHashNote(HashTable tabela, const char* disciplina_cautata, int nota_noua) {
//
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				if (strcmp(temp->info.disciplina, disciplina_cautata) == 0) {
//					temp->info.nota = nota_noua;
//				}
//				temp = temp->next;
//			}
//		}
//		else {
//			printf("Pozitia %d este goala!\n", i);
//		}
//	}
//
//}
//
////void modificaNumeBeneficiar(HashTable tabela, const char* beneficiarVechi, const char* beneficiarNou) {
////	if (tabela.vector != NULL) {
////		for (int i = 0; i < tabela.dim; i++) {
////			Nod* temp = tabela.vector[i];
////			while (temp != NULL) {
////				if (strcmp(temp->info.beneficiar, beneficiarVechi) == 0) {
////					// Eliberam beneficiarul vechi si alocam mem pentru urmatorul
////					free(temp->info.beneficiar);
////					temp->info.beneficiar = (char*)malloc(sizeof(char) * (strlen(beneficiarNou) + 1));
////					strcpy(temp->info.beneficiar, beneficiarNou);
////					printf("Modificarea a fost realizata cu succes!\n");
////				}
////				temp = temp->next;
////			}
////		}
////	}
////}
//
//void main() {
//	int nrExamen;
//	char buffer[30];
//	HashTable tabela;
//	tabela = initializareHash(5);
//
//	Examen e;
//	FILE* f = fopen("examene.txt", "r");
//	fscanf(f, "%d", &nrExamen);
//	for (int i = 0; i < nrExamen; i++) {
//		fscanf(f, "%d", &e.id_examen);
//		fscanf(f, "%s", buffer);
//		e.disciplina = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(e.disciplina, buffer);
//		fscanf(f, "%f", &e.nota);
//		fscanf(f, "%s", buffer);
//		e.profesor = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(e.profesor, buffer);
//
//		inserareHashTable(&tabela, e);
//
//	}
//	fclose(f);
//	printf("---> HashTable: \n");
//	afisareHashTable(tabela);
//	printf("--> Suma de note pentru disciplina MicroEconomie: %.2f", sumaNote(tabela, "Microeconomie"));
//	printf("\n");
//	printf("--> Am modificat nota de la disciplina SGBD: \n");
//	modificareHashNote(tabela, "SGBD", 20);
//	afisareHashTable(tabela);
//
//}

//// HashSimplu
//typedef struct Factura Factura;
//typedef struct Nod Nod;
//typedef struct HashTable HashTable;
//
//struct Factura {
//	int cod_client;
//	char* denumire_furnizor;
//	float suma_plata;
//	char* data_scadenta;
//};
//struct Nod {
//	Factura info;
//	Nod* next;
//};
//struct HashTable {
//	int dim;
//	Nod** vector;
//};
//void afisareFactura(Factura f) {
//	printf("Cod: %d, Denumire: %s, Suma: %.2f ,Data-Scadenta: %s\n",
//		f.cod_client, f.denumire_furnizor, f.suma_plata, f.data_scadenta);
//}
//
//// probam dupa
//HashTable initializareHash(int dim) {
//	HashTable tabela;
//	tabela.dim = dim;
//	tabela.vector = (Nod**)malloc(sizeof(Nod*) * tabela.dim);
//	for (int i = 0; i < dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//	return tabela;
//}
//
//// inserare lista simpla
//void inserareListaSimplaFinal(Nod** cap, Factura f) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = f;
//	nou->next = NULL;
//	if (*cap != NULL) {
//		Nod* temp = *cap;
//		while (temp->next) {
//			temp->next = *cap;
//		}
//		temp->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//}
//
//// functie Hash
//int functieHash(int dim, const char* denumire_furnizor) {
//	return strlen(denumire_furnizor) % dim;
//}
//
//// inserare Hash
//void inserareHashTabel(HashTable* tabela, Factura f) {
//	if (tabela->dim > 0) {
//		int poz = functieHash(tabela->dim, f.denumire_furnizor);
//		if (poz >= 0 && poz < tabela->dim) {
//			inserareListaSimplaFinal(&(tabela->vector[poz]), f);
//		}
//	}
//}
//
//
////afisare Hash
//void afisareHash(HashTable tabela) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			printf("Pozitia din tabel %d\n", i);
//
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				afisareFactura(temp->info);
//				temp = temp->next;
//			}
//		}
//		else {
//			printf("Pozitia %d este goala\n", i);
//		}
//	}
//	
//}
//// return Fact dupa data_scadenta
//
//int nrFacturi2(HashTable tabela, const char* data_scadenta_cautata) {
//	int nr_facturi = 0;
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				if (strcmp(temp->info.data_scadenta, data_scadenta_cautata) == 0) {
//					nr_facturi++;
//				}
//				temp = temp->next;
//			}
//		}
//	}
//	return nr_facturi;
//}
//
//
//
//void main() {
//	int nrFacturi;
//	char buffer[30];
//
//	Factura f;
//	HashTable tabela = initializareHash(10);
//
//	FILE* fisier = fopen("facturi.txt", "r");
//	fscanf(fisier, "%d", &nrFacturi);
//	for (int i = 0; i < nrFacturi; i++) {
//		fscanf(fisier, "%d", &f.cod_client);
//		fscanf(fisier, "%s", buffer);
//		f.denumire_furnizor = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(f.denumire_furnizor, buffer);
//		fscanf(fisier, "%f", &f.suma_plata);
//		fscanf(fisier, "%s", buffer);
//		f.data_scadenta = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(f.data_scadenta, buffer);
//
//		inserareHashTabel(&tabela, f);
//
//	}
//	fclose(fisier);
//	afisareHash(tabela);
//	printf("\n\n");
//	
//	printf("Numarul fac cu data_scadenta egala cu 30 : %d", nrFacturi2(tabela, "30"));
//
//
//}
//
//typedef struct Factura Factura;
//typedef struct Nod Nod;
//typedef struct HashTable HashTable;
//typedef struct ListaDubla ListaDubla;
//typedef struct Heap Heap;
//
//struct Factura {
//	int cod_client;
//	char* denumire_furnizor;
//	float suma_plata;
//	char* data_scadenta;
//};
//struct Nod {
//	Factura info;
//	Nod* next;
//	Nod* prev;
//};
//struct HashTable {
//	int dim;
//	Nod** vector;
//};
//struct ListaDubla {
//	Nod* primulNod;
//	Nod* ultimulNod;
//};
//struct Heap {
//	Factura* vector;
//	int dim;
//};
//
//
//void afisareFactura(Factura f) {
//	printf("Cod: %d, Denumire: %s, Suma: %.2f ,Data-Scadenta: %s\n",
//		f.cod_client, f.denumire_furnizor, f.suma_plata, f.data_scadenta);
//}
//// initializare Hash
//HashTable initilizareHashTable(int dim) {
//	HashTable tabela;
//	tabela.dim = dim;
//	tabela.vector = (Nod*)malloc(sizeof(Nod*) * tabela.dim);
//
//	for (int i = 0; i < dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//
//	return tabela;
//}
////InserareListaSimpla final
//void inserareListaFinal(Nod** cap, Factura f) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = f;
//	nou->next = NULL;
//	if (*cap != NULL) {
//		Nod* aux = *cap;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//}
//
////functia hash
//int functieHash(int dim, const char* denumire_furnizor) {
//	return strlen(denumire_furnizor) % dim;
//}
//
////inserareaHashTable
//
//void inserareHashTable(HashTable tabela, Factura f) {
//	if (tabela.dim > 0) {
//		int poz = functieHash(tabela.dim, f.denumire_furnizor);
//		if (poz > 0 && poz < tabela.dim) {
//			inserareListaFinal(&(tabela.vector[poz]->info), f);
//		}
//	}
//}
//// afisareHashTable
//
//void afisareHashTable(HashTable tabela) {
//	if (tabela.dim > 0) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i] != NULL) {
//				Nod* temp = tabela.vector[i];
//				while (temp != NULL) {
//					afisareFactura(temp->info);
//					temp = temp->next;
//				}
//			}
//			else {
//				printf("Pozitia %d este goala! \n", i);
//			}
//		}
//	}
//}
//
//
////Inserare pe listaDubla
//ListaDubla inserareListaDubla(ListaDubla lista, Factura f) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = f;
//	nou->prev = NULL;
//	nou->next = lista.primulNod;
//
//	if (lista.primulNod != NULL) {
//		lista.primulNod->prev = nou;
//	}
//	else {
//		lista.ultimulNod = nou;
//	}
//	lista.primulNod = nou;
//
//	return lista;
//
//}
//// inserare la inceput
//ListaDubla inserareFinal(ListaDubla lista, Factura f) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = f;
//	nou->prev = lista.ultimulNod;
//	nou->next = NULL;
//	if (lista.ultimulNod != NULL) {
//		lista.ultimulNod->next = nou;
//		lista.ultimulNod = nou;
//	}
//	else {
//		lista.primulNod = nou;
//		lista.ultimulNod = nou;
//	}
//
//	return lista;
//}
//// Heap -> initializare in main
//void initializareHeap(int dim, Factura f, Heap h) {
//	h.dim = 0;
//	h.vector = (Factura**)malloc(sizeof(Factura*) * h.dim);
//
//
//}
//
//
//
//
//
////afisareListaDubla
//
//void afisareListaDubla(ListaDubla lista) {
//	while (lista.primulNod != NULL) {
//		afisareFactura(lista.primulNod->info);
//		lista.primulNod = lista.primulNod->next;
//	}
//}
//
//
//
//
//void main() {
//		int nrFacturi;
//		char buffer[30];
//	
//		Factura f;
//		
//	
//		FILE* fisier = fopen("facturi.txt", "r");
//		fscanf(fisier, "%d", &nrFacturi);
//		for (int i = 0; i < nrFacturi; i++) {
//			fscanf(fisier, "%d", &f.cod_client);
//			fscanf(fisier, "%s", buffer);
//			f.denumire_furnizor = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//			strcpy(f.denumire_furnizor, buffer);
//			fscanf(fisier, "%f", &f.suma_plata);
//			fscanf(fisier, "%s", buffer);
//			f.data_scadenta = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//			strcpy(f.data_scadenta, buffer);
//	
//			
//	
//		}
//		fclose(fisier);
//
//	}

// ListaDubla - Vector 
// 
//typedef struct Comanda Comanda;
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
//
//struct Comanda {
//	unsigned int numar_comanda;
//	char* data_livrare_programata;
//	char* data_livrare_efectuata;
//	char* nume_cleint;
//	float suma_plata;
//
//};
//struct Nod {
//	Comanda info;
//	Nod* next;
//	Nod* prev;
//};
//struct ListaDubla {
//	Nod* prim_nod;
//	Nod* ultim_nod;
//};
//
//void afisareComanda(Comanda c) {
//	printf("Nr: %u, Data-Programata: %s, Data-Efectuata: %s, Nume: %s, Suma: %.2f\n",
//		c.numar_comanda, c.data_livrare_programata, c.data_livrare_efectuata, c.nume_cleint, c.suma_plata);
//}
//
//// InserareListaDubla
//
//ListaDubla adugareLista(ListaDubla lista, Comanda c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = c;
//	nou->prev = NULL;
//	nou->next = lista.prim_nod;
//
//	if (lista.prim_nod != NULL) {
//		lista.prim_nod->prev = nou;
//	}
//	else {
//		lista.ultim_nod = nou;
//	}
//	lista.prim_nod = nou;
//	return lista;
//}
//
//void afisareListaDubla(ListaDubla lista) {
//	while (lista.prim_nod != NULL) {
//		afisareComanda(lista.prim_nod->info);
//		lista.prim_nod = lista.prim_nod->next;
//	}
//}
//// Implementati functia care returneaa din lista dubla 
//// comanda cu diferenta maxima dintre data livrare efectuata si 
//// data programata.Functia implementata se apeleaza in functia
//// main(), iar rezultatul apelului (numarul zile) se afiseaza
//// in consola de executie a aplicatiei
//
////EX : 2
//int diferentaZile(ListaDubla lista) {
//	int diferenta_maxima = 0;
//	
//	return NULL;
//}
////EX : 3
//void aplicareMaximDiscount(ListaDubla lista, float discount) {
//	Nod* maxim = (Nod*)malloc(sizeof(Nod));
//	while (lista.prim_nod != NULL) {
//		lista.prim_nod->info.suma_plata = lista.prim_nod->info.suma_plata - (lista.prim_nod->info.suma_plata * (discount / 100));
//		if (maxim->info.suma_plata < lista.prim_nod->info.suma_plata) {
//			maxim = lista.prim_nod;
//		}
//		lista.prim_nod = lista.prim_nod->next;
//	}
//	printf("\n%.2f\n",maxim->info.suma_plata);
//}
//
//// EX : 4
//void clientulComenziMaxime(ListaDubla lista) {
//	int max_comenzi = 0;
//	char* nume_client_maxim = NULL;
//	Nod* aux = lista.prim_nod;
//	while (aux != NULL) {
//		int nr_comenzi = 0;
//		Nod* aux2 = lista.prim_nod;
//		while (aux2 != NULL) {
//			if (strcmp(aux->info.nume_cleint, aux2->info.nume_cleint) == 0) {
//				nr_comenzi++;
//			}
//			aux2 = aux2->next;
//		}
//
//		if (nr_comenzi > max_comenzi) {
//			max_comenzi = nr_comenzi;
//			if (nume_client_maxim != NULL) {
//				free(nume_client_maxim);
//			}
//			nume_client_maxim = (char*)malloc(sizeof(char) * (strlen(aux->info.nume_cleint) + 1));
//			strcpy(nume_client_maxim, aux->info.nume_cleint);
//		}
//		aux = aux->next;
//	}
//	if (nume_client_maxim != NULL) {
//		printf("\nNumele clientului cu comenzile maxime este: %s", nume_client_maxim);
//		free(nume_client_maxim);
//	}
//}
//
//
//// EX: 5
//
//void conversieVector(ListaDubla lista, Comanda* vector, int* nr) {
//	while (lista.prim_nod != NULL) {
//		vector[*nr] = lista.prim_nod->info;
//		(*nr)++;
//		lista.prim_nod = lista.prim_nod->next;
//	}
//}
//
//// Dezalocare
//void dezalocareListaDubla(ListaDubla lista) {
//	Nod* aux = lista.prim_nod;
//	while (lista.prim_nod != NULL) {
//		
//		free(aux->info.data_livrare_efectuata);
//		free(aux->info.data_livrare_programata);
//		free(aux->info.nume_cleint);
//		free(aux);
//
//		lista.prim_nod = lista.prim_nod->next;
//	}
//}
//
//
//
//void main() {
//	int nrComenzi;
//	char buffer[30];
//	Comanda c;
//
//	ListaDubla lista;
//	lista.prim_nod = NULL;
//	lista.ultim_nod = NULL;
//	
//	FILE* f = fopen("comenzi.txt", "r");
//	fscanf(f, "%d", &nrComenzi);
//	for (int i = 0; i < nrComenzi; i++) {
//		fscanf(f, "%u", &c.numar_comanda);
//		/*char* data_livrare_programata;*/
//		fscanf(f, "%s", buffer);
//		c.data_livrare_efectuata = (char*)malloc(sizeof(char) * (strlen(buffer)) +1);
//		strcpy(c.data_livrare_efectuata, buffer);
//		/*char* data_livrare_efectuata;*/
//		fscanf(f, "%s", buffer);
//		c.data_livrare_programata = (char*)malloc(sizeof(char) * (strlen(buffer)) + 1);
//		strcpy(c.data_livrare_programata, buffer);
//		fscanf(f, "%s", buffer);
//		c.nume_cleint = (char*)malloc(sizeof(char) * (strlen(buffer))+1);
//		strcpy(c.nume_cleint, buffer);
//		fscanf(f, "%f", &c.suma_plata);
//
//		//inserare in structura
//		lista = adugareLista(lista, c);
//
//	}
//	fclose(f);
//	printf("\n -- Afisare ListaDubla --\n");
//	afisareListaDubla(lista);
//	printf("\n -- EXERCITIUL 3 - Discount \n");
//	aplicareMaximDiscount(lista, 20);
//	afisareListaDubla(lista);
//	printf("\n -- EXERCITIUL 4 - NumeAsemanatoare \n");
//	clientulComenziMaxime(lista);
//	printf("\n -- EXERCITIUL 5 - Conversie Vector \n");
//
////	printf("\nEX 5 (VECTOR):\n");
////	int nr = 0;
////	Rezervare* vector = (Rezervare*)malloc(sizeof(Rezervare) * nrRezervari);
////	salvareVector(radacina, vector, &nr);
////	for (int i = 0; i < nr; i++) {
////		printf("ID-ul %hhu , Nume Client: %s\n",
////			vector[i].id_rezervare, vector[i].nume_client);
////	}
////	free(vector);
//
//	int nr = 0;
//	Comanda* vector = (Comanda*)malloc(sizeof(Comanda) * nrComenzi);
//	conversieVector(lista, vector, &nr);
//	for (int i = 0; i < nr; i++) {
//		printf("Numar Comanda: %u, Nume Client: %s\n",
//			vector[i].numar_comanda, vector[i].nume_cleint);
//	}
//	free(vector);
//
//	dezalocareListaDubla(lista);
//	afisareListaDubla(lista);
//}

//// Arbore - Vector - 2023
//typedef struct Fotografie Fotografie;
//typedef struct Nod Nod;
//
//struct Fotografie {
//	unsigned int id_fotografie;
//	char* data_realizare;
//	char* numele_orasului;
//	float rezolutie; //120-600
//};
//
//struct Nod {
//	Nod* stanga;
//	Nod* dreapta;
//	Fotografie info;
//};
//
//void afisareFotografie(Fotografie f) {
//	printf("ID Foto: %d, Oras: %s, Rezolutie: %.2f, Data: %s\n",
//		f.id_fotografie, f.numele_orasului, f.rezolutie, f.data_realizare);
//}
//// Inserare ABC
//void inserareArbore(Nod** radacina, Fotografie f) {
//	if (*radacina == NULL) {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = f;
//		nou->dreapta = NULL;
//		nou->stanga = NULL;
//		*radacina = nou;
//	}
//	else {
//		if (f.id_fotografie < (*radacina)->info.id_fotografie) {
//			inserareArbore(&(*radacina)->stanga, f);
//		}
//		else {
//			inserareArbore(&(*radacina)->dreapta, f);
//		}
//	}
//
//}
//// Afisare PREORDINE, POSTORDINE, IN_ORDINE
//void afisarePreordine(Nod* radacina) {
//	if (radacina != NULL) {
//		afisareFotografie(radacina->info);
//		afisarePreordine(radacina->stanga);
//		afisarePreordine(radacina->dreapta);
//	}
//}
//
//void afisareInOrdine(Nod* radacina) {
//	if (radacina != NULL) {
//		afisareInOrdine(radacina->stanga);
//		afisareFotografie(radacina->info);
//		afisareInOrdine(radacina->dreapta);
//	}
//}
//
//// Exercitiul 2: Numarul de fotografii realizate in acelasi oras
//int numarFotografii(Nod* radacina, const char* oras_cautat) {
//	int nr_fotografii = 0;
//	if (radacina != NULL) {
//
//		if (strcmp(radacina->info.numele_orasului, oras_cautat) == 0) {
//			nr_fotografii++;
//		}
//		nr_fotografii += numarFotografii(radacina->stanga, oras_cautat);
//		nr_fotografii += numarFotografii(radacina->dreapta, oras_cautat);
//	}
//	return nr_fotografii;
//}
//
//// Exercitiul 3: Modifica data realizarii unei fotografii specificata
////	             prin id_fotografie, in lista. Noua data este specificata
////				 in lista de parametrii
//
//void modificaDataRealizarii(Nod** radacina, unsigned int id_fotografie, const char* data_noua) {
//	if (*radacina != NULL) {
//		Nod* temp = *radacina;
//		if ((*radacina)->info.id_fotografie == id_fotografie){
//			free(temp->info.data_realizare);
//			temp->info.data_realizare = (char*)malloc(sizeof(char) * (strlen(data_noua) + 1));
//			strcpy(temp->info.data_realizare, data_noua);
//		}
//		modificaDataRealizarii(&(*radacina)->stanga, id_fotografie, data_noua);
//		modificaDataRealizarii(&(*radacina)->dreapta, id_fotografie, data_noua);
//	}
//}
//
//// Exercitiul 4: Stergere Nod Radacina
//
//Nod* stergereRadacina(Nod* radacina) {
//	if (radacina != NULL) {
//		if (radacina->stanga == NULL) {
//			Nod* minim = radacina;
//			radacina = radacina->dreapta;
//			free(minim->info.numele_orasului);
//			free(minim->info.data_realizare);
//			free(minim);
//			return radacina;
//		}
//		else {
//			radacina->stanga = stergereRadacina(radacina->stanga);
//			return radacina;
//		}
//	}
//	else {
//		return NULL;
//	}
//}
//
//// Exercitiul 5: Transformare in Vector pentru fotografiile care au 
////               o rezolutie primita ca parametru de intrare al functiei
//
//void salvareVector(float rezolutie,Nod* radacina, Fotografie* vector, int* nr) {
//	if (radacina != NULL) {
//		if (radacina->info.rezolutie == rezolutie) {
//			vector[*nr] = radacina->info;
//			(*nr)++;
//		}
//		salvareVector(rezolutie, radacina->stanga, vector, nr);
//		salvareVector(rezolutie, radacina->dreapta, vector, nr);
//	}
//}
//
//
//void main() {
//
//	int nrFotografii;
//	char buffer[30]; 
//
//	Fotografie foto;
//	Nod* radacina = NULL;
//
//	FILE* f = fopen("fotografii.txt", "r");
//	fscanf(f, "%d", &nrFotografii);
//	for (int i = 0; i < nrFotografii; i++) {
//		fscanf(f, "%u", &foto.id_fotografie);
//		fscanf(f, "%s", buffer);
//		foto.numele_orasului = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(foto.numele_orasului, buffer);
//		fscanf(f, "%f", &foto.rezolutie);
//		fscanf(f, "%s", buffer);
//		foto.data_realizare = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy(foto.data_realizare, buffer);
//
//		inserareArbore(&radacina, foto);
//
//	}
//	fclose(f);
//	printf(" --- Afisare ArboreBinar ---\n");
//	afisarePreordine(radacina);
//	printf(" \n--- Exercitiul 2: ---\n");
//	printf("Orasul Tulcea a avut: %d fotografii", numarFotografii(radacina, "Tulcea"));
//	printf(" \n\n--- Exercitiul 3: ---\n");
//	modificaDataRealizarii(&radacina, 6 , "20.10.2010");
//	afisarePreordine(radacina);
//	printf(" \n\n--- Exercitiul 4 Stergere Nod Minim + afisare InOrdine: ---\n");
//	radacina = stergereRadacina(radacina);
//	afisareInOrdine(radacina);
//	printf(" \n\n--- Exercitiul 5 Vector Conditionat: ---\n");
//
//	int nr = 0;
//	Fotografie* vector = (Fotografie*)malloc(sizeof(Fotografie) * nrFotografii);
//	salvareVector(190, radacina, vector, &nr);
//	for (int i = 0; i < nr; i++) {
//		printf("ID: %u, Oras: %s\n", vector[i].id_fotografie, vector[i].numele_orasului);
//	}
//	free(vector);
//
//}

// HashTable - ListaDubla (2023)
//typedef struct Garantie Garantie;
//typedef struct HashTable HashTable;
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
//
//struct Garantie {
//	char* denumire_produs;
//	unsigned int nr_luni_garantie;
//	unsigned char este_electronica;
//	char* service;
//};
//struct Nod {
//	Garantie info;
//	Nod* next; 
//	Nod* prev;
//};
//struct HashTable {
//	int dim;
//	Nod** vector;
//};
//struct ListaDubla {
//	Nod* primul_nod;
//	Nod* ultimul_nod;
//};
//
//void afisareGarantie(Garantie g) {
//	printf("Denumire: %s, Luni-Garantie: %hu, Electronic : %hhu, Service: %s\n",
//		g.denumire_produs, g.nr_luni_garantie, g.este_electronica, g.service);
//}
//
//// Initializare ListaSimpla
//void inserareLista(Nod** cap, Garantie g ) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = g;
//	nou->next = NULL;
//
//	if (*cap == NULL) {
//		*cap = nou;
//	}
//	else {
//		Nod* current = *cap;
//		while (current->next != NULL) {
//			current = current->next;
//		}
//		current->next = nou;
//	}
//
//}
//
//// Implementare HashTable
//HashTable initializareTabela(int dim) {
//	HashTable tabela;
//	tabela.dim = dim;
//	tabela.vector = (Nod**)malloc(sizeof(Nod*) * dim);
//	for (int i = 0; i < dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//	return tabela;
//}
//// Functia Hash
//int functieHash(int dim, const char* service) {
//	return strlen(service) % dim;
//}
//// Inserare HashTable
//void inserareHashTable(HashTable* tabela, Garantie g) {
//	if (tabela->dim > 0) {
//		int poz = functieHash(tabela->dim, g.service);
//		if (poz >= 0 && poz < tabela->dim) {
//			inserareLista(&(tabela->vector[poz]), g);
//		}
//	}
//}
//// Afisare HashTable
//void afisareHashTable(HashTable tabela){
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i] != NULL) {
//				printf("Pozitia %d este ocupata de: \n", i);
//				Nod* temp = tabela.vector[i];
//				while (temp != NULL) {
//					afisareGarantie(temp->info);
//					temp = temp->next;
//				}
//			}
//			else {
//				printf("Pozitia %d este goala!\n", i);
//			}
//		}
//}
//
//// Exercitiul 2 : Nr Garantii bazat pe un anumit service
//int nrGarantiiService(HashTable tabela, const char* nume_service_cautat) {
//	int nr_garantii = 0;
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				if (strcmp(temp->info.service, nume_service_cautat) == 0) {
//					nr_garantii++;
//				}
//				temp = temp->next;
//			}
//		}
//	}
//	return nr_garantii;
//}
//
//// Exercitiul 3 : Extindere Garantie pentru pentru produsele electronice
//void extindereGarantie(HashTable tabela, unsigned int luni_extinse) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				if (temp->info.este_electronica == 1) {
//					temp->info.nr_luni_garantie += luni_extinse;
//				}
//				temp = temp->next;
//			}
//		}
//	}
//}
//
//// Exercitiul 4: Modificare Service (cheie) - nu merge
//void modificareService(HashTable tabela, const char* produs_cautat, const char* noul_produs) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				if (strcmp(temp->info.denumire_produs, produs_cautat) == 0) {
//					free(temp->info.denumire_produs);
//					temp->info.denumire_produs = (char*)malloc(sizeof(char) * (strlen(noul_produs) + 1));
//					strcpy(temp->info.denumire_produs, noul_produs);
//				}
//				temp = temp->next;
//			}
//		}
//	}
//}
//
//// Exercitiul 5: HashTable - ListaDubla
//
//ListaDubla inserareListaDubla(ListaDubla lista, Garantie g) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = g;
//	lista.primul_nod = nou;
//	lista.ultimul_nod = NULL;
//
//	if (lista.primul_nod) {
//		lista.primul_nod->prev = nou;
//	}
//	else {
//		lista.ultimul_nod = nou;
//	}
//	lista.primul_nod = nou;
//	return lista;
//}
//
//// Afisare ListaDubla
//void afisareLista(ListaDubla lista){
//	Nod* temp = lista.primul_nod;
//	while (temp != NULL) {
//		afisareGarantie(temp->info);
//		temp = temp->next;
//	}
//}
//
//
//void salvareListaDubla(HashTable tabela, ListaDubla lista) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			Nod* temp = tabela.vector[i];
//			while (temp != NULL) {
//				lista = inserareListaDubla(lista, temp->info);
//				temp = temp->next;
//			}
//		}
//	}
//}
//
//
//void main() {
//	int nrGarantii;
//	char buffer[30];
//
//	Garantie g;
//	HashTable tabela = initializareTabela(10);
//
//	ListaDubla lista;
//	lista.primul_nod = NULL;
//	lista.ultimul_nod = NULL;
//
//	FILE* f = fopen("garantii.txt", "r");
//	fscanf(f, "%d", &nrGarantii);
//	for (int i = 0; i < nrGarantii; i++) {
//		fscanf(f, "%s", buffer);
//		g.denumire_produs = (char*)malloc(sizeof(char) * (sizeof(buffer) + 1));
//		strcpy(g.denumire_produs, buffer);
//		fscanf(f, "%hu", &g.nr_luni_garantie);
//		fscanf(f, "%hhu", &g.este_electronica);
//		fscanf(f, "%s", buffer);
//		g.service = (char*)malloc(sizeof(char) * (sizeof(buffer) + 1));
//		strcpy(g.service, buffer);
//
//		inserareHashTable(&tabela, g);
//
//	}
//	fclose(f);
//	printf("\n--- Afisare HashTable ---\n ");
//	afisareHashTable(tabela);
//
//	printf("\n--- Exercitiul 2: Numar Garantii ---\n ");
//	printf("\n Numarul de garantii date de serviceul Renault este de: %d", nrGarantiiService(tabela, "Renault"));
//
//	printf("\n--- Exercitiul 3: Extindere Nr Garantii ---\n ");
//	extindereGarantie(tabela, 10);
//	afisareHashTable(tabela);
//
//	printf("\n--- Exercitiul 4: Modificare Cheie ---\n ");
//	modificareService(tabela, "Renault", "Sabin");
//	afisareHashTable(tabela);
//
//	printf("\n--- Exercitiul 5: Conversie ListaDubla: ---\n ");
//	salvareListaDubla(tabela, lista);
//	afisareLista(lista);
//}

// ABC cu Vector
typedef struct Nod Nod;
typedef struct Proiect Proiect;

struct Proiect {
	unsigned int cod_proiect;
	char* titlu;
	char* beneficiar;
	unsigned short numar_zile;
	float buget_alocat;
};

struct Nod {
	Nod* stanga;
	Nod* dreapta;
	Proiect info;
};

void afisareProiect(Proiect p) {
	printf("Cod: %u, Titlu: %s, Beneficiar: %s, Nr Zile: %hu, Buget: %.2f\n",
		p.cod_proiect, p.titlu, p.beneficiar, p.numar_zile, p.buget_alocat);
}

void inserareABC(Nod** radacina, Proiect p) {
	if (*radacina == NULL) {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->info = p;
		nou->stanga = NULL;
		nou->dreapta = NULL;
		*radacina = nou;
	}
	else {
		if (p.cod_proiect > (*radacina)->info.cod_proiect) {
			inserareABC(&(*radacina)->dreapta, p);
		}
		else {
			inserareABC(&(*radacina)->stanga, p);
		}
	}
}

void afisareInOrdine(Nod* radacina) {
	if (radacina != NULL) {
		afisareInOrdine(radacina->stanga);
		afisareProiect(radacina->info);
		afisareInOrdine(radacina->dreapta);
	}
}

int main() {
	int nrProiecte;
	char buffer[30];

	Proiect p;
	Nod* radacina = NULL;

	FILE* f = fopen("proiecte2023.txt", "r");
	if (f == NULL) {
		printf("Eroare la deschiderea fisierului.\n");
		return 1;
	}

	fscanf(f, "%d", &nrProiecte);
	for (int i = 0; i < nrProiecte; i++) {
		fscanf(f, "%u", &p.cod_proiect);
		fscanf(f, "%s", buffer);
		p.beneficiar = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(p.beneficiar, buffer);
		fscanf(f, "%hu", &p.numar_zile);
		fscanf(f, "%f", &p.buget_alocat);

		inserareABC(&radacina, p);
	}

	fclose(f);

	afisareInOrdine(radacina);

	return 0;
}



























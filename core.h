#ifndef CORE_H
#define CORE_H

#define N 25                                                            // numero di caratteri per nome piatti e ingredienti
#define M 100                                                           // numero di caratteri per messaggi
#define MEM 20                                                          // numero di elementi per cui viene inizialmente allocata dinamicamente la memoria
#define TAVOLI 15
#define ARCHIVIO_PIATTI 1
#define ARCHIVIO_INGREDIENTI 2
#define NCAMPI 6


typedef enum {Antipasto, Primo, Secondo, Contorno, Dessert} Tipologia;

typedef struct
{
    int id;
    char nome[N];
    Tipologia tipo;
    char ingredienti[3][N];
    float prezzo;

}Piatto;

typedef struct
{
    int id;
    char nome[N];
    int quantita;
} Ingrediente;

typedef struct
{
    int num_rec;                                            // numero di records totali nel file archivio piatti
    int rec_mem;                                            // numero massimo di piatti attualmente memorizzabili nel vettore
    int uid;                                                // ultimo id generato + 1 = id del prossimo piatto
    int ing_num_rec;                                        // numero records totali nel file archivio ingredienti
    int ing_rec_mem;                                        // numero massimo di ingredienti attualmente memorizzabili nel vettore
    float totale_scontrini;                                 // somma dei totali degli scontrini emessi
    char nome_ristorante[M];                                // nome del ristorante
} Archivio;

typedef struct
{
    int id;
    int id_piatto;                                          // id del piatto ordinato
    char nome_piatto[N];                                    // nome del piatto ordinato
    Tipologia tipo_piatto;                                  // tipo del piatto ordinato
    float prezzo_piatto;                                    // prezzo del piatto ordinato
    int porzioni;                                           // numero porzioni ordinate
    char ingredienti[3][N];

} Ordine;

typedef struct
{
    int id;
    Ordine *ordini;                                         // puntatore al vettore di ordini relativo al tavolo
    int num_ord;                                            // numero ordini relativi al tavolo
    int mem_ord;                                            // numero di ordini per cui e' stata allocata la memoria
    float prezzo_totale;

}Scontrino;


int inizializza (Piatto **, Ingrediente **, Archivio *);    // Controlla se esistono gli archivi ed in caso non esistano, li crea
int esiste_file (char *);                                   // Controlla se esiste il file il cui nome viene passato alla funzione come parametro
int crea_file (char *);                                     // Crea un file vuoto e lo chiama con il nome che viene passato alla funzione come parametro
int numero_rec(int);                                        // Calcola il numero dei record nel file 1=archivio piatti 2=archivio ingredienti
int last_record ();                                         // Restituisce id dell'ultimo record in archivio piatti
int carica_archivi (Piatto **, Ingrediente **, Archivio *); // Carica archivi in memoria
int controllo_nuovo_piatto (Piatto, Piatto *, Archivio *);  // Controlla se il nome del nuovo piatto esiste in archivio
int append_piatto(Piatto *);                                // Aggiunge un piatto all'archivio
void normalizza (char *);                                   // Normalizza nomi piatti e ingredienti trasformando la prima lettera in maiuscolo e le altre in minuscolo
int scrivi_modifica_piatto(Piatto *,int);                   // Scrive sul file il record n-esimo dell'archivio piatti
int inizializza_cassa (Scontrino **);                       // Inizializza il vettore scontrino ed i relativi vettori di ordini


#endif



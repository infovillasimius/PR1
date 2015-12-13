#include "gui.h"


/*  Funzione di Verifica iniziale: viene eseguita prima di attivare l'interfaccia grafica
	e controlla che esistano gli archivi; legge il numero dei record registrati sia per i
	piatti, sia per gli ingredienti e li memorizza nella struttura myfiles; memorizza
	sempre su myfiles anche l'id dell'eventuale prossimo piatto aggiunto; alloca dinamicamente
	la memoria necessaria a contenere un numero di record pari a #MEM sia per i piatti,
	sia per gli ingredienti e carica su vettori di strutture entrambi gli archivi.
	Restituisce un codice di ritorno diverso a seconda dell'errore verificatosi.
	La restituzione di un valore diverso da 1 provoca l'uscita dal programma. */

int inizializza (Piatto **p_piatti,Ingrediente **p_ingredienti, Archivio *myfiles)
{
    int errore;
    if (!esiste_file("arch_menu.dat"))
    {
       if (!crea_file("arch_menu.dat"))
            return -1;
    }
    if (!esiste_file("arch_ingred.dat"))
    {
        if(!crea_file("arch_ingred.dat"))
            return -2;
    }

    if (!esiste_file("totale_scontrini.txt"))
    {
       if (!crea_file("totale_scontrini.txt"))
            return -3;
    }

    myfiles->num_rec = numero_rec(ARCHIVIO_PIATTI);
    if (myfiles->num_rec<0)
    {
        return -4;
    }
    myfiles->ing_num_rec = numero_rec(ARCHIVIO_INGREDIENTI);
    if (myfiles->ing_num_rec<0)
    {
        return -5;
    }
    myfiles->uid = last_record();

    *p_piatti=(Piatto*)malloc(sizeof(Piatto)*MEM);
    if (*p_piatti==NULL)
    {
        return -99;
    }
    myfiles->rec_mem=MEM;

    *p_ingredienti = (Ingrediente*)malloc(sizeof(Ingrediente)*MEM);
    if (*p_ingredienti==NULL)
    {
        return -99;
    }
    myfiles->ing_rec_mem=MEM;

    errore=carica_archivi(p_piatti,p_ingredienti,myfiles);
    if (errore!=1)
    {
        return errore;
    }

    return 1;
}

int esiste_file (char *nomefile)
{
    FILE *fp=NULL;
    fp = fopen(nomefile,"r");                           // apertura file
    if (fp!=NULL)                                       // verifica apertura file
    {
        fclose(fp);                                     // se il file esiste lo chiude e restituisce 1
        return 1;
    }
    return 0;                                           // altrimenti restituisce 0
}

int crea_file (char *archivio)
{
    FILE *fp=NULL;
    fp=fopen(archivio,"w");                             // creazione file vuoto
    if (fp==NULL)                                       // verifica creazione file
    {
        return 0;                                       // se non e' stato possibile creare il file restituisce 0, altrimenti 1
    }

    if (!strcmp(archivio,"totale_scontrini.txt"))       // se il parametro passato alla funzione corrisponde scrive nel file anche quanto specificato nelle due righe seguenti
    {
        fprintf(fp,"%.2f",0.00);
        fprintf(fp,"%s"," € (somma dei totali degli scontrini emessi)");

    }
    fclose(fp);                                         // chiude il file
    return 1;                                           // restituisce 1
}

/* Questa funzione restituisce il numero dei record contenuti nell'archivio piatti o ingredienti a seconda che gli venga passato 1 o 2 come parametro */
int numero_rec(int num_arch)
{
    int size_file=0, num_rec=0;
    FILE *fp=NULL;
    if (num_arch==ARCHIVIO_PIATTI)
    {
        fp=fopen("arch_menu.dat","rb");
    }
    else
    {
        fp=fopen("arch_ingred.dat","rb");
    }

    if (fp==NULL)                                       // solito controllo sulla apertura del file: se fallita restituisce -1
    {
        return -1;
    }
    fseek(fp,0,SEEK_END);                               // posiziona il puntatore alla fine del file
    size_file=ftell(fp);                                // assegna il valore della distanza dall'inizio del file alla variabile

    if (num_arch==1)
    {
        num_rec=size_file/sizeof(Piatto);               // calcola il numero record dividendo la lunghezza del file per la dimensione del record nel caso 1
    }
    else
    {
        num_rec=size_file/sizeof(Ingrediente);          // e nel caso 2
    }

    fclose(fp);                                         // chiude il file
    return num_rec;										// restituisce il numero dei record

}


int last_record()
{
    /* funzione che restituisce l'id dell'ultimo piatto in archivio, aumentato di uno */
    int last_rec=0;
    FILE *fp=NULL;
    Piatto last_p;

    fp=fopen("arch_menu.dat","rb");                     // apre il file in modalita lettura

    if (fp==NULL)                                       // anche in questo caso la funzione restituisce 0 se non e' riuscita l'apertura del file
    {
        return 0;
    }
    fseek(fp,0,SEEK_END);                               // posiziona il puntatore alla fine del file

    if (ftell(fp)==0)                                   // se il file e' vuoto, restituisce 0
    {
        return 0;
    }

    fseek(fp,-sizeof(Piatto),SEEK_END);					// Posiziona il puntatore all'inizio dell'ultimo record
    fread(&last_p,sizeof(Piatto),1,fp);					// e lo legge
    last_rec=(last_p.id)+1;								// Aggiunge 1 al valore dell'id dell'ultimo record

    fclose(fp);
    return last_rec;
}


/*  Funzione di caricamento in memoria degli archivi piatti e ingredienti; viene chiamata
    dalla funzione di inizializzazione.  Si occupa di verificare, in base al numero di record in
	archivio, se occorre riallocare una quantita' di memoria superiore: in tal caso alloca una quantita'
	sufficiente a contenere il doppio dei record presenti in archivio; viene poi caricato il valore del totale
	degli scotrini stampati dal file di testo che lo contiene */

int carica_archivi (Piatto **p_piatti,Ingrediente **p_ingredienti, Archivio *myfiles)
{
    FILE *fp=NULL;

    /* Apre il file che contiene i piatti del menu */
    fp=fopen("arch_menu.dat","rb");
    if (fp==NULL)
    {
        return -6;
    }

    /* Se il numero di record piatti e' uguale o superiore al numero MEM viene allocato
      uno spazio in memoria pari al doppio di quello necessario per tutti i record del file
      in modo che se si inseriscono altri piatti si minimizzi il numero dei ricorsi alla riallocazione  */
    if (myfiles->num_rec>=MEM)
    {
        *p_piatti=(Piatto*) realloc(*p_piatti,sizeof(Piatto)*2*myfiles->num_rec);
        if (*p_piatti==NULL)
        {
            return -7;
        }
        /* Dopo il controllo sulla effettiva riallocazione della memoria assegno a rec_mem il nuovo valore
            massimo dei record che possono essere tenuti in memoria */
        myfiles->rec_mem = 2*myfiles->num_rec;
    }
    /* legge dall'archivio piatti tutti i record contenuti, come da valore calcolato e memorizzato in num_rec */
    fread(*p_piatti,sizeof(Piatto),myfiles->num_rec,fp);

    fclose(fp);

    /* Apre il file che contiene gli ingredienti */
    fp=fopen("arch_ingred.dat","rb");
    if (fp==NULL)
    {
        return -9;
    }
    /* Se il numero di record ingredienti e' uguale o superiore al numero MEM viene allocato
      uno spazio in memoria pari al doppio di quello necessario per tutti i record del file
      in modo che se si inseriscono altri ingredienti si minimizzi il numero dei ricorsi alla riallocazione  */
    if (myfiles->ing_num_rec>=MEM)
    {
        *p_ingredienti=(Ingrediente*) realloc(*p_ingredienti,sizeof(Ingrediente)*2*myfiles->ing_num_rec);
        if (*p_ingredienti==NULL)
        {
            return -11;
        }
        /* Dopo il controllo sulla effettiva riallocazione della memoria assegno a ing_rec_mem il nuovo valore
            massimo dei record che possono essere tenuti in memoria senza una nuova riallocazione*/
        myfiles->ing_rec_mem = 2*myfiles->ing_num_rec;
    }
    /* legge dall'archivio ingredienti tutti i record contenuti, come da valore calcolato e memorizzato in ing_num_rec */
    fread(*p_ingredienti,sizeof(Ingrediente),myfiles->ing_num_rec,fp);
    fclose(fp);

    /* apre il file contenente il totale degli scontrini emessi e ne legge il valore con una fscanf */
    fp=fopen("totale_scontrini.txt","r");
    if (fp==NULL)
    {
        return -12;
    }
    fscanf (fp,"%f",&myfiles->totale_scontrini);
    fclose(fp);

    return 1; // restituisce 1 = tutto ok
}


int append_piatto(Piatto *np)
{
    FILE *fp=NULL;

    fp=fopen("arch_menu.dat","ab");                     // apre il file in modalita append
    if (fp==NULL)                                       // anche in questo caso la funzione restituisce 5 se non e' riuscita l'apertura del file
    {
        return 0;
    }
    fwrite(np,sizeof(Piatto),1,fp);                     // aggiunge il nuovo piatto all'archivio e restituisce 1 che vuol dire tutto ok
    fclose(fp);

    return 1;

}


void normalizza (char *nome)
{
    int n,i;
    n=strlen(nome);                                     // verifica lunghezza nome

    if (n==0)
    {
        return;                                         // se la lunghezza e' 0 esce dalla funzione
    }

    if (nome[0]>96 && nome[0]<123)                      // Verifica prima lettera del nome: se e' minuscolo sottrae 32 e trasforma in maiuscolo
    {
        nome[0]=nome[0]-32;
    }

    for(i=1;i<n;i++)                                    // verifica altre lettere: se maiuscolo trasforma in minuscolo aggiungendo 32
    {
        if (nome[i]>64 && nome[i]<91)
        {
            nome[i]+=32;
        }

    }
}


int controllo_nuovo_piatto (Piatto np, Piatto *piatti, Archivio *mf)
{
    int n[NCAMPI],i;

    n[0] = strlen(np.nome);
    n[1] = strlen(np.ingredienti[0]);
    n[2] = strlen(np.ingredienti[1]);
    n[3] = strlen(np.ingredienti[2]);
    n[4] = np.prezzo;
    n[5] = np.tipo;

    for (i=0;i<NCAMPI-2;i++)							// verifica la lunghezza dei campi nome e ingredienti del piatto
    {
        if (n[i]==0)
        {
            return i+2;									// restituisce valori da 2 e 5 che consentono di identificare quale campo e' stato lasciato vuoto
        }
    }
	if (np.prezzo==0)
	{
		return 6;										// restituisce 6 se il prezzo è stato lasciato a zero
	}
    if (n[5]==-1)
    {
        return 7;										// se la combo e' vuota restituisce il valore 7
    }

    for (i=0; i<mf->num_rec ;i++)                       // verifica la presenza di doppioni e si ferma restituendo 0 appena ne trova uno
    {
        if(strcmp(np.nome,(piatti+i)->nome)==0)
        {
            return 0;
        }
    }
    return 1;                                           // restituisce 1 che significa che il piatto si puo' aggiungere all'archivio
}


int scrivi_modifica_piatto(Piatto *piatto, int n)
{
    FILE *fp=NULL;

    fp=fopen("arch_menu.dat","r+b");                // apre il file in modalita' lettura + scrittura
    if (fp==NULL)                                   // verifica corretta apertura
    {
        return 0;
    }

    fseek(fp,n*sizeof(Piatto),SEEK_SET);            // posiziona il puntatore nel file al punto in cui si trova il record n-esimo

    fwrite(piatto,sizeof(Piatto),1,fp);             // sovrascrive il record n-esimo
    fclose(fp);                                     // chiude il file

    return 1;                                       // restituisce 1: operazione effettuata correttamente
}


int inizializza_cassa (Scontrino **p_scontrini)
{
    int i;
    *p_scontrini=(Scontrino *)malloc(sizeof(Scontrino)*TAVOLI);                 // assegno al puntatore a puntatore l'indirizzo restituito dalla malloc

    if (*p_scontrini==NULL)                                                     // verifico che la memoria sia stata allocata correttamente
    {
        return -100;                                                            // restituisce -100 in caso di errore
    }

    for (i=0; i<TAVOLI; i++)                                                    // assegno agli elementi della struttura i corretti valori
    {
        ((*p_scontrini)+i)->id = i;                                             // id tavoli da 0 al valore #TAVOLI
        ((*p_scontrini)+i)->ordini=(Ordine *) malloc(MEM*sizeof(Ordine));       // alloca la memoria per MEM ordini ed assegna l'indirizzo al puntatore contenuto nella struttura
        if (((*p_scontrini)+i)->ordini==NULL)                                   // verifica effettiva allocazione della memoria
        {
            return -101;
        }
        ((*p_scontrini)+i)->mem_ord = MEM;                                      // assegna il numero di ordini max memorizzabili senza riallocazione a mem_ord
        ((*p_scontrini)+i)->num_ord = 0;                                        // imposta a zero il numero di ordini associato al tavolo
        ((*p_scontrini)+i)->prezzo_totale = 0;                                  // totale degli ordini relativi al tavolo

    }
    return 1;
}





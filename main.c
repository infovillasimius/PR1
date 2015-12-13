#include <gtk/gtk.h>
#include "gui.h"


int main (int argc, char *argv[])
{
    int condizione;
    Parametri gui_par;                      // Struttura parametri gui
    Archivio myfiles;                       // Situazione archivi
    Piatto *piatti=NULL;                    // Puntatore vettore strutture piatti
    Ingrediente *ingredienti=NULL;          // Puntatore vettore strutture ingredienti
    Scontrino *scontrini=NULL;              // Puntatore vettore strutture scontrini


    /* Personalizzazione -> modificare nella riga seguente il nome del ristorante */
    sprintf(myfiles.nome_ristorante,"Ristorante Tutti al fresco...");

    /* Chiamata alla funzione di inizializzazione archivi piatti e ingredienti */
    condizione = inizializza(&piatti,&ingredienti,&myfiles);

    /* Esce dal programma in caso di errore relativo a problemi file o allocazione memoria piatti e ingredienti */
    if (condizione!=1)
    {
        return condizione;
    }

    /* Chiamata alla funzione di inizializzazione archivi scontrini e ordini */
    condizione = inizializza_cassa (&scontrini);

    /* Esce dal programma in caso di errore relativo ad allocazioni di memoria per cassa */
    if (condizione!=1)
    {
        return condizione;
    }

    /*  Assegna i puntatori ai vettori delle strutture piatti, ingredienti e scontrini ai campi
        appositamente predisposti nella struttura gui_par;  assegna il puntatore a myfiles */
    gui_par.piatti = piatti;
    gui_par.ingredienti = ingredienti;
    gui_par.myfiles = &myfiles;
    gui_par.scontrini = scontrini;

    /*  Initializza GTK+ */
    gtk_init (&argc, &argv);

    /* richiama la funzione per la gestione dell'interfaccia grafica principale */
    gui(&gui_par);

    /* Ciclo gtk principale */
    gtk_main ();
    return 0;
}

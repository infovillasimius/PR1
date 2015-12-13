#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <gtk/gtk.h>
#include "core.h"

typedef struct
{
    GtkWidget *main_win;                            /* Finestra principale*/
    GtkWidget *main_box;                            /* Vbox principale contenuto nella  finestra principale */
    GtkWidget *first_box;                           /* Vbox - contiene schermata principale di avvio */
    GtkWidget *second_box;                          /* Vbox - contiene schermate aggiunta e modifica piatto */
    GtkWidget *button_box1;                         /* Hbox che contiene i pulsanti per l'aggiunta record nella seconda finestra */
    GtkWidget *button_box2;                         /* Hbox che contiene i pulsanti per modifica record nella seconda finestra */
    GtkWidget *main_image;                          /* Immagine sfondo principale */
    GtkWidget *home_hbox;                           /* Hbox che contiene le vbox dei pulsanti e la vbox che contiene immagine di sfondo nella finestra di avvio */
    GtkWidget *content_box;                         /* Vbox che contiene immagine di sfondo nella finestra di avvio*/
    GtkWidget *home_button_vbox1;                   /* Vbox pulsanti a sinistra nella pagina principale */
    GtkWidget *home_button_vbox2;                   /* Vbox pulsanti a destra nella pagina principale */
    GtkWidget *home_esci_button;                    /* Pulsante Esci nella pagina principale */
    GtkWidget *home_aggiungi_button;                /* Pulsante Aggiungi piatto nella pagina principale */
    GtkWidget *home_modifica_button;                /* Pulsante Modifica piatto nella pagina principale */
    GtkWidget *home_elimina_button;                 /* Pulsante Elimina piatto nella pagina principale */
    GtkWidget *home_stampa_button;                  /* Pulsante Stampa menu nella pagina principale */
    GtkWidget *home_ricerca_button;                 /* Pulsante Ricerca e stamapa nella pagina principale */
    GtkWidget *home_cassa_button;                   /* Pulsante Gestione CASSA nella pagina principale */
    GtkWidget *home_help_button;                    /* Pulsante Help nella pagina principale */

    GtkWidget *menu;                                /* Barra menu' finestra principale */
    GtkWidget *menu_file;                           /* Menu' file */
    GtkWidget *menu_sub_file;                       /* Sotto menu' file */
    GtkWidget *menu_sub_file_item1;                 /* Prima voce del menu' file: Reinizializza Archivio Piatti */
    GtkWidget *menu_sub_file_item2;                 /* Seconda voce del menu' file: Reinizializza Archivio Ingredienti */
    GtkWidget *menu_sub_file_item3;                 /* Separatore */
    GtkWidget *menu_sub_file_item4;                 /* Terza voce del menu' file: Uscita */
    GtkWidget *menu_gestione;                       /* Menu' gestione */
    GtkWidget *menu_sub_gestione;                   /* Sotto menu' gestione */
    GtkWidget *menu_sub_gestione_item1;             /* Prima voce del menu' gestione: Aggiungi Piatti */
    GtkWidget *menu_sub_gestione_item2;             /* Seconda voce del menu' gestione: Modifica Piatti */
    GtkWidget *menu_sub_gestione_item3;             /* Terza voce del menu' gestione: Elimina Piatti */
    GtkWidget *menu_sub_gestione_item4;             /* Separatore */
    GtkWidget *menu_sub_gestione_item5;             /* Quarta voce del menu' gestione: Stampa menu' */
    GtkWidget *menu_sub_gestione_item6;             /* Quinta voce del menu' gestione: Ricerca e stampa */

    GtkWidget *menu_cassa;                          /* Menu' cassa */
    GtkWidget *menu_sub_cassa;                      /* Sotto menu' cassa */
    GtkWidget *menu_sub_cassa_item1;                /* Prima voce del menu' cassa: Gestione cassa */
    GtkWidget *menu_sub_cassa_item2;                /* Seconda voce del menu' cassa: visualizza file utilizzo ingredienti */
    GtkWidget *menu_sub_cassa_item3;                /* Terza voce del menu' cassa: visualizza file totale ricavi */

    GtkWidget *table;                               /* Tabella posta nella second_box - contiene le widget per la visualizzazione dei piatti */
    GtkWidget *nome_label;                          /* Label descrittiva per la entry_box che visualizza il nome del piatto */
    GtkWidget *tipologia_label;                     /* Label descrittiva per la combo_box che visualizza il tipo del piatto */
    GtkWidget *ingrediente1_label;                  /* Label descrittiva per la entry_box che visualizza il primo ingrediente */
    GtkWidget *ingrediente2_label;                  /* Label descrittiva per la entry_box che visualizza il secondo ingrediente */
    GtkWidget *ingrediente3_label;                  /* Label descrittiva per la entry_box che visualizza il terzo ingrediente */
    GtkWidget *prezzo_label;                        /* Label descrittiva per la entry_box che visualizza il prezzo */

    GtkWidget *label_titolo;                        /* Puntatore alla label del Titolo della schermata */
    GtkWidget *label_id;                            /* Puntatore alla label dell'ID del piatto */
    GtkWidget *nome_entry;                          /* Puntatore alla entry del nome */
    GtkWidget *tipol_combo;                         /* Puntatore alla combo di selezione del tipo di piatto */
    GtkWidget *ingrediente_entry[3];                /* Puntatori alle entri degli ingredienti */
    GtkWidget *prezzo_entry;                        /* Puntatore alla entry del prezzo */

    GtkWidget *registra_button;                     /* Pulsante Registra nuovo piatto */
    GtkWidget *annulla_button;                      /* Pulsante Annulla ed Esci da aggiunta piatti */
    GtkWidget *reg_mod_button;                      /* Pulsante Registra modifiche piatto */
    GtkWidget *esci_button;                         /* Pulsante Annulla ed Esci da modifica piatti */
    GtkWidget *avanti_button;                       /* Pulsante per visualizzare il piatto successivo in modifica piatti */
    GtkWidget *indietro_button;                     /* Pulsante per visualizzare il piatto precedente in modifica piatti */
    GtkWidget *elimina_button;                      /* Pulsante per eliminare il record visualizzato in modifica piatti */
    GtkWidget *ricerca_button;                      /* Pulsante per aprire la finestra di ricerca */

    GtkWidget *ricerca_win;                         /* Finestra principale di ricerca */
    GtkWidget *ricerca_main_box;                    /* Vbox principale contenuto in finestra di ricerca */
    GtkWidget *ricerca_hbox1;                       /* Hbox 1 contenuto in ricerca_main_box - contiene vbox per entry_box e label relative alla ricerca */
    GtkWidget *ricerca_text_view;                   /* text_view contenuto in ricerca_main_box - contiene la lista dei piatti che corrispondono ai criteri di ricerca */
    GtkWidget *ricerca_hbox2;                       /* Hbox 2 contenuto in ricerca_main_box - contiene pulsanti relativi alla ricerca */
    GtkWidget *ricerca_vbox_id;                     /* Contiene entry e label per id */
    GtkWidget *ricerca_vbox_nome;                   /* Contiene entry e label per nome */
    GtkWidget *ricerca_vbox_tipo;                   /* Contiene entry e label per tipo */
    GtkWidget *ricerca_vbox_ingredienti;            /* Contiene entry e label per ingredienti */

    GtkWidget *ricerca_entry_id;                    /* Entry per ricerche su ID piatto */
    GtkWidget *ricerca_entry_nome;                  /* Entry per ricerche su nome piatto */
    GtkWidget *ricerca_combo_tipo;                  /* Combo per ricerche su tipo piatto */
    GtkWidget *ricerca_entry_ingredienti;           /* Entry per ricerche su ingredienti */
    GtkWidget *ricerca_label_id;                    /* label per visualizzazione descrizione campo id */
    GtkWidget *ricerca_label_nome;                  /* label per visualizzazione descrizione campo nome */
    GtkWidget *ricerca_label_tipo;                  /* label per visualizzazione descrizione campo tipo */
    GtkWidget *ricerca_label_ingredienti;           /* label per visualizzazione descrizione campo ingredienti */
    GtkWidget *ricerca_separator1;                  /* primo separatore nella pagina di ricerca */
    GtkWidget *ricerca_separator2;                  /* secondo separatore nella pagina di ricerca */
    GtkWidget *stampa_hbox;                         /* contiene pulsanti nella finestra stampa menu' */
    GtkWidget *stampa_button;                       /* pulsante stampa nella pagina stampa menu' */
    GtkWidget *esci_stampa_button;                  /* pulsante Esci nella finestra stampa menu' */

    GtkListStore *ricerca_list_store;               /* List store finestra di ricerca */
    GtkWidget *ricerca_tree_view;                   /* Tree view finestra di ricerca */
    GtkTreeViewColumn *ricerca_column[7];           /* colonne tree view finestra di ricerca */
    GtkTreeSelection *select;                       /* puntatore per rilevamento avvenuta selezione di una riga nel tree view */

    GtkWidget *ricerca_cerca_button;                /* pulsante per avviare la ricerca */
    GtkWidget *ricerca_esci_button;                 /* pulsante per uscire da ricerca */
    GtkWidget *ricerca_seleziona_button;            /* pulsante per selezionare il record con id = contenuto del ricerca_seleziona_entry */
    GtkWidget *ricerca_pulisci_button;              /* pulsante per ripulire la finestra di ricerca */
    GtkWidget *ricerca_seleziona_entry;             /* entry dove inserire il valore dell'ID del record da selezionare */
    GtkWidget *ricerca_scrolled_win;                /* finestra di tipo scrolled */

    GtkWidget *cassa_main_win;                      /* finestra principale cassa (selezione tavoli) */
    GtkWidget *cassa_main_box;                      /* vbox principale finestra cassa */
    GtkWidget *cassa_hbox1;                         /* hbox parte superiore della finestra cassa */
    GtkWidget *cassa_hbox2;                         /* hbox parte inferiore della finestra cassa */
    GtkWidget *cassa_separator1;                    /* separatore 1 finestra cassa */
    GtkWidget *cassa_separator2;                    /* separatore 2 finestra cassa */
    GtkWidget *cassa_label1;                        /* label titolo finestra cassa */

    GtkTreeStore *cassa_tree_store;                 /* tree_store finestra cassa */
    GtkWidget *cassa_scrolled_win;                  /* scrolled_win finestra cassa */
    GtkWidget *cassa_tree_view;                     /* tree_view finestra cassa */
    GtkTreeViewColumn *cassa_column[7];             /* colonne tree_view finestra cassa */
    GtkTreeSelection *cassa_select;                 /* puntatore per selezione finestra cassa */
    GtkWidget *cassa_aggiungi_button;               /* pulsante per creare nuovo scontrino / aggiungere ordinazione in finestra cassa */
    GtkWidget *cassa_seleziona_entry;               /* entry che contiene id della riga selezionata in finestra cassa */
    GtkWidget *cassa_seleziona_button;              /* pulsante di selezione tavolo in finestra cassa */
    GtkWidget *cassa_esci_button;                   /* pulsante esci da finestra cassa */
    GtkWidget *cassa_quantita_entry;                /* entry che contiene il numero di porzioni ordinate */
    GtkWidget *cassa_quantita_piu_button;           /* pulsante che incrementa il numero di porzioni ordinate */
    GtkWidget *cassa_quantita_meno_button;          /* pulsante che decrementa il numero di porzioni ordinate */

    Piatto *piatti;                                 /* puntatore  al vettore di strutture contenente i piatti */
    Ingrediente *ingredienti;                       /* puntatore  al vettore di strutture contenente gli ingredienti */
    Archivio *myfiles;                              /* puntatore alla struttura che contiene i dati relativi alla situazione attuale degli archivi */
    int i;                                          /* numero record (piatti) attuale per le varie operazioni */
    int i_sel;                                      /* contiene una flag che modifica il comportamento della finestra di ricerca */
    int num_rec;                                    /* numero totale dei record */
    Scontrino *scontrini;                           /* puntatore a vettore scontrini */
    int cassa_i;                                    /* numero record attuale in scontrini */
    char nome_win[M];

}   Parametri;

gboolean delete_event();                                                //  Funzione che evita l'uscita dal programma in caso si prema il tasto chiudi

/* procedure e funzioni richiamate da altre parti (non collegate a g_signal) */
int dialog_scelta (GtkWidget *,char *, char*);                          //  Visualizza dialog_box che consente una scelta
void dialog_info (GtkWidget *, char *);                                 //  Visualizza dialog_box informativa
void gui(Parametri *);                                                  //  Realizza la finestra principale
void gui_ricerca (Parametri *);                                         //  Realizza la finestra di ricerca
void gui_cassa (Parametri *);                                           //  Realizza la finestra gestione cassa
void assegna(Parametri *);                                              //  Aggiorna la visualizzazione della finestra di modifica con i valori correnti
void pulisci (Parametri *);                                             //  Pulisce la finestra di aggiunta/modifica
int scrivi_vettore (Parametri *);                                       //  Scrive sul file il vettore piatti compattato a seguito dell'eliminazione di un piatto
void cassa_aggiorna (Parametri *);                                      //  Aggiorna la visualizzazione della lista tavoli in gestione cassa
void allinea_ingredienti (Parametri *);                                 //  Verifica che tutti gli ingredienti usati nei piatti siano
void controllo_creazione_file (GtkWidget *, char *, char *, char *);    //  Verifica che la creazione dei file archivio vada a buon fine
int controllo_ingredienti(char *, Parametri *);                         //  Verifica se ogni ingrediente del nuovo piatto e' contenuto in archivio e nel caso lo aggiunge


/* Procedure richiamate da eventi generati da pulsanti o da voci di menu */
void esci (GtkWidget * , Parametri * );                                 //  Esce dal programma
void crea_archivio_piatti(GtkWidget *, Parametri *);                    //  Crea archivio dei piatti
void crea_archivio_ingredienti(GtkWidget *, Parametri *);               //  Crea archivio ingredienti
void annulla (GtkWidget *,Parametri *);                                 //  Permette di uscire da aggiunta e da modifica piatti
void aggiungi_piatto (GtkWidget *, Parametri *);                        //  Gestisce l'aggiunta dei piatti
void registra_nuovo(GtkWidget *, Parametri *);                          //  Verifica corretta aggiunta piatto all'archivio
void modifica_piatto (GtkWidget *, Parametri *);                        //  Modifica piatto in archivio
void avanti_record (GtkWidget *, Parametri *);                          //  Nella finestra di modifica, visualizza il piatto successivo
void indietro_record (GtkWidget *, Parametri *);                        //  Nella finestra di modifica, visualizza il piatto precedente
void registra_modifica (GtkWidget *, Parametri *);                      //  Registra sul file le modifiche al piatto visualizzato in finestra modifica
void elimina_record (GtkWidget *, Parametri *);                         //  Elimina un piatto dal menu'
void ricerca_record (GtkWidget *, Parametri *);                         //  Avvia la finestra di ricerca dalla finestra di modifica piatto
void chiudi_gui_ricerca(GtkWidget *, Parametri *);                      //  Chiude la finestra di ricerca operando operazioni diverse a seconda della funzione chiamante
void esci_da_ricerca (GtkWidget*,Parametri*);                           //  Esce dalla finestra di ricerca
void avvia_ricerca(GtkWidget *, Parametri *);                           //  Aggiorna la finestra di ricerca
void pulisci_ricerca (GtkWidget *,Parametri *);                         //  Azzera tutti i parametri di ricerca nella finestra ricerca
void elimina_piatto (GtkWidget *,Parametri *);                          //  Avvia la finestra ricerca in modalita' elimina piatto
void stampa_menu (GtkWidget *,Parametri *);                             //  Avvia la finestra di ricerca in modalita' stampa menu'
void stampa_menu_su_file (GtkWidget *, Parametri *);                    //  Stampa il menu' completo su un file di testo
void ricerca_stampa (GtkWidget *, Parametri *);                         //  Avvia la finestra di ricerca in modalita' ricerca visualizza
void aggiungi_ordine (GtkWidget * , Parametri * );                      //  Avvia la finestra di ricerca in modalita' Aggiungi un ordine
void cassa_esci (GtkWidget * , Parametri * );                           //  Chiude la finestra gestione cassa
void cassa (GtkWidget * , Parametri * );                                //  Avvia la finestra gestione cassa
void stampa_scontrino (GtkWidget * , Parametri * );                     //  Stampa lo scontrino
void stampa_ingredienti (GtkWidget *, Parametri *);                     //  Crea un file di testo con l'elenco degli ingredienti ed il numero dei loro utilizzi
void stampa_ricerca_su_file (GtkWidget *, Parametri *);                 //  Crea un file di testo con i risultati della ricerca
void cassa_quantita_piu (GtkWidget*,Parametri*);                        //  Incrementa il numero di porzioni ordinate memorizzandone il valore su cassa_quantita_entry
void cassa_quantita_meno (GtkWidget*,Parametri*);                       //  Decrementa il numero di porzioni ordinate memorizzandone il valore su cassa_quantita_entry
void visualizza_file_scontrini (GtkWidget*,Parametri*);                 //  Visualizza file totale scontrini
void help ();                                                           //  Visualizza file help


/*  Procedure richiamate da eventi di selezione su lista */
void tree_selection_changed (GtkTreeSelection *,Parametri *);           //  Rileva cambio di selezione e scrive il valore dell'id del piatto selezionato nell'entry di selezione nella finestra di ricerca
void cassa_tree_selection_changed (GtkTreeSelection *, Parametri * );   //  Rileva cambio di selezione in finestra gestione cassa e memorizza id tavolo

#endif // GUI_H_INCLUDED

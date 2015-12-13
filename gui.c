#include "gui.h"


void gui (Parametri *gui_par)
{
    /* Crea la main window e imposta bordo,titolo finestra, posizione,dimensioni ed evento "chiusura non voluta" */

    sprintf(gui_par->nome_win,"Gestione \"%s\"",gui_par->myfiles->nome_ristorante);
    gui_par->main_win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (gui_par->main_win), 0);

    gtk_window_set_title (GTK_WINDOW (gui_par->main_win), gui_par->nome_win);
    gtk_window_set_position (GTK_WINDOW (gui_par->main_win), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(gui_par->main_win),900,500);
    g_signal_connect (gui_par->main_win, "delete-event", G_CALLBACK (delete_event), NULL);

    /* Crea la vbox principale che conterrà tutto il resto e la aggiunge alla finestra principale */
    gui_par->main_box = gtk_vbox_new (FALSE, 10);
    gtk_container_add (GTK_CONTAINER (gui_par->main_win), gui_par->main_box);


    /* Crezione menu con relativi sotto menu e item */
    gui_par->menu = gtk_menu_bar_new();
    /* menu file item */
    gui_par->menu_file = gtk_menu_item_new_with_label("File");
    gtk_menu_bar_append(GTK_MENU_BAR(gui_par->menu) ,gui_par->menu_file);
    /* Sotto menu file */
    gui_par->menu_sub_file = gtk_menu_new();
    /* Voci del sotto menu file con le relative connessioni alle funzioni chiamate */
    gui_par->menu_sub_file_item1 = gtk_menu_item_new_with_label("Reinizializza Archivio Piatti");
    g_signal_connect (gui_par->menu_sub_file_item1, "activate", G_CALLBACK (crea_archivio_piatti), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_file), gui_par->menu_sub_file_item1);
    gui_par->menu_sub_file_item2 = gtk_menu_item_new_with_label("Reinizializza Archivio Ingredienti");
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_file) , gui_par->menu_sub_file_item2);
    g_signal_connect (gui_par->menu_sub_file_item2, "activate", G_CALLBACK (crea_archivio_ingredienti), (gpointer) gui_par);
    gui_par->menu_sub_file_item3 = gtk_separator_menu_item_new ();
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_file), gui_par->menu_sub_file_item3);
    gui_par->menu_sub_file_item4 = gtk_menu_item_new_with_label("Uscita!");
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_file), gui_par->menu_sub_file_item4);
    g_signal_connect (gui_par->menu_sub_file_item4, "activate", G_CALLBACK (esci), (gpointer) gui_par);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(gui_par->menu_file) , gui_par->menu_sub_file);
    /* menu gestione item */
    gui_par->menu_gestione = gtk_menu_item_new_with_label("Gestione Menu'");
    gtk_menu_bar_append(GTK_MENU_BAR(gui_par->menu) , gui_par->menu_gestione);
    gui_par->menu_sub_gestione = gtk_menu_new();
    gui_par->menu_sub_gestione_item1 = gtk_menu_item_new_with_label("Aggiungi Piatto");
    g_signal_connect (gui_par->menu_sub_gestione_item1, "activate", G_CALLBACK (aggiungi_piatto), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_gestione) , gui_par->menu_sub_gestione_item1);
    gui_par->menu_sub_gestione_item2 = gtk_menu_item_new_with_label("Modifica Piatto");
    g_signal_connect (gui_par->menu_sub_gestione_item2, "activate", G_CALLBACK (modifica_piatto), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_gestione) , gui_par->menu_sub_gestione_item2);
    gui_par->menu_sub_gestione_item3 = gtk_menu_item_new_with_label("Elimina Piatto");
    g_signal_connect (gui_par->menu_sub_gestione_item3, "activate", G_CALLBACK (elimina_piatto), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_gestione) , gui_par->menu_sub_gestione_item3);
    gui_par->menu_sub_gestione_item4 = gtk_separator_menu_item_new ();
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_gestione) , gui_par->menu_sub_gestione_item4);
    gui_par->menu_sub_gestione_item5 = gtk_menu_item_new_with_label("Stampa Menu'");
    g_signal_connect (gui_par->menu_sub_gestione_item5, "activate", G_CALLBACK (stampa_menu), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_gestione) , gui_par->menu_sub_gestione_item5);
    gui_par->menu_sub_gestione_item6 = gtk_menu_item_new_with_label("Ricerca e Stampa");
    g_signal_connect (gui_par->menu_sub_gestione_item6, "activate", G_CALLBACK (ricerca_stampa), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_gestione) , gui_par->menu_sub_gestione_item6);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(gui_par->menu_gestione) , gui_par->menu_sub_gestione);
    /* menu cassa item */
    gui_par->menu_cassa = gtk_menu_item_new_with_label("Cassa");
    gtk_menu_bar_append(GTK_MENU_BAR(gui_par->menu) , gui_par->menu_cassa);
    gui_par->menu_sub_cassa = gtk_menu_new();
    gui_par->menu_sub_cassa_item1 = gtk_menu_item_new_with_label("Gestione cassa");
    g_signal_connect (gui_par->menu_sub_cassa_item1, "activate", G_CALLBACK (cassa), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_cassa) , gui_par->menu_sub_cassa_item1);
    gui_par->menu_sub_cassa_item2 = gtk_menu_item_new_with_label("Visualizza file Ingredienti");
    g_signal_connect (gui_par->menu_sub_cassa_item2, "activate", G_CALLBACK (stampa_ingredienti), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_cassa) , gui_par->menu_sub_cassa_item2);
    gui_par->menu_sub_cassa_item3 = gtk_menu_item_new_with_label("Visualizza file totale ricavi");
    g_signal_connect (gui_par->menu_sub_cassa_item3, "activate", G_CALLBACK (visualizza_file_scontrini), (gpointer) gui_par);
    gtk_menu_append(GTK_MENU(gui_par->menu_sub_cassa) , gui_par->menu_sub_cassa_item3);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(gui_par->menu_cassa) , gui_par->menu_sub_cassa);

    /* preparazione finestra 1 (finestra di avvio)*/
    gui_par->first_box = gtk_vbox_new(FALSE,0);
    gtk_box_pack_start (GTK_BOX (gui_par->main_box), gui_par->first_box, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (gui_par->first_box), gui_par->menu, FALSE, FALSE, 0);
    gui_par->home_hbox = gtk_hbox_new(FALSE,0);
    gtk_box_pack_start (GTK_BOX (gui_par->first_box), gui_par->home_hbox, TRUE, TRUE, 0);
    gui_par->home_button_vbox1 = gtk_vbox_new(FALSE,0);
    gtk_box_pack_start (GTK_BOX (gui_par->home_hbox), gui_par->home_button_vbox1, TRUE, TRUE, 5);
    gui_par->content_box = gtk_vbox_new (FALSE, 5);
    gtk_box_pack_start (GTK_BOX (gui_par->home_hbox), gui_par->content_box, FALSE, FALSE, 0);
    gui_par->main_image=gtk_image_new_from_file("sf.jpg");
    gtk_box_pack_start (GTK_BOX (gui_par->content_box), gui_par->main_image, TRUE, TRUE, 0);
    gui_par->home_button_vbox2 = gtk_vbox_new(FALSE,0);
    gtk_box_pack_start (GTK_BOX (gui_par->home_hbox), gui_par->home_button_vbox2, TRUE, TRUE, 5);

    /* Prparazioni pulsanti home (finestra di avvio)*/
    gui_par->home_aggiungi_button=gtk_button_new_with_label ("\n  Aggiungi  \n    Piatto\n");
    gtk_box_pack_start(GTK_BOX (gui_par->home_button_vbox1), gui_par->home_aggiungi_button, TRUE, TRUE, 0);
    g_signal_connect (gui_par->home_aggiungi_button, "clicked", G_CALLBACK (aggiungi_piatto), (gpointer) gui_par);

    gui_par->home_modifica_button=gtk_button_new_with_label ("\n  Modifica  \n    Piatto\n");
    gtk_box_pack_start(GTK_BOX (gui_par->home_button_vbox1), gui_par->home_modifica_button, TRUE, TRUE, 0);
    g_signal_connect (gui_par->home_modifica_button, "clicked", G_CALLBACK (modifica_piatto), (gpointer) gui_par);

    gui_par->home_elimina_button=gtk_button_new_with_label ("\n  Elimina  \n   Piatto\n");
    gtk_box_pack_start(GTK_BOX (gui_par->home_button_vbox1), gui_par->home_elimina_button, TRUE, TRUE, 0);
    g_signal_connect (gui_par->home_elimina_button, "clicked", G_CALLBACK (elimina_piatto), (gpointer) gui_par);

    gui_par->home_stampa_button=gtk_button_new_with_label ("\n  Stampa  \n    Menu'\n");
    gtk_box_pack_start(GTK_BOX (gui_par->home_button_vbox1), gui_par->home_stampa_button, TRUE, TRUE, 0);
    g_signal_connect (gui_par->home_stampa_button, "clicked", G_CALLBACK (stampa_menu), (gpointer) gui_par);

    gui_par->home_ricerca_button=gtk_button_new_with_label ("\n  Ricerca  \n& Stampa\n");
    gtk_box_pack_start(GTK_BOX (gui_par->home_button_vbox2), gui_par->home_ricerca_button, TRUE, TRUE, 0);
    g_signal_connect (gui_par->home_ricerca_button, "clicked", G_CALLBACK (ricerca_stampa), (gpointer) gui_par);

    gui_par->home_cassa_button=gtk_button_new_with_label ("\nGestione\n CASSA\n");
    gtk_box_pack_start(GTK_BOX (gui_par->home_button_vbox2), gui_par->home_cassa_button, TRUE, TRUE, 0);
    g_signal_connect (gui_par->home_cassa_button, "clicked", G_CALLBACK (cassa), (gpointer) gui_par);

    gui_par->home_help_button=gtk_button_new_with_label ("\n  Help  \n");
    gtk_box_pack_start(GTK_BOX (gui_par->home_button_vbox2), gui_par->home_help_button, TRUE, TRUE, 0);
    g_signal_connect (gui_par->home_help_button, "clicked", G_CALLBACK (help), (gpointer) NULL);

    gui_par->home_stampa_button=gtk_button_new_with_label ("\nESCI\n");
    gtk_box_pack_start(GTK_BOX (gui_par->home_button_vbox2), gui_par->home_stampa_button, TRUE, TRUE, 0);
    g_signal_connect (gui_par->home_stampa_button, "clicked", G_CALLBACK (esci), (gpointer) gui_par);

    gtk_widget_show_all (gui_par->main_win);

    /* preparazione finestra 2 (Finestre di aggiunta e di modifica)*/
    gui_par->second_box=gtk_vbox_new(FALSE,10);
    gtk_box_pack_start (GTK_BOX (gui_par->main_box), gui_par->second_box, FALSE, FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (gui_par->second_box),20);
    gui_par->label_titolo=gtk_label_new ("");
    gtk_box_pack_start (GTK_BOX (gui_par->second_box), gui_par->label_titolo, FALSE, FALSE, 0);
    gui_par->label_id=gtk_label_new ("__________");
    gtk_box_pack_start (GTK_BOX (gui_par->second_box), gui_par->label_id, FALSE, FALSE, 0);
    gui_par->table=gtk_table_new(11,2,TRUE);
    gtk_box_pack_start (GTK_BOX (gui_par->second_box), gui_par->table, FALSE, FALSE, 0);

    gui_par->nome_label=gtk_label_new ("");
    gtk_label_set_markup (GTK_LABEL (gui_par->nome_label),"<b>Nome Piatto ______________________________________________</b>");
    gtk_misc_set_alignment (GTK_MISC(gui_par->nome_label),0,0.5);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->nome_label,0,1,1,2);

    gui_par->nome_entry=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->nome_entry),N-1);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->nome_entry,1,2,1,2);

    gui_par->tipologia_label=gtk_label_new ("");
    gtk_label_set_markup (GTK_LABEL (gui_par->tipologia_label),"<b>Tipologia Piatto __________________________________________</b>");
    gtk_misc_set_alignment (GTK_MISC(gui_par->tipologia_label),0,0.5);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->tipologia_label,0,1,3,4);

    gui_par->tipol_combo=gtk_combo_box_new_text ();
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->tipol_combo),"0 - Antipasto");
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->tipol_combo),"1 - Primo");
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->tipol_combo),"2 - Secondo");
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->tipol_combo),"3 - Contorno");
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->tipol_combo),"4 - Dessert");
    gtk_combo_box_set_active (GTK_COMBO_BOX(gui_par->tipol_combo),-1);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->tipol_combo,1,2,3,4);

    gui_par->ingrediente1_label=gtk_label_new ("");
    gtk_label_set_markup (GTK_LABEL (gui_par->ingrediente1_label),"<b>Primo ingrediente ________________________________________ </b>");
    gtk_misc_set_alignment (GTK_MISC(gui_par->ingrediente1_label),0,0.5);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->ingrediente1_label,0,1,5,6);

    gui_par->ingrediente_entry[0]=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->ingrediente_entry[0]),N-1);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->ingrediente_entry[0],1,2,5,6);

    gui_par->ingrediente2_label=gtk_label_new ("");
    gtk_label_set_markup (GTK_LABEL (gui_par->ingrediente2_label),"<b>Secondo ingrediente _____________________________________</b>");
    gtk_misc_set_alignment (GTK_MISC(gui_par->ingrediente2_label),0,0.5);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->ingrediente2_label,0,1,6,7);

    gui_par->ingrediente_entry[1]=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->ingrediente_entry[1]),N-1);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->ingrediente_entry[1],1,2,6,7);

    gui_par->ingrediente3_label=gtk_label_new ("");
    gtk_label_set_markup (GTK_LABEL (gui_par->ingrediente3_label),"<b>Terzo ingrediente ________________________________________ </b>");
    gtk_misc_set_alignment (GTK_MISC(gui_par->ingrediente3_label),0,0.5);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->ingrediente3_label,0,1,7,8);

    gui_par->ingrediente_entry[2]=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->ingrediente_entry[2]),N-1);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->ingrediente_entry[2],1,2,7,8);

    gui_par->prezzo_label=gtk_label_new ("");
    gtk_label_set_markup (GTK_LABEL (gui_par->prezzo_label),"<b>Prezzo </b> (euro) _____________________________________________");
    gtk_misc_set_alignment (GTK_MISC(gui_par->prezzo_label),0,0.5);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->prezzo_label,0,1,9,10);

    gui_par->prezzo_entry=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->prezzo_entry),20);
    gtk_table_attach_defaults (GTK_TABLE(gui_par->table),gui_par->prezzo_entry,1,2,9,10);

    /* preparazione pulsanti finestra 2 in modalita' aggiunta piatto */
    gui_par->button_box1=gtk_hbox_new(FALSE,0);
    gtk_box_pack_start(GTK_BOX (gui_par->second_box), gui_par->button_box1, FALSE, FALSE, 20);

    gui_par->registra_button=gtk_button_new_from_stock ("\n   Registra Piatto   \n");
    gtk_box_pack_start(GTK_BOX (gui_par->button_box1), gui_par->registra_button, FALSE, FALSE, 20);
    g_signal_connect (gui_par->registra_button, "clicked", G_CALLBACK (registra_nuovo), (gpointer) gui_par);

    gui_par->annulla_button=gtk_button_new_from_stock ("\n Annulla ed Esci \n");
    gtk_box_pack_end(GTK_BOX (gui_par->button_box1), gui_par->annulla_button, FALSE, FALSE, 20);
    g_signal_connect (gui_par->annulla_button, "clicked", G_CALLBACK (annulla), (gpointer) gui_par);

    /* preparazione pulsanti finestra2 in modalita' Modifica - Elimina piatto */
    gui_par->button_box2=gtk_hbox_new(FALSE,0);
    gtk_box_pack_start(GTK_BOX (gui_par->second_box), gui_par->button_box2, FALSE, FALSE, 20);

    gui_par->ricerca_button=gtk_button_new_with_label ("\n Ricerca \n");
    gtk_box_pack_start(GTK_BOX (gui_par->button_box2), gui_par->ricerca_button, TRUE, TRUE, 5);
    g_signal_connect (gui_par->ricerca_button, "clicked", G_CALLBACK (ricerca_record), (gpointer) gui_par);

    gui_par->esci_button=gtk_button_new_with_label ("\n Annulla ed ESCI \n");
    gtk_box_pack_end(GTK_BOX (gui_par->button_box2), gui_par->esci_button, TRUE, TRUE, 5);
    g_signal_connect (gui_par->esci_button, "clicked", G_CALLBACK (annulla), (gpointer) gui_par);

    gui_par->reg_mod_button=gtk_button_new_with_label ("\n  Registra Modifica \n");
    gtk_box_pack_end(GTK_BOX (gui_par->button_box2), gui_par->reg_mod_button, TRUE, TRUE, 5);
    g_signal_connect (gui_par->reg_mod_button, "clicked", G_CALLBACK (registra_modifica), (gpointer) gui_par);

    gui_par->indietro_button=gtk_button_new_with_label ("\n Piatto Precedente \n");
    gtk_box_pack_start(GTK_BOX (gui_par->button_box2), gui_par->indietro_button, TRUE, TRUE, 5);
    g_signal_connect (gui_par->indietro_button, "clicked", G_CALLBACK (indietro_record), (gpointer) gui_par);

    gui_par->avanti_button=gtk_button_new_with_label ("\n Piatto Successivo \n");
    gtk_box_pack_start(GTK_BOX (gui_par->button_box2), gui_par->avanti_button, TRUE, TRUE, 5);
    g_signal_connect (gui_par->avanti_button, "clicked", G_CALLBACK (avanti_record), (gpointer) gui_par);

    gui_par->elimina_button=gtk_button_new_with_label ("\n Elimina Piatto \n");
    gtk_box_pack_start(GTK_BOX (gui_par->button_box2), gui_par->elimina_button, TRUE, TRUE, 5);
    g_signal_connect (gui_par->elimina_button, "clicked", G_CALLBACK (elimina_record), (gpointer) gui_par);

    gui_par->num_rec=gui_par->myfiles->num_rec;
}


void gui_ricerca (Parametri *gui_par)
{
    /* Finestra principale */
    gui_par->ricerca_win=gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (gui_par->ricerca_win), 10);
    gtk_window_set_title (GTK_WINDOW (gui_par->ricerca_win), "Ricerca");
    gtk_window_set_position (GTK_WINDOW (gui_par->ricerca_win), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(gui_par->ricerca_win),800,700);
    g_signal_connect (gui_par->ricerca_win, "delete-event", G_CALLBACK (delete_event), NULL);

    /* box principale */
    gui_par->ricerca_main_box = gtk_vbox_new (FALSE, 10);
    gtk_container_set_border_width (GTK_CONTAINER (gui_par->ricerca_main_box),0);
    gtk_container_add (GTK_CONTAINER (gui_par->ricerca_win), gui_par->ricerca_main_box);

    /* box secondari */
    gui_par->ricerca_hbox1 = gtk_hbox_new (FALSE, 5);
    gui_par->ricerca_hbox2 = gtk_hbox_new (FALSE, 5);
    gui_par->ricerca_vbox_id = gtk_vbox_new (TRUE, 0);
    gui_par->ricerca_vbox_nome = gtk_vbox_new (TRUE, 0);
    gui_par->ricerca_vbox_tipo = gtk_vbox_new (TRUE, 0);
    gui_par->ricerca_vbox_ingredienti = gtk_vbox_new (TRUE, 0);

    gui_par->ricerca_separator1 = gtk_hseparator_new();
    gui_par->ricerca_separator2 = gtk_hseparator_new();

    /*  Preparazione della tree_view e del modello list_store */
    gui_par->ricerca_list_store = gtk_list_store_new (7,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    gui_par->ricerca_scrolled_win = gtk_scrolled_window_new (NULL,NULL);
    gui_par->ricerca_tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(gui_par->ricerca_list_store));
    gui_par->ricerca_column[0] = gtk_tree_view_column_new_with_attributes (" Id ", gtk_cell_renderer_text_new (), "text", 0, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->ricerca_tree_view), gui_par->ricerca_column[0]);
    gui_par->ricerca_column[1] = gtk_tree_view_column_new_with_attributes (" Nome  ", gtk_cell_renderer_text_new (), "text", 1, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->ricerca_tree_view), gui_par->ricerca_column[1]);
    gui_par->ricerca_column[2] = gtk_tree_view_column_new_with_attributes (" Tipo  ", gtk_cell_renderer_text_new (), "text", 2, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->ricerca_tree_view), gui_par->ricerca_column[2]);
    gui_par->ricerca_column[3] = gtk_tree_view_column_new_with_attributes ("Ingrediente 1", gtk_cell_renderer_text_new (), "text", 3, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->ricerca_tree_view), gui_par->ricerca_column[3]);
    gui_par->ricerca_column[4] = gtk_tree_view_column_new_with_attributes ("Ingrediente 2", gtk_cell_renderer_text_new (), "text", 4, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->ricerca_tree_view), gui_par->ricerca_column[4]);
    gui_par->ricerca_column[5] = gtk_tree_view_column_new_with_attributes ("Ingrediente 3", gtk_cell_renderer_text_new (), "text", 5, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->ricerca_tree_view), gui_par->ricerca_column[5]);
    gui_par->ricerca_column[6] = gtk_tree_view_column_new_with_attributes ("Prezzo (euro)", gtk_cell_renderer_text_new (), "text", 6, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->ricerca_tree_view), gui_par->ricerca_column[6]);

    /* Inserimento tree_view in una finestra scrolled e impacchettamento dei vari widget */
    gtk_container_add (GTK_CONTAINER (gui_par->ricerca_scrolled_win), gui_par->ricerca_tree_view);

    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_main_box), gui_par->ricerca_hbox1, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_main_box), gui_par->ricerca_separator1, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_main_box), gui_par->ricerca_scrolled_win, TRUE, TRUE, 0);

    gtk_box_pack_end (GTK_BOX (gui_par->ricerca_main_box), gui_par->ricerca_hbox2, FALSE, FALSE, 5);
    gtk_box_pack_end (GTK_BOX (gui_par->ricerca_main_box), gui_par->ricerca_separator2, FALSE, FALSE, 0);

    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox1), gui_par->ricerca_vbox_id, FALSE, TRUE, 5);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox1), gui_par->ricerca_vbox_nome, TRUE, TRUE, 5);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox1), gui_par->ricerca_vbox_tipo, TRUE, TRUE, 5);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox1), gui_par->ricerca_vbox_ingredienti, TRUE, TRUE, 5);

    /* Pulsante avvia ricerca */
    gui_par->ricerca_cerca_button = gtk_button_new_with_label (" Avvia Ricerca ");
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox1), gui_par->ricerca_cerca_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->ricerca_cerca_button, "clicked", G_CALLBACK (avvia_ricerca), (gpointer) gui_par);

    /* Realizzazione parte superiore finestra di ricerca composta da 4 vbox affiancati in una hbox
        al cui interno sono inserite rispettivamente una label e una entry (o la combo) relative a id,
        nome, tipo e ingrediente */
    gui_par->ricerca_label_id = gtk_label_new("ID");
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_vbox_id), gui_par->ricerca_label_id, TRUE, TRUE, 0);
    gui_par->ricerca_entry_id=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->ricerca_entry_id),10);
    gtk_entry_set_width_chars (GTK_ENTRY (gui_par->ricerca_entry_id),10);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_vbox_id), gui_par->ricerca_entry_id, TRUE, TRUE, 0);

    gui_par->ricerca_label_nome = gtk_label_new("NOME");
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_vbox_nome), gui_par->ricerca_label_nome, TRUE, TRUE, 0);
    gui_par->ricerca_entry_nome=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->ricerca_entry_nome),N-1);
    gtk_entry_set_width_chars (GTK_ENTRY (gui_par->ricerca_entry_nome),20);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_vbox_nome), gui_par->ricerca_entry_nome, TRUE, TRUE, 0);

    gui_par->ricerca_label_tipo = gtk_label_new("TIPO");
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_vbox_tipo), gui_par->ricerca_label_tipo, TRUE, TRUE, 0);
    gui_par->ricerca_combo_tipo=gtk_combo_box_new_text ();
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->ricerca_combo_tipo),"0 - Antipasto");
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->ricerca_combo_tipo),"1 - Primo");
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->ricerca_combo_tipo),"2 - Secondo");
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->ricerca_combo_tipo),"3 - Contorno");
    gtk_combo_box_append_text (GTK_COMBO_BOX(gui_par->ricerca_combo_tipo),"4 - Dessert");
    gtk_combo_box_set_active (GTK_COMBO_BOX(gui_par->ricerca_combo_tipo),-1);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_vbox_tipo), gui_par->ricerca_combo_tipo, TRUE, TRUE, 0);
    g_signal_connect (gui_par->ricerca_combo_tipo, "changed", G_CALLBACK (avvia_ricerca), (gpointer) gui_par);

    gui_par->ricerca_label_ingredienti = gtk_label_new("INGREDIENTI");
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_vbox_ingredienti), gui_par->ricerca_label_ingredienti, TRUE, TRUE, 0);
    gui_par->ricerca_entry_ingredienti=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->ricerca_entry_ingredienti),N-1);
    gtk_entry_set_width_chars (GTK_ENTRY (gui_par->ricerca_entry_ingredienti),20);
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_vbox_ingredienti), gui_par->ricerca_entry_ingredienti, TRUE, TRUE, 0);

    /* Pulsanti ed entry della parte bassa dello schermo */
    gui_par->ricerca_esci_button = gtk_button_new_with_label ("\n     ESCI     \n");
    gtk_box_pack_end (GTK_BOX (gui_par->ricerca_hbox2), gui_par->ricerca_esci_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->ricerca_esci_button, "clicked", G_CALLBACK (esci_da_ricerca), (gpointer) gui_par);
    gui_par->ricerca_seleziona_entry = gtk_entry_new ();
    gtk_entry_set_width_chars (GTK_ENTRY (gui_par->ricerca_seleziona_entry),5);
    gtk_box_pack_end (GTK_BOX (gui_par->ricerca_hbox2), gui_par->ricerca_seleziona_entry, FALSE, TRUE, 10);
    gui_par->ricerca_seleziona_button = gtk_button_new_with_label ("\n     Seleziona     \n");
    gtk_box_pack_end (GTK_BOX (gui_par->ricerca_hbox2), gui_par->ricerca_seleziona_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->ricerca_seleziona_button, "clicked", G_CALLBACK (chiudi_gui_ricerca), (gpointer) gui_par);


    gui_par->ricerca_pulisci_button  = gtk_button_new_with_label ("  Pulisci Finestra  ");
    gtk_box_pack_end (GTK_BOX (gui_par->ricerca_hbox2), gui_par->ricerca_pulisci_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->ricerca_pulisci_button, "clicked", G_CALLBACK (pulisci_ricerca), (gpointer) gui_par);

    gui_par->select = gtk_tree_view_get_selection (GTK_TREE_VIEW (gui_par->ricerca_tree_view));
    gtk_tree_selection_set_mode (gui_par->select, GTK_SELECTION_SINGLE);
    g_signal_connect (G_OBJECT (gui_par->select), "changed", G_CALLBACK (tree_selection_changed), gui_par);
}


void gui_cassa (Parametri *gui_par)
{
    /* Crea la finestra principale per la gestione cassa */
    gui_par->cassa_main_win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (gui_par->cassa_main_win), 5);
    gtk_window_set_title (GTK_WINDOW (gui_par->cassa_main_win), gui_par->nome_win);
    gtk_window_set_position (GTK_WINDOW (gui_par->cassa_main_win), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(gui_par->cassa_main_win),900,500);
    gtk_widget_realize (gui_par->cassa_main_win);
    g_signal_connect (gui_par->cassa_main_win, "delete-event", G_CALLBACK (delete_event), NULL);

    gui_par->cassa_main_box = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (gui_par->cassa_main_win), gui_par->cassa_main_box);
    gui_par->cassa_hbox1 = gtk_hbox_new (FALSE, 0);
    gui_par->cassa_hbox2 = gtk_hbox_new (FALSE, 0);
    gui_par->cassa_label1=gtk_label_new ("");
    gtk_label_set_markup (GTK_LABEL (gui_par->cassa_label1),"<b> Gestione Cassa </b>");
    gtk_box_pack_start (GTK_BOX (gui_par->cassa_hbox1), gui_par->cassa_label1, TRUE, TRUE, 10);
    gui_par->cassa_separator1 = gtk_hseparator_new();
    gui_par->cassa_separator2 = gtk_hseparator_new();

    /*  Crea tree store per la visualizzazione dei tavoli e degli ordini associati: la visualizzazione sarà suddivisa in righe principali
        che visualizzeranno solo l'id del tavolo ed il numero degli ordini attivi e righe secondarie che conterranno gli ordini.
        Per le colonne delle righe secondarie si è preferito il tipo stringa per evitare la visualizzazione di zeri che avrebbero potuto confondere
        Con la visualizzazione dei tavoli affidata ad un tree_store si può agevolmente variare il numero dei tavoli modificando il valore di #TAVOLI*/
    gui_par->cassa_tree_store = gtk_tree_store_new (7,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    gui_par->cassa_scrolled_win = gtk_scrolled_window_new (NULL,NULL);
    gui_par->cassa_tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(gui_par->cassa_tree_store));
    gui_par->cassa_column[0] = gtk_tree_view_column_new_with_attributes (" Tavolo ", gtk_cell_renderer_text_new (), "text", 0, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->cassa_tree_view), gui_par->cassa_column[0]);
    gui_par->cassa_column[1] = gtk_tree_view_column_new_with_attributes (" N. ordini / id ordine", gtk_cell_renderer_text_new (), "text", 1, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->cassa_tree_view), gui_par->cassa_column[1]);
    gui_par->cassa_column[2] = gtk_tree_view_column_new_with_attributes (" id Piatto  ", gtk_cell_renderer_text_new (), "text", 2, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->cassa_tree_view), gui_par->cassa_column[2]);
    gui_par->cassa_column[3] = gtk_tree_view_column_new_with_attributes (" Nome Piatto ", gtk_cell_renderer_text_new (), "text", 3, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->cassa_tree_view), gui_par->cassa_column[3]);
    gui_par->cassa_column[4] = gtk_tree_view_column_new_with_attributes (" N. Porzioni ", gtk_cell_renderer_text_new (), "text", 4, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->cassa_tree_view), gui_par->cassa_column[4]);
    gui_par->cassa_column[5] = gtk_tree_view_column_new_with_attributes (" Prezzo Piatto ", gtk_cell_renderer_text_new (), "text", 5, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->cassa_tree_view), gui_par->cassa_column[5]);
    gui_par->cassa_column[6] = gtk_tree_view_column_new_with_attributes (" Importo Tot. Piatto ", gtk_cell_renderer_text_new (), "text", 6, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (gui_par->cassa_tree_view), gui_par->cassa_column[6]);

    /*Aggiunge la tree_view ad una scrolled window */
    gtk_container_add (GTK_CONTAINER (gui_par->cassa_scrolled_win), gui_par->cassa_tree_view);

    /*inserimento delle widget nei relativi contenitori*/
    gtk_box_pack_start (GTK_BOX (gui_par->cassa_main_box), gui_par->cassa_hbox1, FALSE, FALSE, 5);
    gtk_box_pack_start (GTK_BOX (gui_par->cassa_main_box), gui_par->cassa_separator1, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (gui_par->cassa_main_box), gui_par->cassa_scrolled_win, TRUE, TRUE, 0);
    gtk_box_pack_end (GTK_BOX (gui_par->cassa_main_box), gui_par->cassa_hbox2, FALSE, FALSE, 5);
    gtk_box_pack_end (GTK_BOX (gui_par->cassa_main_box), gui_par->cassa_separator2, FALSE, FALSE, 0);

    /* Realizzazione della entry per la selezione del tavolo e dei pulsanti per la creazione e la stampa dello scontrino, nonchè per il pulsante di uscita*/
    gui_par->cassa_seleziona_entry = gtk_entry_new ();
    gtk_entry_set_width_chars (GTK_ENTRY (gui_par->cassa_seleziona_entry),5);
    gtk_box_pack_start (GTK_BOX (gui_par->cassa_hbox2), gui_par->cassa_seleziona_entry, FALSE, TRUE, 5);
    gui_par->cassa_aggiungi_button = gtk_button_new_with_label ("  Crea Scontrino \n Aggiungi Ordine ");
    gtk_box_pack_start (GTK_BOX (gui_par->cassa_hbox2), gui_par->cassa_aggiungi_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->cassa_aggiungi_button, "clicked", G_CALLBACK (aggiungi_ordine), (gpointer) gui_par);
    gui_par->cassa_seleziona_button = gtk_button_new_with_label ("  Stampa Scontrino  ");
    gtk_box_pack_start (GTK_BOX (gui_par->cassa_hbox2), gui_par->cassa_seleziona_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->cassa_seleziona_button, "clicked", G_CALLBACK (stampa_scontrino), (gpointer) gui_par);
    gui_par->cassa_esci_button  = gtk_button_new_with_label ("       Esci       ");
    gtk_box_pack_end (GTK_BOX (gui_par->cassa_hbox2), gui_par->cassa_esci_button, FALSE, TRUE, 5);
    g_signal_connect (gui_par->cassa_esci_button, "clicked", G_CALLBACK (cassa_esci), (gpointer) gui_par);


    /* Definizione dell'evento di cambio di riga selezionata */
    gui_par->cassa_select = gtk_tree_view_get_selection (GTK_TREE_VIEW (gui_par->cassa_tree_view));
    gtk_tree_selection_set_mode (gui_par->cassa_select, GTK_SELECTION_SINGLE);
    g_signal_connect (G_OBJECT (gui_par->cassa_select), "changed", G_CALLBACK (cassa_tree_selection_changed), gui_par);

}


gboolean delete_event ()
{
    /* creazione di una finestra non visibile a cui ancorare il dialog_box */
    GtkWidget * no_ciao=gtk_window_new (GTK_WINDOW_TOPLEVEL);
    /* apertura messaggio chiusura non permessa */
    dialog_info(no_ciao,"Non si puo' uscire cosi'");
    /* chiusura finestra di comodo */
    gtk_widget_destroy(no_ciao);
    return TRUE;
}


void dialog_info (GtkWidget *win, char *message)
{
  /* crea message dialog per visualizzare le informazioni passate come parametro */
  GtkWidget *dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,"%s",message);
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));     // attende interazione con utente
  gtk_widget_destroy (dialog);              // chiude widget
}


int dialog_scelta (GtkWidget *win, char *messaggio, char *title)
{
    /* crea una nuova dialog che permette di visualizzare le informazioni passate come parametri e restituisce la scelta effettuata dall'utente
        sotto forma di vero/falso 1/0 */
    GtkWidget *dialog = NULL;
    GtkWidget *content_area=NULL;
    GtkWidget *label=gtk_label_new (messaggio);
    GtkWidget *hbox=gtk_hbox_new(FALSE,0);
    GtkWidget *image=gtk_image_new_from_file("pericolo.png");
    gint scelta=0;
    dialog =  gtk_dialog_new_with_buttons (title, GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);
    gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(dialog),250,180);
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    gtk_container_add (GTK_CONTAINER (content_area), hbox);
    gtk_box_pack_start(GTK_BOX(hbox),image,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(hbox),label,TRUE,FALSE,0);
    gtk_widget_show_all (dialog);

    scelta=gtk_dialog_run (GTK_DIALOG (dialog)); // assegna a scelta il valore del tasto premuto
    if (scelta== GTK_RESPONSE_ACCEPT)
    {
        gtk_widget_destroy (dialog);            // chiude finestra e restituisce valore 1 se è stato premuto [ok]
        return 1;
    }
    gtk_widget_destroy (dialog);                // chiude finestra e restituisce valore 0 se è stato premuto [cancel]
    return 0;
}


void aggiungi_piatto (GtkWidget *button, Parametri *gui_par)
{
    /* procedura per aggiungere piatti all'archivio: definisce la label del titolo della finestra */
    gtk_label_set_markup (GTK_LABEL (gui_par->label_titolo),"<big><b><span color='#0000FF' background='#FFFFFF' underline='double'> Inserimento nuovo piatto </span></b></big>");
    /* Nasconde la schermata di avvio */
    gtk_widget_hide(gui_par->first_box);
    /* Visualizza la finestra aggiungi/modifica piatti*/
    gtk_widget_show_all (gui_par->second_box);
    /* nasconde la box contenente i pulsanti necessari alla gestione della modifica piatti */
    gtk_widget_hide(gui_par->button_box2);
    /* chiama la procedura di pulizia delle entry contenute nella finestra */
    pulisci(gui_par);
}


void pulisci (Parametri *gui_par)
{
    /* Setta il testo della label contenente le informazioni sull'id del nuovo piatto
    calcolato automaticamente dal programma in base all'id dell'ultimo piatto inserito, pulisce tutte le entry
    e setta la combo su nessuna selezione */
    char id[M];
    sprintf(id,"ID nuovo piatto: %3d",gui_par->myfiles->uid);
    gtk_label_set_text(GTK_LABEL(gui_par->label_id),id);
    gtk_entry_set_text (GTK_ENTRY(gui_par->nome_entry),"");
    gtk_entry_set_text (GTK_ENTRY(gui_par->prezzo_entry),"");
    gtk_entry_set_text (GTK_ENTRY(gui_par->ingrediente_entry[0]),"");
    gtk_entry_set_text (GTK_ENTRY(gui_par->ingrediente_entry[1]),"");
    gtk_entry_set_text (GTK_ENTRY(gui_par->ingrediente_entry[2]),"");
    gtk_combo_box_set_active (GTK_COMBO_BOX(gui_par->tipol_combo),-1);
}


void annulla(GtkWidget *button, Parametri *gui_par)
{
    /* Esce dalla finestra di aggiunta/modifica piatto in caso di risposta affermativa dell'utente */
    if (dialog_scelta(gui_par->main_win,"Vuoi davvero \n\n     Uscire?","Annulla Operazione"))
    {
        pulisci(gui_par);
        /* nasconde la schermata aggiungi/modifica piatto */
        gtk_widget_hide(gui_par->second_box);
        /* visualizza di nuovo la schermata di avvio*/
        gtk_widget_show(gui_par->first_box);
    }
}


void registra_nuovo(GtkWidget *button, Parametri *gui_par)
{
    /* procedura che aggiunge al file archivio piatti un nuovo record: viene utilizzata una variabile di tipo struttura piatto */
    char nome[M],messaggio[M];
    int i,controllo=0;
    Piatto npiatto;
    int scelta=0;

    npiatto.id=gui_par->myfiles->uid;                                           // assegna il nuovo id calcolato e memorizzato a suo tempo in myfiles->uid
    sprintf(nome,"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->nome_entry)));      // legge il testo contenuto nella entry e lo assegna a nome
    normalizza(nome);                                                           // normalizza il nome con l'apposita procedura
    gtk_entry_set_text (GTK_ENTRY(gui_par->nome_entry),nome);                   // scrive il nome normalizzato nella entry
    sprintf(npiatto.nome,"%s",nome);                                            // assegna il nome al relativo campo nella struttura npiatto
    for (i=0;i<3;i++)                                                           // legge, normalizza e scrive anche per i nomi degliingredienti
    {
        sprintf(npiatto.ingredienti[i],"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->ingrediente_entry[i])));
        normalizza(npiatto.ingredienti[i]);
        gtk_entry_set_text (GTK_ENTRY(gui_par->ingrediente_entry[i]),npiatto.ingredienti[i]);
    }
    npiatto.tipo=gtk_combo_box_get_active(GTK_COMBO_BOX(gui_par->tipol_combo));     // assegna il valore relativo alla riga selezionata della combo al campo tipo
    npiatto.prezzo = atof(gtk_entry_get_text(GTK_ENTRY(gui_par->prezzo_entry)));    // legge e assegna il prezzo tramite la funzione atof (ASCII to float)

    controllo=controllo_nuovo_piatto(npiatto,gui_par->piatti,gui_par->myfiles);     // chiama la funzione di controllo per verificare che quanto inserito sia regolare

    /* il valore restituito dalla funzione di controllo rende possibile comunicare all'utente le irregolarità
        dei valori inseriti */
    if (controllo == 2)                                                             // se controllo restituisce 2 il nome del file era vuoto
    {
        dialog_info(gui_par->main_win,"Il nome non puo' essere vuoto");
    }
    else if (controllo == 0)                                                        // il nome del piatto era già in archivio
    {
        sprintf(nome,"%s e' gia' in archivio",nome);
        dialog_info(gui_par->main_win,nome);
        gtk_entry_set_text (GTK_ENTRY(gui_par->nome_entry),"");                     // il programma cancella il nome già in archivio dall'entry
    }
    else if (controllo>2 && controllo<6)                                            // uno dei campi con i nomi degli ingredienti è vuoto
    {
        sprintf(messaggio,"Qualcosa non va all'ingrediente %d",controllo-2);
        dialog_info(gui_par->main_win,messaggio);
    }
    else if (controllo == 7)                                                        // il tipo piatto non è stato selezionato
    {
        dialog_info(gui_par->main_win,"Occorre selezionare il tipo di piatto");
    }
    else if (controllo == 6)                                                        // non è stato inserito il prezzo
    {
        dialog_info(gui_par->main_win,"Manca il prezzo");
    }
    else if (controllo == 1)                                                        // tutto ok possiamo procedere chiamando la funzione che aggiunge il nuovo piatto all'archivio
    {

        if (append_piatto(&npiatto)==1)                                             // se è andato tutto bene valore restituito = 1
        {

            (gui_par->myfiles->uid)++;                                              // viene aggiunto 1 al nuovo id piatto

            if (gui_par->myfiles->num_rec>=gui_par->myfiles->rec_mem)               // viene effettuato il controllo sulla memoria a disposizione
            {
                gui_par->piatti=(Piatto*) realloc(gui_par->piatti,2*sizeof(Piatto)*gui_par->myfiles->num_rec);
                if(gui_par->piatti==NULL)                                           // essendo un punto fondamentale per il buon funzionamento del prg
                {                                                                   // in caso di errore di riallocazione della memoria, lo stesso viene chiuso
                    dialog_info(gui_par->main_win,"Purtroppo non riesco a riallocare la memoria\nper il vettore piatti...\nl'applicazione sarà terminata!");
                    gtk_main_quit ();
                }
                gui_par->myfiles->rec_mem= 2 * gui_par->myfiles->num_rec;           // memorizza il nuovo limite della memoria disponibile
            }
            gui_par->piatti[gui_par->myfiles->num_rec]=npiatto;                     // assegna il nuovo piatto al vettore piatti (in ultima posizione +1) come da valore conservato in num_rec
            (gui_par->myfiles->num_rec)++;                                          // num_rec viene incrementato per essere pronto per il nuovo inserimento
            gui_par->num_rec=gui_par->myfiles->num_rec;                             // viene aggiornato anche il corrispondente valore conservato nella struttura principale del gui

            for (i=0;i<3;i++)                                                       // chiamata alla funzione che si occupa di aggiungere gli ingredienti del nuovo piatto se non ancora in archivio
            {
                controllo_ingredienti(npiatto.ingredienti[i],gui_par);
            }
            /* Visualizza messaggio di avvenuta registrazione del nuovo piatto e contestuale richiesta sul da farsi: continuare a inserire o uscire da aggiungi piatti */
            scelta=dialog_scelta(gui_par->main_win,"Registrato: \nnuovo Inserimento?","Registrazione effettuata");
            if (scelta==0)              // si torna alla schermata di avvio nascondendo la seconda finestra e mostrando la prima
            {
                pulisci(gui_par);
                gtk_widget_hide(gui_par->second_box);
                gtk_widget_show(gui_par->first_box);
            }
            else
            {
                pulisci(gui_par);       // si continua con l'inserimento nella schermata ripulita
            }
        }
        else
        {
            dialog_info(gui_par->main_win,"Errore... \nRegistrazione non effettuata!!!");  // se qualcosa è andato storto visualizza un messaggio di errore
        }
    }

}


void controllo_creazione_file (GtkWidget *win, char *message, char *title, char *archivio)
{
    /*  procedura che si occupa della creazione dei file di archivio nella fase di reinizializzazione
        Poichè in avvio di programma viene richiamata una funzione che in caso non esistano gli archivi, li crea,
        potrebbe sembrare superfluo controllare l'esistenza dei file anche in questo punto ma, non si sa mai... */
    char messaggio[M];
    int scelta=0,esiste=0,ok=0;

    esiste = esiste_file(archivio);     // controllo esistenza file archivio

    if (esiste==0)                      // se non esiste (cosa come già detto poco probabile)
    {
        ok = crea_file(archivio);       // crea l'archivio specificato nei parametri passati alla funzione
        if (ok==0)                      // se la creazione non è riuscita esce dal programma
        {
            sprintf(messaggio,"La creazione del file \"%s\" e' fallita... \n\nIl programma verra' chiuso!",archivio);
            dialog_info(win,messaggio);
            gtk_main_quit();
        }

        else if (ok==1)                 // se la creazione è riuscita visualizza un messaggio di conferma
        {
            sprintf(messaggio,"Il file \"%s\" e' stato creato correttamente",archivio);
            dialog_info(win,messaggio);
        }
    }

    else if (esiste==1)                 // se il file esiste (e normalmente esiste) viene chiesta conferma alla sua riscrittura
    {
        scelta=dialog_scelta(win,message,title);
        if (scelta == 1)                // se la riscrittura è confermata
        {
            ok = crea_file(archivio);
            if (ok==0)                  // e il file non viene creato
            {
                sprintf(messaggio,"La creazione del file \"%s\" e' fallita... \n\nIl programma verra' chiuso!",archivio);
                dialog_info(win,messaggio);
                gtk_main_quit();        // si esce dal programma
            }

            else if (ok==1)             // se il file è stato creato regolarmente
            {
                sprintf(messaggio,"Il file \"%s\" e' stato sovrascritto correttamente",archivio);
                dialog_info(win,messaggio);             // viene visualizzato un messaggio di conferma
            }
        }

        else if (scelta == 0)           // se non viene confermata l'intenzione di sovrascrivere
        {
            sprintf(messaggio,"Il file \"%s\" non e' stato modificato",archivio);
            dialog_info(win,messaggio); // viene visualizzato un messaggio che ci rassicura sul fatto che gli archivi sono rimasti inalterati
        }
    }
}


void crea_archivio_piatti(GtkWidget *button, Parametri *gui_par)
{
    /* procedura richiamata dal menu file - sottomenu item reinizializza archivio piatti*/
    char *archivio="arch_menu.dat", *message="Il File esiste gia'... \n\nSovrascrivo?", *title="Attenzione";
    controllo_creazione_file (gui_par->main_win, message, title, archivio);
    inizializza(&gui_par->piatti,&gui_par->ingredienti,gui_par->myfiles); //dopo la riscrittura dell'archivio occorre aggiornare anche i vettori in memoria
}


void crea_archivio_ingredienti(GtkWidget *button, Parametri *gui_par)
{
    /* Procedura richiamata dal menu file - sottomenu item reinizializza archivio ingredienti*/
    char *archivio="arch_ingred.dat", *message="Il File esiste gia'... \n\nSovrascrivo?", *title="Attenzione";
    controllo_creazione_file (gui_par->main_win, message, title, archivio);
    inizializza(&gui_par->piatti,&gui_par->ingredienti,gui_par->myfiles);// dopo la riscrittura dell'archivio occorre aggiornare anche i vettori in memoria
    allinea_ingredienti(gui_par);                                        // e verificare che tutti gli ingredienti dei piatti in archivio siano presenti nell'archivio ingredienti
}


void modifica_piatto (GtkWidget *button, Parametri *gui_par)
{
    /*  Procedura di modifica piatti */
    gui_par->num_rec=gui_par->myfiles->num_rec;         // aggiorna la variabile che contiene il numero dei piatti memorizzati
    gui_par->i=0;                                       // imposta a 0 il record corrente

    if (gui_par->myfiles->num_rec<=0)                   // se non ci sono piatti memorizzati
    {
        dialog_info(gui_par->main_win,"Occorre prima aggiungere Piatti\n(Nessun piatto trovato!)");  // avvisa che occorre prima inserirne ed esce dalla Procedura
        return;
    }

    /*  Imposta il titolo della schermata */
    gtk_label_set_markup (GTK_LABEL (gui_par->label_titolo),"<big><b><span color='#0000FF' background='#FFFFFF' underline='double'> Archivio piatti </span></b></big>");
    gtk_widget_hide(gui_par->first_box);            // nasconde la schermata di avvio
    gtk_widget_show_all (gui_par->second_box);      // mostra la finestra di aggiunta modifica piatti
    gtk_widget_hide(gui_par->button_box1);          // nasconde box pulsanti per aggiunta
    assegna(gui_par);                               // chiama la procedura che riempie le entry nella finestra con i valori del record corrente
    ricerca_record(gui_par->main_win,gui_par);      /* chiama la procedura di ricerca piatti per selezionare quale piatto va modificato. Nel caso si esca senza selezionare
                                                       nulla viene lasciato visibile il piatto corrispondente al primo record in memoria */
}


void avanti_record (GtkWidget *button, Parametri *gui_par)
{
    /*  Procedura che incrementa di 1 il numero del record corrente (visualizzato nella finestra modifica) */
    int n=gui_par->i;
    if (n<gui_par->num_rec-1) // se il record corrente è minore del numero di record in archivio meno 1
    {
        n++;                  // incrementa di 1 il valore del record attivo
        gui_par->i=n;         // assegna il valore al campo appropriato
        assegna(gui_par);     // chiama la procedura che riempie le entry nella finestra con i valori del record corrente
    }
}


void indietro_record (GtkWidget *button, Parametri *gui_par)
{
    int n=gui_par->i;
    if (n > 0)                  // se il record corrente non è il primo (record 0)
    {
        n--;                    // dencrementa di 1 il valore del record attivo
        gui_par->i=n;           // assegna il valore al campo appropriato
        assegna(gui_par);       // chiama la procedura che riempie le entry nella finestra con i valori del record corrente
    }
}


void assegna(Parametri *gui_par)
{
    /*  Procedura che setta il contenuto delle entry e della combo con i valori provenienti dal record corrente in memoria
        ossia il record il cui numero è contenuto in gui_par->i */
    char id[M];
    sprintf(id,"Piatto ID= %d - Sono presenti %d piatti",gui_par->piatti[gui_par->i].id,gui_par->myfiles->num_rec);
    gtk_label_set_text(GTK_LABEL(gui_par->label_id),id);

    gtk_entry_set_text (GTK_ENTRY(gui_par->nome_entry),gui_par->piatti[gui_par->i].nome);
    sprintf(id,"%.2f",gui_par->piatti[gui_par->i].prezzo);
    gtk_entry_set_text (GTK_ENTRY(gui_par->prezzo_entry),id);
    gtk_entry_set_text (GTK_ENTRY(gui_par->ingrediente_entry[0]),gui_par->piatti[gui_par->i].ingredienti[0]);
    gtk_entry_set_text (GTK_ENTRY(gui_par->ingrediente_entry[1]),gui_par->piatti[gui_par->i].ingredienti[1]);
    gtk_entry_set_text (GTK_ENTRY(gui_par->ingrediente_entry[2]),gui_par->piatti[gui_par->i].ingredienti[2]);
    gtk_combo_box_set_active (GTK_COMBO_BOX(gui_par->tipol_combo),gui_par->piatti[gui_par->i].tipo);
}


void registra_modifica(GtkWidget *button, Parametri *gui_par)
{
    /*  Procedura che registra sul vettore in memoria e sul file archivio piatti le modifiche effettuate nella finestra di modifica */
    char nome[M];
    int i,controllo=0;
    Piatto nuovo_piatto;
    int scelta=0;

    sprintf(nome,"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->nome_entry)));  // legge il nome del piatto
    normalizza(nome);

    for (i=0;i<gui_par->num_rec;i++)
    {
        if(strcmp(nome,(gui_par->piatti[i].nome))==0 && i!=gui_par->i)      // verifica se il nome è gia presente in archivio ad un numero diverso rispetto al record corrente
        {
            controllo++;
        }
    }

    if (strlen(nome)==0)                                                    // verifica se il nome non è stato inserito
    {
        dialog_info(gui_par->main_win,"Il nome non puo' essere vuoto");     // avverte l'utente con un messaggio
        return;
    }
    else if (controllo>0)
    {
        sprintf(nome,"%s e' gia' in archivio",nome);                        // se il nome è stato modificato in un altro già in archivio avvisa dell'errore
        dialog_info(gui_par->main_win,nome);
        return;
    }
    else if (controllo<1)                                                   // se il controllo è stato superato
    {
        gtk_entry_set_text (GTK_ENTRY(gui_par->nome_entry),nome);           // scrive il nuovo nome normalizzato nella entry relativa
        sprintf(nuovo_piatto.nome,"%s",nome);

        for (i=0;i<3;i++)
        {
            sprintf(nuovo_piatto.ingredienti[i],"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->ingrediente_entry[i])));   // legge i nomi degli ingredienti
            if (strlen(nuovo_piatto.ingredienti[i])==0)                                                               // verifica se in nome è stato immesso
            {
                dialog_info(gui_par->main_win,"Manca uno degli ingredienti!");                                         // avvisa del mancato inserimento di un ingrediente
                return;
            }
            normalizza(nuovo_piatto.ingredienti[i]);                                                                    // normalizza nome ingrediente
        }
        /* Assegna ai campi di nuovo piatto i valori da memorizzare nel file e nel vettore piatti per registrare le modifiche al record corrente */
        nuovo_piatto.tipo=gtk_combo_box_get_active(GTK_COMBO_BOX(gui_par->tipol_combo));
        nuovo_piatto.prezzo=atof(gtk_entry_get_text(GTK_ENTRY(gui_par->prezzo_entry)));
        if (nuovo_piatto.prezzo<=0)
        {
            dialog_info(gui_par->main_win,"Manca il prezzo!");                                         // avvisa del mancato inserimento del prezzo
            return;
        }
        nuovo_piatto.id=gui_par->piatti[gui_par->i].id;
        gui_par->piatti[gui_par->i]=nuovo_piatto; // assegna al record corrente i valori memorizzati in nuovo piatto

        if (scrivi_modifica_piatto(&nuovo_piatto,gui_par->i)==1)  // chiama la funzione che scrive in archivio il record modificato e se tutto ok
        {
            for (i=0;i<3;i++)
            {
                controllo_ingredienti(nuovo_piatto.ingredienti[i],gui_par);     // verifica che i tre ingredienti del piatto modificato siano già presenti in archivio
            }

            /* mostra la finestra di scelta avvisando dell'avvenuta registrazione delle modifiche e chiedendo se si vuole proseguire nell'editing */
            scelta=dialog_scelta(gui_par->main_win,"Modifica Registrata.\nVuoi continuare modifiche?","Registrazione effettuata");
            if (scelta==0)                              // scelta negativa: si torna alla schermata di avvio
            {
                pulisci(gui_par);
                gtk_widget_hide(gui_par->second_box);
                gtk_widget_show(gui_par->first_box);
                return;
            }
            else
            {
                assegna(gui_par);                       // scelta positiva si aggiorna la visualizzazione e si rimane in editing
                return;
            }
        }
        else
        {
            /*  Se ci sono stati problemi nella scrittura del file si viene avvisati */
            dialog_info(gui_par->main_win,"Errore... \nRegistrazione non effettuata!!!");
            return;
        }
    }
}


void elimina_record(GtkWidget *button, Parametri *gui_par)
{
    /*  Procedura per l'eliminazione di un piatto dall'archivio. La procedura, dopo la richiesta di conferma
        prima elimina il piatto dal vettore in memoria e poi riscrive il file aggiornato */
    char nome[M];
    int i,scelta;
    sprintf(nome,"Vuoi eliminare \n\"%s\"\n dall'archivio?",gui_par->piatti[gui_par->i].nome);  //prepara il messaggio che richiede la conferma per l'eliminazione

    if (gui_par->i_sel==2)                                                                      //se la procedura è chiamata dalla finestra di ricerca
    {
        scelta = dialog_scelta(gui_par->ricerca_win,nome,"Elimina piatto");                     // chiede la conferma
        if (scelta)
        {
            gtk_widget_destroy(gui_par->ricerca_win);                                           //e chiude la finestra di ricerca in caso affermativo
        }
    }
    else
    {
        scelta = dialog_scelta(gui_par->main_win,nome,"Elimina piatto");                        //se la procedura è chiamata dalla finestra di modifica chiede solo conferma
    }

    if (scelta)                                                                                 //se la risposta è affermativa
    {
        for (i=gui_par->i;i<((gui_par->num_rec) - 1);i++)                                       //scorre il vettore dal record corrente fino alla fine
        {
            gui_par->piatti[i]=gui_par->piatti[i+1];                                            //e, sovrascrivendo il record da eliminare, assegna ad ogni record quello successivo
        }

        (gui_par->num_rec)--;                                                                   //decrementa il valore memorizzato corrispondente al numero dei record in memoria
        gui_par->myfiles->num_rec = gui_par->num_rec;                                           //aggiorna l'altro contatore relativo al numero dei record in archivio
        if (gui_par->i>0)                                                                       //se il record corrente non era il primo ne decrementa di 1 il valore
            (gui_par->i)--;
        assegna(gui_par);                                                                       //riempie gli entry della finestra di modifica con i valori del record precedente a quello eliminato
        if (scrivi_vettore(gui_par)==0)                                                         //scrive il vettore modificato sul file dei piatti
        {
            gtk_main_quit();                                                                    //se la scrittura non è riuscita esce dal programma
        }
        gui_par->myfiles->uid=gui_par->piatti[gui_par->num_rec].id;
    }

    if (gui_par->num_rec<1)                                                                     // se il piatto cancellato era l'unico in memoria
    {
        pulisci(gui_par);                                                                       // ripulisce la finestra di modifica e ritorna alla schermata di avvio
        gtk_widget_hide(gui_par->second_box);
        gtk_widget_show(gui_par->first_box);
    }
}


int scrivi_vettore (Parametri *gui_par)
{
    /* funzione che scrive il vettore dei piatti sul file archivio sostituendone il contenuto */
    FILE *fp=NULL;
    fp=fopen("arch_menu.dat","wb"); // apre il file archivio piatti in modalità scrittura binaria
    if (fp==NULL)                   //verifica la corretta apertura
    {
        dialog_info(gui_par->main_win, "Non riesco ad aprire il file...\n Anche se in questo punto del programma\ne' quasi impossibile...\nIl programma verra' chiuso!");
        return 0;
    }
    fwrite(gui_par->piatti,sizeof(Piatto),gui_par->num_rec,fp); //scrive il vettore sul file
    fclose(fp);                                                 //chiude il file
    return 1;
}


void pulisci_ricerca (GtkWidget *button, Parametri *gui_par)
{
    /*  Procedura che ripulisce i campi ricerca della omonima finestra e fa in modo che vengano visualizzati di nuovo tutti i piatti */
    gtk_entry_set_text (GTK_ENTRY(gui_par->ricerca_entry_id),"");
    gtk_entry_set_text (GTK_ENTRY(gui_par->ricerca_entry_nome),"");
    gtk_entry_set_text (GTK_ENTRY(gui_par->ricerca_entry_ingredienti),"");
    gtk_combo_box_set_active (GTK_COMBO_BOX(gui_par->ricerca_combo_tipo),-1);
    gtk_list_store_clear (gui_par->ricerca_list_store);                             //ripulisce la list store
    gtk_entry_set_text (GTK_ENTRY(gui_par->ricerca_seleziona_entry),"");
    avvia_ricerca(gui_par->main_win,gui_par);                                       //visualizza i piatti che rispondono ai criteri di ricerca: in questo caso tutti
}


void chiudi_gui_ricerca(GtkWidget *button, Parametri *gui_par)
{
    /*  Procedura che chiude la finestra di ricerca ed in base alla flag gui_par->i_sel compie diverse operazioni */
    int i,id;

    if (gui_par->i_sel==0)                                  //caso 0
        {
            gtk_widget_destroy(gui_par->ricerca_win);       //chiude la finestra ed esce
            return;
        }
    /* tutti gli altri casi: verifica se è presente un valore nella entry di selezione */
    if(strlen(gtk_entry_get_text(GTK_ENTRY(gui_par->ricerca_seleziona_entry)))>0)
    {
        id = atoi(gtk_entry_get_text(GTK_ENTRY(gui_par->ricerca_seleziona_entry)));  //ne ricava il valore
    }
    else
    {
        dialog_info(gui_par->ricerca_win, "Occorre selezionare un piatto\ndalla lista con un click del\ntasto sinistro del mouse..."); // nel caso in cui la entry sia vuota visualizza un messaggio
        return;
    }


    for(i=0;i<gui_par->num_rec;i++)                 //trova il record con l'id corrispondente a quello selezionato
    {
        if(gui_par->piatti[i].id==id)
        {
            gui_par->i=i;                           //assegna il valore alla variabile che contiene il valore del record corrente
        }
    }

    if (gui_par->i_sel==1)                          //nel caso 1 (procedura chiamata dalla procedura o dalla finestra di modifica piatto)
    {
        assegna(gui_par);                           //visualizza il record corrente
        gtk_widget_destroy(gui_par->ricerca_win);   //chiude la finestra di ricerca
    }

    else if (gui_par->i_sel==2)                     //nel caso 2 (procedura chiamata da pulsante o voce di menu [elimina piatto])
    {
        elimina_record(button, gui_par);            //chiama la procedura per l'eliminazione del record corrente
    }

    else if (gui_par->i_sel==3)                     //caso 3 (procedura di ricerca chiamata da CASSA per la selezione del piatto da ordinare)
    {
        if (gui_par->scontrini[gui_par->cassa_i].num_ord>=gui_par->scontrini[gui_par->cassa_i].mem_ord) //verifica se la memoria precedentemente allocata per gli ordini del tavolo corrente è sufficiente
        {
            /* Se la memoria non è sufficiente ne rialloca una quantità doppia rispetto a quella necessaria per gli ordini memorizzati fino a quel momento */
            gui_par->scontrini[gui_par->cassa_i].ordini=(Ordine *)realloc(gui_par->scontrini[gui_par->cassa_i].ordini,2*sizeof(Ordine)*gui_par->scontrini[gui_par->cassa_i].num_ord);
            if (gui_par->scontrini[gui_par->cassa_i].ordini==NULL)
            {
                /* Se la riallocazione non va a buon fine esce dal programma dopo la visualizzazione di un messaggio informativo */
                dialog_info(gui_par->cassa_main_win,"Problemi con la riallocazione della memoria\nl'applicazione sara' chiusa!");
                gtk_main_quit();
            }
            (gui_par->scontrini[gui_par->cassa_i].mem_ord)*=2; //aggiorna la variabile con il nuovo valore relativo alla memoria disponibile
        }
        /*assegna la id del piatto corrente al campo id_piatto dellordine relativo al tavolo corrente*/
        gui_par->scontrini[gui_par->cassa_i].ordini[gui_par->scontrini[gui_par->cassa_i].num_ord].id_piatto=gui_par->i;
        /* stessa cosa per il nome del piatto */
        sprintf(gui_par->scontrini[gui_par->cassa_i].ordini[gui_par->scontrini[gui_par->cassa_i].num_ord].nome_piatto,"%s",gui_par->piatti[gui_par->i].nome);
        /* per il prezzo */
        gui_par->scontrini[gui_par->cassa_i].ordini[gui_par->scontrini[gui_par->cassa_i].num_ord].prezzo_piatto=gui_par->piatti[gui_par->i].prezzo;
        /* il tipo */
        gui_par->scontrini[gui_par->cassa_i].ordini[gui_par->scontrini[gui_par->cassa_i].num_ord].tipo_piatto=gui_par->piatti[gui_par->i].tipo;
        /* ricava il numero di porzioni dalla entry predisposta allo scopo e lo memorizza */
        gui_par->scontrini[gui_par->cassa_i].ordini[gui_par->scontrini[gui_par->cassa_i].num_ord].porzioni=atoi(gtk_entry_get_text(GTK_ENTRY(gui_par->cassa_quantita_entry)));
        if (gui_par->scontrini[gui_par->cassa_i].ordini[gui_par->scontrini[gui_par->cassa_i].num_ord].porzioni<1)
        {
            dialog_info(gui_par->ricerca_win,"Il numero di porzioni deve essere maggiore o uguale a uno!"); //in caso il numero di porzioni sia <=0 avverte l'utente ed esce dalla procedura
            return;
        }
        /* assegna id al nuovo ordine relativo al tavolo corrente */
        gui_par->scontrini[gui_par->cassa_i].ordini[gui_par->scontrini[gui_par->cassa_i].num_ord].id=gui_par->scontrini[gui_par->cassa_i].num_ord;
        for (i=0;i<3;i++) // recupera e memorizza i nomi degli ingredienti del piatto ordinato
        {
            strcpy(gui_par->scontrini[gui_par->cassa_i].ordini[gui_par->scontrini[gui_par->cassa_i].num_ord].ingredienti[i],gui_par->piatti[gui_par->i].ingredienti[i]);
        }
        (gui_par->scontrini[gui_par->cassa_i].num_ord)++; //incrementa il numero degli ordini registrati per il tavolo corrente
        cassa_aggiorna(gui_par);                          //aggiorna la visualizzazione della finestra di cassa
        gtk_widget_destroy(gui_par->ricerca_win);         //chiude la finestra di ricerca piatti
    }
}


void ricerca_record (GtkWidget *button, Parametri *gui_par)
{
    /* procedura che richiama la finestra di ricerca piatti dalla finestra di modifica */
    gui_ricerca(gui_par);                           //genera la finestra
    gtk_widget_show_all(gui_par->ricerca_win);      //la mostra
    gui_par->i_sel=1;                               //impostata a 1 significa che a richiamare la finestra di ricerca e' stata la finestra di modifica
    avvia_ricerca(gui_par->main_win,gui_par);       //visualizza tutti i piatti (poichè i parametri di ricerca sono ancora nulli)
}


void avvia_ricerca(GtkWidget *button, Parametri *gui_par)
{
    /* Procedura per la ricerca dei record all'interno del vettore piatti */
    int i;
    Tipologia tipo;                                                                                                 //variabile tipo per memorizzare contenuto combo
    char ricerca[4][N]={},ricercati[4][N]={},tipol[5][12]={"Antipasto", "Primo", "Secondo", "Contorno", "Dessert"}; //vettore di stringhe contenente i tipi piatto

    GtkTreeIter it;                                                                                                 // iteratore per la lista

    tipo = gtk_combo_box_get_active(GTK_COMBO_BOX(gui_par->ricerca_combo_tipo));                                    // memorizza tipo piatto cercato
    sprintf(ricerca[0],"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->ricerca_entry_id)));                              // memorizza come testo l'id cercato
    sprintf(ricerca[1],"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->ricerca_entry_nome)));                            // memorizza il nome piatto cercato
    normalizza(ricerca[1]);                                                                                         // normalizza il nome
    if (tipo!=-1)                                                                                                   // se è selezionato un tipo piatto nella combo
        {
            sprintf(ricerca[2],"%d",gtk_combo_box_get_active(GTK_COMBO_BOX(gui_par->ricerca_combo_tipo)));          // memorizza come testo il valore del tipo piatto cercato
        }
    else
        {
            sprintf(ricerca[2],"%s","\0");                                                                          // altrimenti memorizza una stringa vuota
        }

    sprintf(ricerca[3],"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->ricerca_entry_ingredienti)));                     // memorizza l'ingrediente cercato
    normalizza(ricerca[3]);                                                                                         // lo normalizza
    gtk_entry_set_text (GTK_ENTRY(gui_par->ricerca_entry_ingredienti),ricerca[3]);                                  // e lo scriva nella entry normalizzato
    gtk_list_store_clear (gui_par->ricerca_list_store);                                                             // ripulisce la list_store
    for (i=0;i<gui_par->num_rec;i++)                                                                                // cicla tutti i record in cerca di quelli che rispettano i parametri di ricerca
    {
        sprintf(ricercati[0],"%d",gui_par->piatti[i].id);                                                           // memorizza id (come testo)
        sprintf(ricercati[1],"%s",gui_par->piatti[i].nome);                                                         // memorizza nome
        sprintf(ricercati[2],"%d",gui_par->piatti[i].tipo);                                                         // memorizza tipo (come testo)
        sprintf(ricercati[3],"\t%5.2f",gui_par->piatti[i].prezzo);                                                  // memorizza prezzo (come testo)

        /*  effettua la ricerca nel vettore di strutture, utilizzando la funzione strstr che si presta perfettamente alla bisogna, in quanto se un
            campo di ricerca è una stringa nulla strstr mi restituisce !=NULL qualsiasi cosa trovi; se invece la stringa di ricerca contiene qualcosa
            la strstr mi restituisce NULL solo se non trova la stringa cercata neanche come parte della stringa su cui effettua la ricerca. Il fatto che
            i termini di ricerca siano normalizzati (prima lettera maiuscola e tutte le altre minuscole) fa si che la ricerca dia esito positivo solo come
            parte iniziale della stringa */
        if(strstr(ricercati[0],ricerca[0])!=NULL && strstr(ricercati[1],ricerca[1])!=NULL && strstr(ricercati[2],ricerca[2])!=NULL                          //parte relativa alla ricerca su id, nome e tipo piatto tutte condizioni da virificarsi contemporaneamente
           &&(strstr(gui_par->piatti[i].ingredienti[0],ricerca[3])!=NULL || strstr(gui_par->piatti[i].ingredienti[1],ricerca[3])!=NULL                      //parte relativa agli ingredienti in cui basta che uno dei tre sia TRUE per rendere TRUE tutto il contenuto della parentesi
              || strstr(gui_par->piatti[i].ingredienti[2],ricerca[3])!=NULL))
        {
            /* aggiunta delle righe alla lista */
            gtk_list_store_append(gui_par->ricerca_list_store, &it);
            gtk_list_store_set(gui_par->ricerca_list_store, &it, 0, gui_par->piatti[i].id,
                                                                 1, gui_par->piatti[i].nome,
                                                                 2, tipol[gui_par->piatti[i].tipo],
                                                                 3, gui_par->piatti[i].ingredienti[0],
                                                                 4, gui_par->piatti[i].ingredienti[1],
                                                                 5, gui_par->piatti[i].ingredienti[2],
                                                                 6, ricercati[3],
                                                                -1);
        }
    }
}


void tree_selection_changed (GtkTreeSelection *selection, Parametri *gui_par)
{
    /*  Procedura che verifica se è stata selezionata una riga della lista */
    GtkTreeIter iter;
    GtkTreeModel *model;
    char id_text[N];
    int id;

    if (gtk_tree_selection_get_selected (selection, &model, &iter))                 //se una riga viene selezionata
    {
        gtk_tree_model_get (model, &iter, 0, &id, -1);                              //recupera il valore della colonna 0 e lo memorizza nella variabile id
    }
    sprintf(id_text,"%d",id);                                                       //trasformain testo id
    gtk_entry_set_text (GTK_ENTRY(gui_par->ricerca_seleziona_entry),id_text);       //e lo memorizza nella entry di selezione
}


int controllo_ingredienti(char *n_ingrediente,Parametri *gui_par)
{
    /*  funzione per il controllo della effettiva presenza in archivio degli ingredienti presenti nei nuovo piatti o nei piatti modificati */
    int i=0,n;

    FILE *fp=NULL;

    n=strlen(n_ingrediente);                                                        //memorizza in n la lunghezza del nome dell'ingrediente

    if (n==0)                                                                       // se è una stringa vuota esce dalla funzione restituendo 0
    {
        return 0;
    }

    for (i=0; i<gui_par->myfiles->ing_num_rec; i++)                                 // cicla tutti gli ingredienti del vettore ingredienti
    {
        if(strcmp(gui_par->ingredienti[i].nome,n_ingrediente)==0)                   // se trova un ingrediente con lo stesso nome di quello da controllare
        {
            return 0;                                                               // esce dalla funzione restituendo 0
        }
    }

    if (gui_par->myfiles->ing_num_rec>=gui_par->myfiles->ing_rec_mem)               // se la memoria allocata per il vettore ingredienti è stata tutta usata
    {
        /* rialloca una quantità di memoria pari al doppio di quella gia allocata */
        gui_par->ingredienti=(Ingrediente*) realloc(gui_par->ingredienti,sizeof(Ingrediente)*2*gui_par->myfiles->ing_num_rec);
        if (gui_par->ingredienti==NULL)                                             // verifica se la riallocazione è stata eseguita
        {
            dialog_info(gui_par->cassa_main_win,"Problemi con la riallocazione della memoria\nl'applicazione sara' chiusa!");
            gtk_main_quit();                                                        // esce dall'applicazione in caso di errore nella riallocazione
        }
        gui_par->myfiles->ing_rec_mem = 2 * gui_par->myfiles->ing_num_rec;          // aggiorna il valore memorizzato relativo alla memoria disponibile per il vettore ingredienti
    }

    gui_par->ingredienti[gui_par->myfiles->ing_num_rec].id = gui_par->myfiles->ing_num_rec;         // assegna nuovo id all'ingrediente da memorizzare nel vettore
    sprintf(gui_par->ingredienti[gui_par->myfiles->ing_num_rec].nome,"%s",n_ingrediente);           // memorizza il nome
    gui_par->ingredienti[gui_par->myfiles->ing_num_rec].quantita=0;                                 // imposta a 0 la quantità cioè il numero di utilizzi dell'ingrediente

    fp=fopen("arch_ingred.dat","ab");                                                               // apre il file ingredienti in modalità append
    if (fp==NULL)                                                                                   // verifica la corretta apertura
    {
        return 0;                                                                                   // in caso di errore esce e restituisce 0
    }
    fwrite(&gui_par->ingredienti[gui_par->myfiles->ing_num_rec],sizeof(Ingrediente),1,fp);          // scrive il nuovo ingrediente alla fine del file
    (gui_par->myfiles->ing_num_rec)++;                                                              // aggiorna il numero record del file
    fclose(fp);                                                                                     // chiude il file
    return 1;                                                                                       // restituisce 1 = tutto ok
}


void elimina_piatto (GtkWidget *button,Parametri *gui_par)
{
    /* procedura per l'eliminazione di un piatto dal menu */
    gui_par->num_rec=gui_par->myfiles->num_rec;                 // aggiorna il numero record in memoria
    gui_par->i=0;                                               // setta il numero record corrente a 0

    if (gui_par->myfiles->num_rec<=0)                           // se non sono presenti record in archivio informa sul da farsi l'utente ed esce dalla procedura
    {
        dialog_info(gui_par->main_win,"Occorre prima aggiungere Piatti\n(Nessun piatto trovato!)");
        return;
    }
    gui_ricerca(gui_par);                                       // genera la finestra di ricerca
    gtk_widget_show_all(gui_par->ricerca_win);                  // visualizza la finestra di ricerca
    gui_par->i_sel=2;                                           //impostata a 2 significa che a richiamare la ricerca e' stato il menu elimina piatto
    avvia_ricerca(gui_par->main_win,gui_par);                   //avvia la procedura per la visualizzazione dei piatti nella lista
}


void stampa_menu (GtkWidget *button,Parametri *gui_par)
{
    /*  Procedura per la stampa su file dell'intero menu */
    int i,j;
    /*  dichiara ed inizializza il vettore utilizzato per la memorizzazione temporanea dei piatti e
        il vettore con i tipi di piatto */
    char ricercati[4][N]={},tipol[5][12]={"Antipasto", "Primo", "Secondo", "Contorno", "Dessert"};

    GtkTreeIter it;  // iteratore per la lista

    gui_par->num_rec=gui_par->myfiles->num_rec;             //allinea numero record in memoria ed in archivio
    gui_par->i=0;                                           //imposta numero record corrente a 0
    gui_par->i_sel=0;                                       //imposta a 0 flag per procedura di chiusura finestra
    if (gui_par->myfiles->num_rec<=0)                       //se non ci sono record in archivio informa l'utente
    {
        dialog_info(gui_par->main_win,"Occorre prima aggiungere Piatti\n(Nessun piatto trovato!)");
        return;
    }

    gui_ricerca(gui_par);                                                                                           //genera finestra ricerca
    gtk_window_set_default_size(GTK_WINDOW(gui_par->ricerca_win),800,700);                                          //imposta le dimensioni
    gtk_widget_show_all(gui_par->ricerca_win);                                                                      //la mostra
    gtk_widget_hide(gui_par->ricerca_hbox1);                                                                        //nasconde la hbox1 relativa ai parametri di ricerca
    gtk_widget_hide(gui_par->ricerca_separator1);                                                                   //nasconde il separatore 1 e 2
    gtk_widget_hide(gui_par->ricerca_separator2);
    gtk_widget_hide(gui_par->ricerca_hbox2);                                                                        //nasconde la hbox2, relativa ai pulsanti di selezione
    gtk_window_set_title (GTK_WINDOW (gui_par->ricerca_win), "Stampa Menu'");                                       //cambia il titolo alla finestra

    gui_par->stampa_hbox=gtk_hbox_new(FALSE,5);                                                                     //prepara un nuovo hbox per i pulsanti di stampa
    gtk_box_pack_end (GTK_BOX (gui_par->ricerca_main_box), gui_par->stampa_hbox, FALSE, FALSE, 5);                  //e lo inserisce in finestra

    gui_par->stampa_button = gtk_button_new_with_label (" Stampa su file ");                                        //inserisce pulsante per la stampa
    gtk_box_pack_start (GTK_BOX (gui_par->stampa_hbox), gui_par->stampa_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->stampa_button, "clicked", G_CALLBACK (stampa_menu_su_file), (gpointer) gui_par);

    gui_par->esci_stampa_button = gtk_button_new_with_label ("\n      Esci      \n");                               //inserisce pulsante di uscita
    gtk_box_pack_end (GTK_BOX (gui_par->stampa_hbox), gui_par->esci_stampa_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->esci_stampa_button, "clicked", G_CALLBACK (chiudi_gui_ricerca), (gpointer) gui_par);
    gtk_widget_show_all(gui_par->stampa_hbox);                                                                      //visualizza la nuova hbox

    for(j=0;j<5;j++)                                                                                                //cicla per tipologia
    {
        for (i=0;i<gui_par->num_rec;i++)                                                                            //cicla per numero record
        {
            sprintf(ricercati[0],"%d",gui_par->piatti[i].id);                                                       //assegna i valori del record corrente al vettore per la memorizzazione temporanea
            sprintf(ricercati[1],"%s",gui_par->piatti[i].nome);
            sprintf(ricercati[2],"%d",gui_par->piatti[i].tipo);
            sprintf(ricercati[3],"\t%5.2f",gui_par->piatti[i].prezzo);

            if (gui_par->piatti[i].tipo==j)                                                                         //se il tipo piatto corrisponde
            {
                gtk_list_store_append(gui_par->ricerca_list_store, &it);                                            //aggiunge una riga alla lista che quindi sarà ordinata per tipopiatto crescente
                gtk_list_store_set(gui_par->ricerca_list_store, &it, 0, gui_par->piatti[i].id,
                                                                     1, gui_par->piatti[i].nome,
                                                                     2, tipol[gui_par->piatti[i].tipo],
                                                                     3, gui_par->piatti[i].ingredienti[0],
                                                                     4, gui_par->piatti[i].ingredienti[1],
                                                                     5, gui_par->piatti[i].ingredienti[2],
                                                                     6, ricercati[3],
                                                                    -1);
            }
        }
    }
}


void stampa_menu_su_file (GtkWidget *button,Parametri *gui_par)
{
    /*  Stampa su file il menu */
    int i,j,l;
    char tipol[5][12]={"Antipasto", "Primo", "Secondo", "Contorno", "Dessert"},nome_ristorante[2*M]={};
    FILE *fp;
    fp=fopen("stampa_menu.txt","w");    //apre il file in modalita scrittura
    if (fp==NULL)                       //verifica corretta apertura
    {
        return;                         //in caso di errori esce dalla procedura
    }

    /*  Stampa intestazione menu  */
    fprintf(fp," ________________________________________________________________________________________________________________________________\n");
    fprintf(fp,"|                                                                                                                                |\n");

    l=(128-strlen(gui_par->myfiles->nome_ristorante))/2;                    //assegna a l il valore della metà degli spazi necessari
    for (i=0;i<l+1;i++)                                                     //riempie di spazi i caratteri che non contengono il nome del ristorante
    {
        nome_ristorante[i]=' ',
        nome_ristorante[127-i]=' ';
    }
    sprintf(nome_ristorante+l+1,"%s",gui_par->myfiles->nome_ristorante);         //scrive il nome del ristorante nel punto calcolato della stringa affinchè risulti centrato
    nome_ristorante[l+strlen(gui_par->myfiles->nome_ristorante)+1]=' ';     //cancella il carattere NULL alla fine della stringa stampata, sostituendolo con uno spazio
    nome_ristorante[129]='\0';                                              //imposta il valore NULL a fine stringa

    fprintf(fp,"|%s|\n",nome_ristorante);
    fprintf(fp,"|                                                        Stampa del Menu'                                                        |\n");
    fprintf(fp,"|________________________________________________________________________________________________________________________________|\n");
    fprintf(fp,"|ID   | NOME                    | TIPO       | INGREDIENTI                                                               PREZZO  |\n");

    //cicla per tipo
    for(j=0;j<5;j++)
    {
        //cicla per numero record
        for (i=0;i<gui_par->num_rec;i++)
        {
            if (gui_par->piatti[i].tipo==j)     //se il tipo corrisponde
            {
                /*  Stampa la riga di dettaglio formattata con i nomi impostati a 25 caratteri max di lunghezza */
                fprintf(fp,"|%4d |%-25s|%-12s|%-24s|%-24s|%-24s|  %6.2f|\n",gui_par->piatti[i].id, gui_par->piatti[i].nome, tipol[gui_par->piatti[i].tipo],
                        gui_par->piatti[i].ingredienti[0], gui_par->piatti[i].ingredienti[1],
                        gui_par->piatti[i].ingredienti[2],gui_par->piatti[i].prezzo);
            }
        }
    }
    /* stampa la riga di chiusura del menu */
    fprintf(fp,"|________________________________________________________________________________________________________________________________|\n");
    fclose(fp); //chiude il file

    dialog_info(gui_par->ricerca_win,"Il Menu' e' stato stampato"); //informa l'utente dell'avvenuta preparazione del file

    #ifdef _WIN32
    system ("notepad stampa_menu.txt");  //visualizza il file sotto windows
    #endif

    #ifdef linux
    system ("leafpad stampa_menu.txt");  // e sotto linux
    #endif // linux

}


void ricerca_stampa(GtkWidget *button,Parametri *gui_par)
{
    /*  procedura che permette di cercare e salvare su file i piatti che corrispondono ai criteri di ricerca impostati */
    gui_par->num_rec=gui_par->myfiles->num_rec;         //allinea numero di record in memoria con numero di record nel file
    gui_par->i=0;                                       //imposta il numero del record corrente a 0
    gui_par->i_sel=0;                                   //imposta la flag per la procedura di chiusura ricerca
    if (gui_par->myfiles->num_rec<=0)                   //controllo presenza record in archivio
    {
        dialog_info(gui_par->main_win,"Occorre prima aggiungere Piatti\n(Nessun piatto trovato!)");
        return;
    }
    gui_ricerca(gui_par);                               //predisposizione finestra di ricerca


    gui_par->stampa_button = gtk_button_new_with_label (" Stampa su file ");                                        //aggiunta pulsante per la stampa su file
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox2), gui_par->stampa_button, FALSE, TRUE, 0);
    g_signal_connect (gui_par->stampa_button, "clicked", G_CALLBACK (stampa_ricerca_su_file), (gpointer) gui_par);

    gtk_widget_show_all(gui_par->ricerca_win);                                                  //visualizza finestra di ricerca
    gtk_widget_hide(gui_par->ricerca_separator2);                                               //nasconde separatore 2
    gtk_widget_hide(gui_par->ricerca_seleziona_entry);                                          //nasconde entry per la selezione
    gtk_widget_hide(gui_par->ricerca_seleziona_button);                                         //nasconde pulsante per la selezione
    gtk_window_set_title (GTK_WINDOW (gui_par->ricerca_win), "   Ricerca & Stampa   ");         //imposta il titolo della finestra
    avvia_ricerca(gui_par->main_win,gui_par);                                                   //avvia procedura per la visualizzazione dei record
}


void esci (GtkWidget *button,Parametri *gui_par)
{
    /* Procedura di uscita dal programma */
    int i;

    for (i=0;i<TAVOLI;i++) //cicla per numero tavolo
    {
        if (gui_par->scontrini[i].num_ord>0) //verifica se ci sono ordini memorizzati e quindi scontrini da stampare, impedendo in caso affermativo l'uscita
        {
            dialog_info(gui_par->main_win,"Non puoi uscire:\nHai almeno uno scontrino da stampare!");
            return;
        }
    }
    /*  chiede conferma prima di uscire */
    if (dialog_scelta(gui_par->main_win,"Vuoi davvero \n\n     Uscire?","Annulla Operazione"))
    {
        for (i=0;i<TAVOLI;i++) //cicla per numero tavolo
        {
            free(gui_par->scontrini[i].ordini); //libera memoria allocata per ordini
        }
        free(gui_par->scontrini);               //libera memoria allocata per il vettore tavoli
        free(gui_par->piatti);                  //libera memoria allocata per il vettore piatti
        free(gui_par->ingredienti);             //libera memoria allocata per il vettore ingredienti
        gtk_main_quit();                        //esce dal main loop gtk
    }
}


void aggiungi_ordine(GtkWidget * button , Parametri * gui_par)
{
    /* procedura per l'aggiunta di un ordine ad un tavolo */
    int id;

    /* verifica che sia stato selezionato un tavolo mediante la lunghezza del resto inserito nella entry di selezione del tavolo */
    if(strlen(gtk_entry_get_text(GTK_ENTRY(gui_par->cassa_seleziona_entry)))>0)
    {
        id = atoi(gtk_entry_get_text(GTK_ENTRY(gui_par->cassa_seleziona_entry))); // memorizza come intero l'id del tavolo
    }
    else
    {
        /* se il testo nella entry è nullo informa l'utente */
        dialog_info(gui_par->cassa_main_win, "Occorre selezionare un tavolo\ndalla lista con un click del\ntasto sinistro del mouse...");
        return;
    }
    if (id<0 || id>=TAVOLI)
     {
        /* avverte se il numero tavolo inserito manualmente nella entry è fuori range */
        dialog_info(gui_par->cassa_main_win, "Il valore inserito manualmente\ndeve essere compreso\ntra 0 ed il numero max di tavoli");
        return;
    }

    gui_par->cassa_i=id; // assegna id alla variabile facente parte della struttura principale e che contiene il valore del tavolo corrente

    gui_ricerca(gui_par); //prepara la finestra di ricerca piatti

    /*prepara un pulsante per la funzione di diminuzione della quantità di porzioni */
    gui_par->cassa_quantita_meno_button  = gtk_button_new_with_label ("  Decrementa Quantita'  ");
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox2), gui_par->cassa_quantita_meno_button, FALSE, TRUE, 5);
    g_signal_connect (gui_par->cassa_quantita_meno_button, "clicked", G_CALLBACK (cassa_quantita_meno), (gpointer) gui_par);

    /*prepara una entry per visualizzare il numero di porzioni da ordinare */
    gui_par->cassa_quantita_entry=gtk_entry_new ();
    gtk_entry_set_max_length(GTK_ENTRY (gui_par->cassa_quantita_entry),10);
    gtk_entry_set_width_chars (GTK_ENTRY (gui_par->cassa_quantita_entry),5);
    gtk_entry_set_text (GTK_ENTRY(gui_par->cassa_quantita_entry),"1");
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox2), gui_par->cassa_quantita_entry, FALSE, FALSE, 0);

    /*prepara un pulsante per la funzione di aumento della quantità di porzioni */
    gui_par->cassa_quantita_piu_button  = gtk_button_new_with_label ("  Incrementa Quantita'  ");
    gtk_box_pack_start (GTK_BOX (gui_par->ricerca_hbox2), gui_par->cassa_quantita_piu_button, FALSE, TRUE, 5);
    g_signal_connect (gui_par->cassa_quantita_piu_button, "clicked", G_CALLBACK (cassa_quantita_piu), (gpointer) gui_par);

    gtk_widget_show_all(gui_par->ricerca_win);      //visualizza la finestra di ricerca piatti
    gui_par->i_sel=3;                               //impostata a 3 significa che a richiamare la ricerca e' stata la finestra cassa
    avvia_ricerca(button,gui_par);                  //avvia la procedura per la visualizzazione dei record
}


void cassa_esci(GtkWidget * button , Parametri * gui_par)
{
    /* esce dalla gestione cassa eliminando la finestra cassa e mostrando di nuovo la finestra principale */
    gtk_widget_destroy(gui_par->cassa_main_win);
    gtk_widget_show(gui_par->main_win);
}


void cassa_tree_selection_changed(GtkTreeSelection *selection, Parametri *gui_par)
{
    /* procedura per la verifica dell'avvenuta selezione di una riga della finestra cassa */
    GtkTreeIter iter;
    GtkTreeModel *model;
    char id_text[N];
    int id;

    if (gtk_tree_selection_get_selected (selection, &model, &iter)) //se una riga è stata selezionata
    {
        gtk_tree_model_get (model, &iter, 0, &id, -1);              //memorizza il contenuto della colonna 0 sulla variabile id
    }
    if (id>=0 && id<TAVOLI)                                         //se id è compresa tra 0 ed il numero #TAVOLI
    {
        sprintf(id_text,"%d",id);                                   //stampa id come testo su id_text e lo memorizza nella entry di selezione tavolo
        gtk_entry_set_text (GTK_ENTRY(gui_par->cassa_seleziona_entry),id_text);
    }
}

void cassa(GtkWidget *button, Parametri *gui_par)
{
    /*  procedura per l'apertura della finestra di gestione cassa */
    gui_par->num_rec=gui_par->myfiles->num_rec;     //allinea il numero dei record memorizzati con quelli presenti sul file
    gui_par->i=0;                                   //setta a 0 il numero di record piatti corrente

    if (gui_par->myfiles->num_rec<=0)               //se non sono presenti piatti in archivio informa l'utente
    {
        dialog_info(gui_par->main_win,"Occorre prima aggiungere Piatti\n(Nessun piatto trovato!)");
        return;
    }

    gui_cassa(gui_par);                             //genera la finestra cassa
    gtk_widget_show_all(gui_par->cassa_main_win);   //la visualizza
    gtk_widget_hide(gui_par->main_win);             //nasconde la finestra principale
    cassa_aggiorna(gui_par);                        //aggiorna la visualizzazione con i dati correnti relativi ai tavoli
}

void cassa_aggiorna (Parametri *gui_par)
{
    /*  Procedura per la visualizzazine nella finestra cassa dei dati relativi ai tavoli */
    int i,j;
    char id_piatto[N],prezzo_piatto[N],totale_piatto[N],porzioni[N];
    GtkTreeIter it,it2;                                                 //definisce iteratore principale e secondario
    gtk_tree_store_clear (gui_par->cassa_tree_store);                   //ripulisce il tree_store
    for (i=0; i<TAVOLI; i++)                                            //cicla per numero tavolo
    {
        gtk_tree_store_append(gui_par->cassa_tree_store, &it,NULL);     //aggiunge le righe di dettaglio riferite ai tavoli
        gtk_tree_store_set(gui_par->cassa_tree_store, &it, 0, gui_par->scontrini[i].id, 1,gui_par->scontrini[i].num_ord,
                                                           2, "_______________",
                                                           3, "_________________________",
                                                           4, "_______________",
                                                           5, "_______________",
                                                           6, "_______________",
                                                           -1);

        if (gui_par->scontrini[i].num_ord>0)                            //se il numero di ordini relativo al tavolo corrente è maggiore di 0
        {
            for (j=0;j<gui_par->scontrini[i].num_ord; j++)              //cicla per numero di ordine
            {
                /*prepara i valori contenuti nell'ordine per la visualizzazione nell'albero */
                sprintf(id_piatto,"%6d",gui_par->scontrini[i].ordini[j].id_piatto);
                sprintf(porzioni,"%6d",gui_par->scontrini[i].ordini[j].porzioni);
                sprintf(prezzo_piatto,"%6.2f",gui_par->scontrini[i].ordini[j].prezzo_piatto);
                sprintf(totale_piatto,"%6.2f",gui_par->scontrini[i].ordini[j].prezzo_piatto*gui_par->scontrini[i].ordini[j].porzioni);

                gtk_tree_store_append(gui_par->cassa_tree_store,&it2, &it); //aggiunge una riga di dettaglio secondaria alla riga del tavolo corrente, relativa ad ogni ordine registrato sul tavolo stesso
                gtk_tree_store_set(gui_par->cassa_tree_store, &it2, 0, gui_par->scontrini[i].id,
                                                                    1,gui_par->scontrini[i].ordini[j].id,
                                                                    2, id_piatto,
                                                                    3, gui_par->scontrini[i].ordini[j].nome_piatto,
                                                                    4, porzioni,
                                                                    5, prezzo_piatto,
                                                                    6, totale_piatto,
                                                                    -1);
            }
        }
    }
    gtk_entry_set_text (GTK_ENTRY(gui_par->cassa_seleziona_entry),""); //azzera la entry di selezione tavolo per evitare inserimenti non voluti
}

void stampa_ingredienti (GtkWidget *button, Parametri *gui_par)
{
    /*  La procedura prepara un file di testo che contiene tutti gli ingredienti contenuti nei piatti del menu ed i loro utilizzi
        Il file non è altro che la copia immediatamente leggibile del file archivio ingredienti memorizzato però in formato binario */
    int i,l;
    char nome_ristorante[2*M]={};
    FILE *fp;
    fp=fopen("stampa_ingredienti.txt","w");                                 // apre il file in modalità scrittura
    if (fp==NULL)                                                           // se non riesce ad aprirlo esce dalla procedura
    {
        return;
    }

    /*  Stampa l'intestazione e la riga con le descrizioni */
    fprintf(fp," ______________________________________________ \n");
    fprintf(fp,"|                                              |\n");

    l=(46-strlen(gui_par->myfiles->nome_ristorante))/2;                     //assegna a l il valore della metà degli spazi necessari
    for (i=0;i<l+1;i++)                                                     //riempie di spazi i caratteri che non contengono il nome del ristorante
    {
        nome_ristorante[i]=' ',
        nome_ristorante[45-i]=' ';
    }
    sprintf(nome_ristorante+l+1,"%s",gui_par->myfiles->nome_ristorante);         //scrive il nome del ristorante nel punto calcolato della stringa affinchè risulti centrato
    nome_ristorante[l+strlen(gui_par->myfiles->nome_ristorante)+1]=' ';     //cancella il carattere NULL alla fine della stringa stampata, sostituendolo con uno spazio
    nome_ristorante[46]='\0';                                               //imposta il valore NULL a fine stringa
    fprintf(fp,"|%s|\n",nome_ristorante);

    fprintf(fp,"|                                              |\n");
    fprintf(fp,"|      -> Stampa  utilizzo ingredienti <-      |\n");
    fprintf(fp,"|______________________________________________|\n");
    fprintf(fp,"|  ID | NOME                      | N.UTILIZZI |\n");

    /*  Stampa la riga di dettaglio */
    for (i=0;i<gui_par->myfiles->ing_num_rec;i++)
    {
        fprintf(fp,"|%4d | %-25s | %10d |\n",gui_par->ingredienti[i].id,gui_par->ingredienti[i].nome,gui_par->ingredienti[i].quantita);
    }

    /*  Stampa la parte finale del file */
    fprintf(fp,"|______________________________________________|\n");
    fclose(fp); // e lo chiude

    dialog_info(gui_par->main_win,"L'elenco degli ingredienti\ne' stato stampato"); // avverte l'utente che il file è stato predisposto

    #ifdef _WIN32
    system ("notepad stampa_ingredienti.txt");                                      // e lo apre con il blocco note in windows
    #endif

    #ifdef linux
    system ("leafpad stampa_ingredienti.txt");                                      // e con leafpad in linux
    #endif // linux
}

void stampa_ricerca_su_file (GtkWidget *button, Parametri *gui_par)
{
    /*  procedura per la stampa su file delle ricerche effettuate nella finestra di ricerca e stampa */
    avvia_ricerca(button,gui_par); // chiama la procedura di avvio ricerca
    int i,l;
    char nome_ristorante[M*2]={};
    FILE *fp;
    Tipologia tipo;
    char ricerca[4][N]={},ricercati[4][N]={},tipol[5][12]={"Antipasto", "Primo", "Secondo", "Contorno", "Dessert"}; //predispone vettore di stringhe con tipi piatto

    tipo = gtk_combo_box_get_active(GTK_COMBO_BOX(gui_par->ricerca_combo_tipo));            //legge il valore selezionato nella combo
    sprintf(ricerca[0],"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->ricerca_entry_id)));      //legge il testo contenuto nella entry id
    sprintf(ricerca[1],"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->ricerca_entry_nome)));    //legge il testo contenuto nella entry nome
    normalizza(ricerca[1]);                                                                 // chiama la procedura di normalizzazione del testo
    gtk_entry_set_text (GTK_ENTRY(gui_par->ricerca_entry_nome),ricerca[1]);                 // lo riscrive normalizzato sulla stessa
    if (tipo!=-1)                                                                           // se nella combo è selezionato qualcosa stampa sulla stringa
        {
            sprintf(ricerca[2],"%d",tipo);                                                  // il valore numerico corrispondente
        }
    else
        {
            sprintf(ricerca[2],"%s","\0");                                                  // altrimenti genera una stringa vuota
        }

    sprintf(ricerca[3],"%s",gtk_entry_get_text(GTK_ENTRY(gui_par->ricerca_entry_ingredienti))); // legge il contenuto della entry ingredienti
    normalizza(ricerca[3]);                                                                     // lo normalizza
    gtk_entry_set_text (GTK_ENTRY(gui_par->ricerca_entry_ingredienti),ricerca[3]);              // lo riscrive normalizzato sulla stessa

    /*  apre il file per la scrittura in modalità testo */
    fp=fopen("stampa_ricerca.txt","w");
    if (fp==NULL)                                                                               // verifica corretta apertura
    {
        return;                                                                                 // se il file non viene aperto esce dalla procedura
    }

    /* Scrive l'intestazione della stampa */
    fprintf(fp," ________________________________________________________________________________________________________________________________\n");
    fprintf(fp,"|                                                                                                                                |\n");

    l=(128-strlen(gui_par->myfiles->nome_ristorante))/2;                    //assegna a l il valore della metà degli spazi necessari
    for (i=0;i<l+1;i++)                                                     //riempie di spazi i caratteri che non contengono il nome del ristorante
    {
        nome_ristorante[i]=' ',
        nome_ristorante[127-i]=' ';
    }
    sprintf(nome_ristorante+l+1,"%s",gui_par->myfiles->nome_ristorante);         //scrive il nome del ristorante nel punto calcolato della stringa affinchè risulti centrato
    nome_ristorante[l+strlen(gui_par->myfiles->nome_ristorante)+1]=' ';     //cancella il carattere NULL alla fine della stringa stampata, sostituendolo con uno spazio
    nome_ristorante[129]='\0';                                              //imposta il valore NULL a fine stringa

    fprintf(fp,"|%s|\n",nome_ristorante);
    fprintf(fp,"|                                                        Stampa  Ricerca                                                         |\n");
    fprintf(fp,"|________________________________________________________________________________________________________________________________|\n");
    fprintf(fp,"|ID   | NOME                    | TIPO       | INGREDIENTI                                                               PREZZO  |\n");


    /* Esegue la stampa di dettaglio delle righe estratte con gli stessi parametri di ricerca visualizzati in finestra ricerca e stampa */
    for (i=0;i<gui_par->num_rec;i++)                                        // scorre tutti i piatti
    {
        sprintf(ricercati[0],"%d",gui_par->piatti[i].id);                   // assegna valore id,nome,tipo e prezzo a variabili di comodo
        sprintf(ricercati[1],"%s",gui_par->piatti[i].nome);
        sprintf(ricercati[2],"%d",gui_par->piatti[i].tipo);
        sprintf(ricercati[3],"\t%5.2f",gui_par->piatti[i].prezzo);

        /*  effettua la ricerca nel vettore di strutture, utilizzando la funzione strstr che si presta perfettamente alla bisogna, in quanto se un
            campo di ricerca è una stringa nulla strstr mi restituisce !=NULL qualsiasi cosa trovi; se invece la stringa di ricerca contiene qualcosa
            la strstr mi restituisce NULL solo se non trova la stringa cercata neanche come parte della stringa su cui effettua la ricerca. Il fatto che
            i termini di ricerca siano normalizzati (prima lettera maiuscola e tutte le altre minuscole) fa si che la ricerca dia esito positivo solo come
            parte iniziale della stringa */
        if(strstr(ricercati[0],ricerca[0])!=NULL && strstr(ricercati[1],ricerca[1])!=NULL && strstr(ricercati[2],ricerca[2])!=NULL             //parte relativa alla ricerca su id, nome e tipo piatto tutte condizioni da virificarsi contemporaneamente
           && (strstr(gui_par->piatti[i].ingredienti[0],ricerca[3])!=NULL || strstr(gui_par->piatti[i].ingredienti[1],ricerca[3])!=NULL        //parte relativa agli ingredienti in cui basta che uno dei tre sia TRUE per rendere TRUE tutto il contenuto della parentesi
              || strstr(gui_par->piatti[i].ingredienti[2],ricerca[3])!=NULL))
        {
            /*stampa sul file il piatto che verifica i termini della ricerca */
            fprintf(fp,"|%4d |%-25s|%-12s|%-24s|%-24s|%-24s|  %6.2f|\n",gui_par->piatti[i].id, gui_par->piatti[i].nome, tipol[gui_par->piatti[i].tipo],
                        gui_par->piatti[i].ingredienti[0], gui_par->piatti[i].ingredienti[1],
                        gui_par->piatti[i].ingredienti[2],gui_par->piatti[i].prezzo);
        }
    }
    /* Stampa riga finale del file */
    fprintf(fp,"|________________________________________________________________________________________________________________________________|\n");
    fclose(fp); // chiude il file

    dialog_info(gui_par->ricerca_win,"I risultati della tua ricerca \nsono stati stampati"); // mostra ll'utente un messaggio di conferma

    #ifdef _WIN32
    system ("notepad stampa_ricerca.txt");      // visualizza il file con il blocco note in windows
    #endif

    #ifdef linux
    system ("leafpad stampa_ricerca.txt");      // visualizza il file con leafpad in linux
    #endif // linux
}

void allinea_ingredienti (Parametri *gui_par)
{
    /*  Verifica che tutti gli ingredienti contenuti nei piatti in archivio siano presenti anche nel
        file degli ingredienti. Tale controllo viene fatto per aggiornare l'archivio ingredienti
        quando viene reinizializzato */
    int i,j;
    for (i=0; i<gui_par->myfiles->num_rec; i++)
    {
        for (j=0; j<3; j++)
        {
            controllo_ingredienti(gui_par->piatti[i].ingredienti[j],gui_par);
        }
    }
}

void cassa_quantita_piu(GtkWidget *button, Parametri *gui_par)
{
    /* Incrementa il valore contenuto nella entry relativa al numero di porzioni da inserire nell'ordine */
    char quantita[N];
    int n= atoi(gtk_entry_get_text(GTK_ENTRY(gui_par->cassa_quantita_entry)));  //legge il valore numerico contenuto nella entry
    n++;                                                                        // lo incrementa di 1
    sprintf(quantita,"%d",n);                                                   // prepara una stringa con le cifre di tale numero
    gtk_entry_set_text (GTK_ENTRY(gui_par->cassa_quantita_entry),quantita);     // setta il testo della entry con la stringa predisposta in precedenza
}


void cassa_quantita_meno(GtkWidget *button, Parametri *gui_par)
{
    /* Decrementa il valore contenuto nella entry relativa al numero di porzioni da inserire nell'ordine */
    char quantita[N];
    int n= atoi(gtk_entry_get_text(GTK_ENTRY(gui_par->cassa_quantita_entry)));  //legge il valore numerico contenuto nella entry
    if (n > 1)                                                                  // se è maggiore di 1 lo decrementa
    {
        n--;
        sprintf(quantita,"%d",n);                                               // prepara una stringa con le cifre di tale numero
        gtk_entry_set_text (GTK_ENTRY(gui_par->cassa_quantita_entry),quantita); // setta il testo della entry con la stringa predisposta in precedenza
    }
}


void stampa_scontrino (GtkWidget * button , Parametri * gui_par)
{
    int id=-1;
    int presenza_tipo[5]={};                                                     // vettore di interi per memorizzare la presenza negli ordini delle tipologie di piatto
    int i,j,n=0,trovato=0,scelta=0,k=0,l=0;
    Ordine *ordini=NULL,cancella={};    // puntatore per il vettore appoggio e struttura vuota per velocizzare la cancellazione degli ordini
    char tipol[5][12]={"Antipasti", "Primi", "Secondi", "Contorni", "Dessert"};  // definisce un vettore di "stringhe" che verrà usato nella stampa dello scontrino
    char nome_ristorante[2*M]={};
    float totale_scontrino=0;
    FILE *fp=NULL;

    /* Controlla che sia presente un valore nella entry di selezione del tavolo, ne verifica l'ammissibilita' e,
        in caso contrario, comunica il da farsi attraverso il dialog_info */
    if(strlen(gtk_entry_get_text(GTK_ENTRY(gui_par->cassa_seleziona_entry)))>0)
    {
        id = atoi(gtk_entry_get_text(GTK_ENTRY(gui_par->cassa_seleziona_entry)));
    }
    else
    {
        dialog_info(gui_par->cassa_main_win, "Occorre selezionare un tavolo\ndalla lista con un click del\ntasto sinistro del mouse...");
        return;
    }
    if (id<0 || id>TAVOLI)
    {
        dialog_info(gui_par->cassa_main_win, "Il valore inserito manualmente\ndeve essere compreso\ntra 0 ed il numero max di tavoli");
        return;
    }

    /* Verifica se per il tavolo slezionato sono presenti ordini e alloca la memoria necessaria per il vettore di appoggio */
    if (gui_par->scontrini[id].num_ord<=0)
    {
        dialog_info(gui_par->cassa_main_win, "Non sono memorizzati ordini \nper questo tavolo!");
        return;
    }
    ordini=(Ordine *) calloc(gui_par->scontrini[id].num_ord,sizeof(Ordine));
    if (ordini==NULL)
    {
        dialog_info(gui_par->cassa_main_win, "Ho problemi di allocazione di memoria\nRiprova...!");
        return;
    }

    gui_par->cassa_i=id;

    /* Raggruppa nel vettore di appoggio le ordinazioni riferite allo stesso piatto, facendo il totale del numero di porzioni.
        Il controllo viene fatto scorrendo tutti gli ordini riferiti al tavolo selezionato e verificando se l'ordine corrente
        si riferisce ad un piatto gia' presente nel vettore appoggio: se e' presente si somma il numero di porzioni, altrimenti
        si aggiunge al vettore appoggio (la variabile n contiene il numero di ordinazioni nel vettore appoggio)*/
    for (i=0; i<gui_par->scontrini[id].num_ord; i++)
    {
        trovato=0;
        for (j=0; j<n; j++)
        {
            if (gui_par->scontrini[id].ordini[i].id_piatto==ordini[j].id_piatto)
            {
                (ordini[j].porzioni)+=(gui_par->scontrini[id].ordini[i].porzioni);
                trovato=1;
            }
        }
        if (trovato==0)
        {
            ordini[n]=gui_par->scontrini[id].ordini[i];
            n++;
        }
    }

	/* Verifica la presenza dei tipi di piatto e ne calcola il numero */
    for (i=0; i<n; i++)
    {
        for (j=0; j<5; j++)
        {
            if(ordini[i].tipo_piatto==j)
            {
                presenza_tipo[j]++;
                break; // evita di continuare la verifica se e' stato gia' trovato il tipo corrispondente
            }
        }
    }
    /* Calcola il totale dello scontrino (senza applicare ancora lo sconto) */
    for (i=0; i<n; i++)
    {
        totale_scontrino+=ordini[i].prezzo_piatto*ordini[i].porzioni;
    }

    gui_par->scontrini[id].prezzo_totale=totale_scontrino; // assegno il totale calcolato al campo della struttura, predisposto come da specifiche di progetto


    /* Stampa scontrino */
    fp=fopen("stampa_scontrino.txt","w");
    if (fp==NULL)
    {
        return;
    }
    fprintf(fp," _____________________________________________\n");
    fprintf(fp,"|                                             |\n");

    l=(44-strlen(gui_par->myfiles->nome_ristorante))/2;                     //assegna a l il valore della metà degli spazi necessari
    for (i=0;i<l+1;i++)                                                     //riempie di spazi i caratteri che non contengono il nome del ristorante
    {
        nome_ristorante[i]=' ',
        nome_ristorante[44-i]=' ';
    }
    sprintf(nome_ristorante+l+1,"%s",gui_par->myfiles->nome_ristorante);         //scrive il nome del ristorante nel punto calcolato della stringa affinchè risulti centrato
    nome_ristorante[l+strlen(gui_par->myfiles->nome_ristorante)+1]=' ';     //cancella il carattere NULL alla fine della stringa stampata, sostituendolo con uno spazio
    nome_ristorante[45]='\0';                                               //imposta il valore NULL a fine stringa
    fprintf(fp,"|%s|\n",nome_ristorante);

    fprintf(fp,"|                 Tavolo %3d                  |\n",id);
    fprintf(fp,"|_____________________________________________|\n");
    fprintf(fp,"|                                             |\n");

    /* Effettua la stampa delle righe di dettaglio dello scontrino solo se sono
        presenti piatti della categoria corrente */
    for (i=0;i<5;i++)
    {
        if (presenza_tipo[i]>0)
        {
            fprintf(fp,"| %-43s |\n",tipol[i]);
            fprintf(fp,"|                                             |\n");
            for(j=0;j<n;j++)
            {
                if (ordini[j].tipo_piatto==i)
                {
                    fprintf(fp,"|-%3d x %-26s %9.2f €|\n",ordini[j].porzioni,ordini[j].nome_piatto,ordini[j].prezzo_piatto*ordini[j].porzioni);
                }
            }
            fprintf(fp,"|                                             |\n");
        }
    }
    /* Stampa gli importi parziale e totale e l'eventuale sconto se parziale > 40 euro */
    fprintf(fp,"|_____________________________________________|\n");
    fprintf(fp,"|                                             |\n");
    fprintf(fp,"| Importo parziale%26.2f €|\n",totale_scontrino);
    fprintf(fp,"|                                             |\n");
    if (totale_scontrino>40.0)
    {
        fprintf(fp,"| Sconto (10%%) %29.2f €|\n",totale_scontrino/10);
        fprintf(fp,"|                                             |\n");
        fprintf(fp,"| Importo totale%28.2f €|\n",totale_scontrino*0.9);
        fprintf(fp,"|_____________________________________________|\n");

        /* Aggiorna il totale scontrino se e' applicabile lo sconto */
        totale_scontrino*=0.9;
        gui_par->scontrini[id].prezzo_totale=totale_scontrino; // assegno il totale calcolato al campo della struttura, predisposto come da specifiche di progetto
    }
    else
    {
        fprintf(fp,"|                                             |\n");
        fprintf(fp,"| Importo totale%28.2f €|\n",totale_scontrino);
        fprintf(fp,"|_____________________________________________|\n");
    }
        fprintf(fp,"\n                          Grazie e Arrivederci.");

    fclose(fp);


    /* Apre il file della stampa per un controllo finale */
    #ifdef _WIN32
    system ("notepad stampa_scontrino.txt");
    #endif

    #ifdef linux
    system ("leafpad stampa_scontrino.txt");
    #endif // linux

    /* Chiede conferma prima di effettuare le operazioni di aggiornamento degli archivi */
    scelta=dialog_scelta(gui_par->main_win,"Confermi che la stampa dello scontrino\n e' avvenuta correttamente?\n(Saranno cancellati i relativi ordini)","Richiesta Conferma");
    if (scelta)
    {
        /* Aggiornamento quantita' ingredienti nel vettore degli ingredienti  */
        for(i=0;i<n;i++) //cicla gli ordini
        {
            for (j=0; j<gui_par->myfiles->ing_num_rec; j++) //cicla gli ingredienti del file archivio
            {
                for (k=0;k<3;k++) //cicla i tre ingredienti di ogni piatto ordinato
                {
                    if (!strcmp(ordini[i].ingredienti[k],gui_par->ingredienti[j].nome)) //confronta gli ingredienti da 0 a 2 dell'i-esimo ordine con l'ingrediente j-esimo dell'archivio
                    {
                        gui_par->ingredienti[j].quantita+=ordini[i].porzioni;   //se corrispondono aggiunge all'ingrediente il valore corrispondente al numero di porzioni dell'ordine
                    }
                }

            }
        }

        /* Scrittura del vettore ingredienti aggiornato nel file archivio ingredienti */
        fp=fopen("arch_ingred.dat","wb");
        if (fp==NULL)                                       // nel caso non riesca ad aprire il file avverte l'utente
        {
            dialog_info(gui_par->main_win,"Non riesco ad aggiornare il file \ndegli ingredienti!");
            return;
        }
        fwrite(gui_par->ingredienti,sizeof(Ingrediente),gui_par->myfiles->ing_num_rec,fp);
        fclose(fp);

        /* Cancellazione ordini del tavolo per cui si e' stampato lo scontrino */
        for(i=0; i<gui_par->scontrini[id].num_ord; i++)
        {
            gui_par->scontrini[id].ordini[i]=cancella;
        }
        gui_par->scontrini[id].num_ord=0;
        gui_par->scontrini[id].prezzo_totale=0;
        cassa_aggiorna(gui_par);                        //aggiorna la visualizzazione della finestra cassa

        /* Aggiornamento file totale scontrini */
        fp=fopen("totale_scontrini.txt","w");
        if (fp==NULL)                                   // nel caso non riesca ad aprire il file avverte l'utente
        {
            dialog_info(gui_par->main_win,"Non riesco ad aggiornare il file \ndel totale degli scontrini!");
            return;
        }
        /* Aggiorna il totale degli scontrini in memoria sommandoci il totale scontrino attuale */
        gui_par->myfiles->totale_scontrini+=totale_scontrino;
        /* Sovrascrive il file con il valore attuale ed una breve frase descrittiva */
        fprintf(fp,"%.2f",gui_par->myfiles->totale_scontrini);
        fprintf(fp,"%s"," € (somma dei totali degli scontrini emessi)");
        fclose(fp);
    }
}


void visualizza_file_scontrini(GtkWidget *button,Parametri *gui_par)
{
    /* Apre il file contenente il totale degli scontrini emessi, utilizzando blocco note in windows e leafpad in linux */
    #ifdef _WIN32
    system ("notepad totale_scontrini.txt");
    #endif

    #ifdef linux
    system ("leafpad totale_scontrini.txt");
    #endif // linux
}


void esci_da_ricerca (GtkWidget *button,Parametri *gui_par)
{
    gtk_widget_destroy(gui_par->ricerca_win);
}

void help ()
{
    /* Apre il file help.html con il default broser in windows e con chromium in linux */
    #ifdef _WIN32
    system("help.html");
    #endif //windows

    #ifdef linux
    system ("chromium-browser help.html");
    #endif // linux

}





## Relazione

Le hash table sono state usate per l'intera gestione del grafo.
Il grafo è composto da una hash table principale che contiene tutti i nodi.
I nodi costituiscono le chiavi e il valore a loro associato è una hash table contenente i nodi adiacenti.
Ogni arco è memorizzato come coppia (nodo destinazione , etichetta).
Data la consegna, il valore associato all'arco non può che essere un'etichetta, ma nulla vieta di modificare la libreria per far diventare l'etichetta un puntatore ad una struttura dati, a scelta del utilizzatore della libreria, che contiene informazioni riguardanti l'arco.
Un'altra scelta implementativa importante riguarda il grafo non diretto, quando si inserisce un arco, sia l'arco nodo1->nodo2 che nodo2->nodo1 verranno salvati dalla funzione add_edge e restituiti dalla funzione get_edges (la funzione num_edges infatti restituirà il doppio del numero di archi).
---
I tempi di esecuzione della visita in ampiezza del grafo ricavato da italian_dist_graph.
Da tutti i nodi di partenza esaminati i tempi di esecuzione sono nel range di : 0.014-0.020 secondi.
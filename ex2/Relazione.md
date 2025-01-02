# Relazione Esercizio 2 - Edit distance

Ai fini della risoluzione dell'esercizio abbiamo implementato due funzioni ricorsive: edit_distance (inefficiente per stringhe lunghe) e edit_distance_dyn (che adotta una strategia di programmazione dinamica).

### edit_distance
La funzione edit_distance calcola e restituisce la distanza di edit tra due stringhe, cioè il numero minimo di operazioni (inserimento o cancellazione di caratteri) necessarie per trasformare una stringa nell'altra.
Nello specifico le stringhe vengono confrontate, carattere per carattere, eseguendo tre possibili operazioni: nessuna operazione in caso di caratteri uguali, cancellazione dalla seconda stringa e inserimento nella seconda stringa.
La funzione **rest** viene utilizzata per ottenere una sottostringa senza il primo carattere, facilitando il calcolo ricorsivo.

### edit_distance_dyn
La funzione edit_distance_dyn migliora l'efficienza della funzione originale utilizzando una matrice per memorizzare i risultati intermedi. 
La matrice tiene traccia della distanza di edit tra tutte le sottostringhe di s1 e s2. Ogni elemento della matrice viene calcolato come il minimo tra tre possibili operazioni (nessuna operazione, cancellazione e inserimento), basandosi sui risultati precedenti. 
Questo approccio riduce il tempo di esecuzione da esponenziale a quadratico, risultando molto più efficiente.

## Risultati
La prima soluzione, naif (ingenua), risulta essere estremamente lenta nel calcolare l'edit distance quando sono presenti tante stringhe nel dizionario.
Utilizzando dizionario e file da correggere forniti, rispettivamente di 661562 e 49 stringhe, i risultati sono i seguenti:
- **naif**: dopo 10 minuti di esecuzione il programma avrà restituito solo il risultato della comparazione della prima stringa del file da correggere con tutto il dizionario
- **programmazione dinamica**: 1 minuto e 17 secondi

In caso di modifica dei file `dictionary.txt` e `correctme.txt`, riducendo significativamente il numero di stringhe, si ottengono risultati migliori con la versione naif.
La differenza però di tempo tra le due versioni è abissale:
con un dizionario di 20000 stringhe e un file da correggere di 20 stringhe, il programma utilizzando la funzione **naif** impiega 6.38 secondi mentre con la funzione con **programmazione dinamica** 0.39 secondi.

I test sono stati effettuati con il seguente hardware: Ryzen 5 5500U, scheda grafica integrata, 8gb ram, 256gb ssd

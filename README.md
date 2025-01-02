# Laboratorio per il corso di Algoritmi e Strutture Dati: regole d'esame, indicazioni generali e suggerimenti, consegne per gli esercizi

# Regole d'esame


## Studenti e studentesse di anni precedenti il 2024/2025

Gli studenti e le studentesse iscritti al secondo anno in un anno accademico precedente il 2024/2025 **possono** svolgere il laboratorio secondo:
-  le presenti specifiche

o, in alternativa e **entro e non oltre l'appello di settembre 2025**,

- le specifiche dell'anno accademico 2023/2024:
> [https://gitlab2.educ.di.unito.it/audrito/laboratorio-algoritmi-2023-2024](https://gitlab2.educ.di.unito.it/audrito/laboratorio-algoritmi-2023-2024)

Agli studenti che non hanno ancora cominciato a svolgere gli esercizi 3 o 4 delle precedenti specifiche è comunque consigliato di rifarsi alle specifiche nuove.

## Studenti e studentesse con Algoritmi non di 9 CFU

Gli studenti e le studentesse che hanno nel piano di studi l'insegnamento di Algoritmi con un numero di CFU **differente da 9** sono pregati di contattare il docente al più presto, al fine di concordare un programma d'esame commisurato ai CFU.

## Gruppi di laboratorio e turni

Il progetto di laboratorio può essere svolto individualmente o in gruppo (al più 3 persone). **I membri di uno stesso gruppo devono appartenere tutti allo stesso turno di laboratorio**.

Uno studente o una studentessa, assegnato/a al Turno X può spostarsi al Turno Y, **a patto che trovi un/a collega del turno Y che accetta di spostarsi al turno X**. La richiesta di spostamento deve essere inoltrata via email ai docenti di laboratorio, da parte di una persona che intende effettuare lo scambio, mettendo in cc la persona disposta allo scambio inverso ed entrambi i docenti coinvolti. Lo scambio si intende effettuato solo a seguito di esplicita autorizzazione (via email) da parte dei docenti.
E' possibile effettuare un solo spostamento di turno durante uno stesso anno accademico.
I docenti si riservano di respingere le richieste di spostamento che non dovessero pervenire con congruo anticipo (min. 1 mese) rispetto alla data dello scritto che si intende sostenere.

## Esame complessivo

Come specificato nella descrizione ufficiale dell'insegnamento (https://laurea.informatica.unito.it/do/corsi.pl/Show?_id=iw3r):

L'esame di Algoritmi e strutture dati consiste in una prova scritta, somministrata mediante la piattaforma Esami, ed in una discussione orale del progetto di laboratorio. Il superamento dello scritto permette di accedere alle prove orali della sessione in cui è stato superato lo scritto. Nel caso in cui questa seconda prova non venga superata entro i termini della sessione, lo scritto dovrà essere ripetuto. Il voto sarà la media pesata dei voti ottenuti nelle due prove scritta ed orale [in base ai crediti associati alle parti di teoria (6 CFU) e di laboratorio (3 CFU), nella media lo scritto peserà 6 e l'orale 3], valutate in 30+1 esimi, essendo comunque necessario il raggiungimento della sufficienza in entrambe le prove.

## Consegna del progetto e discussione orale

Il  progetto di laboratorio va consegnato mediante Git (vedi sotto) entro e non oltre la data della prova scritta che si intende sostenere. E' vietato sostenere la prova scritta in caso di mancata consegna del progetto di laboratorio.

La prova orale può essere sostenuta solo dopo il superamento della prova scritta.

In caso di superamento della prova scritta, la prova orale (discussione del laboratorio) va sostenuta **nella medesima sessione della prova scritta superata** (si ricorda che le sessioni sono gennaio-febbraio 2025, giugno-luglio 2025, settembre 2025).

Si noti che per quelle sessioni per cui sono previsti due appelli esisteranno due possibilità per la discussione del laboratorio (primo o secondo appello della sessione); per le sessioni in cui è previsto un solo appello, la discussione deve essere effettuata necessariamente in quell'appello.

Esempio (caso di una sessione con 2 appelli):

- la studentessa/lo studente X sostiene la prova scritta nel primo appello di una sessione con 2 appelli;
- la studentessa/lo studente X deve assicurarsi che il progetto su GitLab, alla data della prova scritta che intende sostenere (in questo esempio, quella del primo appello della sessione), sia aggiornato alla versione che vuole presentare al docente di laboratorio;
- se la studentessa/lo studente X supera la prova scritta nel primo appello della sessione, deve (pena la perdita del voto ottenuto nella prova scritta):
-- iscriversi a uno dei due appelli orali della stessa sessione
-- prenotarsi su i-learn in uno degli slot messi a disposizione dal docente del turno di appartenenza
-- sostenere l'orale nello slot temporale prenotato.

Studentesse/studenti diversi, appartenenti allo stesso gruppo di laboratorio , possono sostenere la prova **scritta** nello stesso appello o in appelli diversi. Se studentesse/studenti diversi, appartenenti allo stesso gruppo, superano la prova scritta nello stesso appello, **devono** sostenere l' **orale** nello stesso appello orale. Se studentesse/studenti diversi, appartenenti allo stesso gruppo, superano la prova scritta in appelli diversi, **possono** sostenere l'**orale** in appelli diversi.

Ad esempio, si consideri un gruppo di laboratorio costituito dalle studentesse/dagli studenti X, Y e Z, e si supponga che i soli X e Y sostengano la prova scritta nel primo appello di una sessione con due appelli, X con successo, mentre Y con esito insufficiente. Devono essere rispettate le seguenti condizioni:

- alla data della prova scritta del primo appello della sessione, il progetto di laboratorio del gruppo deve essere aggiornato alla versione che si intende presentare;
- il solo studente X deve sostenere la prova orale nella stessa sessione in cui ha superato lo scritto,  procedendo come indicato nell'esempio riportato sopra, mentre Y e Z sosterranno la discussione quando avranno superato la prova scritta.
- Supponiamo che Y e Z superino la prova scritta nell'appello di una sessione con un solo appello: essi dovranno sostenere la prova orale in quello stesso appello.
- Gli studenti Y e Z dovranno, di norma, discutere la stessa versione del progetto di laboratorio che ha discusso lo studente X; i.e., eventuali modifiche al laboratorio successive alla discussione di X dovranno essere di modesta entità, debitamente documentate (i.e., il log delle modifiche dovrà comparire su GitLab) e motivate.

**Validità del progetto di laboratorio** : le specifiche per il progetto di laboratorio descritte in questo documento resteranno valide fino all'ultimo appello relativo al corrente anno accademico **(vale a dire, quella di settembre 2025)** e non oltre! Gli appelli delle sessioni successive a quella dovranno essere sostenuti sulla base delle specifiche che verranno descritte nella prossima edizione del laboratorio di algoritmi.

# Indicazioni generali e suggerimenti

## Uso di Git

Durante la scrittura del codice è richiesto di usare in modo appropriato il sistema di versioning Git. Questa richiesta implica quanto segue:

- il progetto di laboratorio va inizializzato "clonando" il repository del laboratorio come descritto nel file Git.md;
- come è prassi nei moderni ambienti di sviluppo, è richiesto di effettuare commit frequenti, con un nome significativo. L'ideale è un commit per ogni blocco di lavoro terminato (es. creazione e test di una nuova funzione, soluzione di un baco, creazione di una nuova interfaccia, ...);
- ogni membro del gruppo dovrebbe effettuare il commit delle modifiche che lo hanno visto come principale sviluppatore;
- al termine del lavoro si dovrà consegnare l'intero repository (dandone accesso al docente).

Il file Git.md contiene un esempio di come usare Git per lo sviluppo degli esercizi proposti per questo laboratorio.

---

**Nota importante**: Su git dovrà essere caricato solamente il codice sorgente, in particolare nessun file dati dovrà essere oggetto di commit!

---

Si rammenta che la valutazione del progetto di laboratorio considererà anche l'uso adeguato di git da parte di ciascun membro del gruppo.

## Linguaggio in cui sviluppare il laboratorio

L'intera implementazione del laboratorio deve essere realizzata nel linguaggio C.

Come indicato sotto, alcuni esercizi chiedono di implementare **codice generico**. Con "codice generico" si intende codice che deve poter essere eseguito con tipi di dato non noti a tempo di compilazione.

**Suggerimento per la realizzazione di codice generico in C**: Nel caso del C, è necessario capire come meglio approssimare l'idea di codice generico utilizzando quanto permesso dal linguaggio. Un approccio comune è far sì che le funzioni e le procedure presenti nel codice prendano in input puntatori a `void` e utilizzino qualche funzione fornita dall'utente per accedere alle componenti necessarie (uso di puntatori a funzione).

## Uso di librerie esterne e/o native del linguaggio scelto

È vietato l'uso di strutture dati native del linguaggio scelto o offerte da librerie esterne, quando la loro realizzazione è richiesta da uno degli esercizi proposti.

È, invece, possibile l'uso di strutture dati native del linguaggio o offerte da librerie esterne, se la loro realizzazione non è richiesta da uno degli esercizi proposti.

**Esempio:** l'uso di una libreria C che implementa array dinamici è consentito, solo se nessun esercizio chiede la realizzazione di un array dinamico.

## Relazione sugli esercizi

La relazione, per quegli esercizi che la richiedono, deve essere inserita nel file README.md del progetto, divenendo così parte integrante della documentazione.

## Unit Testing

Come indicato esplicitamente nei testi degli esercizi, il progetto di laboratorio comprende anche la definizione di opportune suite di unit test.

Si rammenta, però, che il focus del laboratorio è l'implementazione di strutture dati e algoritmi. Relativamente agli unit-test sarà quindi sufficiente che gli studenti dimostrino di averne colto il senso e di saper realizzare una suite di test sufficiente a coprire i casi più comuni e i casi limite.

## Qualità dell'implementazione

È parte del mandato degli esercizi la realizzazione di codice di buona qualità.

Per "buona qualità" intendiamo codice ben organizzato, ben modularizzato, ben commentato e ben testato.

**Alcuni suggerimenti:**

- **Importante**: Gli esercizi richiedono (fra le altre cose) di sviluppare codice generico. Nello sviluppare questa parte, si deve assumere di stare sviluppando una libreria generica intesa come fondamento di futuri programmi. Non è pertanto lecito fare assunzioni semplificative; in generale, l'implementazione della libreria generica deve restare separata e non deve essere influenzata in alcun modo dagli usi di essa eventualmente richiesti negli esercizi (ad esempio, se un esercizio dovesse richiedere l'implementazione della struttura dati grafo e quello stesso o un altro esercizio dovesse richiedere l'implementazione, a partire da tale struttura dati, di un algoritmo per il calcolo delle componenti connesse di un grafo, l'implementazione della struttura dati dovrebbe essere separata dall'algoritmo per il calcolo delle componenti connesse e *non* dovrebbe contenere elementi – variabili, procedure, funzioni, definizioni di tipo, ecc. – eventualmente utili a tale algoritmo, ma non essenziali alla struttura dati; analogamente, se un esercizio dovesse richiedere di operare su grafi con nodi di tipo stringa, l'implementazione della struttura dati grafo dovrebbe restare generica e non potrebbe quindi assumere per i nodi il solo tipo stringa).
- verificare che il codice sia suddiviso correttamente in package o moduli;
- aggiungere un commento, prima di una definizione, che spieghi il funzionamento dell'oggetto definito, meglio se in formato [doxygen](https://www.doxygen.nl). Evitare quando possibile di commentare direttamente il codice interno alle funzioni/metodi implementati (se il codice è ben scritto, i commenti in genere non servono);
- la lunghezza di un metodo/funzione è in genere un campanello di allarme: se essa cresce troppo, probabilmente è necessario rifattorizzare il codice spezzando la funzione in più parti. In linea di massima si può consigliare di intervenire quando la funzione cresce sopra le 30 righe (considerando anche commenti e spazi bianchi);
- sono accettabili commenti in italiano, sebbene siano preferibili in inglese;
- tutti i nomi (es., nomi di variabili, di metodi, di classi, ecc.) *devono* essere significativi e in inglese;
- il codice deve essere correttamente indentato; impostare l'indentazione a 2 o 4 caratteri e impostare l'editor in modo che inserisca "soft tabs" (cioè, deve inserire il numero corretto di spazi invece che un carattere di tabulazione);
- per dare i nomi agli identificatori, seguire le convenzioni in uso per il linguaggio C:
  - macro e costanti sono tutti in maiuscolo e in formato snake case (es. THE\_MACRO, THE\_CONSTANT); i nomi di tipo (e.g.  struct, typedefs, enums, ...) iniziano con una lettera maiuscola e proseguono in camel case (e.g., TheType, TheStruct); i nomi di funzione iniziano con una lettera minuscola e proseguono in snake case (e.g., the\_function());
- i file vanno salvati in formato UTF-8.

# Consegne per gli esercizi

In sede di discussione d'esame, sarà facoltà del docente chiedere di eseguire gli algoritmi implementati su dati forniti dal docente stesso. Nel caso questi dati siano memorizzati su file, questi saranno dei csv con la medesima struttura dei dataset forniti e descritti nel testo dell'esercizio. I codici sviluppati dovranno consentire un rapido e semplice adattamento agli input forniti: ad esempio, **una buona implementazione consentirà di inserire in input il nome del file su cui eseguire il test**, mentre una peggiore richiederà di modificare il codice sorgente e una successiva compilazione a fronte della sola modifica del nome del file contenente il dataset.

Per alcune parti degli esercizi sarà anche fornita durante il corso una piattaforma per la valutazione automatica della correttezza del codice prodotto.


## Esercizio 1 - Merge Sort e Quick Sort

### Testo

Implementare una libreria che offre gli algoritmi di ordinamento  *Merge Sort* e *Quick Sort* su dati generici, implementando i seguenti prototipi di funzione:

```
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
```

- `base` è un puntatore al primo elemento dell'array da ordinare;
- `nitems` è il numero di elementi nell'array da ordinare;
- `size` è la dimensione in bytes di ogni elemento dell'array;
- `compar` è il criterio secondo cui ordinare i dati (dati due **puntatori a elementi** dell'array, restituisce un numero maggiore, uguale o minore di zero se il primo argomento è rispettivamente maggiore, uguale o minore del secondo).

È anche possibile implementare in alternativa i seguenti prototipi, che ordinano dati a patto che siano organizzati in un array di puntatori:

```
void merge_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));
void quick_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));
```

- `base` è un puntatore al primo elemento dell'array di puntatori da ordinare sulla base dei valori riferiti;
- `nitems` è il numero di elementi nell'array di puntatori da ordinare;
- `compar` è il criterio secondo cui ordinare i dati (dati due **elementi** dell'array di puntatori).

Dato che la prima versione è anche in grado di ordinare array di puntatori (passando un comparatore opportuno, i cui argomenti saranno puntatori a puntatori ai dati), non serve implementare questa seconda versione se avete già implementato la prima. In ogni caso non serve neanche implementare la prima se avete già implementato la seconda.

### Unit Testing

Implementare gli unit-test per la libreria secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso della libreria di ordinamento implementata

Il file `records.csv` che potete trovare (compresso) all'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/9sQmzB9TdDHezX7](https://datacloud.di.unito.it/index.php/s/9sQmzB9TdDHezX7)

contiene 20 milioni di record da ordinare.
Ogni record è descritto su una riga e contiene i seguenti campi:

- `id`: (tipo intero) identificatore univoco del record;
- `field1`: (tipo stringa) contiene parole estratte dalla divina commedia,
  potete assumere che i valori non contengano spazi o virgole;
- `field2`: (tipo intero);
- `field3`: (tipo floating point).

Il formato è un CSV standard: i campi sono separati da virgole; i record sono
separati da `\n`.

Usando l'algoritmo implementato precedentemente, si realizzi la seguente funzione per ordinare *record* contenuti nel file `records.csv` in ordine non decrescente secondo i valori contenuti nei tre campi "field".

```
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo);
```

- `infile` è il file contenente i record da ordinare;
- `outfile` è il file nel quale salvare i record ordinati (che deve essere diverso da `infile`);
- `field` può valere 1, 2 o 3 e indica quale dei tre campi deve essere usato per ordinare i record.
- `algo` può valere 1 o 2 e indica quale algoritmo di ordinamento deve essere usato (MergeSort o QuickSort) per ordinare i record.

Si misurino i tempi di risposta per i due algoritmi, per ciascuno dei tre field che si possono usare come chiave di ordinamento, e si produca una breve relazione in cui si riportano i risultati ottenuti insieme a un loro commento. Il commento deve essere basato su statistiche numeriche sui tempi di esecuzione misurati. Nel caso l'ordinamento si protragga per più di 10 minuti potete interrompere l'esecuzione e riportare un fallimento dell'operazione. I risultati sono quelli che vi sareste aspettati? Se sì, perché? Se no, fate delle ipotesi circa il motivo per cui gli algoritmi non funzionano come vi aspettate, verificatele e riportate quanto scoperto nella relazione. I risultati dipendono dal campo usato come chiave di ordinamento?

**Si ricorda che il file `records.csv` (e i file compilati) NON DEVONO ESSERE OGGETTO DI COMMIT SU GIT!**

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex1` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile`. Questo file con il comando `make all` deve produrre all'interno di `ex1/bin` due file eseguibili chiamati `main_ex1` e `test_ex1`. Se avete usato librerie esterne (come Unity) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex1` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.
- L'eseguibile `main_ex1` deve ricevere come parametri il percorso del file CSV contenente i record da ordinare, il percorso del file in cui salvare i record ordinati, il valore del campo `field` da utilizzare per l'ordinamento, e l'indicazione dell'algoritmo da utilizzare. Per esempio:

```
$ ./main_ex1 /tmp/data/records.csv /tmp/data/sorted.csv 1 2
```

### Relazione

bin/main_ex1 dataset/records.csv dataset/sorted.csv  1 1

| Number of Records | Merge Sort (String) | Merge Sort (Int) | Merge Sort (Float) | Quick Sort (String) | Quick Sort (Int) | Quick Sort (Float) |
|:-----------------:|---------------------|------------------|--------------------|---------------------|------------------|--------------------|
|       5000        | 0.001               | 0.001            | 0.001              | 0.001               | 0.001            | 0.001              |
|       25000       | 0.006               | 0.004            | 0.005              | 0.007               | 0.003            | 0.004              |
|      100000       | 0.025               | 0.019            | 0.020              | 0.059               | 0.014            | 0.015              |
|      500000       | 0.151               | 0.121            | 0.122              | 1.358               | 0.099            | 0.100              |
|      1000000      | 0.334               | 0.253            | 0.272              | 5.211               | 0.214            | 0.220              |
|      2000000      | 0.744               | 0.563            | 0.599              | 21.905              | 0.492            | 0.483              |
|      3000000      | 1.193               | 0.895            | 0.939              | x                   | 0.775            | 0.765              |
|      4000000      | 1.729               | 1.300            | 1.314              | x                   | 1.105            | 1.119              |
|      5000000      | 2.143               | 1.671            | 1.702              | x                   | 1.455            | 1.459              |
|      7500000      | 3.463               | 2.608            | 2.679              | x                   | 2.306            | 2.301              |
|     10000000      | 4.784               | 3.651            | 3.718              | x                   | 3.179            | 3.158              |
|     12500000      | 6.009               | 4.664            | 4.671              | x                   | 4.174            | 4.129              |
|     15000000      | 7.271               | 5.761            | 5.658              | x                   | 5.199            | 5.135              |
|     17500000      | 8.708               | 6.629            | 6.811              | x                   | 6.174            | 6.094              |
|     20000000      | 10.407              | 7.879            | 7.895              | x                   | 7.134            | 7.120              |

Dai dati si osserva che generalmente il quick sort è più veloce del merge sort, indipendentemente dal numero dei record.
L'unica eccezione riguarda l'ordinamento delle stringhe, che nel caso del quick sort, i tempi di ordinamento crescono più che linearmente. 
Il risultato non è quello che ci si aspettava, sia dal punto di vista dei tempi così distanti, sia da quello di esecuzione, dato che dopo i due milioni di record, durante l'ordinamento, l'esecuzione si blocca.
Il comportamento è anomalo dato che l'esecuzione termina producendo l'output corretto fino ai due milioni di record. Detto ciò un motivo possibile è un problema nell'utilizzo della memoria, che non è stato possibile definire.

Hardware utilizzato per i test : intel i5-1335U , scheda grafica integrata , 16gb ram , 1tb ssd

## Esercizio 2 - Edit distance

### Testo

Si consideri il problema di determinare la minima distanza di edit tra due stringhe (_edit distance_): date due stringhe $s_1$ e $s_2$, non necessariamente della stessa lunghezza, determinare il minimo numero di operazioni necessarie per trasformare la stringa $s_2$ in $s_1$. Si assuma che le operazioni disponibili siano solo due: **cancellazione** e **inserimento**. Per esempio:

- "casa" e "cassa" hanno edit distance pari a 1 (1 cancellazione);
- "casa" e "cara" hanno edit distance pari a 2 (1 cancellazione + 1 inserimento);
- “vinaio” e “vino” hanno edit distance=2 (2 inserimenti);
- "tassa" e "passato" hanno edit distance pari a 4 (3 cancellazioni + 1 inserimento);
- "pioppo" e "pioppo" hanno edit distance pari a 0.

Si implementi innanzitutto una funzione ricorsiva di calcolo della edit distance, implementando il seguente prototipo di funzione:

```
int edit_distance(const char *s1, const char* s2);
```

- `s1` è la stringa che si vuole ottenere $s_1$;
- `s2` è la stringa di partenza $s_2$.

La struttura della funzione deve rispecchiare la seguente definizione (indichiamo con $|s|$ la lunghezza di $s$ e con $\mathrm{rest}(s)$ la sottostringa di $s$ ottenuta ignorando il primo carattere di $s$):

- se $|s_1|$ = 0, allora $\mathrm{edit\_distance}(s_1,s_2) = |s_2|$;
- se $|s_2|$ = 0, allora $\mathrm{edit\_distance}(s_1,s_2) = |s_1|$;
- altrimenti, siano:
  - $d_{\mathrm{no-op}} = \mathrm{edit\_distance}(\mathrm{rest}(s1),\mathrm{rest}(s2))$   se $s1[0]=s2[0]$, $\infty$ altrimenti
  - $d_{\mathrm{canc}} = 1 + \mathrm{edit\_distance}(s1,\mathrm{rest}(s2))$
  - $d_{\mathrm{ins}} = 1 + \mathrm{edit\_distance}(\mathrm{rest}(s1),s2)$

Si ha quindi che: $\mathrm{edit\_distance}(s_1,s_2) = \min\{d_{\mathrm{no-op}}, d_{\mathrm{canc}}, d_{\mathrm{ins}}\}$.

In seguito, si implementi anche una versione della funzione di calcolo della edit distance che adotta una strategia di programmazione dinamica. Tale versione deve essere anch'essa ricorsiva (in particolare, essa deve essere ottenuta attraverso un insieme minimale di modifiche apportate all'implementazione richiesta al punto precedente). La funzione deve implementare il seguente prototipo:

```
int edit_distance_dyn(const char *s1, const char* s2);
```

*Nota*: Le definizioni sopra riportate non corrispondono al modo usuale di definire la distanza di edit. Sono comunque quelle necessarie a risolvere l'esercizio e su cui dovrà essere basato il codice prodotto.

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso delle funzioni implementate

All'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/9BKY7BXFCY4bMcB](https://datacloud.di.unito.it/index.php/s/9BKY7BXFCY4bMcB)

potete trovare un dizionario (`dictionary.txt`) e un file da correggere (`correctme.txt`).

Il dizionario contiene un elenco di parole. Le parole sono scritte di seguito, ciascuna su una riga.

Il file `correctme.txt` contiene un testo da correggere. Alcune parole in questo testo non ci sono nel dizionario.

Si implementi un'applicazione che usa la funzione `edit_distance_dyn` per determinare, per ogni parola `w` in `correctme.txt`, una breve lista di parole in `dictionary.txt` con edit distance minima da `w`. Si sperimenti il funzionamento dell'applicazione e si riporti in una breve relazione i risultati degli esperimenti.

**Si ricorda** che i file `dictionary.txt` e `correctme.txt` non devono essere oggetto di commit su git!

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex2` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile`. Questo file con il comando `make all` deve produrre all'interno di `ex2/bin` due file eseguibili chiamati `main_ex2` e `test_ex2`. Se avete usato librerie esterne (come Unity) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex2` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.
- L'eseguibile `main_ex2` deve ricevere come parametri il percorso del dizionario da usare come riferimento e il file da correggere. Per esempio:

```
$ ./main_ex2 /tmp/data/dictionary.txt /tmp/data/correctme.txt
```

### Relazione


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


## Esercizio 3 - Tavole hash (con concatenamento)


### Testo

Si implementi, avvalendosi del supporto di un sistema basato su un Large Language Model, quale, ad esempio, ChatGPT (si veda sotto), una libreria generica che realizza la struttura dati *tavola hash (con concatenamento)* in grado di ospitare un insieme di coppie {<chiave_1,valore_1>,...,<chiave_n,valore_n>}.

La tavola hash deve accettare chiavi e valori di tipi generici (tutte le chiavi hanno uno stesso tipo, tutti i valori hanno uno stesso tipo, ma chiavi e valori possono avere tipi fra loro differenti).

La struttura dati deve offrire almeno le seguenti funzionalità (ricavare il significato delle varie funzioni e procedure e dei loro parametri a partire dai loro prototipi e da quanto studiato nella parte di teoria del corso):

```
HashTable* hash_table_create(int (*f1)(const void*,const void*), unsigned long (*f2)(const void*));
void hash_table_put(HashTable*, const void*, const void*);
void* hash_table_get(const HashTable*, const void*);
int hash_table_contains_key(const HashTable*, const void*);
void hash_table_remove(HashTable*, const void*);
int hash_table_size(const HashTable*);
void** hash_table_keyset(const HashTable*);
void hash_table_free(HashTable*);
```

### Unit Testing

Implementare avvalendosi del supporto di un sistema basato su un Large Language Model (LLM), quale, ad esempio, ChatGPT (si veda sotto), gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso di sistema basato su un Large Language Model:

Si richiede che per implementare quanto richiesto dal presente esercizio ci si avvalga del supporto di un sistema basato su un Large Language Model, quale, ad esempio, ChatGPT.

E' possibile che il processo di sviluppo risulti iterativo, comportando varie interazioni con il sistema LLM.

Si documenti, in una relazione (README.md su git), il suddetto processo di sviluppo nei suoi aspetti principali (prompt iniziale, output prodotto dal sistema, analisi critica dell'output, raffinamento del prompt, ecc.) e si riportino alcune considerazioni generali sull'intero processo.

### Relazione
## Iterazione 1
### Input
Libreria generica su hash table concatenate e tutte le funzioni da generare, fornite nella consegna
### Output
Libreria completa, fornito il codice dei file ".c" e ".h" commentato.

<details>
  <summary>File hash_table.h</summary>

```
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

// Struttura per i nodi della lista concatenata
typedef struct HashNode {
    void* key;               // Chiave generica
    void* value;             // Valore generico
    struct HashNode* next;   // Puntatore al nodo successivo
} HashNode;

// Struttura per la tavola hash
typedef struct HashTable {
    HashNode** buckets;            // Array di puntatori a nodi
    size_t capacity;               // Numero di bucket
    size_t size;                   // Numero di elementi nella tavola
    int (*compare_keys)(const void*, const void*);   // Funzione di confronto
    unsigned long (*hash_func)(const void*);         // Funzione di hash
} HashTable;

// Prototipi delle funzioni
HashTable* hash_table_create(int (*f1)(const void*, const void*), unsigned long (*f2)(const void*));
void hash_table_put(HashTable*, const void*, const void*);
void* hash_table_get(const HashTable*, const void*);
int hash_table_contains_key(const HashTable*, const void*);
void hash_table_remove(HashTable*, const void*);
int hash_table_size(const HashTable*);
void** hash_table_keyset(const HashTable*);
void hash_table_free(HashTable*);

#endif // HASH_TABLE_H
```
</details>

<details>
  <summary>File: hash_table.c</summary>

```
#include "hash_table.h"
#include <string.h>

// Funzione di creazione della tavola hash
HashTable* hash_table_create(int (*f1)(const void*, const void*), unsigned long (*f2)(const void*)) {
HashTable* table = malloc(sizeof(HashTable));
table->capacity = 16; // Capacità iniziale
table->size = 0;
table->buckets = calloc(table->capacity, sizeof(HashNode*));
table->compare_keys = f1;
table->hash_func = f2;
return table;
}

// Funzione per inserire un elemento
void hash_table_put(HashTable* table, const void* key, const void* value) {
unsigned long hash = table->hash_func(key) % table->capacity;
HashNode* current = table->buckets[hash];

    // Cerca se la chiave esiste già
    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            current->value = (void*)value; // Aggiorna il valore
            return;
        }
        current = current->next;
    }

    // Altrimenti, aggiunge un nuovo nodo
    HashNode* new_node = malloc(sizeof(HashNode));
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[hash];
    table->buckets[hash] = new_node;
    table->size++;
}

// Funzione per ottenere un valore
void* hash_table_get(const HashTable* table, const void* key) {
unsigned long hash = table->hash_func(key) % table->capacity;
HashNode* current = table->buckets[hash];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL; // Chiave non trovata
}

// Funzione per verificare la presenza di una chiave
int hash_table_contains_key(const HashTable* table, const void* key) {
return hash_table_get(table, key) != NULL;
}

// Funzione per rimuovere un elemento
void hash_table_remove(HashTable* table, const void* key) {
unsigned long hash = table->hash_func(key) % table->capacity;
HashNode* current = table->buckets[hash];
HashNode* prev = NULL;

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[hash] = current->next;
            }
            free(current);
            table->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Funzione per ottenere il numero di elementi
int hash_table_size(const HashTable* table) {
return table->size;
}

// Funzione per ottenere tutte le chiavi
void** hash_table_keyset(const HashTable* table) {
void** keys = malloc(table->size * sizeof(void*));
size_t index = 0;

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            keys[index++] = current->key;
            current = current->next;
        }
    }
    return keys;
}

// Funzione per liberare la memoria
void hash_table_free(HashTable* table) {
for (size_t i = 0; i < table->capacity; i++) {
HashNode* current = table->buckets[i];
while (current) {
HashNode* temp = current;
current = current->next;
free(temp);
}
}
free(table->buckets);
free(table);
}
```
</details>

Da notare che nel input fornito la funzione di creazione della hash table non aveva dei parametri con un nome esplicativo, il LLM gli ha dato la giusta interpretazione.
Il codice fornito soddisfa le richieste della traccia, anche se è possibile notare :

- una mancanza di gestione degli errori
- una capacità iniziale, alla creazione della hash table che non puoi scegliere
- una possibile cattiva gestione della memoria dovuta al free che non libera la memoria occupata dai valori (<chiave,valore>) e anche della chiave (es. una coppia <struct,struct>)
---
## Iterazione 2
Dati i possibili errori, chiedo in maniera generica come sarebbe possibile migliorare la libreria appena generata.
### Input
Come miglioreresti il codice sopra fornito?
### Output
Come notato alla fine della prima iterazione, il LLM ha dato suggerimenti su:
- Gestione della memoria: Supporto opzionale per liberare la memoria delle chiavi e dei valori.
- Gestione della capacità: Ridimensionamento automatico per mantenere un buon fattore di carico ed evitare il degrado delle prestazioni.
- Error handling: Restituire valori indicativi per verificare errori o stati della struttura.

__Nuovo file header :__

<details>
  <summary>File hash_table.h</summary>

```
// Struttura modificata
typedef struct HashTable {
    HashNode** buckets;                       // Array di bucket
    size_t capacity;                          // Numero di bucket
    size_t size;                              // Numero di elementi
    int (*compare_keys)(const void*, const void*);   // Funzione di confronto
    unsigned long (*hash_func)(const void*);         // Funzione di hash
    void (*free_key)(void*);                  // Funzione opzionale per liberare le chiavi
    void (*free_value)(void*);                // Funzione opzionale per liberare i valori
} HashTable;

// Funzioni principali
HashTable* hash_table_create(
    int (*compare_keys)(const void*, const void*), 
    unsigned long (*hash_func)(const void*), 
    void (*free_key)(void*), 
    void (*free_value)(void*)
);

int hash_table_put(HashTable*, const void* key, const void* value); // Restituisce 0 se OK, -1 se errore
void* hash_table_get(const HashTable*, const void* key);            // Valore o NULL se non trovato
int hash_table_contains_key(const HashTable*, const void* key);     // 1 se trovato, 0 altrimenti
int hash_table_remove(HashTable*, const void* key);                 // 0 se OK, -1 se errore
size_t hash_table_size(const HashTable*);                           // Numero di elementi
void** hash_table_keyset(const HashTable*, size_t* count);          // Array di chiavi
void hash_table_resize(HashTable*);                                 // Ridimensiona dinamicamente
void hash_table_free(HashTable*);                                   // Libera memoria
```
</details>

__Funzioni modificate :__
<details>
  <summary>hash_table_create</summary>

```
HashTable* hash_table_create(
    int (*compare_keys)(const void*, const void*), 
    unsigned long (*hash_func)(const void*), 
    void (*free_key)(void*), 
    void (*free_value)(void*)
) {
    HashTable* table = malloc(sizeof(HashTable));
    table->capacity = 16;
    table->size = 0;
    table->buckets = calloc(table->capacity, sizeof(HashNode*));
    table->compare_keys = compare_keys;
    table->hash_func = hash_func;
    table->free_key = free_key;
    table->free_value = free_value;
    return table;
}
```
</details>
<details>
  <summary>hash_table_put</summary>

```
int hash_table_put(HashTable* table, const void* key, const void* value) {
    if ((float)table->size / table->capacity > 0.75) {
        hash_table_resize(table);
    }

    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (table->free_value) {
                table->free_value(current->value);
            }
            current->value = (void*)value;
            return 0;
        }
        current = current->next;
    }

    HashNode* new_node = malloc(sizeof(HashNode));
    if (!new_node) return -1; // Errore di allocazione
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[hash];
    table->buckets[hash] = new_node;
    table->size++;
    return 0;
}
```
</details>
<details>
  <summary>hash_table_resize</summary>

```
void hash_table_resize(HashTable* table) {
    size_t new_capacity = table->capacity * 2;
    HashNode** new_buckets = calloc(new_capacity, sizeof(HashNode*));

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            unsigned long new_hash = table->hash_func(current->key) % new_capacity;

            HashNode* next = current->next;
            current->next = new_buckets[new_hash];
            new_buckets[new_hash] = current;

            current = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;
}
```
</details>
<details>
  <summary>hash_table_remove</summary>

```
int hash_table_remove(HashTable* table, const void* key) {
    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];
    HashNode* prev = NULL;

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[hash] = current->next;
            }

            if (table->free_key) {
                table->free_key(current->key);
            }
            if (table->free_value) {
                table->free_value(current->value);
            }

            free(current);
            table->size--;
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return -1; // Chiave non trovata
}
```
</details>
<details>
  <summary>hash_table_free</summary>

```
void hash_table_free(HashTable* table) {
    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            HashNode* temp = current;
            if (table->free_key) {
                table->free_key(temp->key);
            }
            if (table->free_value) {
                table->free_value(temp->value);
            }
            current = current->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}
```
</details>

Tutte le modifiche che dovevano essere apportate al codice sono state segnalate e i problemi trovati alla fine della prima iterazione sono stati risolti.
Tuttavia la possibilità di inizializzare la capacità della hash table e avere la capacità fissa (togliere il ridimensionamento automatico), sono delle caratteristiche fondamentali per una libreria generica.
---
## Iterazione 3

### Input
Potresti aggiungere la possibilità di scegliere un valore iniziale di capacità e di non permettere il suo ampliamento?
### Output
__Modifiche apportate :__
<details>
  <summary>Struct HasteTable</summary>

```
typedef struct HashTable {
    HashNode** buckets;                       // Array di bucket
    size_t capacity;                          // Numero di bucket
    size_t size;                              // Numero di elementi
    int allow_resize;                         // Flag per consentire il ridimensionamento
    int (*compare_keys)(const void*, const void*);   // Funzione di confronto
    unsigned long (*hash_func)(const void*);         // Funzione di hash
    void (*free_key)(void*);                  // Funzione opzionale per liberare le chiavi
    void (*free_value)(void*);                // Funzione opzionale per liberare i valori
} HashTable;
```
</details>
<details>
  <summary>hash_table_create</summary>

```
HashTable* hash_table_create(
    int (*compare_keys)(const void*, const void*), 
    unsigned long (*hash_func)(const void*), 
    void (*free_key)(void*), 
    void (*free_value)(void*), 
    size_t initial_capacity, 
    int allow_resize
) {
    if (initial_capacity == 0) {
        initial_capacity = 16; // Capacità predefinita
    }

    HashTable* table = malloc(sizeof(HashTable));
    table->capacity = initial_capacity;
    table->size = 0;
    table->buckets = calloc(table->capacity, sizeof(HashNode*));
    table->compare_keys = compare_keys;
    table->hash_func = hash_func;
    table->free_key = free_key;
    table->free_value = free_value;
    table->allow_resize = allow_resize;
    return table;
}
```
</details>
<details>
  <summary>hash_table_put</summary>

```
int hash_table_put(HashTable* table, const void* key, const void* value) {
    if (table->allow_resize && (float)table->size / table->capacity > 0.75) {
        hash_table_resize(table);
    } else if (!table->allow_resize && table->size >= table->capacity) {
        return -1; // Errore: capacità massima raggiunta
    }

    unsigned long hash = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[hash];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (table->free_value) {
                table->free_value(current->value);
            }
            current->value = (void*)value;
            return 0;
        }
        current = current->next;
    }

    HashNode* new_node = malloc(sizeof(HashNode));
    if (!new_node) return -1; // Errore di allocazione
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[hash];
    table->buckets[hash] = new_node;
    table->size++;
    return 0;
}
```
</details>
<details>
  <summary>hash_table_resize</summary>

```
void hash_table_resize(HashTable* table) {
    if (!table->allow_resize) return; // Non ridimensionare se il flag è disabilitato

    size_t new_capacity = table->capacity * 2;
    HashNode** new_buckets = calloc(new_capacity, sizeof(HashNode*));

    for (size_t i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            unsigned long new_hash = table->hash_func(current->key) % new_capacity;

            HashNode* next = current->next;
            current->next = new_buckets[new_hash];
            new_buckets[new_hash] = current;

            current = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;
}
```
</details>

Le modifiche sono corrette, ma ha imposto un limite di elementi inseribili nel caso di hash table non ridimensionabile. Tenere in considerazione il fattore di carico (size/capacity) è giusto, ma è compito del programmatore non sovraccaricare la hash table. Inoltre vorresti avere la possibilità di modificare la capacità a una quantità desiderata in qualsiasi momento.

---
## Iterazione 4

### Input
Puoi scrivere la libreria togliendo il limite di elementi che puoi aggiungere in base alla capacità(nella funzione put) e inserire una funzione che ti permetta in qualsiasi momento di modificare la capacità?
### Output
<details>
  <summary>File hash_table.h</summary>

```
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <stdbool.h>

// Nodo della lista concatenata per un bucket
typedef struct HashNode {
    void* key;
    void* value;
    struct HashNode* next;
} HashNode;

// Struttura principale della hash table
typedef struct HashTable {
    HashNode** buckets;               // Array di bucket
    int capacity;                     // Numero di bucket
    int size;                         // Numero di elementi attualmente presenti
    bool allow_resize;                // Consente il ridimensionamento
    int (*compare_keys)(const void*, const void*);
    unsigned long (*hash_func)(const void*);
    void (*free_key)(void*);
    void (*free_value)(void*);
} HashTable;

// Funzioni principali
HashTable* hash_table_create(
    int initial_capacity,
    bool allow_resize,
    int (*compare_keys)(const void*, const void*),
    unsigned long (*hash_func)(const void*),
    void (*free_key)(void*),
    void (*free_value)(void*)
);

int hash_table_put(HashTable* table, const void* key, const void* value);
void* hash_table_get(const HashTable* table, const void* key);
int hash_table_contains_key(const HashTable* table, const void* key);
void hash_table_remove(HashTable* table, const void* key);
int hash_table_size(const HashTable* table);
void** hash_table_keyset(const HashTable* table);
void hash_table_free(HashTable* table);

// Nuova funzione: Ridimensionamento forzato della tabella
int hash_table_resize_to(HashTable* table, int new_capacity);

#endif // HASH_TABLE_H
```
</details>

<details>
  <summary>File hash_table.c</summary>

```
#include "hash_table.h"
#include <string.h>
#include <stdio.h>

// Funzione per creare una nuova hash table
HashTable* hash_table_create(
    int initial_capacity,
    bool allow_resize,
    int (*compare_keys)(const void*, const void*),
    unsigned long (*hash_func)(const void*),
    void (*free_key)(void*),
    void (*free_value)(void*)
) {
    if (initial_capacity <= 0 || !compare_keys || !hash_func) {
        return NULL;
    }

    HashTable* table = malloc(sizeof(HashTable));
    if (!table) return NULL;

    table->capacity = initial_capacity;
    table->size = 0;
    table->allow_resize = allow_resize;
    table->compare_keys = compare_keys;
    table->hash_func = hash_func;
    table->free_key = free_key;
    table->free_value = free_value;
    table->buckets = calloc(table->capacity, sizeof(HashNode*));
    if (!table->buckets) {
        free(table);
        return NULL;
    }

    return table;
}

// Funzione per ridimensionare la tabella hash
static int resize_table_internal(HashTable* table, int new_capacity) {
    if (new_capacity <= 0 || new_capacity < table->size) {
        return -1; // Capacità non valida
    }

    HashNode** new_buckets = calloc(new_capacity, sizeof(HashNode*));
    if (!new_buckets) return -1;

    for (int i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            unsigned long new_index = table->hash_func(current->key) % new_capacity;
            HashNode* next = current->next;

            current->next = new_buckets[new_index];
            new_buckets[new_index] = current;
            current = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;

    return 0;
}

// Funzione pubblica per ridimensionare a una capacità desiderata
int hash_table_resize_to(HashTable* table, int new_capacity) {
    if (!table) return -1;
    return resize_table_internal(table, new_capacity);
}

// Inserisce o aggiorna un elemento nella hash table
int hash_table_put(HashTable* table, const void* key, const void* value) {
    if (!table || !key) return -1;

    // Ridimensiona se necessario
    if (table->allow_resize && (float)table->size / table->capacity > 0.75) {
        resize_table_internal(table, table->capacity * 2);
    }

    unsigned long index = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[index];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (table->free_value) table->free_value(current->value);
            current->value = (void*)value;
            return 0;
        }
        current = current->next;
    }

    HashNode* new_node = malloc(sizeof(HashNode));
    if (!new_node) return -1;
    new_node->key = (void*)key;
    new_node->value = (void*)value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
    table->size++;

    return 0;
}

// Ottiene un valore dalla hash table
void* hash_table_get(const HashTable* table, const void* key) {
    if (!table || !key) return NULL;

    unsigned long index = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[index];

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// Verifica se una chiave esiste nella tabella
int hash_table_contains_key(const HashTable* table, const void* key) {
    return hash_table_get(table, key) != NULL;
}

// Rimuove un elemento dalla hash table
void hash_table_remove(HashTable* table, const void* key) {
    if (!table || !key) return;

    unsigned long index = table->hash_func(key) % table->capacity;
    HashNode* current = table->buckets[index];
    HashNode* prev = NULL;

    while (current) {
        if (table->compare_keys(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }

            if (table->free_key) table->free_key(current->key);
            if (table->free_value) table->free_value(current->value);
            free(current);
            table->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Ritorna il numero di elementi nella tabella
int hash_table_size(const HashTable* table) {
    return table ? table->size : 0;
}

// Ritorna tutte le chiavi come array
void** hash_table_keyset(const HashTable* table) {
    if (!table || table->size == 0) return NULL;

    void** keys = malloc(table->size * sizeof(void*));
    if (!keys) return NULL;

    int index = 0;
    for (int i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            keys[index++] = current->key;
            current = current->next;
        }
    }
    return keys;
}

// Libera la memoria della hash table
void hash_table_free(HashTable* table) {
    if (!table) return;

    for (int i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            HashNode* next = current->next;
            if (table->free_key) table->free_key(current->key);
            if (table->free_value) table->free_value(current->value);
            free(current);
            current = next;
        }
    }

    free(table->buckets);
    free(table);
}
```
</details>

Il codice fornito ora sembra soddisfare tutte le richieste e offre varie possibilità di personalizzazione.
Adesso procedo con scrivere il codice e testarlo con unit test che creerò nella prossima iterazione grazie al LLM.

___

## Iterazione 5

### Input
Scrivi degli unit test per testare ogni funzione della libreria in "modalità" diverse quindi utilizzando o no le funzioni di free e allow_resize. gli unit test devono essere fatti grazie alla libreria unity e devono essere fatti su situazione "particolari".
### Output

<details>
  <summary>File test_ex3.c</summary>

```
#include "unity.h"
#include "hash_table.h"
#include <string.h>
#include <stdlib.h>

// Funzioni di supporto per il test
static int compare_keys(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

static unsigned long hash_func(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}

static void free_key(void* key) {
    free(key);
}

static void free_value(void* value) {
    free(value);
}

// Variabili per i test
HashTable* table;

// Test di setup
void setUp(void) {
    // Viene chiamato prima di ogni test
}

// Test di teardown
void tearDown(void) {
    // Viene chiamato dopo ogni test
    if (table) {
        hash_table_free(table);
        table = NULL;
    }
}

// Test della creazione della hash table
void test_create_table_no_resize_no_free(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, NULL, NULL);
    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_EQUAL(10, table->capacity);
    TEST_ASSERT_EQUAL(0, table->size);
    TEST_ASSERT_FALSE(table->allow_resize);
}

void test_create_table_with_resize_and_free(void) {
    table = hash_table_create(5, true, compare_keys, hash_func, free_key, free_value);
    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_EQUAL(5, table->capacity);
    TEST_ASSERT_EQUAL(0, table->size);
    TEST_ASSERT_TRUE(table->allow_resize);
}

// Test dell'inserimento con chiavi duplicate
void test_put_duplicate_key(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, free_key, free_value);
    hash_table_put(table, strdup("key1"), strdup("value1"));
    hash_table_put(table, strdup("key1"), strdup("value2")); // Sovrascrive "value1"

    TEST_ASSERT_EQUAL(1, hash_table_size(table));
    char* value = hash_table_get(table, "key1");
    TEST_ASSERT_NOT_NULL(value);
    TEST_ASSERT_EQUAL_STRING("value2", value);
}

// Test dell'inserimento con ridimensionamento
void test_put_with_resize(void) {
    table = hash_table_create(2, true, compare_keys, hash_func, NULL, NULL);
    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");
    hash_table_put(table, "key3", "value3"); // Triggers resize

    TEST_ASSERT_EQUAL(4, table->capacity);
    TEST_ASSERT_EQUAL(3, hash_table_size(table));
    TEST_ASSERT_EQUAL_STRING("value1", hash_table_get(table, "key1"));
    TEST_ASSERT_EQUAL_STRING("value2", hash_table_get(table, "key2"));
    TEST_ASSERT_EQUAL_STRING("value3", hash_table_get(table, "key3"));
}

// Test del ridimensionamento forzato
void test_resize_to(void) {
    table = hash_table_create(5, false, compare_keys, hash_func, NULL, NULL);
    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");

    TEST_ASSERT_EQUAL(5, table->capacity);
    TEST_ASSERT_EQUAL(2, hash_table_size(table));

    hash_table_resize_to(table, 10);

    TEST_ASSERT_EQUAL(10, table->capacity);
    TEST_ASSERT_EQUAL(2, hash_table_size(table));
    TEST_ASSERT_EQUAL_STRING("value1", hash_table_get(table, "key1"));
    TEST_ASSERT_EQUAL_STRING("value2", hash_table_get(table, "key2"));
}

// Test del keyset
void test_keyset(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, NULL, NULL);
    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");

    void** keys = hash_table_keyset(table);
    TEST_ASSERT_NOT_NULL(keys);

    int found_key1 = 0, found_key2 = 0;
    for (int i = 0; i < 2; i++) {
        if (strcmp((const char*)keys[i], "key1") == 0) found_key1 = 1;
        if (strcmp((const char*)keys[i], "key2") == 0) found_key2 = 1;
    }

    TEST_ASSERT_TRUE(found_key1);
    TEST_ASSERT_TRUE(found_key2);
    free(keys);
}

// Test della rimozione
void test_remove(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, free_key, free_value);
    hash_table_put(table, strdup("key1"), strdup("value1"));
    hash_table_put(table, strdup("key2"), strdup("value2"));

    TEST_ASSERT_EQUAL(2, hash_table_size(table));

    hash_table_remove(table, "key1");
    TEST_ASSERT_EQUAL(1, hash_table_size(table));
    TEST_ASSERT_NULL(hash_table_get(table, "key1"));
    TEST_ASSERT_NOT_NULL(hash_table_get(table, "key2"));
}

// Test dell'accesso a chiavi non esistenti
void test_get_non_existent_key(void) {
    table = hash_table_create(10, false, compare_keys, hash_func, NULL, NULL);
    TEST_ASSERT_NULL(hash_table_get(table, "key1"));
}

// Test del comportamento con capacità insufficiente
void test_put_over_capacity_no_resize(void) {
    table = hash_table_create(2, false, compare_keys, hash_func, NULL, NULL);
    hash_table_put(table, "key1", "value1");
    hash_table_put(table, "key2", "value2");

    // Il terzo inserimento non deve essere permesso
    int result = hash_table_put(table, "key3", "value3");
    TEST_ASSERT_EQUAL(-1, result);
    TEST_ASSERT_EQUAL(2, hash_table_size(table));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_table_no_resize_no_free);
    RUN_TEST(test_create_table_with_resize_and_free);
    RUN_TEST(test_put_duplicate_key);
    RUN_TEST(test_put_with_resize);
    RUN_TEST(test_resize_to);
    RUN_TEST(test_keyset);
    RUN_TEST(test_remove);
    RUN_TEST(test_get_non_existent_key);
    RUN_TEST(test_put_over_capacity_no_resize);

    return UNITY_END();
}
```
</details>

La serie di test generati vengono eseguiti correttamente e testano varie funzionalità della libreria. L'unico test che fallisce è l'ultimo, perchè non ha tenuto in memoria il cambiamento che ho richiesto nella scorsa iterazione, rendendo il test inutile.

Ora tolgo il test inutile e ne aggiungo di significativi.

___

## Iterazione 6
Questa iterazione è stata fatta in un momento e una chat diversa.
### Input
Crea un programma che calcola la parola più frequente con lunghezza minima da un file di testo, usando questa libreria: *file hash_table.c*
### Output

<details>
  <summary>File main_ex3.c</summary>

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash_table.h"

// Funzione hash per le stringhe
unsigned long string_hash(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++; // hash * 33 + c
    }
    return hash;
}

// Funzione di confronto per le stringhe
int string_compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

// Funzione per trovare la parola più frequente con lunghezza minima
char* find_most_frequent_word(const char* filename, size_t min_length) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Errore nell'aprire il file: %s\n", filename);
        return NULL;
    }

    // Crea una hash table
    HashTable* table = hash_table_create(
        16,                    // Capacità iniziale
        true,                  // Consenti ridimensionamento
        string_compare,        // Funzione di confronto
        string_hash,           // Funzione hash
        free,                  // Funzione per liberare le chiavi
        free                   // Funzione per liberare i valori
    );
    if (!table) {
        fclose(file);
        fprintf(stderr, "Errore nella creazione della hash table.\n");
        return NULL;
    }

    char word[256];
    while (fscanf(file, "%255s", word) != EOF) {
        if (strlen(word) < min_length) {
            continue;
        }

        // Controlla se la parola è già nella tabella
        int* count = (int*)hash_table_get(table, word);
        if (count) {
            (*count)++;
        } else {
            // Nuova parola
            int* new_count = malloc(sizeof(int));
            if (!new_count) {
                fprintf(stderr, "Errore di memoria.\n");
                fclose(file);
                hash_table_free(table);
                return NULL;
            }
            *new_count = 1;
            hash_table_put(table, strdup(word), new_count);
        }
    }
    fclose(file);

    // Trova la parola più frequente
    char* most_frequent_word = NULL;
    int max_count = 0;

    void** keys = hash_table_keyset(table);
    int size = hash_table_size(table);

    for (int i = 0; i < size; i++) {
        const char* key = keys[i];
        int* value = (int*)hash_table_get(table, key);
        if (*value > max_count) {
            max_count = *value;
            most_frequent_word = (char*)key; // Non liberiamo "key", è gestito dalla hash table
        }
    }
    free(keys);

    // Copia la parola più frequente per restituirla
    char* result = most_frequent_word ? strdup(most_frequent_word) : NULL;

    // Libera la tabella
    hash_table_free(table);

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <file di testo> <lunghezza minima>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    size_t min_length = (size_t)atoi(argv[2]);

    char* result = find_most_frequent_word(filename, min_length);
    if (result) {
        printf("La parola più frequente di lunghezza almeno %zu è: %s\n", min_length, result);
        free(result);
    } else {
        printf("Nessuna parola valida trovata o errore durante l'analisi.\n");
    }

    return 0;
}
```
</details>

Il main viene eseguito correttamente e la richiesta è rispettata.
L'input in questo caso è diverso, il codice della libreria è stato letto e usato nel contesto della richiesta correttamente, ciascuna funzione utilizzata è stata compresa dal LLM.

___

## Iterazione extra
Dato che il correttore automatico per questo esercizio prevede una libreria che ha le funzioni strutturate come nella consegna, ho ripreso l'output generato alla prima iterazione e ho creato una versione base della libreria, che non prevede alcun cambiamento che è stato inserito nel corso delle iterazioni.
Per farlo è stato chiesto al LLM, come nella sesta iterazione, il main e i test, dando in input il file [hash_table.c](#iterazione-1).
Per comodità i file avranno lo stesso nome dei rispettivi sviluppati fino a ora, e la versione "estesa" è stata spostata in un altra cartella.

### Output

<details>
  <summary>File main_ex3.c</summary>

```
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Per funzioni di controllo sui caratteri

// Funzione hash per le stringhe
unsigned long string_hash(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++; // hash * 33 + c
    }
    return hash;
}

// Funzione di confronto per le stringhe
int string_compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

// Funzione per filtrare una parola, separando parole su caratteri non alfabetici
void filter_word(char* word) {
    size_t len = strlen(word);
    size_t j = 0;

    for (size_t i = 0; i < len; i++) {
        if (isalpha(word[i])) { // Controlla se il carattere è una lettera
            word[j++] = tolower(word[i]); // Converte il carattere in minuscolo
        } else {
            word[j] = '\0'; // Termina la parola corrente
            break; // La funzione lascia che il resto venga gestito separatamente
        }
    }
    word[j] = '\0'; // Termina la stringa
}

// Funzione per trovare la parola più frequente con lunghezza minima
void find_most_frequent_word(const char* filename, int min_length) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Errore nell'aprire il file: %s\n", filename);
        return;
    }

    // Creazione della hash table
    HashTable* table = hash_table_create(string_compare, string_hash);
    if (!table) {
        fclose(file);
        fprintf(stderr, "Errore nella creazione della hash table.\n");
        return;
    }

    char word[256];
    while (fscanf(file, "%255s", word) != EOF) {
        filter_word(word); // Rimuove caratteri non validi

        if (strlen(word) < (size_t)min_length) {
            continue; // Salta le parole troppo corte
        }

        // Cerca la parola nella hash table
        int* count = (int*)hash_table_get(table, word);
        if (count) {
            (*count)++;
        } else {
            // Nuova parola, aggiungila alla hash table
            int* new_count = malloc(sizeof(int));
            if (!new_count) {
                fprintf(stderr, "Errore di memoria.\n");
                fclose(file);
                hash_table_free(table);
                return;
            }
            *new_count = 1;
            hash_table_put(table, strdup(word), new_count);
        }
    }
    fclose(file);

    // Trova tutte le parole con il conteggio massimo
    void** keys = hash_table_keyset(table);
    int size = hash_table_size(table);

    int max_count = 0;
    for (int i = 0; i < size; i++) {
        const char* key = (const char*)keys[i];
        int* count = (int*)hash_table_get(table, key);
        if (*count > max_count) {
            max_count = *count;
        }
    }

    printf("Le parole più frequenti con lunghezza almeno %d sono:\n", min_length);
    for (int i = 0; i < size; i++) {
        const char* key = (const char*)keys[i];
        int* count = (int*)hash_table_get(table, key);
        if (*count == max_count) {
            printf("'%s' (conteggio: %d)\n", key, *count);
        }
    }

    if (max_count == 0) {
        printf("Nessuna parola con lunghezza almeno %d trovata.\n", min_length);
    }

    // Libera la memoria
    free(keys);
    hash_table_free(table);
}



int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <file di testo> <lunghezza minima>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    int min_length = atoi(argv[2]);

    if (min_length <= 0) {
        fprintf(stderr, "La lunghezza minima deve essere un intero positivo.\n");
        return 1;
    }

    find_most_frequent_word(filename, min_length);

    return 0;
}
```
</details>

<details>
  <summary>File test_ex3.c</summary>

```
#include "hash_table.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

// Funzione hash per stringhe
unsigned long string_hash(const void* key) {
    const char* str = (const char*)key;
    unsigned long hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++; // hash * 33 + c
    }
    return hash;
}

// Funzione di confronto per stringhe
int string_compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

void setUp(void) {
    // Funzione chiamata prima di ogni test
}

void tearDown(void) {
    // Funzione chiamata dopo ogni test
}

void test_hash_table_create_and_free(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);
    TEST_ASSERT_NOT_NULL(table);
    TEST_ASSERT_EQUAL(0, hash_table_size(table));
    hash_table_free(table);
}

void test_hash_table_put_and_get(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    char* key1 = "chiave1";
    char* value1 = "valore1";
    hash_table_put(table, strdup(key1), strdup(value1));

    char* result = (char*)hash_table_get(table, key1);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING(value1, result);

    hash_table_free(table);
}

void test_hash_table_update_value(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    char* key = "chiave";
    char* value1 = "valore1";
    char* value2 = "valore2";

    hash_table_put(table, strdup(key), strdup(value1));
    hash_table_put(table, strdup(key), strdup(value2));

    char* result = (char*)hash_table_get(table, key);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING(value2, result);

    hash_table_free(table);
}

void test_hash_table_remove(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    char* key = "chiave";
    char* value = "valore";

    hash_table_put(table, strdup(key), strdup(value));
    hash_table_remove(table, key);

    void* result = hash_table_get(table, key);
    TEST_ASSERT_NULL(result);

    hash_table_free(table);
}

void test_hash_table_keyset(void) {
    HashTable* table = hash_table_create(string_compare, string_hash);

    char* key1 = "chiave1";
    char* value1 = "valore1";
    char* key2 = "chiave2";
    char* value2 = "valore2";

    hash_table_put(table, strdup(key1), strdup(value1));
    hash_table_put(table, strdup(key2), strdup(value2));

    void** keys = hash_table_keyset(table);
    TEST_ASSERT_NOT_NULL(keys);
    TEST_ASSERT_EQUAL(2, hash_table_size(table));

    free(keys);
    hash_table_free(table);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_hash_table_create_and_free);
    RUN_TEST(test_hash_table_put_and_get);
    RUN_TEST(test_hash_table_update_value);
    RUN_TEST(test_hash_table_remove);
    RUN_TEST(test_hash_table_keyset);

    return UNITY_END();
}
```
</details>

I test risultano molto più semplici, dato che non ho richiesto dei test specifici. Invece il main cambia da quello già presentato, questo separa le parole, togliendo caratteri che non sono lettere e trasformando le parole tutte minuscole.
Dato che i test forniti su moodle richiedono questa versione, cambio il codice anche per la versione precedente.
Inoltre dato che c'è stato un fraintendimento con il modo in cui funziona il correttore, ho modificato più volte il codice, un cambiamento significativo è l'inizializzazione del array di bucket, in cui tutti i valori sono stati messi a NULL, evitando possibili problemi con i puntatori.
Il problema con il correttore riguarda la funzione di compare, io usando una struttura simile ai comparatori del esercizio 1, che restituiva -1 se minore, 0 se uguale e 1 se maggiore, nel codice di hash_table.c quando veniva controllata l'uguaglianza tra due chiavi, mi aspettavo il risultato di compare uguale a 0, invece in quella usata dal correttore, se uguale veniva restituito 1.

___

## Conclusioni

La libreria ha subito una evoluzione significativa sia in termini di funzionalità che di robustezza, il processo di creazione è stato semplice e con la necessità di pochi input, lasciando alla interpretazione del LLM vari elementi non definiti.
Non si sono presentate problematiche gravi durante le iterazioni, sebbene una volta non abbia memorizzato il cambiamento richiesto e un'altra volta ha inserito un limite non richiesto e solitamente non utilizzato.
Questo genere di errori potrebbero essere sempre più frequenti man mano che la grandezza del codice richiesto aumenta, dato che il contesto e le conoscenze che deve avere memorizzate sono tante.
I LLM si presentano quindi molto utili al supporto alla programmazione a patto che si abbia una conoscenza dell'argomento e si sappia riconoscere gli errori. 

In questo esercizio è stato utilizzato esclusivamente ChatGPT, tutti gli input, esclusi quelli dell'iterazione 6 ed extra, sono stati forniti sulla stessa chat.

## Esercizio 4 - Grafi sparsi e Visita in Ampiezza

### Linguaggio richiesto: C

### Testo

Si implementi una libreria che realizza la struttura dati *Grafo* in modo che sia ottimale per dati sparsi
(**attenzione**: le scelte implementative che farete dovranno essere giustificate in relazione alle nozioni presentate
durante le lezioni in aula).

È richiesto che l'implementazione sfrutti la Tavola Hash implementata nell'esercizio 3.

L'implementazione deve essere generica sia per quanto riguarda il tipo dei nodi, sia per quanto riguarda le etichette
degli archi, implementando le funzioni riportate nel seguente header file (con requisiti minimi di complessità; dove _N_ può indicare il numero di nodi o il numero di archi, a seconda del contesto):

```
graph.h

typedef enum {false = 0, true = 1} Bool;

typedef struct graph *Graph;

typedef struct edge {
   void* source; //nodo d'origine
   void* dest; //nodo di destinazione
   void* label; //etichetta dell'arco
}Edge;

Graph graph_create(Bool labelled, Bool directed,
                     int (*compare)(const void*, const void*),
                     unsigned long (*hash)(const void*));

//crea un grafo vuoto, etichettato se labelled == true e diretto se directed == true,
//le funzioni f1 e f2 sono necessarie per la costruzione della tavola hash che deve essere usata dalla libreria -- O(1)

Bool graph_is_directed(const Graph gr);                                                           // dice se il grafo è diretto o meno -- O(1)
Bool graph_is_labelled(const Graph gr);                                                           // dice se il grafo è etichettato o meno -- O(1)
Bool graph_add_node(Graph gr, const void* node);                                                  // aggiunge un nodo -- O(1)
Bool graph_add_edge(Graph gr, const void* node1, const void* node2, const void* label);           // aggiunge un arco dati estremi ed etichetta -- O(1) (*)
Bool graph_contains_node(const Graph gr, const void* node);                                       // controlla se un nodo è nel grafo -- O(1)
Bool graph_contains_edge(const Graph gr, const void* node1, const void* node2);                   // controlla se un arco è nel grafo -- O(1) (*)
Bool graph_remove_node(Graph gr, const void* node);                                               // rimuove un nodo dal grafo -- O(N)
Bool graph_remove_edge(Graph gr, const void* node1, const void* node2);                           // rimuove un arco dal grafo -- O(1) (*)
int graph_num_nodes(const Graph gr);                                                              // numero di nodi -- O(1)
int graph_num_edges(const Graph gr);                                                              // numero di archi -- O(N)
void** graph_get_nodes(const Graph gr);                                                           // recupero dei nodi del grafo -- O(N)
Edge** graph_get_edges(const Graph gr);                                                           // recupero degli archi del grafo -- O(N)
void** graph_get_neighbours(const Graph gr, const void* node);                                    // recupero dei nodi adiacenti ad un dato nodo -- O(1) (*)
int graph_num_neighbours(const Graph gr, const void* node);                                       // recupero del numero di nodi adiacenti ad un dato nodo -- O(1)
void* graph_get_label(const Graph gr, const void* node1, const void* node2);                      // recupero dell'etichetta di un arco -- O(1) (*)
void graph_free(Graph gr);
```

_(*)_ quando il grafo è veramente sparso, assumendo che l'operazione venga effettuata su un nodo la cui lista di adiacenza ha una lunghezza in O(1).

La struttura ```struct graph``` deve essere decisa prendendo in considerazione la richiesta di usare la Tabella Hash dell'esercizio precedente.


*Suggerimento*:  un grafo non diretto può essere rappresentato usando un'implementazione per grafi diretti modificata
per garantire che, per ogni arco *(a,b)* etichettato *w*, presente nel grafo, sia presente nel grafo anche l'arco *(b,a)*
etichettato *w*. Ovviamente, il grafo dovrà mantenere l'informazione che specifica se esso è un grafo diretto o non diretto.
Similmente, un grafo non etichettato può essere rappresentato usando l'implementazione per grafi etichettati modificata per garantire
che le etichette siano sempre `null` (che invece non devono mai essere `null` per i grafi etichettati).

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso della libreria che implementa la struttura dati Grafo

Si implementi l'algoritmo di visita in ampiezza secondo il seguente prototipo di funzione

```
void** breadth_first_visit(Graph gr, void* start, int (*compare)(const void*, const void*), unsigned long (*hash)(const void*));
//start è il nodo di partenza da cui cominciare la visita, la funzione restituisce l'array dei nodi nell'ordine di visita.
//eventualmente, la funzione restituisce null se il nodo start non è presente nel grafo gr.

```

L'implementazione dell'algoritmo di visita in ampiezza dovrà utilizzare la libreria sui grafi appena implementata.
L'algoritmo dovrà poi essere usato con i dati contenuti nel file `italian_dist_graph.csv`, che potete recuperare all'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/FqneW99EGWLSRpY](https://datacloud.di.unito.it/index.php/s/FqneW99EGWLSRpY)

Tale file contiene le distanze in metri tra varie località italiane e una frazione delle località a loro più vicine. Il formato è un CSV standard: i campi sono separati da virgole; i record sono separati dal carattere di fine riga (`\n`).

Ogni record contiene i seguenti dati:

- `place1`: (tipo stringa) nome della località "sorgente" (la stringa può contenere spazi ma non può contenere virgole);
- `place2`: (tipo stringa) nome della località "destinazione" (la stringa può contenere spazi ma non può contenere virgole);
- `distance`: (tipo float) distanza in metri tra le due località.

**Note:**

- Potete interpretare le informazioni presenti nelle righe del file come archi **non diretti** (per cui probabilmente vorrete inserire nel vostro grafo sia l'arco di andata che quello di ritorno a fronte di ogni riga letta).
- Il file è stato creato a partire da un dataset poco accurato. I dati riportati contengono inesattezze e imprecisioni.

**Si ricorda che il file `italian_dist_graph.csv` (e i file compilati) NON DEVONO ESSERE OGGETTO DI COMMIT SU GIT!**

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex3-4` all'interno del repository, che conterrà i file relativi a questo esercizio e al precedente.
- Includete nella consegna anche un `Makefile` che con il comando `make all` deve produrre all'interno di `ex3-4/bin` due file eseguibili chiamati `main_ex3-4` e `test_ex3-4`. Se avete usato librerie esterne (come Unity) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex3-4` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.
- L'eseguibile `main_ex3-4` deve ricevere come parametri il percorso del file `italian_dist_graph.csv`, il nome della città di partenza e il nome di un file di output, e salvare in quest'ultimo i nomi delle località visitate durante una visita in ampiezza del grafo, un nome per riga, partendo da un nodo di partenza specificato. I nomi dei file non devono essere hardcoded, ma devono essere passati come argomenti da linea di comando.

```
$ ./main_ex3-4 italian_dist_graph.csv torino output.txt
```

Si documenti brevemente, in una relazione (README.md su git), le scelte implementative effettuate e i risultati e tempi dell'esecuzione dell'algoritmo rispetto a quanto atteso.

### Relazione

Le hash table sono state usate per l'intera gestione del grafo.
Il grafo è composto da una hash table principale che contiene tutti i nodi.
I nodi costituiscono le chiavi e il valore a loro associato è una hash table contenente i nodi adiacenti.
Ogni arco è memorizzato come coppia (nodo destinazione , etichetta).
Data la consegna, il valore associato all'arco non può che essere un'etichetta, ma nulla vieta di modificare la libreria per far diventare l'etichetta un puntatore ad una struttura dati, a scelta del utilizzatore della libreria, che contiene informazioni riguardanti l'arco.
Un'altra scelta implementativa importante riguarda il grafo non diretto, quando si inserisce un arco, sia l'arco nodo1->nodo2 che nodo2->nodo1 verranno salvati dalla funzione add_edge e restituiti dalla funzione get_edges (la funzione num_edges infatti restituirà il doppio del numero di archi).
---
I tempi di esecuzione della visita in ampiezza del grafo ricavato da italian_dist_graph.
Da tutti i nodi di partenza esaminati i tempi di esecuzione sono nel range di : 0.014-0.020 secondi.

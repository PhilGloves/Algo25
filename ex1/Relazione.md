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
# Traccia fornita

Un’area quadrata del mediterraneo è stata delimitata e suddivisa in N riquadri. Sulla superficie di 
ciascun riquadro sono stati installati 1, 2 o 3 pannelli solari galleggianti. Una piataforma mobile 
alimentata ad energia eletrica è inizialmente posizionata in un riquadro con 1 pannello solare, ma 
ha bisogno di una grande quantità di energia per cui 1 solo pannello non è sufficiente e la si vuole 
spostare in un riquadro con 3 pannelli solari. La piataforma può spostarsi di un solo riquadro alla 
volta, nelle direzioni: alto, basso, sinistra o destra, rimanendo però all'interno dell’area delimitata. 
Scrivere un programma che calcoli il numero minimo di spostamenti da eseguire per arrivare in un 
riquadro con 3 pannelli solari, partendo inizialmente da uno qualsiasi dei riquadri con 1 solo 
pannello solare

### Input
La prima riga contiene la dimensione N dell'area, con 1 ≤ N ≤ 100. Poi ci sono N righe, ciascuna con il 
numero di pannelli degli N riquadri presenti in quella riga.

### Output
Stampare una riga con il numero minimo di spostamenti da eseguire per giungere ad un riquadro 
con 3 pannelli solari, indipendentemente dal riquadro di partenza (che comunque deve essere uno 
tra quelli che hanno 1 solo pannello solare).

#### Esempio di input
4 \
1223 \
2123 \
2213 \
3212

#### Esempio di output
3

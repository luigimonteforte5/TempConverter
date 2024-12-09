# Descrizione del Progetto
In questo progetto, realizzerai un semplice convertitore di temperature a riga di comando utilizzando C++. Il programma supporterà la conversione tra Celsius, Fahrenheit e Kelvin.

## Requisiti
- **Librerie C++**: Utilizzare le librerie standard di C++.
- **Interfaccia Utente**: Creare una semplice interfaccia utente a riga di comando che permetta all’utente di inserire la temperatura e selezionare le unità di conversione.

## Funzionalità
1. **Raccogliere la Temperatura dall’Utente**: Chiedere all’utente di inserire una temperatura.
2. **Selezionare le Unità di Conversione**: Chiedere all’utente di selezionare l’unità di misura di origine e di destinazione (Celsius, Fahrenheit, Kelvin).
3. **Eseguire la Conversione**: Eseguire la conversione e visualizzare il risultato.

## Formule di Conversione
- **Celsius a Fahrenheit**:  
  \[
  F = (C * 9 / 5) + 32
  \]
- **Celsius a Kelvin**:  
  \[
  K = C + 273.15
  \]
- **Fahrenheit a Celsius**:  
  \[
  C = (fahrenheit - 32.0) * 5.0 / 9.0;
  \]
- **Fahrenheit a Kelvin**:  
  \[
  K = (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
  \]
- **Kelvin a Celsius**:  
  \[
  C = K - 273.15
  \]
- **Kelvin a Fahrenheit**:  
  \[
  F = (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
  \]

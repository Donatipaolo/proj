# 📦 Proj — C/C++ Project & Library Manager

`proj` è un tool da linea di comando scritto in **Bash** per creare, gestire e compilare progetti **C e C++** utilizzando **Makefile** e librerie statiche.

È pensato per chi vuole uno strumento:
- semplice
- trasparente
- facilmente modificabile
- basato su Makefile tradizionali

---

## ✨ Caratteristiche

- 🚀 Creazione rapida di progetti C / C++
- 📁 Struttura standard automatica:

```bash
include/
src/
obj/
bin/
libs/
```

- ⚙️ Generazione automatica dei Makefile
- 📚 Gestione delle librerie:
- librerie globali
- librerie copiate nel progetto
- librerie referenziate
- 🔄 Aggiornamento automatico dei Makefile
- 📦 Creazione di progetti portabili
- 🧱 Separazione tra tool di progetto (`proj`) e tool per librerie (`projlib`)

---

## 🧠 Filosofia

`proj` **non sostituisce CMake o Meson**.

È progettato per:
- progetti piccoli/medi
- studio e sperimentazione
- comprendere realmente il processo di build

Tutto ciò che viene generato è **leggibile e modificabile**.

---

## 📁 Struttura del progetto
```bash
~/.proj/
├── proj
├── projlib
├── templates/
│ ├── c/
│ ├── cpp/
│ └── library/
└── libraries/
```

Ogni progetto creato ha la seguente struttura:
```bash
MyProject/
├── include/
├── src/
│ └── main.c / main.cpp
├── obj/
├── bin/
├── libs/
├── Makefile
└── libs.mk
```

---

## 🚀 Utilizzo

### Creare un nuovo progetto

```bash
proj new -t c++ -n MyProject
cd MyProject
```

### Compilare il progetto

```bash
proj build
```

### Eseguire il programma

```bash
proj run
```

### Gestione delle Librerie
## Creazione di un Libreria
```bash
projlib new MyLib --lang c++
```

## Struttura di una Libreria
```bash
MyLib/
├── include/
├── src/
├── obj/
├── bin/
├── Makefile
└── projlib.json
```

## Aggiungere una libreria al tuo progetto
```bash
proj add-lib MyLib --mode copy --content full
```

## Aggiornare una libreria copiata
```bash
proj update-lib MyLib
```
oppure tutte le librerie
```bash
proj update-lib --all
```

### 🔄 Aggiornamento delle dipendenze

Il file libs.mk viene generato automaticamente da proj e contiene:
- percorsi di include
- percorsi delle librerie
- flag di compilazione
- Non va modificato manualmente.

## 📦 Progetti portabili
```bash
proj package
```

## Crea un archivio .tar.gz contenente:
- sorgenti
- Makefile
- librerie copiate


### 🧪 Dipendenze
- bash
- make
- gcc / g++
- ar
- jq

### ⚠️ Limitazioni
- Supporto solo per librerie statiche (.a)
- Pensato per ambienti Linux / WSL
- Nessun supporto IDE automatico


# Novomatic Test

## Poniżej znajduje się szybka instrukcja jak skompilować zadania.

### Wymagania wstępne

- CMake (>= 3.28.3)

### Instalacja

#### Linux

1. Klonowanie repozytorium:
   ```bash
   git clone https://github.com/Misieeeek/novomatic_tasks.github
   cd novomatic_tasks
   ```
2. Budowa zadania:
   
   2.1. Budowa zadania 1:
   ```bash
   cd task1/build
   cmake ..
   ```
   2.2. Budowa zadania 2:
   ```bash
   cd task2/build
   cmake ..
   ```
   2.3. Budowa zadania 3:
   ```bash
   cd task3/build
   cmake ..
   ```
4. Kompilacja projektu:

   3.1. Kompilacja zadania 1:
   ```bash
   make
   ./Novomatic_Task_1
   ```
   3.2. Kompilacja zadania 2:
   ```bash
   make
   ./Novomatic_Task_2
   ```
   3.3. Kompilacja zadania 3:
   ```bash
   make
   ./Novomatic_Task_3
   ```

#### Windows (Visual Studio)

1. Klonowanie repozytorium:
   ```cmd
   git clone https://github.com/Misieeeek/novomatic_tasks.github
   cd novomatic_tasks
   ```
2. Budowa zadania (Uwaga: Dostosuj wersję Visual Studio do zainstalowanej wersji):
   
   2.1. Budowa zadania 1:
   ```cmd
   cd task1/build
   cmake .. -G "Visual Studio 17 2022" -A x64
   ```
   2.2. Budowa zadania 2:
   ```cmd
   cd task2/build
   cmake .. -G "Visual Studio 17 2022" -A x64
   ```
   2.3. Budowa zadania 3:
   ```cmd
   cd task3/build
   cmake .. -G "Visual Studio 17 2022" -A x64
   ```
4. Otwórz wygenerowany plik .sln w Visual Studio i zbuduj projekt lub użyj wiersza poleceń:
   ```cmd
   cmake --build . --config Release
   ```

#### Windows (MinGW)

1. Klonowanie repozytorium:
   ```cmd
   git clone https://github.com/Misieeeek/novomatic_tasks.github
   cd novomatic_tasks
   ```
2. Skonfiguruj projekt za pomocą CMake:

   2.1. Budowa zadania 1:
   ```cmd
   cd task1/build
   cmake .. -G "MinGW Makefiles"
   ```
   2.2. Budowa zadania 2:
   ```cmd
   cd task2/build
   cmake .. -G "MinGW Makefiles
   ```
   2.3. Budowa zadania 3:
   ```cmd
   cd task3/build
   cmake .. -G "MinGW Makefiles
   ```
4. Kompilacja zadania:
   ```cmd
   mingw32-make
   ```

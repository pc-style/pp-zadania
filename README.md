# PP-Zadania

Rozwiązania zadań z przedmiotu **Podstawy Programowania** w języku C++.

## Struktura

```
pp-zadania/
├── lab01/          # Lista 01 - podstawy języka C++
│   ├── zad1.cpp   # Hello World
│   ├── zad2.cpp   # Wyświetlanie zmiennej liczbowej
│   ├── zad3.cpp   # Wyświetlanie znaków
│   ├── zad4.cpp   # Suma dwóch liczb
│   ├── zad5.cpp   # Zamiana znaków na kod ASCII
│   ├── zad6.cpp   # Wyświetlanie liczby w systemie binarnym
│   ├── zad7.cpp   # Zamiana liczby dziesiętnej na szesnastkową
│   ├── zad8.cpp   # Sprawdzenie czy znak jest cyfrą czy literą
│   ├── zad9.cpp   # Konwersja małej litery na wielką
│   ├── zad10.cpp  # Dodawanie liczb w różnych systemach
│   ├── zad11.cpp  # Instrukcje iteracyjne
│   └── zad12.cpp  # Instrukcje iteracyjne, argumenty funkcji
├── lab02/          # Lista 02
└── ...
```

## Kompilacja i uruchomienie

```bash
# Kompilacja
g++ -std=c++20 -Wall -pedantic -g -o prog prog.cpp

# Uruchomienie z detekcją wycieków pamięci
leaks --atExit -- ./prog
```

## Narzędzia pomocnicze

W repozytorium dostępne są skrypty pomocnicze:
- `compile` / `c` - kompilacja plików C++
- `run` / `r` - uruchomienie programów z detekcją pamięci
- `new_lab` - tworzenie nowej listy zadań

## Wymagania

- C++20
- macOS / Linux
- GCC / Clang

## Licencja

MIT

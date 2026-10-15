# TD Algorithmique et Structures de Données

Travaux dirigés d'*Algorithmique et Structures de Données* (ENSISA, 1A
Informatique et Réseaux), écrits en C.

## Organisation du dépôt

```
.
├── README.md
├── .clang-format          # style de code commun (indentation 4, 80 colonnes)
├── data_structur/         # structures de données réutilisables
│   ├── array/             # tableau dynamique
│   ├── list/
│   │   ├── single/        # liste simplement chaînée
│   │   ├── double/        # liste doublement chaînée
│   │   └── circular/      # liste circulaire
│   ├── stack/             # pile (LIFO)
│   ├── queue/             # file (FIFO)
│   └── hash_table/        # table de hachage
├── TD1/                   # TD1 : introduction aux algorithmes
│   ├── main.pdf           # énoncé du TD
│   ├── fibo.c
│   └── prime.c
└── TD2/ ...               # un dossier TDn par TD
```

Chaque TD a son propre dossier `TDn/`, qui contient **l'énoncé en PDF**
(`main.pdf`) et le code qui y répond.

## TDs

| TD  | Sujet                        | Contenu                                                                                                                                |
| --- | ---------------------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| TD1 | Introduction aux algorithmes | Fibonacci (naïf / programmation dynamique), nombres premiers (naïf / crible d'Ératosthène), comparaison des temps avec `clock()` |

## Structures de données

Chaque module est un couple `nom.h` / `nom.c`, sans dépendance externe.

| Module         | Fonctions                                                                            |
| -------------- | ------------------------------------------------------------------------------------ |
| `array`      | `new_array`, `get`, `insert`, `delete_index`                                 |
| `list`       | `new_list`, `get`, `insert`, `supress` (3 variantes)                         |
| `stack`      | `new_stack`, `push`, `peek`, `pop`                                           |
| `queue`      | `new_queue`, `Enqueue`, `Dequeue`, `peek`                                    |
| `hash_table` | `new_hash_map`, `hash`, `put`, `get`, `delete_hash_key`, `free_hash_map` |

## Ajouter un nouveau TD

1. Créer le dossier `TDn/`.
2. Y déposer l'énoncé en PDF (`main.pdf`).
3. Y ajouter le code du TD, puis une ligne dans le tableau « TDs » ci-dessus.
4. Si le TD a besoin d'une structure de données, l'inclure depuis
   `data_structur/` (par exemple `-I../data_structur/stack`) plutôt que de la
   copier.

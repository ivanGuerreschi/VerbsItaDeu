/* main.c
   Copyright (C) 2020 Ivan Guerreschi

This file is part of verbsitadeu.

Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>e

verbsitadeu is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

verbsitadeu is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Nome-Programma.  If not, see <http://www.gnu.org/licenses/>. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "verbs.h"
#include "include/menu.h"

int
main (int argc, char *argv[])
{
  int menu = 0;
  char verb[BUFSIZ];

  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  while (true)
    {
      menu = print_menu ();

      switch (menu)
        {
        case 1:
          exit (1);
          break;

        case 2:
          for (int i = 0; i < row; i++)
            printf ("%s-%s\n", verbs[i].ita, verbs[i].deu);
          break;

        case 3:
          puts (random_verb_ita (verbs, row));
          break;

        case 4:
          puts (random_verb_deu (verbs, row));
          break;

        case 5:
          puts ("Enter Deu verb");

          if (fgets (verb, sizeof (verb), stdin) == NULL)
            fprintf (stderr, "Fail to read the input stream\n");
          else
            verb[strcspn (verb, "\r\n")] = 0;

          puts (exist_verb_deu (verbs, verb, row)
                ? "The verb exists"
                : "The verb does not exist");
          break;

        case 6:
          puts ("Enter Ita verb");

          if (fgets (verb, sizeof (verb), stdin) == NULL)
            fprintf (stderr, "Fail to read the input stream\n");
          else
            verb[strcspn (verb, "\r\n")] = 0;

          puts (exist_verb_ita (verbs, verb, row)
                ? "The verb exists"
                : "The verb does not exist");
          break;

        case 7:
          puts ("Translate random verb Ita in Deu");

          char *verb_ita;
          verb_ita = (random_verb_ita (verbs, row));
          puts (verb_ita);

          if (fgets (verb, sizeof (verb), stdin) == NULL)
            fprintf (stderr, "Fail to read the input stream\n");
          else
            verb[strcspn (verb, "\r\n")] = 0;

          puts (translate_verb_deu (verbs, verb_ita, verb, row)
                ? "The verb translate correct"
                : "The verb translate not correct");

          break;

        default:
          fprintf (stderr, "Error input, please enter number (0, 1, 2, 3, 4, 5, 6, 7)\n");
          break;
        }
    }

  close_file (&file_row);
  close_file (&file_verbs);

  for (int i = 0; i < row; i++)
    {
      free (verbs[i].ita);
      free (verbs[i].deu);
    }

  free (verbs);

  return 0;
}

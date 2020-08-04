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
#include "verbs.h"

int
main (int argc, char *argv[])
{
  FILE *file_verbs, *file_row;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");
  
  int row = count_row_file (file_row); 
  verb_t *verbs = all_verbs (file_verbs, row); 
  
  for (int i = 0; i < row; i++)
    printf ("%s-%s\n", verbs[i].ita, verbs[i].deu);

  const char *verbo = "haben";
  if (exist_verb_deu (verbs, verbo, row) == true)
    printf ("Il verbo Tedesco %s Esiste\n", verbo);

  char *random_verb_ita = random_verb(verbs, row);

  puts (translate_verb (verbs, random_verb_ita, "haben", row) ? "true" : "false");

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

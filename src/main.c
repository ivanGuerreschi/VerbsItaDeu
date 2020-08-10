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
#include "include/menu.h"

int
main (int argc, char *argv[])
{
  int menu = 0;
  
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
	case 0:
	  exit (1);
	  break;

	case 1:
	  for (int i = 0; i < row; i++)
	    printf ("%s-%s\n", verbs[i].ita, verbs[i].deu);
	  break;

	case 2:
	  printf ("%s\n", random_verb_ita (verbs, row));
	  break;

	case 3:
	  printf ("%s\n", random_verb_deu (verbs, row));
	  break;

	case 4:
	  printf ("%s\n", "Enter Deu verb");
	  char *verb = NULL;
	  /* ISO C does not support the 'm' scanf flag */
	  scanf ("%ms", &verb);
	  if (verb)
	    puts (exist_verb_deu (verbs, verb, row) ? "true" : "false");
	 
	  free (verb);
	  break;
	}
    }
 
  /* const char *verbo = "haben"; */
  /* if (exist_verb_deu (verbs, verbo, row) == true) */
  /*   printf ("Il verbo Tedesco %s Esiste\n", verbo); */

  /* char *random_verb_ita = random_verb(verbs, row); */

  /* puts (translate_verb (verbs, random_verb_ita, "haben", row) ? "true" : "false"); */

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

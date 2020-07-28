/* libverbs.c
   Copyright (C) 2020 Ivan Guerreschi

This file is part of verbsitadeu.

Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>

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
#include "verbs.h"

void
all_verbs ()
{
  FILE *fp;
  verb_t *verb = malloc(100 * sizeof(verb_t));
  int n = 0;
  int res = 0;

  fp = fopen ("verbs.dat", "r");
  if (fp == NULL)
    {
      perror ("Error open file");
      exit (1);
    }

  while (1)
    {
      res = fscanf (fp, "%s", verb[n].ita);
      if (res != 1)
	break;

      res = fscanf (fp, "%s", verb[n].deu);
      if (res != 1)
	{
	  perror ("Error read file");
	  exit (1);
	}

      n++;
    }

  for (int i = 0; i <= n - 1; i++)
    {
      printf ("%s-%s\n", verb[i].ita, verb[i].deu);
    }

  fclose (fp);
}



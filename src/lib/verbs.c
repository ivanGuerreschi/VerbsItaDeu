/* verbs.c
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
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "verbs.h"

FILE*
open_file ()
{
  FILE *fp;
  fp = fopen ("verbs.dat", "r");
  if (fp == NULL)
    {
      perror ("Error open file");
      exit (1); 
    }

  return fp;
}

verb_t
*all_verbs (FILE *fp, int row)
{  
  verb_t *verb = malloc (row * sizeof(verb_t));
  int n = 0;
  
  while (1)
    {
      verb[n].ita = malloc (20 * sizeof(char));
      verb[n].deu = malloc (20 * sizeof(char));

      if (fscanf (fp, "%s%s", verb[n].ita, verb[n].deu) != 2)
	break;     

      n++;
    }

  fclose (fp);
  
  return verb;
}

int
count_row_file (FILE *fp)
{
  char c;
  int count = 1;
  for (c = getc(fp); c != EOF; c = getc(fp)) 
    if (c == '\n') 
      count++;
  
  return count;
  
  fclose (fp);
}

bool
exist_verb_deu (verb_t *verbs,
		const char *verb,
		int row)
{
  bool compare = false;
  
  for (int i = 0; i < row; i++)
    {
      if (strcmp (verbs[i].deu, verb) == 0);
      compare = true;
    }

  return compare;
}

bool
translate_verb(verb_t *verbs,
	       const char *verb,
	       int row)
{
  bool translate = false;
  
  return translate;
}


char
*random_verb (verb_t *verbs, int row)

{
  time_t t;
  char *random_verb;
  
  srand ((unsigned) time (&t));
  
  random_verb = verbs[rand () % row].ita;
 
  return random_verb;
}

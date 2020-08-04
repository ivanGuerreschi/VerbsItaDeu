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

void
open_file (FILE **file, const char *name_file)
{    
  if ((*file = fopen (name_file, "r")) == NULL)
    {
      perror ("Error open file");
      exit (1); 
    }  
}

void
close_file (FILE **file)
{
  if (fclose (*file) != 0)
    perror ("Error close file");        
}

verb_t
*all_verbs (FILE *file, int row)
{  
  verb_t *verb = malloc (row * sizeof (verb_t)); 
  int n = 0;
  
  while (1)
    {       
      if (fscanf (file, "%s%s", verb[n].ita, verb[n].deu) != 2)
	break;     

      n++;
    }  
  
  return verb;  
}

int
count_row_file (FILE *file)
{
  char c;
  int count = 1;
  for (c = getc(file); c != EOF; c = getc(file)) 
    if (c == '\n') 
      count++;
 
  return count;
}

bool
exist_verb_deu (verb_t *verbs,
		const char *verb,
		int row)
{
  bool compare = false;
  
  for (int i = 0; i < row; i++)
    {
      if (strcmp (verbs[i].deu, verb) == 0)
	compare = true;
    }

  return compare;
}

bool
translate_verb(verb_t *verbs,
	       const char *verb_ita,
	       const char *verb_deu,
	       int row)
{
  bool translate = false;

  for (int i = 0; i < row; i++)
    if (strcmp (verbs[i].ita, verb_ita) == 0)
      if (strcmp (verbs[i].deu, verb_deu) == 0) 
	translate = true;

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

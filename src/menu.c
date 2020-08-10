/* menu.c
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

int
print_menu (void)
{
  int number_input = 0;
 
  printf ("%s\n", "----------------------------------------------");
  printf ("%s\n\n", "VerbsItaDeu");
  printf ("%s\n", "(0, 1, 2, 3, 4)Input number");
  printf ("%s\n", "(0) Quit ");
  printf ("%s\n", "(1) Print all verbs"); 
  printf ("%s\n", "(2) Random verb Ita");
  printf ("%s\n", "(3) Random verb Deu");
  printf ("%s\n", "(4) Exist verb Deu?");
  printf ("%s\n", "----------------------------------------------");
  
  if (scanf ("%d", &number_input) != 1)
    {
      printf ("%s\n", "Error input, please enter number (0, 1, 2, 3, 4");
      scanf("%*s");
      number_input = 1;
    }       
  
  return number_input;  
}
  
  

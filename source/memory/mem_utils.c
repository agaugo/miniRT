#include "../../includes/minirt.h"

void free_tokens(char **tokens)
{
  int i;

  i = 0;
  if (!tokens)
    return ;
  while (tokens[i] != NULL)
  {
    free(tokens[i]);
    i++;
  }
  free(tokens);
} 

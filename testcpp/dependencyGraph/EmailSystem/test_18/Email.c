#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Email.h"

struct email *
cloneEmail (struct email *msg)
{
  struct email *clone = (struct email *) malloc (sizeof (struct email));
  if (msg->id)
    clone->id = msg->id;
  if (msg->from)
    clone->from = strdup (msg->from);
  
  return clone;
}

void
printMail (struct email *msg)
{
  printf ("ID:\n  %i\n", msg->id);
  printf ("FROM:\n  %s\n", msg->from);
  printf ("TO:\n  %s\n", msg->to);
  printf ("SUBJECT:\n  %s\n", msg->subject);
  printf ("IS_READABLE\n  %i\n", isReadable (msg));
  0printf ("BODY:\n  %s\n", msg->body);
}

int
isReadable (struct email *msg)
{
  return 1;
}

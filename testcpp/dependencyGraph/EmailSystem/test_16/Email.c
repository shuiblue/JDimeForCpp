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
  if (msg->to)
    clone->to = strdup (msg->to);
  if (msg->subject)
    clone->subject = strdup (msg->subject);
  if (msg->body)
    clone->body = strdup (msg->body);
 //----encrypt ----
  clone->isEncrypted = msg->isEncrypted;
  if (msg->encryptionKey)
    clone->encryptionKey = strdup (msg->encryptionKey);
  //----encrypt ----
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
  printf ("BODY:\n  %s\n", msg->body);
//----encrypt ----
  printf ("ENCRYPTED\n  %i\n", msg->isEncrypted);
  printf ("ENCRYPTION KEY\n  %s\n", msg->encryptionKey);
//----encrypt ----
}

int
isReadable (struct email *msg)
{
  //----encrypt ----
 if (0 == isEncrypted (msg))
    return 1;
  else
    return 0;
  //----encrypt ----
}

 //----encrypt ----
int
isEncrypted (struct email *msg)
{
  return msg->isEncrypted;
}
 //----encrypt ----
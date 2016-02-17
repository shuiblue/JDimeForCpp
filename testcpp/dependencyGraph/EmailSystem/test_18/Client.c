#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Client.h"

// outgoing emails leave the client at this point. here they are put in an outgoing queue instead.
void
mail (struct client *client, struct email *msg)
{
  //----encrypt ----
// VERIFICATION HOOK
  int verificationHook_isEncrypted = isEncrypted (msg);
  printf ("mail:\nisEncrypted = %i\nid = %i\n", verificationHook_isEncrypted,
    msg->id);
// VERIFICATION HOOK END
//----encrypt ----
  
  //TODO 
//  printf ("=> %s MAIL\n", client->name);
//  printMail (msg);
  if (!client->outgoingBuffer)
    client->outgoingBuffer = list_create (msg);
  else
    list_insert_after (client->outgoingBuffer, msg);
}

// emails to be sent are processed by this method before beeing mailed.
void
outgoing (struct client *client, struct email *msg)
{
   //----encrypt ----
   encrypt (client, msg);
    //----encrypt ----

  //----addressBook ----
  resolveAlias (client, msg);
  //----addressBook ----

  msg->from = strdup (client->name);
  mail (client, msg);
}

// incoming emails reach the user at this point. here they are put in a mailbox.
void
deliver (struct client *client, struct email *msg)
{
  //TODO
  // printf ("=> %s DELIVER\n", client->name);
  //printMail (msg);
}

// incoming emails are processed by this method before delivery.
void
incoming (struct client *client, struct email *msg)
{
  //-----decrypt----
// VERIFICATION HOOK
  int verificationHook_isEncrypted = isEncrypted (msg);
  printf ("incoming:\nisEncrypted = %i\nid = %i\n",
    verificationHook_isEncrypted, msg->id);
// VERIFICATION HOOK END
  decrypt (client, msg);
//-----decrypt----
  
  autoRespond (client, msg);
  deliver (client, msg);
}

//----addressBook ----
int
findAddressBookEntry (void *listdata, void *searchdata)
{
  return strcmp
    (((struct addressBookEntry *) listdata)->alias,
     (char *) searchdata) ? 0 : 1;
}

void
resolveAlias (struct client *client, struct email *msg)
{
  if (!client->addressBook)
    return;
  struct email *clone = cloneEmail (msg);
  NODE *found =
    list_find (client->addressBook, findAddressBookEntry, clone->to);
  if (!found)
    return;
  NODE *address = ((struct addressBookEntry *) found->data)->address;
  if (address)
    {
      msg->to = strdup (address->data);
      address = address->next;
    }
  while (address)
    {
      struct email *newmsg = cloneEmail (clone);
      newmsg->to = strdup (address->data);
      address = address->next;
      outgoing (client, newmsg);
    }
}
//----addressBook ----

//----autoResponder ----
void
autoRespond (struct client *client, struct email *msg)
{
  if (!client->autoResponse || !isReadable (msg))
    return;
  struct email *response = cloneEmail (msg);
  response->to = strdup (msg->from);
  response->body = strdup (client->autoResponse);
  char *respondPrefix = "Auto-Response ";
  response->subject =
    (char *) malloc (strlen (respondPrefix) + strlen (msg->subject));
  strcat (response->subject, respondPrefix);
  strcat (response->subject, msg->subject);
  outgoing (client, response);
}
//----autoResponder ----

//----encrypt ----
void
encrypt (struct client *client, struct email *msg)
{
  NODE *foundPublicKeyPair =
    list_find (client->userPublicKeyPairs, findUserPublicKeyPair, msg->to);
  if (foundPublicKeyPair)
    {
      msg->encryptionKey =
  strdup (((struct userPublicKeyPair *) foundPublicKeyPair->data)->
    publicKey);
      msg->isEncrypted = 1;
    }
}
//----encrypt ----

//-----decrypt----
// removes the decryption flag if possible
void
decrypt (struct client *client, struct email *msg)
{
// VERIFICATION HOOK
  int verificationHook_isKeyPairValid =
    isKeyPairValid (msg->encryptionKey, client->privateKey);
// printf ("\n> hook\n%i\n\n", verificationHook_isKeyPairValid);
// VERIFICATION HOOK END
  if (!client->privateKey)
    return;
  if (msg->isEncrypted == 1
      && 0 == strcmp (msg->encryptionKey, client->privateKey))
    {
      msg->encryptionKey = NULL;
      msg->isEncrypted = 0;
    }
}
//-----decrypt----


//-----keys----
int
findUserPublicKeyPair (void *listdata, void *searchdata)
{
  if (!listdata || !searchdata)
    return 0;
  return strcmp
    (((struct userPublicKeyPair *) listdata)->user,
     (char *) searchdata) ? 0 : 1;
}

int
isKeyPairValid (char *publicKey, char *privateKey)
{
  if (!publicKey || !privateKey)
    return 0;
  return strcmp (publicKey, privateKey) ? 0 : 1;
}
//-----keys----



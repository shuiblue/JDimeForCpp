
// outgoing emails leave the client at this point. here they are put in an outgoing queue instead.
void
mail (struct client *client, struct email *msg)
{
  //TODO 
//  printf ("=> %s MAIL\n", client->name);
//  printMail (msg);
  if (!client->outgoingBuffer)
    client->outgoingBuffer = list_create (msg);
  else
    list_insert_after (client->outgoingBuffer, msg);
}

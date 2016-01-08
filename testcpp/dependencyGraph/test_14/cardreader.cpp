void
mail (struct client *client, struct email *msg)
{
  //TODO 
//  printf ("=> %s MAIL\n", client->name);
//  printMail (msg);
  if (!client->outgoingBuffer)
{
  client->outgoingBuffer = list_create (msg);
  client->outgoingBuffer = list_create(bbb);
}
else
    list_insert_after (client->outgoingBuffer, msg);
}

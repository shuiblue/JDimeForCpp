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

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
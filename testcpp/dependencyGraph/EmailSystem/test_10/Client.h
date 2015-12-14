
struct client
{
  char *name;
  NODE *outgoingBuffer;
};

void outgoing (struct client *client, struct email *msg);

void incoming (struct client *client, struct email *msg);

#include "Email.h"
#include "slist.h"

/*
 * two sorts of emails are processed by this client: incoming and outgoing ones.
 * control flow is
 * email from internet > incoming > deliver > receipient receives mail
 * sender writes email > outgoing > mail > email sent through internet
 */
struct client
{
  char *name;
  NODE *outgoingBuffer;
  NODE *addressBook;
  char *autoResponse;
  //----keys----
  NODE *userPublicKeyPairs;
  char *privateKey;
  //----keys----
};

struct addressBookEntry
{
  char *alias;
  NODE *address;
};
  //----keys----
struct userPublicKeyPair
{
  char *user;
  char *publicKey;
};
  //----keys----
void outgoing (struct client *client, struct email *msg);

void incoming (struct client *client, struct email *msg);

// TODO remove after fixing the composition-function-order-problem
void resolveAlias (struct client *client, struct email *msg);

void autoRespond (struct client *client, struct email *msg);

//-----encrypt----
// TODO remove
void encrypt (struct client *client, struct email *msg);
//-----encrypt----

//-----decrypt----
// TODO remove
void decrypt (struct client *client, struct email *msg);
//-----decrypt----

int isKeyPairValid (char *publicKey, char *privateKey);

struct link {
   void* value;
   struct link * next;
};
struct listQueue {
   struct link *firstLink;
   struct link *lastLink;
};
void listQueueInit (struct listQueue *q) {
   struct link *lnk = (struct link *) malloc(sizeof(struct link));
   assert(lnk != 0); /* lnk is the sentinel */
   lnk->next = 0;
   q->firstLink = q->lastLink = lnk;
}
void listQueueAddBack (struct listQueue *q, void* e) 
{
}
void* listQueueFront (struct listQueue *q) 
{
}
void listQueueRemoveFront (struct listQueue *q) 
{
}
int listQueueIsEmpty (struct listQueue *q) 
{
}
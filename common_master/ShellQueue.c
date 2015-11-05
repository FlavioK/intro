/**
 * \file
 * \brief Shell Message Queue module.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module uses queues for message passing to the Shell.
 */

#include "Platform.h"
#if PL_CONFIG_HAS_SHELL_QUEUE
#include "ShellQueue.h"
#include "FRTOS1.h"

static xQueueHandle SQUEUE_Queue;

#define SQUEUE_LENGTH      32 /* items in queue, that's my buffer size */
#define SQUEUE_ITEM_SIZE   1  /* each item is a single character */

void SQUEUE_SendString(const unsigned char *str) {
  /*! \todo Implement function */
}

unsigned char SQUEUE_ReceiveChar(void) {
  /*! \todo Implement function */
}

unsigned short SQUEUE_NofElements(void) {
  return (unsigned short)FRTOS1_uxQueueMessagesWaiting(SQUEUE_Queue);
}

void SQUEUE_Deinit(void) {
  FRTOS1_vQueueUnregisterQueue(SQUEUE_Queue);
  FRTOS1_vQueueDelete(SQUEUE_Queue);
  SQUEUE_Queue = NULL;
}

void SQUEUE_Init(void) {
  SQUEUE_Queue = FRTOS1_xQueueCreate(SQUEUE_LENGTH, SQUEUE_ITEM_SIZE);
  if (SQUEUE_Queue==NULL) {
    for(;;){} /* out of memory? */
  }
  FRTOS1_vQueueAddToRegistry(SQUEUE_Queue, "ShellQueue");
}
#endif /* PL_CONFIG_HAS_SHELL_QUEUE */

#ifndef TXN_JSON_DECODE_H
#define TXN_JSON_DECODE_H

#include "../jsmn.h"

// Define few macros that is only define din Ledger and not available
// to us for standalone testing.

#define MAX(X, Y) (X) > (Y) ? (X) : (Y)
#define MIN(X, Y) (X) < (Y) ? (X) : (Y)

#include "stdio.h"
#define PRINTF(...) fprintf(stderr, __VA_ARGS__)

#include <stdlib.h>
#define FAIL(...) PRINTF(__VA_ARGS__); abort()

#define CHECK_CANARY

#define MAX_NUM_TOKENS 24

typedef struct
{
  jsmntok_t tokens[MAX_NUM_TOKENS];
  int total_tokens;
} Tokens;

int process_json(Tokens *tokens, const char jsonBuf[], int jsonBufLen, char *output, int output_size);

#endif // TXN_JSON_DECODE_H
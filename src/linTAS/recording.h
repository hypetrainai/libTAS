#include <stdio.h>
#include <unistd.h>
#include "../shared/inputs.h"

#define HEADER_SIZE 256

FILE* openRecording(const char* filename, int recording);
void writeHeader(FILE* fp);
void readHeader(FILE* fp);
int writeFrame(FILE* fp, unsigned long frame, struct AllInputs inputs);
int readFrame(FILE* fp, unsigned long frame, struct AllInputs* inputs);
void truncateRecording(FILE* fp);
void closeRecording(FILE* fp);

#include <stdio.h>
#include <stdlib.h>
#include "audio_processor.h"

int main( int argc, char *argv[]) {

    if (argc == 3) {
        printf("Processing audio file %s into %s.\n", argv[1], argv[2]);
    } else {
        printf("Arguments error. Usage: OfflineAudioProcessor INPUT OUTPUT.");
        return -1;
    }

    // try to open input file
    FILE* inputFileHandler = fopen(argv[1],"rb");
    if (inputFileHandler == NULL) {
        printf("Failed to open input file.");
        return -1;
    }

    // try to create output file
    FILE* outputFileHandler = fopen(argv[2],"wb");
    if (outputFileHandler == NULL) {
        printf("Failed to create output file.");
        return -1;
    }

    // prepare audio processor and processing buffer
    AudioProcessor * processor = new_audio_processor(1.0f);
    unsigned int bufferSize = 4096;
    float * buffer = calloc(bufferSize, sizeof(float));

    // main processing loop
    size_t readSize = 0;
    size_t writeSize = 0;
    while (readSize = fread(buffer, sizeof(float), bufferSize, inputFileHandler)) {
        printf("Processing %d frames...\n", readSize);
        ap_process(processor, buffer, readSize);
        size_t writeSize = fwrite(buffer, sizeof(float), readSize, outputFileHandler);
        if (writeSize != readSize) {
            printf("Failed to write into output file. %d, %d", readSize, writeSize);
            return -1;
        }
    }

    // clean up
    destroy_audio_processor(processor);
    free(buffer);

    // finish
    printf("Processing done. Output file : %s.", argv[2]);

    return 0;
}


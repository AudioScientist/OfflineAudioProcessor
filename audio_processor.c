//
// Created by Thomas Hezard on 24/03/2018.
//

#include "audio_processor.h"
#include <stdlib.h>


// alloc an AudioProcessor, initialize all data members, pre-allocate memory if needed
AudioProcessor* new_audio_processor(float gain) {

    AudioProcessor* newProcessor = (AudioProcessor*)calloc(1,sizeof(AudioProcessor));

    if (gain < 0.0f) {
        gain = 0.0f;
    }
    if (gain > 1.0f) {
        gain = 1.0f;
    }
    newProcessor->gain = gain;

    return newProcessor;
}


// free AudioProcessor and its allocated members if needed
void destroy_audio_processor(AudioProcessor* processor) {

    free(processor);
}


// process function, plug it to your main audio signal process flow
void ap_process(AudioProcessor* processor, float * ioBuffer, unsigned int numberFrames) {

    float gain = processor->gain;
    for (unsigned int i=0; i<numberFrames; ++i) {
        ioBuffer[i] *= gain;
    }
}
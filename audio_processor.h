//
// Created by Thomas Hezard on 24/03/2018.
//

#ifndef AUDIO_ECHO_AUDIO_PROCESSOR_H
#define AUDIO_ECHO_AUDIO_PROCESSOR_H


#ifdef __cplusplus
extern "C" {
#endif


    typedef struct AudioProcessor {

        // persistent data members
        // ex: float           sampleRate;
        float           gain;


        // pre-allocated memory
        // ex: | float *         memoryBuffer;
        //     | unsigned int    memoryBufferLength;

    }AudioProcessor;

    // alloc an AudioProcessor, initialize all data members, pre-allocate memory if needed
    AudioProcessor* new_audio_processor(float gain);

    // free AudioProcessor and its allocated members if needed
    void destroy_audio_processor(AudioProcessor* processor);

    // process function, plug it to your main audio signal process flow
    void ap_process(AudioProcessor* processor, float * ioBuffer, unsigned int numberFrames);


#ifdef __cplusplus
}
#endif



#endif //AUDIO_ECHO_AUDIO_PROCESSOR_H

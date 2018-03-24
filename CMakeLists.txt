cmake_minimum_required(VERSION 3.9)
project(OfflineAudioProcessor C)

set(CMAKE_C_STANDARD 99)

set(SRCS
        main.c
        audio_processor.c)

set(HDRS
        audio_processor.h)

add_executable(OfflineAudioProcessor ${SRCS} ${HDRS})
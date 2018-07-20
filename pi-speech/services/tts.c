#include "tts.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char * list[] = {VOICE_FEMALE1,VOICE_FEMALE2,VOICE_MALE1,VOICE_MALE2};

void tts_read (const char *text)
{
    char *cl_start = "echo '";
    char *cl_end = "' | festival --tts";
    char str[255];

    strcpy(str, cl_start);
    strcat(str, text);
    strcat(str, cl_end);

    system(str);
}

void tts_read_with (const char *text_start, const char *text)
{
    char *cl_start = "echo '";
    char *cl_end = "' | festival --tts";
    char str[255];

    strcpy(str, cl_start);
    strcat(str, text_start);
    strcat(str, text);
    strcat(str, cl_end);

    system(str);
}


void tts_set_voice (const char *voice)
{
    int i;
    for(i=0; i<4; i++) {
        if (strstr(list[i], voice) != NULL) {
            char *cl_start = "sudo echo \"(set! voice_default \'";
            char *cl_end = ")\" >  /home/pi/.festivalrc";
            char str[80];

            strcpy(str, cl_start);
            strcat(str, voice);
            strcat(str, cl_end);

            system(str);
            break;
        }
    }
}

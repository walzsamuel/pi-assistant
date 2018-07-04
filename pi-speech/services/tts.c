#include "tts.h"
#include <stdlib.h>
#include <string.h>

void tts_read (const char *text)
{
    char *cl_start = "echo 'You Said: ";
    char *cl_end = "' | festival --tts";
    char str[255];

    strcpy(str, cl_start);
    strcat(str, text);
    strcat(str, cl_end);

    system(str);
}


void tts_change_voice (const char *voice)
{
    if (voice == VOICE_MALE1 || voice == VOICE_MALE2 || voice == VOICE_FEMALE1 || voice == VOICE_FEMALE2) {
        char *cl_start = "sudo echo '(set! voice_default \'";
        char *cl_end = ")' >>  home/pi/.festivalrc";
        char str[80];

        strcpy(str, cl_start);
        strcat(str, voice);
        strcat(str, cl_end);

        system(str);
    }
}

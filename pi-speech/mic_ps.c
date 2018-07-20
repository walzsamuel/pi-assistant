#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>
#include "services/tts.h"

const char * recognize_from_microphone();

ps_decoder_t *ps;                  // create pocketsphinx decoder structure
cmd_ln_t *config;                  // create configuration structure
ad_rec_t *ad;                      // create audio recording structure - for use with ALSA functions

int16 adbuf[4096];                 // buffer array to hold audio data
uint8 utt_started, in_speech;      // flags for tracking active speech - has speech started? - is speech currently happening?
int32 k;                           // holds the number of frames in the audio buffer
char const *hyp;                   // pointer to "hypothesis" (best guess at the decoded result)
char const *decoded_speech;
bool is_tts_voice_female;

int main(int argc, char *argv[])
{

    config = cmd_ln_init(NULL, ps_args(), TRUE,                         // Load the configuration structure - ps_args() passes the default values
        "-hmm", "/usr/local/share/pocketsphinx/model/en-us/en-us",      // path to the standard english language model
        "-lm", "models/pi_commands.lm",                                 // custom language model (file must be present)
        "-dict", "models/pi_commands.dic",                              // custom dictionary (file must be present)
        "-logfn", "/dev/null",                                          // suppress log info from being sent to screen
        NULL);

    ps = ps_init(config);                                                        // initialize the pocketsphinx decoder
    // ad = ad_open_dev("plughw:1,0", (int) cmd_ln_float32_r(config, "-samprate")); // open default microphone at default samplerate
    ad = ad_open_dev("plughw:1,0", 16000);

    tts_set_voice(VOICE_FEMALE1);
    is_tts_voice_female = true;

    while(1) {
        decoded_speech = recognize_from_microphone();                    // call the function to capture and decode speech
        if (strcmp ("", decoded_speech) != 0) {
            printf("You Said: %s\n", decoded_speech);

            // string search    if(strstr(string, "WEATHER"))
            // string compare   if(strcmp(string, "WEATHER"))

            if (strstr(decoded_speech, "WEATHER")) {
                tts_read("The weather in Karlsruhe is sonny with 26 degree Celsius");
            }  else if (strstr(decoded_speech, "NEED HELP")) {
                tts_read("I am sorry. .. I can not help you");
            } else if (strstr(decoded_speech, "MUSIC")) {
                tts_read("Now Playing .. Sleep Away .. from Bob Acri");
                system("sudo mpg123 -n 313 /home/pi/music/sleep_away.mp3");
            }  else if (strstr(decoded_speech, "TODAY")) {
                tts_read("Today is the 19 July 2018");
            }  else if (strstr(decoded_speech, "TOMORROW")) {
                tts_read("Tomorrow is the 20 July 2018");
            }  else if (strstr(decoded_speech, "SHUT DOWN")) {
                if (is_tts_voice_female) {
                    tts_read("System is shutting down now! in 3.. 2.. 1.. go............................ just a prank");
                } else {
                    tts_read("System is shutting down now. Not really!");
                }
            }  else if (strstr(decoded_speech, "WIKI")) {
                tts_read("Wikipedia access is still under construction");
            }  else if (strstr(decoded_speech, "CHANGE VOICE")) {
                if (is_tts_voice_female) {
                    tts_set_voice(VOICE_MALE1);
                    is_tts_voice_female = false;
                    tts_read("Hello everyone! I am Mr. Smith");

                } else {
                    tts_set_voice(VOICE_FEMALE1);
                    is_tts_voice_female = true;
                    tts_read("Good day, i am Tiffany");
                }
            }  else if (strstr(decoded_speech, "TIME")) {
                time_t now;
            	now = time(0);
                tts_read(ctime(&now));
            }
//            else {
//              tts_read(decoded_speech);
//            }
        }

    }

     ad_close(ad);                                                       // close the microphone
}

const char * recognize_from_microphone()
{

    ad_start_rec(ad);                                // start recording
    ps_start_utt(ps);                                // mark the start of the utterance
    utt_started = FALSE;                             // clear the utt_started flag

    while(1) {
        k = ad_read(ad, adbuf, 4096);                // capture the number of frames in the audio buffer
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder

        in_speech = ps_get_in_speech(ps);            // test to see if speech is being detected

        if (in_speech && !utt_started) {             // if speech has started and utt_started flag is false
            utt_started = TRUE;                      // then set the flag
        }

        if (!in_speech && utt_started) {             // if speech has ended and the utt_started flag is true
            ps_end_utt(ps);                          // then mark the end of the utterance
            ad_stop_rec(ad);                         // stop recording
            hyp = ps_get_hyp(ps, NULL );             // query pocketsphinx for "hypothesis" of decoded statement
            return hyp;                              // the function returns the hypothesis
            break;                                   // exit the while loop and return to main
        }
    }
}

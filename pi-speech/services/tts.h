#ifndef TTS_H
#define TTS_H

#define VOICE_FEMALE1 "voice_cmu_us_slt_arctic_clunits"
#define VOICE_FEMALE2 "voice_cmu_us_clb_arctic_clunits"
#define VOICE_MALE1 "voice_cmu_us_bdl_arctic_clunits"
#define VOICE_MALE2 "voice_cmu_us_awb_arctic_clunits"


extern void tts_read(const char *);
extern void tts_read_with(const char *, const char *);
extern void tts_set_voice(const char *);


#endif /* TTS_H */

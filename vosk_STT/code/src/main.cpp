#include <vosk_api.h>
#include <fstream>

int main()
{
    VoskModel *model = vosk_model_new("vosk-model-small-en-us-0.15");
    VoskRecognizer *recognizer = vosk_recognizer_new(model, 16000.0);

    std::ifstream audio_file("test.wav", std::ios::binary);
    char buffer[4096];

    while (audio_file.read(buffer, sizeof(buffer)))
    {
        if (vosk_recognizer_accept_waveform(recognizer, buffer, audio_file.gcount()))
        {
            printf("%s\n", vosk_recognizer_result(recognizer));
        }
    }

    printf("%s\n", vosk_recognizer_final_result(recognizer));
    vosk_recognizer_free(recognizer);
    vosk_model_free(model);
    return 0;
}

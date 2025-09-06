#include <vosk_api.h>
#include <portaudio.h>  // 用于音频输入

int main() {
    // 初始化 Vosk
    VoskModel *model = vosk_model_new("vosk-model-small-en-us-0.15");
    VoskRecognizer *recognizer = vosk_recognizer_new(model, 16000.0);

    // 初始化 PortAudio
    Pa_Initialize();
    PaStream *stream;
    Pa_OpenDefaultStream(&stream, 1, 0, paInt16, 16000, 256, NULL, NULL);
    Pa_StartStream(stream);

    // 实时识别
    short buffer[4096];
    while (1) {
        Pa_ReadStream(stream, buffer, 4096);
        if (vosk_recognizer_accept_waveform_s(recognizer, buffer, 4096)) {
            printf("%s\n", vosk_recognizer_result(recognizer));
        }
    }

    // 清理
    vosk_recognizer_free(recognizer);
    vosk_model_free(model);
    Pa_StopStream(stream);
    Pa_Terminate();
    return 0;
}
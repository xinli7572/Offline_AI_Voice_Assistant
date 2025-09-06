#include <vosk_api.h>
#include <portaudio.h>  // ������Ƶ����

int main() {
    // ��ʼ�� Vosk
    VoskModel *model = vosk_model_new("vosk-model-small-en-us-0.15");
    VoskRecognizer *recognizer = vosk_recognizer_new(model, 16000.0);

    // ��ʼ�� PortAudio
    Pa_Initialize();
    PaStream *stream;
    Pa_OpenDefaultStream(&stream, 1, 0, paInt16, 16000, 256, NULL, NULL);
    Pa_StartStream(stream);

    // ʵʱʶ��
    short buffer[4096];
    while (1) {
        Pa_ReadStream(stream, buffer, 4096);
        if (vosk_recognizer_accept_waveform_s(recognizer, buffer, 4096)) {
            printf("%s\n", vosk_recognizer_result(recognizer));
        }
    }

    // ����
    vosk_recognizer_free(recognizer);
    vosk_model_free(model);
    Pa_StopStream(stream);
    Pa_Terminate();
    return 0;
}
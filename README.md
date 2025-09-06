

#  Offline AI Voice Assistant Prototype 
#  Java springboot/Android --> C++ Backend


https://github.com/user-attachments/assets/8470d2bd-a5ef-403f-8369-0f5a830b5a53



> 🎙️ This project is a prototype of an **offline AI voice assistant**, featuring three locally-deployed AI components:
> - **Speech Recognition (STT)** using Vosk,
> - **Language Modeling (LLM)** using TinyLLaMA via llama.cpp,
> - **Text-to-Speech (TTS)** using Piper.

It also includes **Java-based Web and Android clients**, both communicating with the C++ backend through sockets.

---

## ✅ Current Project Status

The project includes:

| Component            | Description                                                   | Status       |
|----------------------|---------------------------------------------------------------|--------------|
| 🧠 **TinyLLaMA**      | Lightweight language model via llama.cpp (C++ wrapper)         | ✅ Tested     |
| 🗣️ **Vosk**          | Offline speech recognition engine (C++ interface)             | ✅ Tested     |
| 🔊 **Piper**         | Local text-to-speech engine using ONNX models (C++ interface) | ✅ Tested     |
| 🌐 **Java Web UI**   | HTML + JS browser-based frontend with socket communication    | ✅ Functional |
| 📱 **Android Client**| Native Android app using socket communication                 | ✅ Functional |
| ⚙️ **Install Scripts**| Individual setup scripts and test code for each model         | ✅ Provided   |

> Each model is **tested individually** with standalone C++ test programs.

---

## 📦 Project Structure
```
offline-voice-ai/
├── models/ # Model directories (downloaded via scripts)
│ ├── vosk/
│ ├── piper/
│ └── tinyllama/
├── cpp-tests/ # C++ test programs for each model
│ ├── vosk_test.cpp
│ ├── llama_test.cpp
│ └── piper_test.cpp
├── java-web/ # Java-based Web UI (HTML + WebSocket)
│ ├── index.html
│ └── ...
├── android-client/ # Android client (native Java/Kotlin)
│ └── app/
├── setup/ # Shell scripts for model installation (written by author)
│ ├── install_vosk.sh
│ ├── install_piper.sh
│ └── install_llama.sh
├── README.md
└── docs/ # Documentation and screenshots
```


---

## 📋 C++ Model Test Instructions

###  1. Vosk STT Test

```bash
cd cpp-tests
g++ -std=c++17 -lstdc++ -Wall  -I/usr/src/vosk_stt/include  -c main.cpp -o main.o
g++ -std=c++17  -lstdc++ -o vosks main.o  -L/usr/src/vosk_stt/lib  -lvosk -Wl,--copy-dt-needed-entries -Wl,-rpath=/usr/src/vosk_stt/lib -lm -lpthread -ldl  /usr/lib/x86_64-linux-gnu/libpthread.a

```
Output: Recognized text from audio.

### 2. TinyLLaMA LLM Test

```bash
cd cpp-tests
	./llama-cli \
	  -m /usr/src/llama.cpp/build/bin/tinyllama-1.1b-chat-v1.0.Q4_K_S.gguf\
	  --temp 0.6 \
	  --top-k 20 \
	  --top-p 0.5 \
	  --repeat-penalty 1.2
```
Output: AI-generated response.

### 3. Piper TTS Test

```bash
cd cpp-tests
g++ -std=c++17 -lstdc++ -Wall  -I/usr/src/piper_tts/cpp -I/usr/src/piper_tts/pi/include  -c main.cpp -o main.o
g++ -std=c++17 -lstdc++ -Wall  -I/usr/src/piper_tts/cpp -I/usr/src/piper_tts/pi/include  -c piper.cpp -o piper.o
g++ -std=c++17  -lstdc++ -o pipers main.o piper.o -L/usr/src/piper_tts/pi/lib  -lonnxruntime -lpiper_phonemize -lespeak-ng -Wl,--copy-dt-needed-entries -Wl,-rpath=/usr/src/piper_tts/pi/lib -lm -lpthread  /usr/lib/x86_64-linux-gnu/libpthread.a

```
Output: reply.wav audio file with synthesized speech.

##  Java Web Frontend

- Open `java-web/index.html` in your browser.
- Uses **Java WebSocket client** to connect with the local **C++ backend**.
- Supports:
  - 🎤 Microphone input
  - 🧠 Real-time AI response display
  - 🔊 Audio playback of AI-generated reply

---

##  Android Client

- Import `android-client/` into **Android Studio**.
- Update the backend server IP address (`192.168.x.x`).
- Build and run on **Android 8.0+** devices.
- Features:
  - 🎤 Voice input
  - 💬 Text response display
  - 🔊 Audio playback

---

##  Notes

- This project is currently a **prototype and module testbed**.
- Models are **not yet integrated into a unified backend server**.
- Each component is designed for **independent testing**.
- Integration and orchestration are left to the user for **custom development**.

---

## ✍ Author Note

- All **C++ test code**, **installation scripts**, and **communication logic** were developed by the author.
- The goal is to demonstrate **fully offline AI voice interaction** using **open-source models**.
- Contributions, forks, and custom adaptations are welcome.

---

##  License

This project is released under the **MIT License**.

Each AI model follows its respective original license:

| Model      | Source                                         | License     |
|------------|------------------------------------------------|-------------|
| **Vosk**   | [https://github.com/alphacep/vosk-api/releases](https://github.com/alphacep/vosk-api/releases)             | Apache 2.0  |
| **TinyLLaMA** | [https://huggingface.co/TheBloke/TinyLlama-1.1B-Chat-v1.0-GGUF](https://huggingface.co/TheBloke/TinyLlama-1.1B-Chat-v1.0-GGUF) | MIT         |
| **Piper**  | [https://github.com/rhasspy/piper?tab=readme-ov-file](https://github.com/rhasspy/piper?tab=readme-ov-file)       | MIT         |


## Contact

For questions or collaboration requests, please open a GitHub issue or fork the project.


---

### 🔧 Optional Additions

If you want, I can also provide:

- `.gitignore` for C++/Java/Android projects  
- `LICENSE` file (MIT)  
- `CONTRIBUTING.md` template  
- Badges (for GitHub Actions, License, etc.)

Let me know if you'd like to include those.

---




















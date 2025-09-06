

# 🧠 Offline AI Voice Assistant Prototype (C++ Backend + Java Web + Android)



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
g++ vosk_test.cpp -o vosk_test -lvosk
./vosk_test sample.wav
```
Output: Recognized text from audio.

### 2. TinyLLaMA LLM Test

```bash
cd cpp-tests
g++ llama_test.cpp -o llama_test -L/path/to/llama.cpp/lib
./llama_test "Hello, who are you?"
```
Output: AI-generated response.

### 3. Piper TTS Test

```bash
cd cpp-tests
g++ piper_test.cpp -o piper_test -lpiper
./piper_test "Hello, I am your voice assistant"
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
| **Vosk**   | [https://alphacephei.com/vosk/](https://alphacephei.com/vosk/)             | Apache 2.0  |
| **TinyLLaMA** | [https://github.com/ggerganov/llama.cpp](https://github.com/ggerganov/llama.cpp) | MIT         |
| **Piper**  | [https://github.com/rhasspy/piper](https://github.com/rhasspy/piper)       | MIT         |


#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

#include "json.hpp"
#include "piper.hpp"

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {
  piper::PiperConfig piperConfig;
  piper::Voice voice;


  auto modelPath = std::string("en_US-lessac-medium.onnx");
  piperConfig.eSpeakDataPath = std::string("espeak-ng-data");
  auto outputPath = std::string("out.wav");

  optional<piper::SpeakerId> speakerId;
  loadVoice(piperConfig, modelPath, modelPath + ".json", voice, speakerId,
            false);
  piper::initialize(piperConfig);

  // Output audio to WAV file
  ofstream audioFile(outputPath, ios::binary);

  piper::SynthesisResult result;
  piper::textToWavFile(piperConfig, voice, "This is a test.", audioFile,
                       result);
  piper::terminate(piperConfig);

  // Verify that file has some data
  if (audioFile.tellp() < 10000) {
    std::cerr << "ERROR: Output file is smaller than expected!" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "OK" << std::endl;

  return EXIT_SUCCESS;
}

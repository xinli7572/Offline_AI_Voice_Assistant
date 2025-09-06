

#!/bin/sh

sudo apt-get update
sudo dpkg --configure -a
sudo apt --fix-broken install
apt-get install portaudio19-dev

#======================
# 查看可用音频输入设备
#======================
# arecord -l

#======================
# 测试录音 3 秒钟
#======================
# arecord -d 3 test.wav

#======================
# 启动 PulseAudio（以 system 模式）
#======================
# pulseaudio --system --disallow-exit --no-cpu-limit --daemon










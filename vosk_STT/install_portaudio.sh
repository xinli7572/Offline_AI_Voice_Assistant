

#!/bin/sh

sudo apt-get update
sudo dpkg --configure -a
sudo apt --fix-broken install
apt-get install portaudio19-dev

#======================
# �鿴������Ƶ�����豸
#======================
# arecord -l

#======================
# ����¼�� 3 ����
#======================
# arecord -d 3 test.wav

#======================
# ���� PulseAudio���� system ģʽ��
#======================
# pulseaudio --system --disallow-exit --no-cpu-limit --daemon










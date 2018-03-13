#-*- coding: utf-8 -*-
import io
import sys
import os
import json
from six.moves import urllib
from google.cloud import speech

def google_stt():

    os.system("export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/project/smart_speaker/calendar/quickstart_google/stt_key.json")
    
    print("start google stt")
    reload(sys)
    sys.setdefaultencoding('utf-8')

    print("start recording")
    os.system("arecord -D plughw:1,0 -f S16_LE -c1 -r16000 -d 3 input.wav")
    print("recording complete!")

	# start stt
    print("stt start!")
    speech_client = speech.SpeechClient()
    print("request set complete!")

    with io.open('input.wav', 'rb') as audio_file:
        content = audio_file.read()
        audio_sample = speech_client.sample(
            content=content,
            source_uri=None,
            encoding='LINEAR16',
            sample_rate_hertz=16000)

    alternatives = audio_sample.recognize('ko-KR')
    for alternative in alternatives:
        return alternative.transcript
    

if __name__ == '__main__':
    google_stt()

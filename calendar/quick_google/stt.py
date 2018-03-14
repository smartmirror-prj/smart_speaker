#-*- coding: utf-8 -*-
import io
import sys
import os
import json
from six.moves import urllib
from google.oauth2 import service_account
from google.cloud import speech_v1
from google.cloud import speech
from google.cloud import storage
from google.cloud.speech import enums
from google.cloud.speech import types

def google_stt():

#   os.system("export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/project/smart_speaker/calendar/quickstart_google/smartMirror-speech-c0698d4d6c1b.json")
    os.system("export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/project/smart_speaker/calendar/quick_google/client_secret_292941919493-1n6ie58ttn9n7entefq8trqvbc1oo8qa.apps.googleusercontent.com.json")


    # If you don't specify credentials when constructing the client, the
    # client library will look for credentials in the environment.
    storage_client = storage.Client()

    # Make an authenticated API request
    buckets = list(storage_client.list_buckets())

    print(buckets)
    
    print("start google stt")
    reload(sys)
    sys.setdefaultencoding('utf-8')

    print("start recording")
    os.system("arecord -D plughw:1,0 -f S16_LE -c1 -r16000 -d 3 input.wav")
    print("recording complete!")

	# start stt
    print("stt start!")
#   speech_client = speech.SpeechClient()
    client = speech.SpeechClient()
    print("request set complete!")

    with io.open('input.wav', 'rb') as audio_file:
        content = audio_file.read()
        audio = types.RecognitionAudio(content=content)

    config = types.RecognitionConfig(
            encoding = enums.RecognitionConfig.AudioEncoding.LINEAR16,
            sample_rate_hertz = 16000,
            language_code = 'ko-KR')

    response = client.recognize(config, audio)

    for result in response.results: 
        print('Transcript: {}'.format(result.alternatives[0].transcript))
    # [END speech_quickstart]



#       audio_sample = speech_client.sample(
#           content=content,
#           source_uri=None,
#           encoding='LINEAR16',
#           sample_rate_hertz=16000)
#   alternatives = audio_sample.recognize('ko-KR')
#   for alternative in alternatives:
#       return alternative.transcript
    

if __name__ == '__main__':
    google_stt()

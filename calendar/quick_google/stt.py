#-*- coding: utf-8 -*-
import io
import sys
import os
import json
from six.moves import urllib
from google.oauth2 import service_account
from google.cloud import speech
from google.cloud import storage
from google.cloud.speech import enums
from google.cloud.speech import types

def google_stt():

    os.system("export GOOGLE_APPLICATION_CREDENTIALS=/home/ark/git_repo/smart_speaker/calendar/quick_google/my_stt_master_calendar.json")
    # If you don't specify credentials when constructing the client, the
    # client library will look for credentials in the environment.
    storage_client = storage.Client()

    # Make an authenticated API request
    buckets = list(storage_client.list_buckets())

    print(buckets)
    
    print("start google stt")
    reload(sys)
    sys.setdefaultencoding('utf-8')

	# start stt
    print("stt start!")

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

if __name__ == '__main__':
    google_stt()

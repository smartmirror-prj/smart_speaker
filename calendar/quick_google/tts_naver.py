from __future__ import print_function

#-*- coding: utf-8 -*-

# =================================================
# import => module
# =================================================
import os
import datetime
import time
import io
import sys
import unicodedata
import json

import urllib
import urllib2
#import urllib.request

#from urllib.request import urlopen
#from six.moves import urllib

client_id = "Qmk9XrEhvf_CTzbpuUq4"
client_secret = "25Keve2oyj"

url = "https://openapi.naver.com/v1/voice/tts.bin"

# ==============================================
# voice type
# ==============================================
speakers=['mijin', 'jinho']
# en_speakers={'clara', 'matt'}

tmpPlayPath = './tmp.mp3'

class tts_class():
    def __init__(self, speaker=0, speed=0):
        self.speaker = speakers[speaker]
        self.speed=str(speed)

    def calendar_tts(self, txt):
        print("==================== python TTS ==================== ")
        encText = urllib.pathname2url(txt)
        print("encText : ", encText)

        data = "speaker=" + self.speaker + "&speed=" + self.speed + "&text=" + encText;
        print("data : ", data)

        request = urllib2.Request(url)
        request.add_header("X-Naver-Client-Id",client_id)
        request.add_header("X-Naver-Client-Secret",client_secret)
        response = urllib2.urlopen(request, data=data.encode('utf-8'))
        rescode = response.getcode()
        print("rescode : ",rescode)


        print("calendar_tts c++ -> python     : ",txt)

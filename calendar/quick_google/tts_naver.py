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

client_id = "Qmk9XrEhvf_CTzbpuUq4"
client_secret = "25Keve2oyj"

url = "https://openapi.naver.com/v1/voice/tts.bin"
ko_speakers={'mijin', 'jinho'}
en_speakers={'clara', 'matt'}

tmpPlayPath = './tmp.mp3'

class tts_class():

    def calendar_tts(self, txt):
        print("==================== python TTS ==================== ")
        print("calendar_tts c++ -> python     : ",txt)
        encText = urllib.pathname2url(url)
        print("encText : ", encText)
    

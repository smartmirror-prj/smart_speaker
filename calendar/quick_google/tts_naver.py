
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


import urllib2 #python ver 2
#import urllib.request # python ver 3

client_id = "Qmk9XrEhvf_CTzbpuUq4"
client_secret = "25Keve2oyj"

url = "https://openapi.naver.com/v1/voice/tts.bin"

class tts_class():
    def print_string(self, input_string):
        print("c++ -> python : ",input_string)

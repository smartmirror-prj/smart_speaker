# -*- coding: utf-8 -*-

import io

import sys

import os

import json

from six.moves import urllib

from google.cloud import speech



def helloworld():



        print "Hello world!1"



            return None



            def initialize(index):



                    value = [1, -2, 2.94, -3.18]



                        return value[index]



                        def google_stt():

                                """Transcribe the given audio file."""



                                    # 환경 변수 설정

                                    os.system("export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/dddddddddddddd.json")



                                        # 인코딩 설정

                                        reload(sys)

        sys.setdefaultencoding('utf-8')



            # 녹음

            os.system("arecord -D plughw:1,0 -f S16_LE -c1 -r16000 -d 3 input.wav")

                print("recording complete!")



                    # start stt

                    speech_client = speech.Client()



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

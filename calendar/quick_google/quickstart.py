from __future__ import print_function

# =================================================
# import => module
# =================================================
import os
import httplib2
import datetime
import io
import sys

# =================================================
# from & import => module
# =================================================
from googleapiclient import sample_tools
from oauth2client import tools
from oauth2client.file import Storage
from oauth2client import client
from apiclient import discovery

if not hasattr(sys,'argv'):
    sys.argv=[]
import json

try:
    import argparse
    flags = argparse.ArgumentParser(parents=[tools.argparser]).parse_args()
except ImportError:
    flags = None

# If modifying these scopes, delete your previously saved credentials
# at ~/.credentials/calendar-python-quickstart.json
SCOPES = 'https://www.googleapis.com/auth/calendar.readonly'
CLIENT_SECRET_FILE = '/home/pi/project/smartmirror/calendar/quick_google/client_secret_633702561980-l5hu5n4tfo4hd64po79s803039pj1u6c.apps.googleusercontent.com'
APPLICATION_NAME = 'Google Calendar API Python Quickstart'

# =================================================
# get calendar credentials 
# =================================================
def get_credentials():
    """Gets valid user credentials from storage.
    If nothing has been stored, or if the stored credentials are invalid,
    the OAuth2 flow is completed to obtain the new credentials.
    Returns:
        Credentials, the obtained credential.
    """
    home_dir = os.path.expanduser('~')
    credential_dir = os.path.join(home_dir, '.credentials')
    if not os.path.exists(credential_dir):
        os.makedirs(credential_dir)
    credential_path = os.path.join(credential_dir,
                                   'calendar-python-quickstart.json')

    store = Storage(credential_path)
    credentials = store.get()
    if not credentials or credentials.invalid:
        flow = client.flow_from_clientsecrets(CLIENT_SECRET_FILE, SCOPES)
        flow.user_agent = APPLICATION_NAME
        if flags:
            credentials = tools.run_flow(flow, store, flags)
        else: # Needed only for compatibility with Python 2.6
            credentials = tools.run(flow, store)
        print('Storing credentials to ' + credential_path)
    return credentials


# =================================================
# nowDate == calendarDate check
# =================================================
def time_check(calendar_day):
    """
    time compare
    nowDate == input_date:calendar_day return True
    nowDate != input_date:calendar_day return False
    """
    now = datetime.datetime.now()
    nowDate = now.strftime('%Y-%m-%d') #datetime.datetime.now() 

    if nowDate in calendar_day:
        return True
    else:
        return False


# =================================================
# get calendar info
# =================================================
def get_calendar_info():
    """
    Shows basic usage of the Google Calendar API.
    Creates a Google Calendar API service object and outputs a list of the next
    10 events on the user's calendar.
    """
    credentials = get_credentials()
    http = credentials.authorize(httplib2.Http())
    service = discovery.build('calendar', 'v3', http=http)

    now = datetime.datetime.utcnow().isoformat() + 'Z' # 'Z' indicates UTC time
    print('Getting the upcoming 10 events')
    eventsResult = service.events().list(
        calendarId='primary', timeMin=now, maxResults=10, singleEvents=True,
        orderBy='startTime').execute()
    events = eventsResult.get('items', [])

    if not events:
        print('No upcomming events found')
    for event in events:
        start = event['start'].get('dateTime',event['start'].get('date'))
        print(time_check(start))
        print(start, event['summary'])

# =================================================
# calendar event get function
# =================================================
def get_eventTodayList():
    credentials = get_credentials()
    http = credentials.authorize(httplib2.Http())
    service = discovery.build('calendar', 'v3', http=http)

    page_token = None

    now = datetime.datetime.now()
    nowDate = now.strftime('%Y-%m-%d')
#   lt = datetime.time(23,59,59)
#   finishDate  = datetime.datetime.combine(nowDate,lt)
    today = now.date()
    print("today  \t\t : ",today , "\ttype : ",type(today))

    now = datetime.datetime.utcnow().isoformat() + 'Z' # 'Z' indicates UTC time

    # ================================================================
    # timeMin,timeMax format 
    # RFC3339 : ex)2018-02-09T07:02:06.440759Z
    # timeMin parameter defolt format  ex)2018-02-10T00:00:00Z(yyyy-mm-ddThh:mm:ssZ || 2018-02-09 16:24:39.060761)
    # ================================================================
    eventsResult = service.events().list(
        calendarId='primary', timeMin=now, maxResults=5, singleEvents=True,
        orderBy='startTime').execute()
    events = eventsResult.get('items', [])

    print("t : ",True)

    if not events:
        print('No upcomming events found')
    for event in events:
        start = event['start'].get('dateTime',event['start'].get('date'))
        if start.dateTime() in today
            print("today : ",today)
            print(start, event['summary'])

#    if not events:
#        print('No upcoming events found')
#    for event in events:
#        start = event['start'].get('dateTime',event['start'].get('date'))
#        print(start,event['summary'])

#   print(json.dumps(eventsResult, indent=4), eventsResult['summary'])

#    event_list = json.dumps(events, inden =4) 
#    f = open ("calendar_event.txt",'w')
#    f.write(event_list)
#    f.close()
#   print(json.dumps(eventsResult, indent=4), eventsResult['summary'])

def main():
#   print(time_check("2018-02-04"))
#   get_calendar_info()
    get_eventTodayList()

if __name__ == '__main__':
    main()


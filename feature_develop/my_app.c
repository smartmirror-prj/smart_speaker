#include <CkJsonObject.h>
#include <CkHttp.h>

void ChilkatSample(void)
{
	//  This example requires the Chilkat API to have been previously unlocked.
	//  See Global Unlock Sample for sample code.
	//  This example uses a previously obtained access token having permission for the
	//  Google Calendar scope.
	//  In this example, Get Google Calendar OAuth2 Access Token, the access
	//  token was saved to a JSON file.  This example fetches the access token from the file..
	CkJsonObject jsonToken;
				    bool success = jsonToken.LoadFile("qa_data/tokens/googleCalendar.json");
					    if (jsonToken.HasMember("access_token") == false) {
							        std::cout << "No access token found." << "\r\n";
									        return;
											    }

						    CkHttp http;
							    http.put_AuthToken(jsonToken.stringOf("access_token"));

								    //  Let's get the primary calendar.
								    const char *jsonResponse = http.quickGetStr("https://www.googleapis.com/calendar/v3/users/me/calendarList/primary");
									    if (http.get_LastMethodSuccess() != true) {
											        std::cout << http.lastErrorText() << "\r\n";
													        return;
															    }

										    std::cout << jsonResponse << "\r\n";

		//  A sample response is:

		//  {
		//   "kind": "calendar#calendarListEntry",
		//   "etag": "\"1465249947472000\"",
		//   "id": "support@chilkatcloud.com",
		//   "summary": "support@chilkatcloud.com",
		//   "timeZone": "America/Chicago",
		//   "colorId": "14",
		//   "backgroundColor": "#9fe1e7",
		//   "foregroundColor": "#000000",
		//   "selected": true,
		//   "accessRole": "owner",
		//   "defaultReminders": [
		//    {
		//     "method": "popup",
		//     "minutes": 10
		//    }
		//   ],
		//   "notificationSettings": {
		//    "notifications": [
		//     {
		//      "type": "eventCreation",
		//      "method": "email"
		//     },
		//     {
		//      "type": "eventChange",
		//      "method": "email"
		//     },
		//     {
		//      "type": "eventCancellation",
		//      "method": "email"
		//     },
		//     {
		//      "type": "eventResponse",
		//      "method": "email"
		//     }
		//    ]
		//   },
		//   "primary": true
		//  }

		//  It can be parsed like this:
	CkJsonObject json;
	json.Load(jsonResponse);
	std::cout << "kind: " << json.stringOf("kind") << "\r\n";
	std::cout << "id: " << json.stringOf("id") << "\r\n";

	//  Examine the notification settings, if any..
	int numSettings = json.SizeOfArray("notificationSettings.notifications");
	if (numSettings > 0) {
		int i = 0;
		while (i < numSettings) {
			json.put_I(i);
			std::cout << "Notification Type: " << json.stringOf("notificationSettings.notifications[i].type") << "\r\n";
			std::cout << "Notification Method: " << json.stringOf("notificationSettings.notifications[i].method") << "\r\n";
			i = i + 1;
		}
	}
}

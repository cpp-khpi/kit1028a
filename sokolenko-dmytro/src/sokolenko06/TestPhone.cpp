//#include "TestPhone.h"
//
//bool TestPhone::testPhoneToString()
//{
//	string expectedString = "Nokia 3310 | 700 | 2 | 3200 | 1000";
//	phone = { "Nokia 3310", 700, 2, 3200, 1000 };
//
//	string testString = phone.phoneToString();
//	
//	return expectedString == testString;
//}
//
//bool TestPhone::testStringToPhone()
//{
//	string testString = "Nokia 3310 | 700 | 2 | 3200 | 1000";
//	Phone expectedPhone = { "Nokia 3310", 700, 2, 3200, 1000 };
//	
//	phone.stringToPhone(testString);
//
//	return expectedPhone == phone;
//}
//
//bool TestPhone::testAll()
//{
//	return testPhoneToString() && testStringToPhone();
//}
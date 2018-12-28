#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
	Msg_HiHoneyImHome,
	Msg_StewReady,
	Msg_FindFly,
	Msg_FlyExists,
	Msg_HitFly,
	Msg_FlyRunAway
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";
	
  case Msg_FindFly:

	return "FindFly";
  case Msg_FlyExists:
	return "FlyExists";

  case Msg_HitFly:
	  return "HitFly";

  case Msg_FlyRunAway:
	  return "FlyRunAway";

  default:

    return "Not recognized!";
  }
}

#endif
/* This file is part of the Springlobby (GPL v2 or later), see COPYING */

#include <wx/log.h>
#include <stdio.h>
#include <utils/conversion.h>

extern void lsllogerror(const char* format, ...)
{
	char buf[1024];
	va_list args;
	va_start(args, format);
	vsnprintf(buf, 1024, format, args);
	wxLogError(TowxString(buf));
	va_end(args);
}


/* This file is part of the Springlobby (GPL v2 or later), see COPYING */

#include "iconscollection.h"

#include "user.h"

#include <wx/icon.h>
#include <wx/image.h>
#include <wx/bitmap.h>

IconsCollection::IconsCollection() {
}

IconsCollection::~IconsCollection() {
}

IconsCollection* IconsCollection::Instance() {
	if (m_Instance == nullptr) {
		m_Instance = new IconsCollection();
	}
	return m_Instance;
}

void IconsCollection::Release() {
	if (m_Instance != nullptr) {
		delete m_Instance;
	}
}

IconsCollection* IconsCollection::m_Instance = nullptr;

wxBitmap& IconsCollection::GetHostBmp(bool isSpec) {
	if (isSpec) {
		return BMP_HOST_SPECTATOR;
	} else {
		return BMP_HOST;
	}
}

wxBitmap& IconsCollection::GetReadyBmp(bool isSpec, bool isReady, bool inSync,
		bool isBot) {

	if (isBot) {
		return BMP_BOT;
	}

	if (isSpec) {
		if (inSync) {
			return BMP_SPECTATOR;
		} else {
			return BMP_SPECTATOR_UNSYNC;
		}
	}

	if (isReady) {
		if (inSync) {
			return BMP_READY;
		} else {
			return BMP_READY_UNSYNC;
		}
	} else {
		if (inSync) {
			return BMP_NREADY;
		} else {
			return BMP_NREADY_UNSYNC;
		}
	}
}

wxBitmap& IconsCollection::GetUserListStateIcon(const UserStatus& us, bool chanop, bool inbroom)
{
	if (us.bot) {
		if (us.in_game) {
			return BMP_BOT_INGAME;
		}
		if (inbroom) {
			return BMP_BOT_BROOM;
		}
		if (us.away) {
			return BMP_BOT_AWAY;
		}
		return BMP_BOT;
	} else if (us.moderator) {
		if (us.in_game) {
			return BMP_ADMIN_INGAME;
		}
		if (us.away) {
			return BMP_ADMIN_AWAY;
		}
		if (inbroom) {
			return BMP_ADMIN_BROOM;
		}
		return BMP_ADMIN;
	} else if (chanop) {
		if (us.in_game) {
			return BMP_OP_INGAME;
		}
		if (us.away) {
			return BMP_OP_AWAY;
		}
		if (inbroom) {
			return BMP_OP_BROOM;
		}
		return BMP_OP;
	}

	if (us.in_game) {
		return BMP_INGAME;
	}
	if (us.away) {
		return BMP_AWAY;
	}
	if (inbroom) {
		return BMP_BROOM;
	}

	return BMP_NOSTATE;
}

wxBitmap& IconsCollection::GetFlagBmp(wxString& country) {
	return BMP_ADMIN;
}

wxBitmap& IconsCollection::GetRankBmp(RankContainer& rank) {
	return BMP_ADMIN;
}

wxBitmap& IconsCollection::GetColourBmp(LSL::lslColor& colour) {
	return BMP_ADMIN;
}
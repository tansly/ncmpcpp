/***************************************************************************
 *   Copyright (C) 2008-2009 by Andrzej Rybczak                            *
 *   electricityispower@gmail.com                                          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef _LYRICS_H
#define _LYRICS_H

#include "ncmpcpp.h"

namespace Lyrics
{
	void Init();
	void Resize();
	void Update();
	
	void Get();
#	ifdef HAVE_CURL_CURL_H
	bool Ready();
#	endif // HAVE_CURL_CURL_H
}

#ifdef HAVE_CURL_CURL_H
# include <pthread.h>
# include "curl/curl.h"

struct LyricsPlugin
{
	const char *url;
	const char *tag_open;
	const char *tag_close;
	bool (*not_found)(const std::string &);
};

const char *GetLyricsPluginName(int);

#endif // HAVE_CURL_CURL_H

#endif


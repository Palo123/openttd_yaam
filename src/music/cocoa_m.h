/* $Id: cocoa_m.h 26108 2013-11-25 14:30:22Z rubidium $ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file cocoa_m.h Base of music playback via CoreAudio. */

#ifndef MUSIC_MACOSX_COCOA_H
#define MUSIC_MACOSX_COCOA_H

#include "music_driver.hpp"

class MusicDriver_Cocoa : public MusicDriver {
public:
	/* virtual */ const char *Start(const char * const *param);

	/* virtual */ void Stop();

	/* virtual */ void PlaySong(const char *filename);

	/* virtual */ void StopSong();

	/* virtual */ bool IsSongPlaying();

	/* virtual */ void SetVolume(byte vol);
	/* virtual */ const char *GetName() const { return "cocoa"; }
};

class FMusicDriver_Cocoa : public DriverFactoryBase {
public:
	FMusicDriver_Cocoa() : DriverFactoryBase(Driver::DT_MUSIC, 10, "cocoa", "Cocoa MIDI Driver") {}
	/* virtual */ Driver *CreateInstance() const { return new MusicDriver_Cocoa(); }
};

#endif /* MUSIC_MACOSX_COCOA_H */

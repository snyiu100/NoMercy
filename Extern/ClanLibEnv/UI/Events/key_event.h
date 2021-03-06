/*
**  ClanLib SDK
**  Copyright (c) 1997-2016 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/

#pragma once

#include "event.h"
#include "../../Core/Math/point.h"
#include "../../Display/Window/keys.h"
#include <string>

namespace clan
{
	/// Keyboard key event type
	enum class KeyEventType
	{
		none,   // No key event type specified
		press,  // Key was pressed
		release // Key was released
	};

	/// Keyboard key event
	class KeyEvent : public EventUI
	{
	public:
		KeyEvent(KeyEventType type, Key key, int repeat_count, const std::string &text, const Pointf &pointer_pos, bool alt_down, bool shift_down, bool ctrl_down, bool cmd_down) :
			_type(type), _key(key), _repeat_count(repeat_count), _text(text), _pointer_pos(pointer_pos), _alt_down(alt_down), _shift_down(shift_down), _ctrl_down(ctrl_down), _cmd_down(cmd_down)
		{
		}

		/// Key event type
		KeyEventType type() const { return _type; }

		/// Key relevant for the event
		Key key() const { return _key; }

		/// Key press repeat counter for key being held down
		int repeat_count() const { return _repeat_count; }

		/// Unicode characters generated by this event
		const std::string &text() const { return _text; }

		/// Cursor position returned in local content coordinates for the view specified
		Pointf pointer_pos(View *view) const;

		/// True if the alt key was down
		bool alt_down() const { return _alt_down; }

		/// True if the shift key was down
		bool shift_down() const { return _shift_down; }

		/// True if the control key was down
		bool ctrl_down() const { return _ctrl_down; }

		/// True if the command key was down
		bool cmd_down() const { return _cmd_down; }

	private:
		KeyEventType _type = KeyEventType::none;
		Key _key = Key::none;
		int _repeat_count = 0;
		std::string _text;
		Pointf _pointer_pos;
		bool _alt_down = false;
		bool _shift_down = false;
		bool _ctrl_down = false;
		bool _cmd_down = false;
	};
}

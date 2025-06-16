#include <realization/input/KeyboardSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------
	
    cKeyboardSDL::cKeyboardSDL(cLowLevelInputSDL* apLowLevelInputSDL)
	{
        mpLowLevelInputSDL = apLowLevelInputSDL;

		mvKeyArray.resize(eKey::eKey_Count);
		mvKeyArray.assign(mvKeyArray.size(), false);
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////
	
	// -----------------------------------------------------------------------
	
	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	bool cKeyboardSDL::GetAnyKeyPressed() const
	{
		for (size_t i = 0; i < mvKeyArray.size(); ++i)
		{
			if (mvKeyArray[i] == true)
				return true;
		}

		return false;
	}

	bool cKeyboardSDL::GetKeyPressed(eKey aKey) const
	{
		return mvKeyArray[aKey];
	}

    void cKeyboardSDL::SetKeyRepeat(bool abRepeat)
    {
        mbKeyRepeat = abRepeat;
    }

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cKeyboardSDL::Update()
	{
        mvPressedKeys.clear();

		for (const auto& Event : mpLowLevelInputSDL->GetEvents())
		{
			if (Event.type != SDL_KEYDOWN && Event.type != SDL_KEYUP)
				continue;

            eKey Key = SDLToKey(Event.key.keysym.sym);

            if (Event.type == SDL_KEYDOWN)
            {
                if (mbKeyRepeat || Event.key.repeat == 0)
                {
                    mvKeyArray[Key] = true;
                    mvPressedKeys.push_back(Key);
                }

                continue;
            }

            mvKeyArray[Key] = false;
		}
	}
	
	// -----------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    
    //////////////////////////////////////////
    // Core Functionality
    //////////////////////////////////////////

	eKey cKeyboardSDL::SDLToKey(int alKey)
	{
        switch (alKey)
        {
            //////////////////////////////////////////
            // Control keys
            //////////////////////////////////////////
        case SDLK_BACKSPACE:    return eKey_BackSpace;
        case SDLK_TAB:          return eKey_Tab;
        case SDLK_CLEAR:        return eKey_Clear;
        case SDLK_RETURN:       return eKey_Return;
        case SDLK_PAUSE:        return eKey_Pause;
        case SDLK_ESCAPE:       return eKey_Escape;
        case SDLK_SPACE:        return eKey_Space;
        case SDLK_DELETE:       return eKey_Delete;
        case SDLK_PRINTSCREEN:  return eKey_Print;
        case SDLK_MENU:         return eKey_Menu;
        case SDLK_POWER:        return eKey_Power;
        case SDLK_HELP:         return eKey_Help;
        case SDLK_SYSREQ:       return eKey_SysReq;
        case SDLK_MODE:         return eKey_Mode;

            //////////////////////////////////////////
            // Punctuation and symbols
            //////////////////////////////////////////
        case SDLK_EXCLAIM:      return eKey_Exclaim;
        case SDLK_QUOTEDBL:     return eKey_QuoteDouble;
        case SDLK_HASH:         return eKey_Hash;
        case SDLK_DOLLAR:       return eKey_Dollar;
        case SDLK_AMPERSAND:    return eKey_Ampersand;
        case SDLK_QUOTE:        return eKey_Quote;
        case SDLK_LEFTPAREN:    return eKey_LeftParen;
        case SDLK_RIGHTPAREN:   return eKey_RightParen;
        case SDLK_ASTERISK:     return eKey_Asterisk;
        case SDLK_PLUS:         return eKey_Plus;
        case SDLK_COMMA:        return eKey_Comma;
        case SDLK_MINUS:        return eKey_Minus;
        case SDLK_PERIOD:       return eKey_Period;
        case SDLK_SLASH:        return eKey_Slash;
        case SDLK_COLON:        return eKey_Colon;
        case SDLK_SEMICOLON:    return eKey_SemiColon;
        case SDLK_LESS:         return eKey_Less;
        case SDLK_EQUALS:       return eKey_Equals;
        case SDLK_GREATER:      return eKey_Greater;
        case SDLK_QUESTION:     return eKey_Question;
        case SDLK_AT:           return eKey_At;
        case SDLK_LEFTBRACKET:  return eKey_LeftBracket;
        case SDLK_BACKSLASH:    return eKey_BackSlash;
        case SDLK_RIGHTBRACKET: return eKey_RightBracket;
        case SDLK_CARET:        return eKey_Caret;
        case SDLK_UNDERSCORE:   return eKey_Underscore;
        case SDLK_BACKQUOTE:    return eKey_BackQuote;

            //////////////////////////////////////////
            // Numbers
            //////////////////////////////////////////
        case SDLK_0: return eKey_0;
        case SDLK_1: return eKey_1;
        case SDLK_2: return eKey_2;
        case SDLK_3: return eKey_3;
        case SDLK_4: return eKey_4;
        case SDLK_5: return eKey_5;
        case SDLK_6: return eKey_6;
        case SDLK_7: return eKey_7;
        case SDLK_8: return eKey_8;
        case SDLK_9: return eKey_9;

            //////////////////////////////////////////
            // Letters
            //////////////////////////////////////////
        case SDLK_a: return eKey_A;
        case SDLK_b: return eKey_B;
        case SDLK_c: return eKey_C;
        case SDLK_d: return eKey_D;
        case SDLK_e: return eKey_E;
        case SDLK_f: return eKey_F;
        case SDLK_g: return eKey_G;
        case SDLK_h: return eKey_H;
        case SDLK_i: return eKey_I;
        case SDLK_j: return eKey_J;
        case SDLK_k: return eKey_K;
        case SDLK_l: return eKey_L;
        case SDLK_m: return eKey_M;
        case SDLK_n: return eKey_N;
        case SDLK_o: return eKey_O;
        case SDLK_p: return eKey_P;
        case SDLK_q: return eKey_Q;
        case SDLK_r: return eKey_R;
        case SDLK_s: return eKey_S;
        case SDLK_t: return eKey_T;
        case SDLK_u: return eKey_U;
        case SDLK_v: return eKey_V;
        case SDLK_w: return eKey_W;
        case SDLK_x: return eKey_X;
        case SDLK_y: return eKey_Y;
        case SDLK_z: return eKey_Z;

            //////////////////////////////////////////
            // Numpad
            //////////////////////////////////////////
        case SDLK_KP_0:        return eKey_KP_0;
        case SDLK_KP_1:        return eKey_KP_1;
        case SDLK_KP_2:        return eKey_KP_2;
        case SDLK_KP_3:        return eKey_KP_3;
        case SDLK_KP_4:        return eKey_KP_4;
        case SDLK_KP_5:        return eKey_KP_5;
        case SDLK_KP_6:        return eKey_KP_6;
        case SDLK_KP_7:        return eKey_KP_7;
        case SDLK_KP_8:        return eKey_KP_8;
        case SDLK_KP_9:        return eKey_KP_9;
        case SDLK_KP_PERIOD:   return eKey_KP_Period;
        case SDLK_KP_DIVIDE:   return eKey_KP_Divide;
        case SDLK_KP_MULTIPLY: return eKey_KP_Multiply;
        case SDLK_KP_MINUS:    return eKey_KP_Minus;
        case SDLK_KP_PLUS:     return eKey_KP_Plus;
        case SDLK_KP_ENTER:    return eKey_KP_Enter;
        case SDLK_KP_EQUALS:   return eKey_KP_Equals;

            //////////////////////////////////////////
            // Navigation
            //////////////////////////////////////////
        case SDLK_UP:       return eKey_Up;
        case SDLK_DOWN:     return eKey_Down;
        case SDLK_RIGHT:    return eKey_Right;
        case SDLK_LEFT:     return eKey_Left;
        case SDLK_INSERT:   return eKey_Insert;
        case SDLK_HOME:     return eKey_Home;
        case SDLK_END:      return eKey_End;
        case SDLK_PAGEUP:   return eKey_PageUp;
        case SDLK_PAGEDOWN: return eKey_PageDown;

            //////////////////////////////////////////
            // Function keys
            //////////////////////////////////////////
        case SDLK_F1:  return eKey_F1;
        case SDLK_F2:  return eKey_F2;
        case SDLK_F3:  return eKey_F3;
        case SDLK_F4:  return eKey_F4;
        case SDLK_F5:  return eKey_F5;
        case SDLK_F6:  return eKey_F6;
        case SDLK_F7:  return eKey_F7;
        case SDLK_F8:  return eKey_F8;
        case SDLK_F9:  return eKey_F9;
        case SDLK_F10: return eKey_F10;
        case SDLK_F11: return eKey_F11;
        case SDLK_F12: return eKey_F12;
        case SDLK_F13: return eKey_F13;
        case SDLK_F14: return eKey_F14;
        case SDLK_F15: return eKey_F15;

            //////////////////////////////////////////
            // Lock keys
            //////////////////////////////////////////
        case SDLK_NUMLOCKCLEAR: return eKey_NumLock;
        case SDLK_CAPSLOCK:     return eKey_CapsLock;
        case SDLK_SCROLLLOCK:   return eKey_ScrollLock;

            //////////////////////////////////////////
            // Modifier
            //////////////////////////////////////////
        case SDLK_RSHIFT: return eKey_RightShift;
        case SDLK_LSHIFT: return eKey_LeftShift;
        case SDLK_RCTRL:  return eKey_RightCtrl;
        case SDLK_LCTRL:  return eKey_LeftCtrl;
        case SDLK_RALT:   return eKey_RightAlt;
        case SDLK_LALT:   return eKey_LeftAlt;
        case SDLK_LGUI:   return eKey_LeftSuper;
        case SDLK_RGUI:   return eKey_RightSuper;

        default: return eKey_None;
        }
    }
    
    // -----------------------------------------------------------------------
}
#include <realization/KeyboardSDL.h>

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

	bool cKeyboardSDL::GetAnyKeyPressed()
	{
		for (size_t i = 0; i < mvKeyArray.size(); ++i)
		{
			if (mvKeyArray[i] == true)
				return true;
		}

		return false;
	}

	bool cKeyboardSDL::GetKeyPressed(eKey aKey)
	{
		return mvKeyArray[aKey];
	}

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cKeyboardSDL::Update()
	{
		for (const auto& rEvent : mpLowLevelInputSDL->GetEvents())
		{
			if (rEvent.type != SDL_KEYDOWN && rEvent.type != SDL_KEYUP)
				continue;

            eKey Key = SDLToKey(rEvent.key.keysym.sym);
            mvKeyArray[Key] = rEvent.type == SDL_KEYDOWN;
		}
	}

    //////////////////////////////////////////
    // Core Functionality
    //////////////////////////////////////////

    eKey cKeyboardSDL::SDLToKey(int alKey)
    {
        switch (alKey)
        {
            // Special keys
        case SDLK_BACKSPACE: return eKey_BACKSPACE;
        case SDLK_TAB:       return eKey_TAB;
        case SDLK_RETURN:    return eKey_RETURN;
        case SDLK_RETURN2:   return eKey_RETURN;
        case SDLK_ESCAPE:    return eKey_ESCAPE;
        case SDLK_SPACE:     return eKey_SPACE;

            // Arrow keys
        case SDLK_UP:       return eKey_UP;
        case SDLK_DOWN:     return eKey_DOWN;
        case SDLK_LEFT:     return eKey_LEFT;
        case SDLK_RIGHT:    return eKey_RIGHT;

            // Modifier keys
        case SDLK_LSHIFT:
        case SDLK_RSHIFT:   return eKey_SHIFT;
        case SDLK_LCTRL:
        case SDLK_RCTRL:    return eKey_CTRL;
        case SDLK_LALT:
        case SDLK_RALT:     return eKey_ALT;

            // Function keys
        case SDLK_F1:       return eKey_F1;
        case SDLK_F2:       return eKey_F2;
        case SDLK_F3:       return eKey_F3;
        case SDLK_F4:       return eKey_F4;
        case SDLK_F5:       return eKey_F5;
        case SDLK_F6:       return eKey_F6;
        case SDLK_F7:       return eKey_F7;
        case SDLK_F8:       return eKey_F8;
        case SDLK_F9:       return eKey_F9;
        case SDLK_F10:      return eKey_F10;
        case SDLK_F11:      return eKey_F11;
        case SDLK_F12:      return eKey_F12;

            // Alphabet keys
        case SDLK_a:        return eKey_A;
        case SDLK_b:        return eKey_B;
        case SDLK_c:        return eKey_C;
        case SDLK_d:        return eKey_D;
        case SDLK_e:        return eKey_E;
        case SDLK_f:        return eKey_F;
        case SDLK_g:        return eKey_G;
        case SDLK_h:        return eKey_H;
        case SDLK_i:        return eKey_I;
        case SDLK_j:        return eKey_J;
        case SDLK_k:        return eKey_K;
        case SDLK_l:        return eKey_L;
        case SDLK_m:        return eKey_M;
        case SDLK_n:        return eKey_N;
        case SDLK_o:        return eKey_O;
        case SDLK_p:        return eKey_P;
        case SDLK_q:        return eKey_Q;
        case SDLK_r:        return eKey_R;
        case SDLK_s:        return eKey_S;
        case SDLK_t:        return eKey_T;
        case SDLK_u:        return eKey_U;
        case SDLK_v:        return eKey_V;
        case SDLK_w:        return eKey_W;
        case SDLK_x:        return eKey_X;
        case SDLK_y:        return eKey_Y;
        case SDLK_z:        return eKey_Z;

            // Numeric keys
        case SDLK_0:        return eKey_0;
        case SDLK_1:        return eKey_1;
        case SDLK_2:        return eKey_2;
        case SDLK_3:        return eKey_3;
        case SDLK_4:        return eKey_4;
        case SDLK_5:        return eKey_5;
        case SDLK_6:        return eKey_6;
        case SDLK_7:        return eKey_7;
        case SDLK_8:        return eKey_8;
        case SDLK_9:        return eKey_9;

            // Keypad keys (optional)
        case SDLK_KP_0:     return eKey_0;
        case SDLK_KP_1:     return eKey_1;
        case SDLK_KP_2:     return eKey_2;
        case SDLK_KP_3:     return eKey_3;
        case SDLK_KP_4:     return eKey_4;
        case SDLK_KP_5:     return eKey_5;
        case SDLK_KP_6:     return eKey_6;
        case SDLK_KP_7:     return eKey_7;
        case SDLK_KP_8:     return eKey_8;
        case SDLK_KP_9:     return eKey_9;

        default:            return eKey_NONE;
        }
    }
	
	// -----------------------------------------------------------------------
}
#include <implementation/KeyboardSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------
	
	cKeyboardSDL::cKeyboardSDL()
	{
		mvKeyArray.resize(eKey::eKey_Count);
		mvKeyArray.assign(mvKeyArray.size(), false);
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////
	
	// -----------------------------------------------------------------------
	
	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cKeyboardSDL::Update()
	{
		SDL_Event KeyEvents[gkMaxInputEvents];

		int lEventsCount = SDL_PeepEvents(
			KeyEvents, // Array where events will be recorded
			gkMaxInputEvents, // Maximum number of events to extract
			SDL_GETEVENT, // What to do with events
			SDL_KEYDOWN, // Minimum event type
			SDL_KEYUP // Maximum event type
		);

		if (lEventsCount < 0)
			return;

		for (size_t i = 0; i < lEventsCount; ++i)
		{
			bool bKeyDown = KeyEvents[i].type == SDL_KEYDOWN ? true : false;

            switch (KeyEvents[i].key.keysym.sym)
            {
            case SDLK_BACKSPACE:    mvKeyArray[eKey_BACKSPACE] = bKeyDown; break;
            case SDLK_TAB:          mvKeyArray[eKey_TAB] = bKeyDown; break;
            case SDLK_RETURN:       mvKeyArray[eKey_RETURN] = bKeyDown; break;
            case SDLK_ESCAPE:       mvKeyArray[eKey_ESCAPE] = bKeyDown; break;
            case SDLK_SPACE:        mvKeyArray[eKey_SPACE] = bKeyDown; break;

            case SDLK_UP:           mvKeyArray[eKey_UP] = bKeyDown; break;
            case SDLK_DOWN:         mvKeyArray[eKey_DOWN] = bKeyDown; break;
            case SDLK_LEFT:         mvKeyArray[eKey_LEFT] = bKeyDown; break;
            case SDLK_RIGHT:        mvKeyArray[eKey_RIGHT] = bKeyDown; break;

            case SDLK_LSHIFT:
            case SDLK_RSHIFT:       mvKeyArray[eKey_SHIFT] = bKeyDown; break;
            case SDLK_LCTRL:
            case SDLK_RCTRL:        mvKeyArray[eKey_CTRL] = bKeyDown; break;
            case SDLK_LALT:
            case SDLK_RALT:         mvKeyArray[eKey_ALT] = bKeyDown; break;

            // Functional keys
            case SDLK_F1:           mvKeyArray[eKey_F1] = bKeyDown; break;
            case SDLK_F2:           mvKeyArray[eKey_F2] = bKeyDown; break;
            case SDLK_F3:           mvKeyArray[eKey_F3] = bKeyDown; break;
            case SDLK_F4:           mvKeyArray[eKey_F4] = bKeyDown; break;
            case SDLK_F5:           mvKeyArray[eKey_F5] = bKeyDown; break;
            case SDLK_F6:           mvKeyArray[eKey_F6] = bKeyDown; break;
            case SDLK_F7:           mvKeyArray[eKey_F7] = bKeyDown; break;
            case SDLK_F8:           mvKeyArray[eKey_F8] = bKeyDown; break;
            case SDLK_F9:           mvKeyArray[eKey_F9] = bKeyDown; break;
            case SDLK_F10:          mvKeyArray[eKey_F10] = bKeyDown; break;
            case SDLK_F11:          mvKeyArray[eKey_F11] = bKeyDown; break;
            case SDLK_F12:          mvKeyArray[eKey_F12] = bKeyDown; break;

            // Letters
            case SDLK_a:            mvKeyArray[eKey_A] = bKeyDown; break;
            case SDLK_b:            mvKeyArray[eKey_B] = bKeyDown; break;
            case SDLK_c:            mvKeyArray[eKey_C] = bKeyDown; break;
            case SDLK_d:            mvKeyArray[eKey_D] = bKeyDown; break;
            case SDLK_e:            mvKeyArray[eKey_E] = bKeyDown; break;
            case SDLK_f:            mvKeyArray[eKey_F] = bKeyDown; break;
            case SDLK_g:            mvKeyArray[eKey_G] = bKeyDown; break;
            case SDLK_h:            mvKeyArray[eKey_H] = bKeyDown; break;
            case SDLK_i:            mvKeyArray[eKey_I] = bKeyDown; break;
            case SDLK_j:            mvKeyArray[eKey_J] = bKeyDown; break;
            case SDLK_k:            mvKeyArray[eKey_K] = bKeyDown; break;
            case SDLK_l:            mvKeyArray[eKey_L] = bKeyDown; break;
            case SDLK_m:            mvKeyArray[eKey_M] = bKeyDown; break;
            case SDLK_n:            mvKeyArray[eKey_N] = bKeyDown; break;
            case SDLK_o:            mvKeyArray[eKey_O] = bKeyDown; break;
            case SDLK_p:            mvKeyArray[eKey_P] = bKeyDown; break;
            case SDLK_q:            mvKeyArray[eKey_Q] = bKeyDown; break;
            case SDLK_r:            mvKeyArray[eKey_R] = bKeyDown; break;
            case SDLK_s:            mvKeyArray[eKey_S] = bKeyDown; break;
            case SDLK_t:            mvKeyArray[eKey_T] = bKeyDown; break;
            case SDLK_u:            mvKeyArray[eKey_U] = bKeyDown; break;
            case SDLK_v:            mvKeyArray[eKey_V] = bKeyDown; break;
            case SDLK_w:            mvKeyArray[eKey_W] = bKeyDown; break;
            case SDLK_x:            mvKeyArray[eKey_X] = bKeyDown; break;
            case SDLK_y:            mvKeyArray[eKey_Y] = bKeyDown; break;
            case SDLK_z:            mvKeyArray[eKey_Z] = bKeyDown; break;

            // Numbers
            case SDLK_0:            mvKeyArray[eKey_0] = bKeyDown; break;
            case SDLK_1:            mvKeyArray[eKey_1] = bKeyDown; break;
            case SDLK_2:            mvKeyArray[eKey_2] = bKeyDown; break;
            case SDLK_3:            mvKeyArray[eKey_3] = bKeyDown; break;
            case SDLK_4:            mvKeyArray[eKey_4] = bKeyDown; break;
            case SDLK_5:            mvKeyArray[eKey_5] = bKeyDown; break;
            case SDLK_6:            mvKeyArray[eKey_6] = bKeyDown; break;
            case SDLK_7:            mvKeyArray[eKey_7] = bKeyDown; break;
            case SDLK_8:            mvKeyArray[eKey_8] = bKeyDown; break;
            case SDLK_9:            mvKeyArray[eKey_9] = bKeyDown; break;

            default:
                break;
            }
		}
	}
	
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

	bool cKeyboardSDL::GetKeyDown(eKey aKey)
	{
		return mvKeyArray[aKey];
	}
	
	// -----------------------------------------------------------------------
}
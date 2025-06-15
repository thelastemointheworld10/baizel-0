#include <engine/Updater.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cUpdater::cUpdater()
	{
		mvUpdateable.reserve(gkDefaultEntitiesCount);
	}

	cUpdater::~cUpdater()
	{
		mvUpdateable.clear();
	}

	// -----------------------------------------------------------------------
	
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	void cUpdater::AddUpdateable(iUpdateable* apUpdateable)
	{
		mvUpdateable.push_back(apUpdateable);
	}

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cUpdater::OnStart()
	{
		for (iUpdateable* pUpdateable : mvUpdateable)
		{
			pUpdateable->OnStart();
		}
	}

	void cUpdater::OnDraw()
	{
		for (iUpdateable* pUpdateable : mvUpdateable)
		{
			pUpdateable->OnDraw();
		}
	}

	void cUpdater::OnUpdate(float afTimeStep)
	{
		for (iUpdateable* pUpdateable : mvUpdateable)
		{
			pUpdateable->OnUpdate(afTimeStep);
		}
	}

	void cUpdater::OnExit()
	{
		for (iUpdateable* pUpdateable : mvUpdateable)
		{
			pUpdateable->OnExit();
		}
	}

	// -----------------------------------------------------------------------
}
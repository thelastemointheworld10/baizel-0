#ifndef BAIZEL_UPDATER_H
#define BAIZEL_UPDATER_H

#include <vector>

#include <engine/Updateable.h>

namespace baizel
{
	const int gkDefaultEntitiesCount = 64;
	using tUpdateableVec = std::vector<iUpdateable*>;

	class cUpdater final
	{
	public:
		cUpdater();
		~cUpdater();

		void AddUpdateable(iUpdateable* apUpdateable);

		void OnStart();
		void OnDraw();
		void OnUpdate(float afTimeStep);
		void OnExit();

	private:
		tUpdateableVec mvUpdateable = {};
	};
}

#endif // BAIZEL_UPDATER_H
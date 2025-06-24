#ifndef BAIZEL_UPDATEABLE_H
#define BAIZEL_UPDATEABLE_H

namespace baizel
{
	class iUpdateable
	{
	public:
		virtual ~iUpdateable() = default;

		virtual void OnStart() = 0;
		virtual void OnUpdate(float afTimeStep) = 0;
		virtual void OnDraw() = 0;
		virtual void OnExit() = 0;
	};
}

#endif // BAIZEL_UPDATEABLE_H
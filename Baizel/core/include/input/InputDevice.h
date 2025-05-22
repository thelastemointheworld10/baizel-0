#ifndef BAIZEL_INPUTDEVICE_H
#define BAIZEL_INPUTDEVICE_H

namespace baizel
{
	class iInputDevice
	{
	public:
		virtual void Update() = 0;
	};
}

#endif // BAIZEL_INPUTDEVICE_H
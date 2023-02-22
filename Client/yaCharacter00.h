#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Character00 : public GameObject
	{
	public:
		Character00();
		~Character00();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* mImage;
	};
}


#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class PlayBackGround : public GameObject
	{
	public:
		PlayBackGround();
		~PlayBackGround();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* mImage;
	};
}

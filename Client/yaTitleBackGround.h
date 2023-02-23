#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class TitleBackGround : public GameObject
	{
	public:
		TitleBackGround();
		~TitleBackGround();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* mImage;
	};
}

#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class MainBackGround : public GameObject
	{
	public:
		MainBackGround();
		~MainBackGround();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* mImage;
	};
}
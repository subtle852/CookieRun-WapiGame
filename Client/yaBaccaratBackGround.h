#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class BaccaratBackGround : public GameObject
	{
	public:
		BaccaratBackGround();
		~BaccaratBackGround();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
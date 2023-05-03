#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class BonusBackGround : public GameObject
	{
	public:
		BonusBackGround();
		~BonusBackGround();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
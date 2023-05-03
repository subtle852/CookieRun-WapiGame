#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Bonus_UI_01_B : public GameObject
	{
	public:
		Bonus_UI_01_B();
		~Bonus_UI_01_B();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
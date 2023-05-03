#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Bonus_UI_05_S : public GameObject
	{
	public:
		Bonus_UI_05_S();
		~Bonus_UI_05_S();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Bonus_UI_06_T : public GameObject
	{
	public:
		Bonus_UI_06_T();
		~Bonus_UI_06_T();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
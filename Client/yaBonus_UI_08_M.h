#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Bonus_UI_08_M : public GameObject
	{
	public:
		Bonus_UI_08_M();
		~Bonus_UI_08_M();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
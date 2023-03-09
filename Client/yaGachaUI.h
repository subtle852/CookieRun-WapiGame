#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class GachaUI : public GameObject
	{
	public:
		GachaUI();
		~GachaUI();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
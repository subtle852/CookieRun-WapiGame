#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class SelectPetBackGround : public GameObject
	{
	public:
		SelectPetBackGround();
		~SelectPetBackGround();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
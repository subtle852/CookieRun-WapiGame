#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Play_Score : public GameObject
	{
	public:
		Play_Score();
		~Play_Score();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
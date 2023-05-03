#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Play_Silver : public GameObject
	{
	public:
		Play_Silver();
		~Play_Silver();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
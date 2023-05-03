#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class SelectCharBackGround : public GameObject
	{
	public:
		SelectCharBackGround();
		~SelectCharBackGround();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage1;
		Image* mImage2;
		Image* mImage3;
		Image* mImage4;
		Image* mImage5;
		Image* mImage6;
		Image* mImage7;
		Image* mImage8;
		//float mTime = 50.0f;

		public:
		//static bool flag;
	};
}
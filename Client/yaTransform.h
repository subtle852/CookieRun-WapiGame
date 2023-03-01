#pragma once
#include "yaComponent.h"

namespace ya
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetPos(Vector2 pos) { mPos = pos; }
		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetPos() { return mPos; }
		Vector2 GetScale() { return mScale; }

	private:
		Vector2 mPos;
		Vector2 mScale;
	};
}
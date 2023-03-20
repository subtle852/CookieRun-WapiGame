#pragma once
#include "yaGameObject.h"

namespace ya
{
	class UnderGround : public GameObject
	{
	public:
		UnderGround();
		virtual ~UnderGround();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	private:
		class Collider* mCollider;
	};
}
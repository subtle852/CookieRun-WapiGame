#include "yaBlackOut.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"

namespace ya
{
	BlackOut::BlackOut()
	{

	}

	BlackOut::~BlackOut()
	{

	}

	void BlackOut::Initialize()
	{
		mImage = Resources::Load<Image>(L"BlackOut", L"..\\Resources\\BlackOut.bmp");

		GameObject::Initialize();
	}

	void BlackOut::Update()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//pos.x += 500.0f * Time::DeltaTime();
		//tr->SetPos(pos);

		GameObject::Update();
	}

	void BlackOut::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));
	}

	void BlackOut::Release()
	{
		GameObject::Release();
	}
}
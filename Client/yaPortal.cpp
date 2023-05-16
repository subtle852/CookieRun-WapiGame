#include "yaPortal.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaScene.h"

namespace ya
{
	Portal::Portal()
	{

	}
	Portal::~Portal()
	{

	}

	void Portal::Initialize()
	{
		//mImage = Resources::Load<Image>(L"Portal00", L"..\\Resources\\Portal00.bmp");

		GameObject::Initialize();
	}

	void Portal::Update()
	{
		GameObject::Update();
	}

	void Portal::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();

		//TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 2.5, mImage->GetHeight() * 2.5
		//	, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));
	}

	void Portal::Release()
	{
		GameObject::Release();
	}
}
#include "yaTitleBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
	TitleBackGround::TitleBackGround()
	{

	}
	TitleBackGround::~TitleBackGround()
	{
	}
	void TitleBackGround::Initialize()
	{
		mImage = Resources::Load<Image>(L"BG", L"..\\Resources\\Title\\TitleBG.bmp");

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos.x = 0.0f; pos.y = 0.0f;
		tr->SetPos(pos);

		GameObject::Initialize();
	}
	void TitleBackGround::Update()
	{
		GameObject::Update();
	}
	void TitleBackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();

		BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void TitleBackGround::Release()
	{
		GameObject::Release();
	}
}
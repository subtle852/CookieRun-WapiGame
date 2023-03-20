#include "yaBlackOutM.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"

namespace ya
{
	BlackOutM::BlackOutM()
	{

	}

	BlackOutM::~BlackOutM()
	{

	}

	void BlackOutM::Initialize()
	{
		mImage = Resources::Load<Image>(L"BlackOutM", L"..\\Resources\\Item\\Effect\\BlackOutM.bmp");

		GameObject::Initialize();
	}

	void BlackOutM::Update()
	{
		GameObject::Update();
	}

	void BlackOutM::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		TransparentBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));
	}

	void BlackOutM::Release()
	{
		GameObject::Release();
	}
}
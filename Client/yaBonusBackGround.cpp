#include "yaBonusBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    BonusBackGround::BonusBackGround()
    {

    }

    BonusBackGround::~BonusBackGround()
    {

    }

    void BonusBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"BonusBackGround", L"..\\Resources\\Bonus\\bonus_bg_0001.bmp");

        GameObject::Initialize();
    }

    void BonusBackGround::Update()
    {
        GameObject::Update();
    }

    void BonusBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void BonusBackGround::Release()
    {
        GameObject::Release();
    }
}
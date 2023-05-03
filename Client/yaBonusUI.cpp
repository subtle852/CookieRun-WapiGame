#include "yaBonusUI.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    BonusUI::BonusUI()
    {

    }

    BonusUI::~BonusUI()
    {

    }

    void BonusUI::Initialize()
    {
        mImage = Resources::Load<Image>(L"BonusUI", L"..\\Resources\\Bonus\\bonus_ui.bmp");

        GameObject::Initialize();
    }

    void BonusUI::Update()
    {
        GameObject::Update();
    }

    void BonusUI::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 1.0, mImage->GetHeight() * 1.0
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void BonusUI::Release()
    {
        GameObject::Release();
    }
}
#include "yaBonus_UI_08_M.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    Bonus_UI_08_M::Bonus_UI_08_M()
    {

    }

    Bonus_UI_08_M::~Bonus_UI_08_M()
    {

    }

    void Bonus_UI_08_M::Initialize()
    {
        mImage = Resources::Load<Image>(L"BonusUI_08", L"..\\Resources\\Bonus\\M_0001.bmp");

        GameObject::Initialize();
    }

    void Bonus_UI_08_M::Update()
    {
        GameObject::Update();
    }

    void Bonus_UI_08_M::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 0.5, mImage->GetHeight() * 0.5
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void Bonus_UI_08_M::Release()
    {
        GameObject::Release();
    }
}
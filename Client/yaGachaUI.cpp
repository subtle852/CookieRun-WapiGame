#include "yaGachaUI.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    GachaUI::GachaUI()
    {

    }

    GachaUI::~GachaUI()
    {

    }

    void GachaUI::Initialize()
    {
        mImage = Resources::Load<Image>(L"GachaUI", L"..\\Resources\\Main\\main_ui_gacha.bmp");

        GameObject::Initialize();
    }

    void GachaUI::Update()
    {
        GameObject::Update();
    }

    void GachaUI::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth()* 1.3, mImage->GetHeight() * 1.3
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void GachaUI::Release()
    {
        GameObject::Release();
    }
}
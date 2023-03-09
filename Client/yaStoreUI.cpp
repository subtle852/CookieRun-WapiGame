#include "yaStoreUI.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    StoreUI::StoreUI()
    {

    }

    StoreUI::~StoreUI()
    {

    }

    void StoreUI::Initialize()
    {
        mImage = Resources::Load<Image>(L"StoreUI", L"..\\Resources\\Main\\main_ui_store.bmp");

        GameObject::Initialize();
    }

    void StoreUI::Update()
    {
        GameObject::Update();
    }

    void StoreUI::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 1.3, mImage->GetHeight() * 1.3
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void StoreUI::Release()
    {
        GameObject::Release();
    }
}
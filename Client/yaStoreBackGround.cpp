#include "yaStoreBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    StoreBackGround::StoreBackGround()
    {

    }

    StoreBackGround::~StoreBackGround()
    {

    }

    void StoreBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"StoreBG", L"..\\Resources\\Store\\store_bg_new.bmp");

        GameObject::Initialize();
    }

    void StoreBackGround::Update()
    {
        GameObject::Update();
    }

    void StoreBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();

        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void StoreBackGround::Release()
    {
        GameObject::Release();
    }
}
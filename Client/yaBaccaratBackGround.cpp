#include "yaBaccaratBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    BaccaratBackGround::BaccaratBackGround()
    {

    }

    BaccaratBackGround::~BaccaratBackGround()
    {

    }

    void BaccaratBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"BaccaratBG", L"..\\Resources\\Baccarat\\baccarat_bg.bmp");

        GameObject::Initialize();
    }

    void BaccaratBackGround::Update()
    {
        GameObject::Update();
    }

    void BaccaratBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();

        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void BaccaratBackGround::Release()
    {
        GameObject::Release();
    }
}
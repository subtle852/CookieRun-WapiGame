#include "yaResultFailBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    ResultFailBackGround::ResultFailBackGround()
    {

    }

    ResultFailBackGround::~ResultFailBackGround()
    {

    }

    void ResultFailBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"ResultFailBG", L"..\\Resources\\Result\\result_bg_fail.bmp");

        GameObject::Initialize();
    }

    void ResultFailBackGround::Update()
    {
        GameObject::Update();
    }

    void ResultFailBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void ResultFailBackGround::Release()
    {
        GameObject::Release();
    }
}
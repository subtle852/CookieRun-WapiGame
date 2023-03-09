#include "yaResultSucBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    ResultSucBackGround::ResultSucBackGround()
    {
    }

    ResultSucBackGround::~ResultSucBackGround()
    {
    }

    void ResultSucBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"ResultSucBG", L"..\\Resources\\Result\\result_bg_suc.bmp");

        GameObject::Initialize();
    }

    void ResultSucBackGround::Update()
    {
        GameObject::Update();
    }

    void ResultSucBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void ResultSucBackGround::Release()
    {
        GameObject::Release();
    }
}
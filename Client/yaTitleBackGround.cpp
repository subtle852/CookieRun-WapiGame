#include "yaTitleBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"

namespace ya
{
    TitleBackGround::TitleBackGround()
    {

    }

    TitleBackGround::~TitleBackGround()
    {

    }

    void TitleBackGround::Initialize()
    {
        //mImage = Resources::Load<Image>(L"TitleBG", L"..\\Resources\\title.bmp");

        Transform* tr = GetComponent<Transform>();
        tr->SetPos(Vector2(600.0f, 700.0f));
        tr->SetScale(Vector2(1.3f, 1.3f));

        mAnimator = AddComponent<Animator>();

        mAnimator->CreateAnimations(L"..\\Resources\\Title\\Bg", Vector2::Zero, 0.1f);
        mAnimator->Play(L"TitleBg", true);

        GameObject::Initialize();
    }

    void TitleBackGround::Update()
    {
        GameObject::Update();
    }

    void TitleBackGround::Render(HDC hdc)
    {
        //Transform* tr = GetComponent<Transform>();
        //Vector2 pos = tr->GetPos();
        ////BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        //TransparentBlt(hdc, pos.x, pos.y, 1600, 900
        //    , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void TitleBackGround::Release()
    {
        GameObject::Release();
    }
}
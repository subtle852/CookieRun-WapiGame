#include "yaJumpButton.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    JumpButton::JumpButton()
    {

    }

    JumpButton::~JumpButton()
    {

    }

    void JumpButton::Initialize()
    {
        mImage = Resources::Load<Image>(L"JumpNoUI", L"..\\Resources\\Play\\btn_jump_no.bmp");
        //mImage = Resources::Load<Image>(L"JumpYesUI", L"..\\Resources\\Play\\btn_jump_dim.bmp");

        GameObject::Initialize();
    }

    void JumpButton::Update()
    {
        if (Input::GetKeyDown(eKeyCode::W))
        {
            mImage = Resources::Load<Image>(L"JumpYesUI", L"..\\Resources\\Play\\btn_jump_dim.bmp");
        }
        if (Input::GetKeyUp(eKeyCode::W))
        {
            mImage = Resources::Load<Image>(L"JumpNoUI", L"..\\Resources\\Play\\btn_jump_no.bmp");
        }

        GameObject::Update();
    }

    void JumpButton::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        //TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight()
        //    , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        BLENDFUNCTION func = {};
        func.BlendOp = AC_SRC_OVER;
        func.BlendFlags = 0;
        func.AlphaFormat = AC_SRC_ALPHA;
        func.SourceConstantAlpha = 127;

        AlphaBlend(hdc, pos.x, pos.y, mImage->GetWidth()* 1.2, mImage->GetHeight()* 1.2
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), func);


        GameObject::Render(hdc);
    }

    void JumpButton::Release()
    {
        GameObject::Release();
    }
}
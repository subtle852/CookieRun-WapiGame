#include "yaPauseButton.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    PauseButton::PauseButton()
    {

    }

    PauseButton::~PauseButton()
    {

    }

    void PauseButton::Initialize()
    {
        mImage = Resources::Load<Image>(L"PauseButton", L"..\\Resources\\Play\\btn_puase_no.bmp");

        GameObject::Initialize();
    }

    void PauseButton::Update()
    {
        GameObject::Update();
    }

    void PauseButton::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();

        BLENDFUNCTION func = {};
        func.BlendOp = AC_SRC_OVER;
        func.BlendFlags = 0;
        func.AlphaFormat = AC_SRC_ALPHA;
        func.SourceConstantAlpha = 127;

        AlphaBlend(hdc, pos.x, pos.y, mImage->GetWidth() * 1.2, mImage->GetHeight() * 1.2
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), func);

        GameObject::Render(hdc);
    }

    void PauseButton::Release()
    {
        GameObject::Release();
    }
}
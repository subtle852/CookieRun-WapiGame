#include "yaRacingBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    RacingBackGround::RacingBackGround()
    {

    }

    RacingBackGround::~RacingBackGround()
    {

    }

    void RacingBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"RacingBG", L"..\\Resources\\Racing\\lane_bg_real.bmp");

        GameObject::Initialize();
    }

    void RacingBackGround::Update()
    {
        GameObject::Update();
    }

    void RacingBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();

        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void RacingBackGround::Release()
    {
        GameObject::Release();
    }
}
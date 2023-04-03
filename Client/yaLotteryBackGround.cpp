#include "yaLotteryBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    LotteryBackGround::LotteryBackGround()
    {

    }

    LotteryBackGround::~LotteryBackGround()
    {

    }

    void LotteryBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"LotteryBG", L"..\\Resources\\Lottery\\lottery_bg_new.bmp");

        GameObject::Initialize();
    }

    void LotteryBackGround::Update()
    {
        GameObject::Update();
    }

    void LotteryBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();

        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void LotteryBackGround::Release()
    {
        GameObject::Release();
    }
}
#include "yaGaugeBar.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaCharacter01.h"

namespace ya
{
    GaugeBar::GaugeBar()
    {

    }

    GaugeBar::~GaugeBar()
    {

    }

    void GaugeBar::Initialize()
    {
        mImage = Resources::Load<Image>(L"GaugeBar", L"..\\Resources\\Play\\gauge_heart_orange.bmp");

        GameObject::Initialize();
    }

    void GaugeBar::Update()
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        pos.x -= 50.0f * Time::DeltaTime();

        tr->SetPos(pos);

        //Vector2(59.0f, 32.0f)
        mHpLink = Character01::GetHp();
        if (mHpLink == 70 && cnt == 0)// 장애물 한번 부딪
        {
            cnt++;
            Transform* tr = GetComponent<Transform>();
            Vector2 pos = tr->GetPos();
            pos.x -= 200.0f;
            tr->SetPos(pos);
        }
        if (mHpLink == 40 && cnt == 1)// 장애물 두번 부딪
        {
            cnt++;
            Transform* tr = GetComponent<Transform>();
            Vector2 pos = tr->GetPos();
            pos.x -= 200.0f;
            tr->SetPos(pos);
        }
        if (mHpLink == 10 && cnt == 2)// 장애물 세번 부딪
        {
            cnt++;
            Transform* tr = GetComponent<Transform>();
            Vector2 pos = tr->GetPos();
            pos.x -= 200.0f;
            tr->SetPos(pos);
        }

        GameObject::Update();
    }

    void GaugeBar::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 1.3, mImage->GetHeight() * 1.3
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void GaugeBar::Release()
    {
        GameObject::Release();
    }
}
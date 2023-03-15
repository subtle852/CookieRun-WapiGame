#include "yaSelectCharBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    //bool SelectCharBackGround::flag = false;

    SelectCharBackGround::SelectCharBackGround()
    {

    }

    SelectCharBackGround::~SelectCharBackGround()
    {

    }

    void SelectCharBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"SelectCharBG", L"..\\Resources\\selectchar_a.bmp");

        GameObject::Initialize();
    }

    void SelectCharBackGround::Update()
    {
        GameObject::Update();
    }

    void SelectCharBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        //if(flag == false && mTime < 255.0f)
        //    mTime += Time::DeltaTime() * 50.0f;

        //if (flag == true)
        //{
        //    if(mTime > 0.0f)
        //    mTime -= Time::DeltaTime() * 50.0f;

        //    if(mTime <= 50.0f)
        //        SceneManager::LoadScene(eSceneType::SelectStage);
        //}

        //BLENDFUNCTION func = {};
        //func.BlendOp = AC_SRC_OVER;
        //func.BlendFlags = 0;
        //func.AlphaFormat = AC_SRC_ALPHA;
        //func.SourceConstantAlpha = static_cast<int>(mTime);

        //AlphaBlend(hdc, pos.x, pos.y, 1600, 900
        //    , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), func);

        GameObject::Render(hdc);
    }

    void SelectCharBackGround::Release()
    {
        GameObject::Release();
    }
}
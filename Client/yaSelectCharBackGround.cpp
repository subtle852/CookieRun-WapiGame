#include "yaSelectCharBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaSelectCharScene.h"

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
        mImage1 = Resources::Load<Image>(L"SelectChar01", L"..\\Resources\\SelectC\\selectchar_bg_01.bmp");
        mImage2 = Resources::Load<Image>(L"SelectChar02", L"..\\Resources\\SelectC\\selectchar_bg_02.bmp");
        mImage3 = Resources::Load<Image>(L"SelectChar03", L"..\\Resources\\SelectC\\selectchar_bg_03.bmp");
        mImage4 = Resources::Load<Image>(L"SelectChar04", L"..\\Resources\\SelectC\\selectchar_bg_04.bmp");
        mImage5 = Resources::Load<Image>(L"SelectChar05", L"..\\Resources\\SelectC\\selectchar_bg_05.bmp");
        mImage6 = Resources::Load<Image>(L"SelectChar06", L"..\\Resources\\SelectC\\selectchar_bg_06.bmp");
        mImage7 = Resources::Load<Image>(L"SelectChar07", L"..\\Resources\\SelectC\\selectchar_bg_07.bmp");
        mImage8 = Resources::Load<Image>(L"SelectChar08", L"..\\Resources\\SelectC\\selectchar_bg_08.bmp");

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

        if (SelectCharScene::GetCharNumber() == 1)
        {
            TransparentBlt(hdc, pos.x, pos.y, 1600, 900
                , mImage1->GetHdc(), 0, 0, mImage1->GetWidth(), mImage1->GetHeight(), RGB(170, 0, 0));
        }
        if (SelectCharScene::GetCharNumber() == 2)
        {
            TransparentBlt(hdc, pos.x, pos.y, 1600, 900
                , mImage2->GetHdc(), 0, 0, mImage2->GetWidth(), mImage2->GetHeight(), RGB(170, 0, 0));
        }
        if (SelectCharScene::GetCharNumber() == 3)
        {
            TransparentBlt(hdc, pos.x, pos.y, 1600, 900
                , mImage3->GetHdc(), 0, 0, mImage3->GetWidth(), mImage3->GetHeight(), RGB(170, 0, 0));
        }
        if (SelectCharScene::GetCharNumber() == 4)
        {
            TransparentBlt(hdc, pos.x, pos.y, 1600, 900
                , mImage4->GetHdc(), 0, 0, mImage4->GetWidth(), mImage4->GetHeight(), RGB(170, 0, 0));
        }
        if (SelectCharScene::GetCharNumber() == 5)
        {
            TransparentBlt(hdc, pos.x, pos.y, 1600, 900
                , mImage5->GetHdc(), 0, 0, mImage5->GetWidth(), mImage5->GetHeight(), RGB(170, 0, 0));
        }
        if (SelectCharScene::GetCharNumber() == 6)
        {
            TransparentBlt(hdc, pos.x, pos.y, 1600, 900
                , mImage6->GetHdc(), 0, 0, mImage6->GetWidth(), mImage6->GetHeight(), RGB(170, 0, 0));
        }
        if (SelectCharScene::GetCharNumber() == 7)
        {
            TransparentBlt(hdc, pos.x, pos.y, 1600, 900
                , mImage7->GetHdc(), 0, 0, mImage7->GetWidth(), mImage7->GetHeight(), RGB(170, 0, 0));
        }
        if (SelectCharScene::GetCharNumber() == 8)
        {
            TransparentBlt(hdc, pos.x, pos.y, 1600, 900
                , mImage8->GetHdc(), 0, 0, mImage8->GetWidth(), mImage8->GetHeight(), RGB(170, 0, 0));
        }

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
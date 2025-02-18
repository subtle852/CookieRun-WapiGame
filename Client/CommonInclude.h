#pragma once
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
// framework.h에 있는 것도 그냥 여기로 들고 왔음
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 우리가 자주 사용하는 헤더 파일들 몰아넣기
#include <string>
#include <vector>
#include <list>
#include <map>
#include <assert.h>
#include <functional>
#include <filesystem>

#pragma comment(lib, "Msimg32.lib")

#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")


// 타일 하나 크기
#define TILE_SIZE_X 64
#define TILE_SIZE_Y 64

// 단축키
// 문장 단위로 넘길때 ctrl누르고 좌우 
// 문장 앞, 뒤 HOME, END버튼
// 헤더 <-> cpp ctrl +KO
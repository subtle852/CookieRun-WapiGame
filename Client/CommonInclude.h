#pragma once
// Windows ��� ����
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
// framework.h�� �ִ� �͵� �׳� ����� ��� ����
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// �츮�� ���� ����ϴ� ��� ���ϵ� ���Ƴֱ�
#include <string>
#include <vector>
#include <list>
#include <map>
#include <assert.h>
#include <functional>
#include <filesystem>

#pragma comment(lib, "Msimg32.lib")

// Ÿ�� �ϳ� ũ��
#define TILE_SIZE_X 64
#define TILE_SIZE_Y 64

// ����Ű
// ���� ������ �ѱ涧 ctrl������ �¿� 
// ���� ��, �� HOME, END��ư
// ��� <-> cpp ctrl +KO
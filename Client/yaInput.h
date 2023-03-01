#pragma once
#include "YamYamEngine.h"
namespace ya
{
	// Ű �Է��� �� 4���� ���·� ����
	// DOWN : ó�� ������ ��
	// PRESSED : ��� ���������� ��
	// UP : ���� ��
	// NONE : �Է� ���� 

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		END,
	};

	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	class Input
	{
	public:
		// Enum�� �ȳ־��� ������ 
		// Enum�� �ִ� ����� ��𼭳� ����� ���ɼ��� ������
		// struct Key�� 
		// ��¥�� ���⼭ cpp�� ������� �� ����ϴ� Ŭ���� ��� ����ü�� ������
		struct Key
		{
			eKeyCode key;// Ű
			eKeyState state;// ����
			bool bPressed;// ������ �ִ� ��
		};

	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		inline static eKeyState GetKeyState(eKeyCode keyCode)
			// inline�� �Լ��� ó���ϴ� �Ϲ����� ���(�ѹ� Ÿ����)�� �޸�
			// �� �Լ��� ȣ���ϸ� �ٷ� �Ʒ� ���� �����θ� �����ؼ� 
			// �ٷ� ����ǵ��� �ϴ� ��
			// inline �ٿ��� ������ �����Ϸ��� �Ǵ��ؼ� ����ϱ⿡
			// __forceinline�� �ٿ��� ������ �����ų ���� ����
			// �׸��� inline�� cpp������ ����� �� ����
			// cpp ��ü�� �ѹ� Ÿ�� ���̱⿡ �ǹ̰� ����?
		{
			return mKeys[(UINT)keyCode].state;
		}

		//GetKey()		Ű�� ������ �ð���ŭ true�� ��ȯ
		//GetKeyDown()	Ű�� ������ ��, �� �ѹ� true�� ��ȯ
		//GetKeyUp()	Ű�� ������ ���� ��, �� �ѹ� true�� ��ȯ

		static __forceinline bool GetKey(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::Pressed;
		}

		static __forceinline bool GetKeyDown(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::Down;
		}

		static __forceinline bool GetKeyUp(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::Up;
		}

	private:
		static std::vector<Key> mKeys;
	};
}


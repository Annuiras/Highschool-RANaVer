
#include "GameApp.h"
#include "Gallery.h"

//�ύX����V�[���i�O���Q�ƁB���Ԃ�GameApp.cpp�j
extern int gChangeScene;

#define MenuCnt (15)

int galleryCnt = 0;

Gallery::Gallery() :
	m_BackTexture(),
	m_SelectTexture(),
	m_PickUp(),
	m_Text(),
	gFont1(),
	gFont2()
{

}

Gallery::~Gallery()
{

}

//������
void Gallery::Initialize(void)
{
	gFont1.Create(44, "UD �f�W�^�� ���ȏ��� N-B");
	gFont2.Create(32, "UD �f�W�^�� ���ȏ��� N-B");
}

//�X�V
void Gallery::Update(void)
{
	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}
	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
	}

	//���L�[�E�őI�����E�ɍs���悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		if (galleryCnt < MenuCnt - 1)
		{
			galleryCnt++;
		}
	}

	//���L�[���őI�������ɍs���悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		if (galleryCnt > 0)
		{
			galleryCnt--;
		}
	}

	//���L�[���őI����������悤�ɂ���
	//���ɉ����遁5��̂��̂ɂȂ�
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		if (galleryCnt < MenuCnt - 1 && galleryCnt < 10)
		{
			galleryCnt += 5;
		}
	}
	//���L�[��őI�����オ��悤�ɂ���
	//��ɏオ�遁5�O�̂��̂ɂȂ�
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		if (galleryCnt > 0 && galleryCnt - 5 >= 0)
		{
			galleryCnt -= 5;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		if (LastAddFlag[0] == false)
		{
			LastAddFlag[0] = true;
		}
		else
		{
			LastAddFlag[0] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_2))
	{
		if (LastAddFlag[1] == false)
		{
			LastAddFlag[1] = true;
		}
		else
		{
			LastAddFlag[1] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_3))
	{
		if (LastAddFlag[2] == false)
		{
			LastAddFlag[2] = true;
		}
		else
		{
			LastAddFlag[2] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_4))
	{
		if (LastAddFlag[3] == false)
		{
			LastAddFlag[3] = true;
		}
		else
		{
			LastAddFlag[3] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_5))
	{
		if (LastAddFlag[4] == false)
		{
			LastAddFlag[4] = true;
		}
		else
		{
			LastAddFlag[4] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_6))
	{
		if (LastAddFlag[5] == false)
		{
			LastAddFlag[5] = true;
		}
		else
		{
			LastAddFlag[5] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_7))
	{
		if (LastAddFlag[6] == false)
		{
			LastAddFlag[6] = true;
		}
		else
		{
			LastAddFlag[6] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_8))
	{
		if (LastAddFlag[7] == false)
		{
			LastAddFlag[7] = true;
		}
		else
		{
			LastAddFlag[7] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_9))
	{
		if (LastAddFlag[8] == false)
		{
			LastAddFlag[8] = true;
		}
		else
		{
			LastAddFlag[8] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_0))
	{
		if (LastAddFlag[9] == false)
		{
			LastAddFlag[9] = true;
		}
		else
		{
			LastAddFlag[9] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_Q))
	{
		if (LastAddFlag[10] == false)
		{
			LastAddFlag[10] = true;
		}
		else
		{
			LastAddFlag[10] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_W))
	{
		if (LastAddFlag[11] == false)
		{
			LastAddFlag[11] = true;
		}
		else
		{
			LastAddFlag[11] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_E))
	{
		if (LastAddFlag[12] == false)
		{
			LastAddFlag[12] = true;
		}
		else
		{
			LastAddFlag[12] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_R))
	{
		if (LastAddFlag[13] == false)
		{
			LastAddFlag[13] = true;
		}
		else
		{
			LastAddFlag[13] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_T))
	{
		if (LastAddFlag[14] == false)
		{
			LastAddFlag[14] = true;
		}
		else
		{
			LastAddFlag[14] = false;
		}
	}
}

//�`��
void Gallery::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�M�������[���");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");

	//�ŏI�e�p�䎆
	//m_BackTexture.Render(10,50);

	for (int i = 0; i < 15; i++)
	{
		m_LastApp[i].Render(pos[i].x, pos[i].y);
	}

	m_PickUp.Render(766, 60);
	m_Text.Render(766, 471);

	//�t���O��false�̏ꍇ�A�ŏI�e�p���B������
	//�摜�ɍ����ւ���
	if (LastAddFlag[0] == false)
	{
		CGraphicsUtilities::RenderFillRect(60, 60, 180, 260, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[1] == false)
	{
		CGraphicsUtilities::RenderFillRect(180, 60, 300, 260, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[2] == false)
	{
		CGraphicsUtilities::RenderFillRect(300, 60, 420, 260, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[3] == false)
	{
		CGraphicsUtilities::RenderFillRect(420, 60, 540, 260, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[4] == false)
	{
		CGraphicsUtilities::RenderFillRect(540, 60, 660, 260, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}



	if (LastAddFlag[5] == false)
	{
		CGraphicsUtilities::RenderFillRect(60, 260, 180, 460, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[6] == false)
	{
		CGraphicsUtilities::RenderFillRect(180, 260, 300, 460, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[7] == false)
	{
		CGraphicsUtilities::RenderFillRect(300, 260, 420, 460, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[8] == false)
	{
		CGraphicsUtilities::RenderFillRect(420, 260, 540, 460, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[9] == false)
	{
		CGraphicsUtilities::RenderFillRect(540, 260, 660, 460, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}





	if (LastAddFlag[10] == false)
	{
		CGraphicsUtilities::RenderFillRect(60, 460, 180, 660, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[11] == false)
	{
		CGraphicsUtilities::RenderFillRect(180, 460, 300, 660, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[12] == false)
	{
		CGraphicsUtilities::RenderFillRect(300, 460, 420, 660, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[13] == false)
	{
		CGraphicsUtilities::RenderFillRect(420, 460, 540, 660, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	if (LastAddFlag[14] == false)
	{
		CGraphicsUtilities::RenderFillRect(540, 460, 660, 660, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE, MOF_COLOR_WHITE, MOF_COLOR_CWHITE);
	}

	//���e�����e�L�X�g
	const char* MenuString[MenuCnt] =
	{
		"�o��"
	};

	const char* ExString[MenuCnt] =
	{
		"�e�p�̐����������ɓ��͂��Ă�\n�������B�e�p�̐����������ɓ�\n�͂��Ă��������B�e�p�̐�����\n�����ɓ��͂��Ă��������B�e�p\n�̐����������ɓ��͂��Ă�����"
	};

	//1�e�p���Ƃ̋�`�ڈ�
	//CGraphicsUtilities::RenderFillRect(60, 60, 180, 260, MOF_COLOR_CWHITE, MOF_COLOR_CWHITE,MOF_COLOR_WHITE,MOF_COLOR_CWHITE);
	/*CGraphicsUtilities::RenderRect(129, 50, 250, 250, MOF_COLOR_CWHITE);
	CGraphicsUtilities::RenderRect(249, 50, 370, 250, MOF_COLOR_BLUE);
	CGraphicsUtilities::RenderRect(369, 50, 490, 250, MOF_COLOR_GREEN);
	CGraphicsUtilities::RenderRect(489, 50, 610, 250, MOF_COLOR_CWHITE);

	CGraphicsUtilities::RenderRect(10, 250, 130, 450, MOF_COLOR_BLUE);
	CGraphicsUtilities::RenderRect(129, 250, 250, 450, MOF_COLOR_GREEN);
	CGraphicsUtilities::RenderRect(249, 250, 370, 450, MOF_COLOR_CWHITE);
	CGraphicsUtilities::RenderRect(369, 250, 490, 450, MOF_COLOR_BLUE);
	CGraphicsUtilities::RenderRect(489, 250, 610, 450, MOF_COLOR_GREEN);

	CGraphicsUtilities::RenderRect(10, 450, 130, 650, MOF_COLOR_CWHITE);
	CGraphicsUtilities::RenderRect(129, 450, 250, 650, MOF_COLOR_BLUE);
	CGraphicsUtilities::RenderRect(249, 450, 370, 650, MOF_COLOR_GREEN);
	CGraphicsUtilities::RenderRect(369, 450, 490, 650, MOF_COLOR_CWHITE);
	CGraphicsUtilities::RenderRect(489, 450, 610, 650, MOF_COLOR_BLUE);*/


	//��`���m�F�p
	CGraphicsUtilities::RenderString(10, 100, "galleryCnt:%d", galleryCnt);

	//���ݑI����`�\���i���F�ɂȂ�j
	//�����ׂ��̂ŉ摜�Ŏl�p�`������̂�ǂݍ��ނ��ǂ����������c�c
	switch (galleryCnt)
	{
	case 0:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		gFont1.RenderString(930, 471, MenuString[galleryCnt]);
		gFont2.RenderString(766, 520, ExString[galleryCnt]);

		if (!LastAddFlag[0])
		{
			m_PickUp.Render(766, 50);
		}
		else
		{
			m_LastAppPic[0].Render(766, 50);
		}
		break;

	case 1:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[1].Render(766, 50);
		break;

	case 2:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[2].Render(766, 50);
		break;

	case 3:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[3].Render(766, 50);
		break;

	case 4:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[4].Render(766, 50);
		break;

	case 5:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[5].Render(766, 50);
		break;

	case 6:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[6].Render(766, 50);
		break;

	case 7:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[7].Render(766, 50);
		break;

	case 8:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[8].Render(766, 50);
		break;

	case 9:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[9].Render(766, 50);
		break;

	case 10:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[10].Render(766, 50);
		break;

	case 11:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[11].Render(766, 50);
		break;

	case 12:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[12].Render(766, 50);
		break;

	case 13:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[13].Render(766, 50);
		break;

	case 14:
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		m_LastAppPic[14].Render(766, 50);
		break;
	}



}

//���[�h
bool Gallery::Load(void)
{
	//�w�i�e�N�X�`���̓ǂݍ���
	if (!m_BackTexture.Load("collection.png"))
	{
		return false;
	}

	//�I�����̎l�p�`
	if (!m_SelectTexture.Load("Select.png"))
	{
		return false;
	}

	//�ŏI�e�p�̑䎆�e�N�X�`���i�o���j
	if (!m_LastApp[0].Load("OlderSister.png"))
	{
		return false;
	}

	if (!m_LastApp[1].Load("ClassFavorite.png"))
	{
		return false;
	}

	if (!m_LastApp[2].Load("Gal.png"))
	{
		return false;
	}

	if (!m_LastApp[3].Load("CheerLeader.png"))
	{
		return false;
	}

	if (!m_LastApp[4].Load("LibraryManager.png"))
	{
		return false;
	}

	if (!m_LastApp[5].Load("Otaku.png"))
	{
		return false;
	}

	if (!m_LastApp[6].Load("infulencer.png"))
	{
		return false;
	}

	if (!m_LastApp[7].Load("Chairman.png"))
	{
		return false;
	}

	if (!m_LastApp[8].Load("LoftyDream.png"))
	{
		return false;
	}

	if (!m_LastApp[9].Load("Yankee.png"))
	{
		return false;
	}

	if (!m_LastApp[10].Load("SuperLady.png"))
	{
		return false;
	}

	if (!m_LastApp[11].Load("FussyPerson.png"))
	{
		return false;
	}

	if (!m_LastApp[12].Load("LiteratureGirl.png"))
	{
		return false;
	}

	if (!m_LastApp[13].Load("Chu-nibyou.png"))
	{
		return false;
	}

	if (!m_LastApp[14].Load("GodSupport.png"))
	{
		return false;
	}


	//�ŏI�e�p�̑䎆�e�N�X�`��(�o��&�s�b�N�A�b�v�p)
	if (!m_LastAppPic[0].Load("Picup1.png"))
	{
		return false;
	}

	if (!m_LastAppPic[1].Load("Picup2.png"))
	{
		return false;
	}

	if (!m_LastAppPic[2].Load("Picup3.png"))
	{
		return false;
	}

	if (!m_LastAppPic[3].Load("Picup4.png"))
	{
		return false;
	}

	if (!m_LastAppPic[4].Load("Picup5.png"))
	{
		return false;
	}

	if (!m_LastAppPic[5].Load("Picup6.png"))
	{
		return false;
	}

	if (!m_LastAppPic[6].Load("Picup7.png"))
	{
		return false;
	}

	if (!m_LastAppPic[7].Load("Picup8.png"))
	{
		return false;
	}

	if (!m_LastAppPic[8].Load("Picup9.png"))
	{
		return false;
	}

	if (!m_LastAppPic[9].Load("Picup10.png"))
	{
		return false;
	}

	if (!m_LastAppPic[10].Load("Picup11.png"))
	{
		return false;
	}

	if (!m_LastAppPic[11].Load("Picup12.png"))
	{
		return false;
	}

	if (!m_LastAppPic[12].Load("Picup13.png"))
	{
		return false;
	}

	if (!m_LastAppPic[13].Load("Picup14.png"))
	{
		return false;
	}

	if (!m_LastAppPic[14].Load("Picup15.png"))
	{
		return false;
	}


	if (!m_PickUp.Load("Picup.png"))
	{
		return false;
	}

	if (!m_Text.Load("Text.png"))
	{
		return false;
	}


	return true;
}

//�����[�X
void Gallery::Release(void)
{
	m_BackTexture.Release();
	m_SelectTexture.Release();
	gFont1.Release();

	for (int i = 0; i < 15; i++)
	{
		m_LastApp[i].Release();
	}

	for (int i = 0; i < 15; i++)
	{
		m_LastAppPic[i].Release();
	}

	m_PickUp.Release();
	m_Text.Release();

}



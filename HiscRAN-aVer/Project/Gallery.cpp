#include "Gallery.h"


#define MenuCnt (16)

int galleryCnt = 0;



CGallery::CGallery() :
	m_BackTexture(),
	m_LastApp(),
	m_NotLastApp(),
	m_SelectTexture(),
	m_SelectTexture_s(),
	m_BackButton(),
	m_PickUp(),
	m_Text()
{

}

CGallery::~CGallery()
{

}

//���[�h
bool CGallery::Load(void)
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Gallery");

	//�w�i�e�N�X�`���̓ǂݍ���
	if (!m_BackTexture.Load("CollectionBG.png"))
	{
		return false;
	}

	//�ŏI�e�p�I���摜�ǂݍ���
	if (!m_LastApp.Load("collection.png"))
	{
		return false;
	}

	//������
	if (!m_PickUpText.Load("Collection_Text.png"))
	{
		return false;
	}

	//������ŏI�e�p�I���摜�ǂݍ���
	if (!m_NotLastApp[0].Load("collection_NotFound_00.png"))
	{
		return false;
	}

	if (!m_NotLastApp[1].Load("collection_NotFound_01.png"))
	{
		return false;
	}

	if (!m_NotLastApp[2].Load("collection_NotFound_02.png"))
	{
		return false;
	}

	if (!m_NotLastApp[3].Load("collection_NotFound_03.png"))
	{
		return false;
	}

	if (!m_NotLastApp[4].Load("collection_NotFound_04.png"))
	{
		return false;
	}

	if (!m_NotLastApp[5].Load("collection_NotFound_05.png"))
	{
		return false;
	}

	if (!m_NotLastApp[6].Load("collection_NotFound_06.png"))
	{
		return false;
	}

	if (!m_NotLastApp[7].Load("collection_NotFound_07.png"))
	{
		return false;
	}

	if (!m_NotLastApp[8].Load("collection_NotFound_08.png"))
	{
		return false;
	}

	if (!m_NotLastApp[9].Load("collection_NotFound_09.png"))
	{
		return false;
	}

	if (!m_NotLastApp[10].Load("collection_NotFound_10.png"))
	{
		return false;
	}

	if (!m_NotLastApp[11].Load("collection_NotFound_11.png"))
	{
		return false;
	}

	if (!m_NotLastApp[12].Load("collection_NotFound_12.png"))
	{
		return false;
	}

	if (!m_NotLastApp[13].Load("collection_NotFound_13.png"))
	{
		return false;
	}

	if (!m_NotLastApp[14].Load("collection_NotFound_14.png"))
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

	//�I�����̎l�p�`
	if (!m_SelectTexture.Load("Select.png"))
	{
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	if (!m_SelectTexture_s.Load("Select_s.png"))
	{
		return false;
	}

	//�߂�{�^��
	if (!m_BackButton.Load("BackButton.png"))
	{
		return false;
	}



	return true;
}

//������
void CGallery::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	Load();

	g_MusicManager->BGMStart(BGMT_GALLERY);

	m_NowScene = SCENENO_GALLERY;

}

//�X�V
void CGallery::Update(void)
{

	//Enter�Ŗ߂邩�͌���
	if (galleryCnt == 15 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}
	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//���L�[�E�őI�����E�ɍs���悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		//SE�Đ����Ȃ�������
		g_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt < MenuCnt - 1)
		{
			galleryCnt++;
		}
	}

	//���L�[���őI�������ɍs���悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		g_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt > 0)
		{
			galleryCnt--;
		}
	}

	//���L�[���őI����������悤�ɂ���
	//���ɉ����遁5��̂��̂ɂȂ�
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		g_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt < MenuCnt - 1 && galleryCnt <= 10)
		{
			galleryCnt += 5;
		}
		else if (galleryCnt > 10)
		{
			galleryCnt = 15;
		}
	}
	//���L�[��őI�����オ��悤�ɂ���
	//��ɏオ�遁5�O�̂��̂ɂȂ�
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		g_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt > 0 && galleryCnt - 5 >= 0)
		{
			galleryCnt -= 5;
		}
	}


}

//�`��
void CGallery::Render(void)
{

	//�ŏI�e�p�䎆
	m_BackTexture.Render(0, 0);

	//�ŏI�e�p����ς݉摜
	m_LastApp.Render(60, 40);

	//�ŏI�e�p�\���ʒu
	m_PickUp.Render(766, 40);

	//�e�L�X�g�{�b�N�X
	m_Text.Render(766, 461);

	//�߂�{�^��
	m_BackButton.Render(60, 650);

	//�t���O��false�̏ꍇ�A�ŏI�e�p���B������
	//�摜�ɍ����ւ���
	for (int i = 0; i < 15; i++)
	{
		if (LastAddFlag[i] == false)
		{
			m_NotLastApp[i].Render(pos[i].x, pos[i].y);
		}

	}
	//�I�����͂ݘg�̕\��
	if (galleryCnt == 15)
	{
		m_SelectTexture_s.Render(60, 650);
		m_PickUp.Render(766, 50);
	}
	else if (galleryCnt != 15)
	{
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
	}

	//�����ŏI�e�p����t���O��False�������ꍇ
	if (LastAddFlag[galleryCnt] == false)
	{
		//�ŏI�e�p��\�������ʉ摜��\��
		m_PickUp.Render(766, 50);

		//��������̕\�L�ɂ���
		m_NotPickUpText.Render(766, 461, RecTextBox[galleryCnt]);
	}
	else
	{
		//�ŏI�e�p��\��
		m_LastAppPic[galleryCnt].Render(766, 50);

		m_PickUpText.Render(766, 461, RecTextBox[galleryCnt]);
	}



}

void CGallery::RenderDebug(void)
{
	//��`���m�F�p
	CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "galleryCnt:%d", galleryCnt);

	CGraphicsUtilities::RenderString(10, 10, "�M�������[���");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");

	//�t���O�؂芷��
	//����f�o�b�N�ɏ����ʂ�
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


//�����[�X
void CGallery::Release(void)
{
	m_BackTexture.Release();
	m_SelectTexture.Release();
	m_SelectTexture_s.Release();
	m_BackButton.Release();

	m_LastApp.Release();

	for (int i = 0; i < 15; i++)
	{
		m_NotLastApp[i].Release();
	}

	for (int i = 0; i < 15; i++)
	{
		m_LastAppPic[i].Release();
	}

	m_PickUp.Release();
	m_Text.Release();

	g_MusicManager->BGMStop(BGMT_GALLERY);

}



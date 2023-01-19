////////////////////////////////////////
//	�M�������[�̃v���O�����ł��@�@�@�@//
//									�@//
//�@�쐬�ҁF���Y���H�@�@�@�@�@		�@//
//									�@//
//�@���t�@�N�^�����O�����l�F�c���@�@//
//									�@//
//�@�ŏI�X�V�F2023/01/17			�@//
////////////////////////////////////////

#include "Gallery.h"

CGallery::CGallery() :
	m_BackTexture(),
	m_LastApp(),
	m_SelectTexture(),
	m_SelectTexture_s(),
	m_BakLastAp(),
	S_LastParameter(),
	m_BakLastRect(),
	m_PickUpText(),
	m_NotPickUpText(),
	m_BackButton(),
	m_Text(),
	m_BakAlph(),
	m_galleryCnt()
{

}

CGallery::~CGallery()
{

}

//���[�h
void CGallery::Load(void)
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Gallery");

	//�w�i�e�N�X�`���̓ǂݍ���
	if (!m_BackTexture.Load("CollectionBG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�ŏI�e�p�I���摜�ǂݍ���
	if (!m_LastApp.Load("collection.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//������
	if (!m_PickUpText.Load("Collection_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//������{�I�摜�ǂݍ���
	char* NotFound_name[] = {
	"collection_NotFound_00.png",
	"collection_NotFound_01.png",
	"collection_NotFound_02.png",
	"collection_NotFound_03.png",
	"collection_NotFound_04.png",
	"collection_NotFound_05.png",
	"collection_NotFound_06.png",
	"collection_NotFound_07.png",
	"collection_NotFound_08.png",
	"collection_NotFound_09.png",
	"collection_NotFound_10.png",
	"collection_NotFound_11.png",
	"collection_NotFound_12.png",
	"collection_NotFound_13.png",
	"collection_NotFound_14.png"
	};

	for (int i = 0; i < 15; i++)
	{
		if (!S_LastParameter[i].s_NotLastApp.Load(NotFound_name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}


	//�ŏI�e�p�̃e�N�X�`��
	char* Picup_name[] = {
	"Picup1.png",
	"Picup2.png",
	"Picup3.png",
	"Picup4.png",
	"Picup5.png",
	"Picup6.png",
	"Picup7.png",
	"Picup8.png",
	"Picup9.png",
	"Picup10.png",
	"Picup11.png",
	"Picup12.png",
	"Picup13.png",
	"Picup14.png",
	"Picup15.png"
	};

	for (int i = 0; i < 15; i++)
	{
		if (!S_LastParameter[i].s_LastAppPic.Load(Picup_name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}

	//�ŏI�e�p�w�i
	if (!m_BakLastAp.Load("collection_Picup_Rare.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//��������̃q���g�A�C�R��
	if (!m_NotPickUpText.Load("Collection_NotFoundText.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�e�L�X�g�{�b�N�X�w�i
	if (!m_Text.Load("Collection_TextBox.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�I�����̎l�p�`
	if (!m_SelectTexture.Load("Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//�߂�{�^���I��g
	if (!m_SelectTexture_s.Load("BackButton_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�߂�{�^��
	if (!m_BackButton.Load("BackButton.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	b_LoadSitu = LOAD_COMP;

}

//������
void CGallery::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//�e�}�l�[�W���[�Z�b�g
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;

	//�ŏI�e�p�w�i�̕\����`��ݒ�
	//�m�[�}��
	m_BakLastRect[BL_NORMAL].SetValue(800,400,1200,800);

	//�X�[�p�[���f�B
	m_BakLastRect[BL_SUPERLADY].SetValue(0, 0, 400, 400);

	//�����q��
	m_BakLastRect[BL_OTYOUSI].SetValue(400, 0, 800, 400);

	//���w����
	m_BakLastRect[BL_BUNGAKU].SetValue(800, 0, 1200, 400);

	//����a
	m_BakLastRect[BL_TYUNI].SetValue(0, 400, 400, 800);

	//�_�Ή�
	m_BakLastRect[BL_KAMITAIOU].SetValue(400, 400, 800, 800);

	//����󋵂��擾
	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_LastAddFlag = b_GameProgMamt->GetGallery_flg(i);
	}

	//�f�ރ��[�h
	Load();

	//�G���[��ԂłȂ��ꍇ
	if (b_LoadSitu != LOAD_ERROR) {
		//����������
		b_LoadSitu = LOAD_DONE;
	}

	//���݂̃V�[���Z�b�g
	m_NowScene = SCENENO_GALLERY;

	//�t�F�[�h�C���p
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	//�J�[�\��������
	m_galleryCnt = 0;
}

//�X�V
void CGallery::Update(void)
{
	//BGM�Đ�
	b_MusicManager->BGMStart(BGMT_GALLERY);

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//�t�F�[�h�A�E�g�I��->���̃V�[����
	if (b_Fadein == FADE_NEXT) {

		//���[�h�Z���N�g��
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}


	//�t���O�؂芷��
	//����f�o�b�N�ɏ����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_0))
	{
		S_LastParameter[m_galleryCnt].s_LastAddFlag = S_LastParameter[m_galleryCnt].s_LastAddFlag ? !S_LastParameter[m_galleryCnt].s_LastAddFlag : !S_LastParameter[m_galleryCnt].s_LastAddFlag;
	}


	//Enter�Ŗ߂�
	if (m_galleryCnt == 15 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	
	//���L�[�E�őI�����E�ɍs���悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		//SE�Đ����Ȃ�������
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (m_galleryCnt < MenuCnt)
		{
			m_galleryCnt++;
		}
	}

	//���L�[���őI�������ɍs���悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (m_galleryCnt > 0)
		{
			m_galleryCnt--;
		}
	}

	//���L�[���őI����������悤�ɂ���
	//���ɉ����遁5��̂��̂ɂȂ�
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (m_galleryCnt < MenuCnt&& m_galleryCnt <= 10)
		{
			m_galleryCnt += 5;
		}
		else if (m_galleryCnt > 10)
		{
			m_galleryCnt = 15;
		}
	}
	//���L�[��őI�����オ��悤�ɂ���
	//��ɏオ�遁5�O�̂��̂ɂȂ�
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (m_galleryCnt > 0 && m_galleryCnt - 5 >= 0)
		{
			m_galleryCnt -= 5;
		}
	}


}

//�`��
void CGallery::Render(void)
{

	//�M�������[��ʔw�i
	m_BackTexture.Render(0, 0);

	//�����{�I�\��
	m_LastApp.Render(60, 40);

	//�߂�{�^��
	m_BackButton.Render(60, 650);

	//�t���O��false�̏ꍇ�A�ŏI�e�p���B������
	//�摜�ɍ����ւ���
	for (int i = 0; i < 15; i++)
	{
		if (S_LastParameter[i].s_LastAddFlag == false)
		{
			//���J���{�e�N�X�`��
			S_LastParameter[i].s_NotLastApp.Render(60 + (120 * (i % 5)), 40 + ((i / 5) * 200));
		}

	}

	//�I�����͂ݘg�̕\��
	//�߂�{�^��
	if (m_galleryCnt == 15)
	{
		m_SelectTexture_s.Render(60, 650);

	}
	else
	{
		//�e�L�X�g�{�b�N�X�w�i
		m_Text.Render(766, 461);

		//�ŏI�e�p����t���O
		if (S_LastParameter[m_galleryCnt].s_LastAddFlag)
		{

			//�ŏI�e�p�w�i
			if (m_galleryCnt == LT_SUPERLADY) {

				//�X�[�p�[���f�B
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_SUPERLADY]);
			}
			else if (m_galleryCnt == LT_OTYOUSI)
			{
				//�����q��
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_OTYOUSI]);
			}
			else if (m_galleryCnt == LT_BUNGAKU)
			{
				//���w����
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_BUNGAKU]);
			}
			else if (m_galleryCnt == LT_TYUNI)
			{
				//����a
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_TYUNI]);
			}
			else if (m_galleryCnt == LT_KAMITAIOU)
			{
				//�_�Ή�
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_KAMITAIOU]);
			}
			else
			{
				//���̑��m�[�}��
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_NORMAL]);
			}

			//�ŏI�e�p��\��
			S_LastParameter[m_galleryCnt].s_LastAppPic.Render(766, 50);

			//�����e�L�X�g�\����`
			CRectangle r_Text = { (400.f * (m_galleryCnt % 3)),(m_galleryCnt / 3) * 189.f,
								400.f + (400 * (m_galleryCnt % 3)),189.f + (189 * (m_galleryCnt / 3))
			};

			//������
			m_PickUpText.Render(766, 461, r_Text);

		}
		else
		{

			//�����e�L�X�g�\����`
			CRectangle r_Text = { (400.f * (m_galleryCnt % 3)),(m_galleryCnt / 3) * 189.f,
								400.f + (400 * (m_galleryCnt % 3)),189.f + (189 * (m_galleryCnt / 3)) };

			//��������̕\�L�ɂ���
			m_NotPickUpText.Render(766, 461, r_Text);
		}

		//�{�I�ɑI���͂ݘg
		m_SelectTexture.Render(60 + (120 * (m_galleryCnt % 5)), 40 + ((m_galleryCnt / 5) * 200));
	}


	//�t�F�[�h�A�E�g���]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BakAlph, 255, 255, 255));

}

void CGallery::RenderDebug(void)
{
	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//��`���m�F�p
	CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "m_galleryCnt:%d", m_galleryCnt);

	CGraphicsUtilities::RenderString(10, 10, "�M�������[���");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");


}


//�����[�X
void CGallery::Release(void)
{
	m_BackTexture.Release();
	m_SelectTexture.Release();
	m_SelectTexture_s.Release();
	m_BackButton.Release();
	m_LastApp.Release();
	m_BakLastAp.Release();
	m_PickUpText.Release();

	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_LastAppPic.Release();
	}

	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_NotLastApp.Release();
	}

	m_Text.Release();
	m_NotPickUpText.Release();

	//BGM�X�g�b�v
	b_MusicManager->BGMStop(BGMT_GALLERY);

}


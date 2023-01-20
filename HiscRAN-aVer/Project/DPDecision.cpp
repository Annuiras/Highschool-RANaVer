///////////////////////////////////////////
//�@DP�I����ʂ̃v���O�����ł�   �@�@  �@//
//								   �@�@�@//
//�@�쐬�ҁF���Y���H  �@�@�@�@�@�@�@�@�@ //
//								   �@�@�@//
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@//
//								   �@�@�@//
//�@�ŏI�X�V�F2023/01/19		   �@�@�@//
///////////////////////////////////////////

#include "DPDecision.h"

//�R���X�g���N�^
CDPDecision::CDPDecision() :
	RandmuBak(),
	m_Back_BB(),
	m_BackChara_B(),
	m_Target_Text(),
	m_SelectTexture(),
	m_BackMagnet_Name(),
	m_WhiteBakAlph(),
	DPDecCnt(),
	flagD(true),
	SP_flg()
{

}

//�f�X�g���N�^
CDPDecision::~CDPDecision()
{

}

//�f�ރ��[�h
void CDPDecision::Load(void)
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("DPDecision");

	//�w�i����
	if (!m_Back_BB.Load("DPDecision_new_2.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�I��g
	if (!m_SelectTexture.Load("DPDecision_new_4.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���h��L����
	if (!m_BackChara_B.Load("DPDecision_new_3.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�}�O�l�b�g&���O
	if (!m_BackMagnet_Name.Load("DPDecision_new_1.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}


	//�ڕW����
	if (!m_Target_Text.Load("DPDecision_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//��ʐ���
	if (!m_Screen_Ex.Load("DPDecision_new_ExText.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//���[�h�󋵍X�V
	b_LoadSitu = LOAD_COMP;

}

//������
void CDPDecision::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//�e�}�l�[�W���[�Z�b�g
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;
	b_MenuMamt = menu;

	//�f�ރ��[�h
	Load();

	//�G���[��ԂłȂ��ꍇ
	if (b_LoadSitu == LOAD_COMP) {
		//����������
		b_LoadSitu = LOAD_DONE;
	}

	//�I����������
	DPDecCnt = 0;

	//�����\��
	flagD = true;

	//�t�F�[�h�C��
	m_WhiteBakAlph = 255;
	b_Fadein = FADE_IN;

	//SP�X�e�[�W���ǂ����𔻒�
	SP_flg =false;
	if (RandmuBak.GetRandomNumbe(0, 5) == 50) {
		//�ܕ��̈�̊m����SP�X�e�[�W����
		SP_flg = true;
	}

}

//�X�V
void CDPDecision::Update(void)
{
	//BGM�Đ�
	b_MusicManager->BGMStart(BGMT_DPDECISION);

	//�f�o�b�N�X�V
	UpdateDebug();

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph,true);
		return;
	}

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		//���j���[�̃^�C�v����
		if (b_MenuMamt->GetMenuType()== MENUT_GAME_END) {
			m_bEnd = true;
			m_NextScene = SCENENO_SELECTMODE;
		}
		else
		{
			//���ڂ�I��ł���
			m_bEnd = true;
			m_NextScene = SCENENO_GAME;
		}

	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		return;
	}


	//�����\����
	if (flagD == true)
	{
		//�G���^�[�Ŕ�\��
		if (g_pInput->IsKeyPush(MOFKEY_RETURN)) {
			flagD = false;

			//SE�Đ��F�J�[�\���ړ�
			b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		}		
		return;
	}

	if (b_MenuMamt->IsShow())
	{
		//���j���[�̍X�V
		b_MenuMamt->Update();

		//���j���[���莞
		if (b_MenuMamt->IsEnter())
		{
			//���j���[�̃^�C�v�ʏ���
			switch (b_MenuMamt->GetMenuType())
			{
			case MENUT_DPCONFIRM:
				if (b_MenuMamt->GetSelect() == 0)
				{
					b_Fadein = FADE_OUT;
					//DP�̑I�����L�^
					b_GameProgMamt->SetDPdec_type(DPDecCnt);
					//���j���[��\��
					b_MenuMamt->Hide();
				}
				else if (b_MenuMamt->GetSelect() == 1)
				{
					//���j���[��\��
					b_MenuMamt->Hide();
				}

				break;

			case MENUT_GAME_END:
				if (b_MenuMamt->GetSelect() == 0)
				{
					b_Fadein = FADE_OUT;
					//���j���[��\��
					b_MenuMamt->Hide();
				}
				else if (b_MenuMamt->GetSelect() == 1)
				{
					//���j���[��\��
					b_MenuMamt->Hide();
				}
				break;
			default:
				break;
			}

		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//DP�I���m�胁�j���[�\��
		b_MenuMamt->Show(MENUT_DPCONFIRM);

		//SE�Đ��F���莞
		b_MusicManager->SEStart(SE_T_DECISION);
	}
	else if(g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//�I�����j���[�\��
		b_MenuMamt->Show(MENUT_GAME_END);
	}
	else 
	{
		//���L�[�E�őI�����E�ɍs���悤�ɂ���
		if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
		{
			if (DPDecCnt < DPDECISION_MENUCNT - 1)
			{
				DPDecCnt++;

				//SE�Đ��F�J�[�\���ړ�
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
		}
		//���L�[���őI�������ɍs���悤�ɂ���
		else if (g_pInput->IsKeyPush(MOFKEY_LEFT))
		{
			if (DPDecCnt > 0)
			{
				DPDecCnt--;

				//SE�Đ��F�J�[�\���ړ�
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
		}
		//���L�[���őI����������悤�ɂ���
		//���ɉ����遁�R��̂��̂ɂȂ�
		if (g_pInput->IsKeyPush(MOFKEY_DOWN))
		{
			if (DPDecCnt < DPDECISION_MENUCNT - 1 && DPDecCnt < 2)
			{
				DPDecCnt += 3;

				//SE�Đ��F�J�[�\���ړ�
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
			else if (DPDecCnt == 3)
			{
				DPDecCnt = 3;

				//SE�Đ��F�J�[�\���ړ�
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
		}

		//���L�[��őI�����オ��悤�ɂ���
		//��ɏオ�遁�R�O�̂��̂ɂȂ�
		if (g_pInput->IsKeyPush(MOFKEY_UP))
		{
			if (DPDecCnt > 0 && DPDecCnt - 3 >= 0)
			{
				DPDecCnt -= 3;

				//SE�Đ��F�J�[�\���ړ�
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
		}

	}
}

void CDPDecision::UpdateDebug(void)
{

	//SP�t���O�̐؂�ւ�
	if (g_pInput->IsKeyPush(MOFKEY_P))
	{
		SP_flg = !SP_flg;
	}

}

//�`��
void CDPDecision::Render(void)
{
	//�w�i����
	m_Back_BB.Render(0, 0);

	//���h��L����
	m_BackChara_B.Render(0, 0);

	//�I���摜�`����W�ʒu�iX���W�j
	int PosSelectX = 399;

	//�I���摜�`����W�ʒu�iY���W�j
	int PosSelectY = 350;

	//�\���ʒu�A��`���Z�o
	int addX = DPDecCnt % 3;
	int addY = DPDecCnt / 3;
	//�摜��`
	CRectangle recSelect(PosSelectX * addX, PosSelectY* addY, 
						 PosSelectX+(PosSelectX * addX), PosSelectY+(PosSelectY * addY));

	//�I��g
	m_SelectTexture.Render(recSelect.Left, recSelect.Top, recSelect);

	//�}�O�l�b�g&���O
	m_BackMagnet_Name.Render(0, 0);


	//�z��̔ԍ���DP���̑Ή��͈ȉ��̒ʂ�ł��B
	//[0]���z����
	//[1]���s����
	//[2]������
	//[3]���R�~����
	//[4]���w��

	//���������\���ʒuX
	int	PosTextX[5] = { 867,867,867,867,856 };
	//���������\���ʒuY
	int PosTextY = 397;
	//����������`
	CRectangle recExText[5] = { {0,0,343,259},{344,0,687,259},{688,0,1031,259},{0,259,344,518},{344,259,708,519} };

	//��������
	m_Target_Text.Render(PosTextX[DPDecCnt], PosTextY,recExText[DPDecCnt]);

	//����\���������\��
	if (flagD == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_Screen_Ex.Render(0, 124);
	}

	//���j���[�̕`��
	if (b_MenuMamt->GetMenuType() == MENUT_DPCONFIRM){

		//DP�I�����胁�j���[���
		b_MenuMamt->Render(DPDecCnt);

	}
	else
	{
		//�Q�[����ʏI�����
		b_MenuMamt->Render();
	}

	//�t�F�[�h�A�E�g
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

}

//�f�o�b�N�`��
void CDPDecision::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 300, "DPDecCnt:%d", DPDecCnt);

	if (SP_flg) {
		CGraphicsUtilities::RenderString(10, 330, "SP����");

	}
	else
	{
		CGraphicsUtilities::RenderString(10, 330, "SP�Ȃ�");

	}

}

void CDPDecision::Release(void)
{
	//�摜�f�ނ̉��
	m_Back_BB.Release();
	m_BackChara_B.Release();
	m_Target_Text.Release();
	m_SelectTexture.Release();
	m_Screen_Ex.Release();
	m_BackMagnet_Name.Release();

	//SP�t���O��ۑ�
	b_GameProgMamt->SetDPdec_SPflg(SP_flg);

	//BGM�X�g�b�v
	b_MusicManager->BGMStop(BGMT_DPDECISION);
}
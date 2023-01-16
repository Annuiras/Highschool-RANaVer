#include "MusicManager.h"

//����ҁF�c�� ��

CMusicMgmt::CMusicMgmt()
{}

CMusicMgmt::~CMusicMgmt()
{}

tag_LoadSituation CMusicMgmt::Load(void) {

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("SE");

	//SE�̓ǂݍ���
	char* sename[] = {
	#pragma region �Q�[��,�I�[�o�[,�N���A���
		//�W�����v�n
		"Jump.mp3",
		"great_jump.mp3",
		"jumpLanding.mp3",

		//�q�b�g�n
		//"DP_GET���1.mp3",
		//"DP_GET���2.mp3",
		"DP_GET.mp3",
		//"DP_GET���4.mp3",

		//"��Q�����b�J_���1.mp3",
		//"��Q����_���1.mp3",
		//"��Q����_���2.mp3",
		//"��Q����_���3.mp3",
		//"��e_���1.mp3",
		//"��e_���3.mp3",
		"hit.mp3",

		//�Q�[���I�[�o�[�n
		//"Gameover_���1_�G�R�[�v.mp3",
		//"Gameover_���2.mp3",
		"Gameover.mp3",
		//"Gameover_���4.mp3",
		//"�I�[�o�[���_���5.mp3",

		//�Q�[���N���A�n
		"Clear.mp3",
		//"�N���A_���2.mp3",
		//"�N���A_���3.mp3",
		//"�N���A_���4.mp3",
	#pragma endregion

	#pragma region DP�I�����
		"DPDecision_dec.mp3",
	#pragma endregion

	#pragma region �M�������[���
		"Gallery_Cursor_Move.mp3",
	#pragma endregion

	#pragma region ���[�h�Z���N�g,�I�v�V�������
		"Mode_Select_Cursor_Move.mp3",
		//"�J�[�\���ړ�_���2.mp3",
		//"�J�[�\���ړ�_���3.mp3",
		//"�J�[�\���ړ�_���4.mp3",
		//"�J�[�\���ړ�_���5.mp3",
		"Decision.mp3",
		"Chime-Announce07-1.mp3",

	#pragma endregion

	};

	for (int type = 0; type < SE_TYPE_COUNT; type++)
	{
		//�����Đ����ݒ�
		//m_Music_SE[SET_CHIME].SetBufferCount(5);

		if (!m_Music_SE[type].Load(sename[type]))
		{
			return tag_LoadSituation::LOAD_ERROR;
		}
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("BGM");

	//bgm�̓ǂݍ���
	char* bgmname[] = {

	#pragma region �^�C�g�����
		//"Title_��� (1).mp3",
		"Title.mp3",
		//"Title_��� (3).mp3",
		//"Title_��� (4).mp3",
		//"Title_��� (5).mp3",
		//"Title_��� (6).mp3",
		//"Title_��� (7).mp3",
		//"Title_��� (8).mp3",
		//"Title_��� (9).mp3",
	#pragma endregion

	#pragma region �`���[�g���A�����
		"Tutorial.mp3",
	#pragma endregion


	#pragma region �Q�[��,�I�[�o�[,�N���A���
		//"Stage_��� (1).mp3",
		"Stage.mp3",
		//"Stage_��� (3).mp3",
		//"Stage_��� (4).mp3",
		//"Stage_��� (5).mp3",
		//"Stage_��� (6).mp3",
		//"Stage_��� (7).mp3",
		//"Stage_��� (8).mp3",
		//"Stage_��� (9).mp3",
		//"Stage_��� (10).mp3",
		//"Stage_��� (11).mp3",
		//"Stage_��� (12).mp3",
		//"SP��_���1.mp3",
		"clear.mp3",
	#pragma endregion

	#pragma region DP�I�����
		"DPDecision_BGM.mp3",
	#pragma endregion


	#pragma region �M�������[���
		"Gallery.mp3",
	#pragma endregion
		
	#pragma region ���[�h�Z���N�g,�I�v�V�������
		"ModeOption.mp3",
	#pragma endregion

	};
	for (int type = 0; type < BGM_TYPE_COUNT; type++)
	{
		if (!m_Music_BGM[type].Load(bgmname[type]))
		{
			return tag_LoadSituation::LOAD_ERROR;
		}
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return tag_LoadSituation::LOAD_COMP;
}

//������
void CMusicMgmt::Initialize(float bgmv, float sev) {	

	//�{�����[���Z�b�g
	BGMSetVolume(bgmv);
	SESetVolume(sev);
}

//��ʐ��ڎ��̏���������
void CMusicMgmt::InitializeIn_middle(float bgmv, float sev)
{
	//�{�����[���Z�b�g
	BGMSetVolume(bgmv);
	SESetVolume(sev);
}

//SE�Đ�
CSoundBuffer* CMusicMgmt::SEStart(tag_SE_TYPE type) {

	m_Music_SE[type].Play();
	return &m_Music_SE[type];

}

//SE��~
void CMusicMgmt::SEStop(tag_SE_TYPE type)
{
	for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
	{
		if (m_Music_SE[type].IsPlay())
		{
			m_Music_SE[type].Stop();
		}
	}
}

//SE�{�����[���Z�b�g
void CMusicMgmt::SESetVolume(float sev)
{	
	//SE�̊�b�ݒ�
	//��ނ̐�
	for (int type = 0; type < SE_TYPE_COUNT; type++)
	{
		m_Music_SE[type].SetVolume(sev);	
	}

}
//SE���Đ�����Ă��邩�擾
bool CMusicMgmt::SEisPlay(tag_SE_TYPE type)
{
	if (m_Music_SE[type].IsPlay())
		return true;

	return false;
}

//BGM�X�^�[�g
CSoundBuffer* CMusicMgmt::BGMStart(tag_BGM_TYPE type)
{
	if (!m_Music_BGM[type].IsPlay())
	{	
		m_Music_BGM[type].Play();
		return &m_Music_BGM[type];
	}
	
	return NULL;
}

//BGM��~
void CMusicMgmt::BGMStop(tag_BGM_TYPE type)
{
	if (m_Music_BGM[type].IsPlay())
	{
		m_Music_BGM[type].Stop();
	}

}

//BGM�{�����[���Z�b�g
void CMusicMgmt::BGMSetVolume(float bgmv)
{	
	//BGM�̊�b�ݒ�
	//��ނ̐�
	for (int type = 0; type < BGM_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].SetVolume(bgmv);
	}

}

//SE�����ׂĒ�~
void CMusicMgmt::SEALLStop(void)
{
	for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
	{
		if (m_Music_SE[mgmt].IsPlay())
		{
			m_Music_SE[mgmt].Stop();
		}
	}


}

//BGM���[�v�ݒ�
void CMusicMgmt::BGMLoop(tag_BGM_TYPE type, bool b)
{
	m_Music_BGM[type].SetLoop(b);

}

//SE�{�����[���Q�b�g
//SE�̃{�����[���͂��ׂē����Ȃ̂ň�̂ݎ擾
float CMusicMgmt::GetSEVolume()
{
	return m_Music_SE[0].GetVolume();
}

//BGM�{�����[���Q�b�g
//BGM�̃{�����[���͂��ׂē����Ȃ̂ň�̂ݎ擾
float CMusicMgmt::GetBGMVolume()
{
	return 	m_Music_BGM->GetVolume();
}

//���
void CMusicMgmt::Release() {

	for (int type = 0; type < SE_TYPE_COUNT; type++)
	{
		m_Music_SE[type].Release();
	}

	for (int type = 0; type < BGM_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].Release();
	}

}
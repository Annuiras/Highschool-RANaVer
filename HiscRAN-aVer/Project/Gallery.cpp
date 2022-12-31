#include "Gallery.h"


#define MenuCnt (16)

int galleryCnt = 0;


CGallery::CGallery() :
	m_BackTexture(),
	m_LastApp(),
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

	//������ŏI�e�p�I���摜�ǂݍ���
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


	//�ŏI�e�p�̃e�N�X�`��(�o��&�s�b�N�A�b�v�p)
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


	if (!m_PickUp.Load("Picup.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_Text.Load("Text.png"))
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

	if (!m_SelectTexture_s.Load("Select_s.png"))
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

	//Vector2{}		�F�{���W
	//CRectangle{}	�F�������\����`
	//����t���O	�Ftrue,�����

	//�o��
	S_LastParameter[0] = SetLastParameter({ 60, 40 }, { 0,0,400,189 },true);

	//�N���X�̐l�C��
	S_LastParameter[1] = SetLastParameter({ 180,40 }, { 400,0,800,189 },true);

	//�M����
	S_LastParameter[2] = SetLastParameter({ 300,40 }, { 800,0,1200,189 },true);

	//�����c��
	S_LastParameter[3] = SetLastParameter({ 420,40 }, { 0,189,400,378 },true);

	//�}�����̒�
	S_LastParameter[4] = SetLastParameter({ 540,40 }, { 400,189,800,378 },true);

	//�I�^�N
	S_LastParameter[5] = SetLastParameter({ 60,240 }, { 800,189,1200,378 },true);

	//�C���t���G���T�[
	S_LastParameter[6] = SetLastParameter({ 180,240 }, { 0,378,400,567 },true);

	//�ψ���
	S_LastParameter[7] = SetLastParameter({ 300,240 }, { 400,378,800,567 },true);

	//����̉�
	S_LastParameter[8] = SetLastParameter({ 420,240 }, { 800,378,1200,567 },true);

	//�����L�[
	S_LastParameter[9] = SetLastParameter({ 540,240 }, { 0,567,400,756 },true);

	//�X�[�p�[���f�B
	S_LastParameter[10] = SetLastParameter({ 60,440 }, { 400,567,800,756 },true);

	//�����q��
	S_LastParameter[11] = SetLastParameter({ 180,440 }, { 800,567,1200,756 },true);

	//���w����
	S_LastParameter[12] = SetLastParameter({ 300,440 }, { 0,756,400,945 },true);

	//����a
	S_LastParameter[13] = SetLastParameter({ 420,440 }, { 400,756,800,945 },true);

	//�_�Ή�
	S_LastParameter[14] = SetLastParameter({ 540,440 }, { 800,756,1200,945 },true);


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

}

//�X�V
void CGallery::Update(void)
{
	b_MusicManager->BGMStart(BGMT_GALLERY);

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}

	//�t�F�[�h�A�E�g�I��->���̃V�[����
	if (b_Fadein == FADE_NEXT) {

		//���[�h�Z���N�g��
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}


	//Enter�Ŗ߂邩�͌���
	if (galleryCnt == 15 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
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
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt < MenuCnt - 1)
		{
			galleryCnt++;
		}
	}

	//���L�[���őI�������ɍs���悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt > 0)
		{
			galleryCnt--;
		}
	}

	//���L�[���őI����������悤�ɂ���
	//���ɉ����遁5��̂��̂ɂȂ�
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
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
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
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
		if (S_LastParameter[i].s_LastAddFlag == false)
		{
			//���J���{�e�N�X�`��
			S_LastParameter[i].s_NotLastApp.Render(S_LastParameter[i].s_Mount_Pos.x, S_LastParameter[i].s_Mount_Pos.y);
		}

	}

	//�I�����͂ݘg�̕\��
	if (galleryCnt == 15)
	{
		m_SelectTexture_s.Render(60, 650);
		m_PickUp.Render(766, 50);
	}
	else
	{
		//�I����`
		m_SelectTexture.Render(S_LastParameter[galleryCnt].s_Mount_Pos.x, S_LastParameter[galleryCnt].s_Mount_Pos.y);
	}

	//�����ŏI�e�p����t���O��False�������ꍇ
	if (S_LastParameter[galleryCnt].s_LastAddFlag == false)
	{
		//�ŏI�e�p��\�������ʉ摜��\��
		m_PickUp.Render(766, 50);

		//��������̕\�L�ɂ���
		m_NotPickUpText.Render(766, 461,S_LastParameter[galleryCnt].s_TextBoxRect);
	}
	else
	{
		//�ŏI�e�p��\��
		S_LastParameter[galleryCnt].s_LastAppPic.Render(766, 50);

		//������
		m_PickUpText.Render(766, 461, S_LastParameter[galleryCnt].s_TextBoxRect);
	}

	//�t�F�[�h�A�E�g���]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BakAlph, 255, 255, 255));

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
	if (g_pInput->IsKeyPush(MOFKEY_O))
	{
		if (S_LastParameter[galleryCnt].s_LastAddFlag == false)
		{
			S_LastParameter[galleryCnt].s_LastAddFlag = true;
		}
		else
		{
			S_LastParameter[galleryCnt].s_LastAddFlag = false;
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

	m_PickUpText.Release();

	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_LastAppPic.Release();
	}

	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_NotLastApp.Release();
	}

	m_PickUp.Release();
	m_Text.Release();

	b_MusicManager->BGMStop(BGMT_GALLERY);

}


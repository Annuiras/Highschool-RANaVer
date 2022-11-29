#pragma once
#include "Mof.h"
#include "Define.h"
#include "RandomValue.h"
#include "Ground.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"
#include "EffectManager.h"
#include "MusicManager.h"

////DP�̏o���ʒu���p�\����
typedef struct tag_DP_POS
{
	float Scroll;	//DP�o���X�N���[���l
	float Pos_y;	//DP�o��Y���W
	tag_DP_TYPE	Type;		//DP�^�C�v

} DP_info;

//��Q���̏o���ʒu���p�\����
typedef struct tag_OBSTAClE_POS
{	
	float Scroll;	//��Q���o���X�N���[���l
	float Pos_y;	//��Q���o��Y���W
	tag_OBTYPE	Type;		//��Q���^�C�v

} OB_info;


//����̏o���ʒu���p�\����
typedef struct tag_BAR_POS
{	
	float Scroll;	//����o���X�N���[���l
	float Pos_y;	//����o��Y���W
	tag_BAR	Type;		//����^�C�v�i���j

} BAR_info;

class CStage
{
private:

	//��������
	RandomValue RandmuBak;

	//�G�t�F�N�g�}�l�[�W���[
	CEffectMgmt* m_pEffectMgmt;

	//SE�EBGM�}�l�[�W���[
	CMusicMgmt* m_MusicMgmt;


	#pragma region �X�e�[�W�e�N�X�`��

	//�L���n�܂�
	CTexture m_BakStart;

	//�E��
	CTexture m_BakRdoor;
	
	//�E��
	CTexture m_BakRwall;

	//����
	CTexture m_Bakldoor;

	//����
	CTexture m_Baklwall;

	//��
	CTexture m_BakWindow;

	//�K�i
	CTexture m_BakStairs;

	//�L���I���
	CTexture m_BakEnd;

	//SP�X�e�[�W�e�N�X�`��
	CTexture m_SPBak;

#pragma endregion

	#pragma region DP�e�N�X�`��

	//��DP�e�N�X�`���F�w��
	CTexture dp_Textuer_Scholastic;

	//��DP�e�N�X�`���F�s����
	CTexture dp_Textuer_Action;

	//��DP�e�N�X�`���F�z����
	CTexture dp_Textuer_Imagination;

	//��DP�e�N�X�`���F�R�~����
	CTexture dp_Textuer_Communication;

	//��DP�e�N�X�`���F����
	CTexture dp_Textuer_Charm;


#pragma endregion

	#pragma region ��Q���e�N�X�`��

	//���e�N�X�`���F��
	CTexture ob_Textuer_Desk;

	//���e�N�X�`���F�Q�i��
	CTexture ob_Textuer_TwoDesk;

	//���e�N�X�`���F���b�J�[
	CTexture ob_Textuer_Locker;



#pragma endregion

#pragma region ����e�N�X�`��

	//���e�N�X�`���F���ꒆ
	CTexture bar_Textuer_Medium;

#pragma endregion

	//�}�b�v�p�^�[���Y����
	int m_MapNo;

	//�X�e�[�W�\�������߂�z��
	int m_StageComposition[MAP_INFO_PATTERN] = { 1 };


	//DP�̔z�u���󂯎��z��
	//[]:�}�b�vDP�p�^�[�����
	//[]:�}�b�vDP�p�^�[��1�����ɂ����\���̂����邩
	//DP�̔z�u���
	DP_info m_dpinfo[MAP_INFO_PATTERN][DP_INFO_STRUCT];

	//�\���ς�DP��
	int m_dpcount;


	//OB�̔z�u���󂯎��z��
	//[]:�}�b�vOB�p�^�[�����
	//[]:�}�b�vOB�p�^�[��1�����ɂ����\���̂����邩
	//OB�̔z�u���
	OB_info m_obinfo[MAP_INFO_PATTERN][OB_INFO_STRUCT];

	//�\���Ϗ�Q��
	int m_obcount;


	//����̔z�u���󂯎��z��
	//[]:�}�b�v����p�^�[�����
	//[]:�}�b�v����p�^�[��1�����ɂ����\���̂����邩
	//����̔z�u���
	BAR_info m_barinfo[MAP_INFO_PATTERN][OB_INFO_STRUCT];


	//�\���ςݑ��ꐔ
	int m_barcount;


	//�w�i�p�X�N���[���l
	float	m_BakScroll;

	//�X�e�[�W�p�X�N���[��
	float	m_StageScroll;

	//���Ԕw�i�p�����_�����l
	//����
	int m_RandamuBakLeft;
	//�E��
	int m_RandamuBakRight;

	//�g�p�ς݃p�^�[���ԍ��L�^�p�z��
	int	m_AlreadyUsedArray[MAP_INFO_PATTERN];

	//�̗p�σJ�E���g
	int m_AdoptCount;

	//�w�i�J�E���g
	int m_countbak;

	//�X�N���[���X�s�[�h
	float m_Scroll_Speed;

	//�X�e�[�W���Ŏ擾����DP�̐�
	int	m_Scholastic;		//�w��
	int	m_Action;			//�s����
	int	m_Imagination;		//�z����
	int	m_Communication;	//�R�~����
	int	m_Charm;			//����

	//�X�e�[�W�ω�
	int					m_StageChange;
	bool				m_bStart;//�ω��t���O true:�ω���
	//todo:�w�i���l
	int m_BakAVal;

	//todo SP�X�e�[�W
	int					m_SPSitua;
	int					m_SPcountbak;
	bool				m_SPflg;

	//�N���A�t���O
	bool m_bClear;

	//�Q�[���J�n�t���O
	bool					m_Startflg;

public:
	CStage();
	~CStage();

	//dpin[][]:DP�̔z�u���
	//[]:�}�b�v�p�^�[�����������邩
	//[]:1�}�b�v�p�^�[���ɂ����\���̂����邩
	void Initialize(DP_info dpin[][DP_INFO_STRUCT], BAR_info barin[][BAR_INFO_STRUCT], OB_info obin[][OB_INFO_STRUCT]);

	//todo SP����DP�z�u�����邽�߂̊֐�
	void SPInitialize(void);


	void Update(CRectangle plrect);
	bool Load(void);
	void Render(void);
	void Release(void);
	void RenderDebugging(void);

	//�}�b�v�p�^�[��
	void MapChange(void);

	//���ꐶ��
	void OccurrenceBar(void);

	//DP����
	void OccurrenceDP(void);

	//��Q������
	void OccurrenceOB(void);

	//DP�ƐڐG����
	void UPdeteCollisionDP(int dpt);

	//�N���A����̎擾
	bool GetClear(void);

	//SE�EBGM�}�l�[�W���[�Z�b�g
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//�G�t�F�N�g�}�l�[�W���[�Z�b�g
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }

	//��Q��
	CObstacle ob_array[OB_VOLUME];

	//�n�ʃN���X
	Ground g_ground;

	//����N���X
	Bar	b_bar[BAR_VOLUME];

	//���ʂɕ\������DP�̐������p��
	//DP�N���X
	DetailPoint dp_array[DP_VOLUME];

	//�Q�[����~�F�Đ��؂�ւ�
	void GameStopPlayChange();

	//�X�e�[�W�������Ă��邩�擾
	bool GetGameStopPlay();




};


#pragma once
#include "Mof.h"
#include "RandomValue.h"
#include "Ground.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"
//todo�F���ʒ�`�t�@�C��
#include "Define.h"

//todo:���ʂɑ��݂���ő�DP�ɕύX
#define DP_VOLUME	20


////DP�̏o���ʒu���p�\����
//todo:DP�\���̂̏��ԕς��Ă܂�
typedef struct tag_DP_POS
{
	float Scroll;	//DP�o���X�N���[���l
	float Pos_y;	//DP�o��Y���W
	int	Type;		//DP�^�C�v

} DP_info;

//��Q���̏o���ʒu���p�\����
//todo:��Q���\���̂̏��ԕς��Ă܂�
typedef struct tag_OBSTAClE_POS
{	
	float Scroll;	//��Q���o���X�N���[���l
	float Pos_y;	//��Q���o��Y���W
	int	Type;		//��Q���^�C�v

} OB_info;


//����̏o���ʒu���p�\����
typedef struct tag_BAR_POS
{
	float Pos_y;	//����o��Y���W
	float Scroll;	//����o���X�N���[���l

} BAR_info;

class CStage
{
private:

	//��������
	RandomValue RandmuBak;

	//�w�i�e�N�X�`��
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

	//todo:�N���A�p�X�N���[���l
	float	m_Scroll_Clear;

	//todo:�}�b�vDP�p�^�[���Y����
	int m_MapNo_DP;

	//todo:�}�b�vOB�p�^�[���Y����
	int m_MapNo_OB;


	//todo:�X�e�[�WDP�\�������߂�z��
	int m_StageDPConstitution[DP_INFO_PATTERN] = { 1 };

	//todo:�X�e�[�W��Q���\�������߂�z��
	int m_StageOBConstitution[OB_INFO_PATTERN] = { 1 };


	//todo:DP�̔z�u���󂯎��z��
	//[]:�}�b�vDP�p�^�[�����
	//[]:�}�b�vDP�p�^�[��1�����ɂ����\���̂����邩
	//DP�̔z�u���
	DP_info m_dpinfo[DP_INFO_PATTERN][DP_INFO_STRUCT];


	//todo:���ݎg�p���Ă��܂���
	//DP�̏��
	int m_dpvolume;

	//�\���ς�DP��
	int m_dpcount;


	//����̔z�u���
	BAR_info* m_barinfo;

	//����̏��
	int m_barvolume;

	//�\���ςݑ��ꐔ
	int m_barcount;

	//todo:DP�̔z�u���󂯎��z��
	//[]:�}�b�v�p�^�[�����
	//[]:�}�b�v�p�^�[��1�����ɂ����\���̂����邩
	//DP�̔z�u���
	OB_info m_obinfo[OB_INFO_PATTERN][OB_INFO_STRUCT];


	//todo:���ݎg�p���Ă��܂���
	//��Q���̏��
	int m_obvolume;

	//�\���Ϗ�Q��
	int m_obcount;


	//�w�i�p�X�N���[���l
	float	m_BakScroll;

	//�X�e�[�W�p�X�N���[��
	float	m_StageScroll;

	//���Ԕw�i�p�����_�����l
	//����
	int m_RandamuBakLeft;
	//�E��
	int m_RandamuBakRight;


	//���W�ʒu
	float					m_PosX;
	float					m_PosY;

	//�ړ����x
	float					m_MoveX;
	float					m_MoveY;

	//�w�i�J�E���g
	int m_countbak;

	//�I�[�o�[�l
	float	m_Over;

	//SP�X�e�[�W�t���O
	bool m_spflg;

	//�X�e�[�W���Ŏ擾����DP�̐�
	int	m_gaku;
	int	m_sou;
	int	m_kou;
	int	m_komyu;
	int	m_miryoku;

	//�N���A�t���O
	bool m_bClear;


	//�w�i�f�o�b�N�p
	float m_baklineX;


public:
	CStage();
	~CStage();

	//todo:������񎟌��z��ɕύX
	//dpin[][]:DP�̔z�u���
	//[]:�}�b�v�p�^�[�����������邩
	//[]:1�}�b�v�p�^�[���ɂ����\���̂����邩
	void Initialize(DP_info dpin[][DP_INFO_STRUCT], BAR_info* barin, int barco, OB_info obin[][OB_INFO_STRUCT]);

	//�����ǉ� CRectangle pl2, float suckingX, float suckingY
	void Update(float over, CRectangle pl,CRectangle pl2, float suckingX, float suckingY);
	bool Load(void);
	void Render(void);
	void Release(void);
	void DebuggingRender(void);

	//DP�ƐڐG����
	void UPdeteCollisionDP(int dpt);

	//�N���A����̎擾
	bool GetClear(void);

	//��Q��
	CObstacle ob_array[OB_VOLUME];

	//�n�ʃN���X
	Ground g_ground;

	//����N���X
	Bar	b_bar[BAR_MAX];

	//todo:���ʂɕ\������DP�̐������p��
	//DP�N���X
	DetailPoint dp_array[DP_VOLUME];


};


#pragma once
#include "Mof.h"
#include "RandomValue.h"
#include "Ground.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"

////DP�̏o���ʒu���p�\����
typedef struct tag_DP_POS
{
	float Pos_y;	//DP�o��Y���W
	float Scroll;	//DP�o���X�N���[���l
	int	Type;		//DP�^�C�v

} DP_info;

//��Q���̏o���ʒu���p�\����
typedef struct tag_OBSTAClE_POS
{
	float Pos_y;	//��Q���o��Y���W
	float Scroll;	//��Q���o���X�N���[���l

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

	//DP�̔z�u���
	DP_info* m_dpinfo;

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


	//��Q���̔z�u���
	OB_info* m_obinfo;

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

	void Initialize(DP_info* dpin, int dpco, BAR_info* barin, int barco, OB_info* obin, int obco);
	
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

	//DP�N���X
	DetailPoint dp_array[DP_VOLUME];


};


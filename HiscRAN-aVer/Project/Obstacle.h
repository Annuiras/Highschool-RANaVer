#pragma once
#include "Mof.h"
#include "Define.h"
#define OB_VOLUME 5

//��Q���F�����E�c��
#define OB_DESK_WIDTH 131
#define OB_DESK_HEIGHT 172

//��i��
#define OB_TOWDESK_WIDTH 131
#define OB_TOWDESK_HEIGHT 292

//���b�J�[
#define OB_LOCKER_WIDTH 138
#define OB_LOCKER_HEIGHT 308

//�����`���荂��
#define OB_TOPBAR_HEIGHT 20

class CObstacle
{

private:

	//���e�N�X�`��
	CTexture*	ob_Textuer;

	//���W
	float ob_PosX;
	float ob_PosY;

	//�\���t���O:true�F�\��
	bool ob_Show;

	//��Q���^�C�v�ʉ���
	float ob_HitWidth;

	int ob_Type;

public:

	CObstacle();
	~CObstacle();

	void Initialize(void);


	void Update(float over);
	void Start(float posy,int type);

	//OB�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* obtex);

	void Render(void);
	void RenderDebugging(void);


	//�_���[�W��`�擾
	CRectangle GetRect(int type);

	//��Q����ɏ��铖���蔻��擾
	CRectangle GetTopBarRect(int type);


	//�\�����t���O�擾
	bool Getshow(void) { return ob_Show; }

	//��Q���^�C�v�擾
	bool GetType(void) { return ob_Type; }

	//Y���W�擾
	float GetY(void) { return ob_PosY; }

	//�\���t���O�Z�b�g
	void Setshow(bool b) { ob_Show = b; }

};


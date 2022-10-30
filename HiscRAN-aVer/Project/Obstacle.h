#pragma once
#include "Mof.h"
#define OB_VOLUME 5

#define OB_DESK_WIDTH 137
#define OB_DESK_HEIGHT 180

class CObstacle
{

private:

	//todo:���e�N�X�`��:�֎q
	CTexture	ob_Textuer_Desk;

	////���e�N�X�`��:
	//CTexture	ob__Textuer;

	////���e�N�X�`��:
	//CTexture	ob__Textuer;

	float ob_PosX;
	float ob_PosY;

	//�\���t���O:true�F�\��
	bool ob_Show;

	//todo:��Q���^�C�v�ʉ���
	float ob_HitWidth;

	//todo:��Q����ށi���j
	//1:��
	//2:�Q�i��
	int ob_Type;

public:

	CObstacle();
	~CObstacle();

	void Initialize(void);

	//todo:���[�h�ǉ��ł�
	bool Load(void);


	void Update(float over);
	void Start(float posy,int type);

	void Render(void);
	void RenderDebugging(void);



	CRectangle GetRect(int type);

	bool Getshow(void) { return ob_Show; }

	bool GetType(void) { return ob_Type; }

	void Setshow(bool b) { ob_Show = b; }

};

